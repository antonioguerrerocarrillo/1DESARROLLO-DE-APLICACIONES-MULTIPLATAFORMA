#include <iostream>
#include <string>
#include <stdlib.h>
#include <iomanip>
#include <stdio.h>
#include <string.h>

#define BLACK_COLOR "\033[1;30m"
#define RED_COLOR "\033[1;31m"
#define GREEN_COLOR "\033[1;32m"
#define YELLOW_COLOR "\033[1;33m"
#define BLUE_COLOR "\033[1;34m"
#define PURPLE_COLOR "\033[1;35m"
#define CYAN_COLOR "\033[1;36m"
#define WHITE_COLOR "\033[1;39m"
#define RESTORE_DEFAULT_COLOR "\033[0m"

using namespace std;

class Polinomio{
	private: 
		float *coef;
		int grado;
		int max_grado;
		void resize(float nuevo_coeficiente, int grado);
	public:
		Polinomio(); //constructir por defecto
		Polinomio(int max_grado); //constructor por parametros
		Polinomio(const Polinomio &p);
		~Polinomio(); //destructor
		void setcoeficiente(int i, float c);
		void setgrado(int nuevo_grado);
		int getcoef(int i);
		int getgrado();
		void imprimir();
		void setmax_grado(int nuevo_maxgrado);
		void set_introducir_coef();
		int getmax_grado();
		void setcoef(float *p);
		float getcoef2(int grado);
		void setcoef2(int coeficiente, float grado);
		void resize2();
		void sumar(Polinomio &p2);
		void setCoeficiente(float nuevo_coeficiente, int grado);
		void sumarv2(Polinomio &p2, Polinomio &p3);
		Polinomio sumav3(Polinomio &p2);

};

Polinomio::Polinomio(){
	cout << RED_COLOR << "debug: Construyendo polinomio por defecto" << RESTORE_DEFAULT_COLOR << "\t" << endl;
    max_grado = 10;
    setgrado(0);
    coef = new float[max_grado + 1];
    if (coef == 0){
        cerr << "No hay memoria. Goodbye my polilover!" << endl;
        exit(-1);
    }
    //inicializamos a cero todos los coeficientes
    for (int i = 0; i <= max_grado; i++)
        coef[i] = 0.0;
    cout << "debug: Polinomio construído..." << endl;
}
Polinomio::Polinomio(int max_grado){
   cout << RED_COLOR << "debug: Construyendo polinomio por parametros " << RESTORE_DEFAULT_COLOR << "\t" << endl;
    setgrado(0);
    setmax_grado(max_grado);
    coef = new float[max_grado + 1];
    if (coef == 0){
        cerr << "No hay memoria. Goodbye my polilover!" << endl;
        exit(-1);
    }
    //inicializamos a cero todos los coeficientes
    for (int i = 0; i <= max_grado; i++)
        coef[i] = 0.0;
    cout << "debug: Polinomio construído..." << endl;
}
Polinomio::Polinomio(const Polinomio &p){
    cout << "debug: Construyendo polinomio por copia" << endl;
    max_grado=p.max_grado;
    grado=p.grado;
    coef=new float [max_grado + 1];
    if (coef == 0){
            cerr << "No hay memoria. Goodbye my polilover!" << endl;
            exit(-1);
    }
     for (int i = 0; i <= max_grado; i++){
            coef[i] = p.coef[i];
    }
            cout << "debug: Polinomio construído..." << endl;

}
Polinomio::~Polinomio(){
    if (coef != 0){
        cout << RED_COLOR << "debug: Destruyendo polinomio..." << RESTORE_DEFAULT_COLOR << "\t" << endl;
        for (int i = 0; i <= max_grado; i++)
            coef[i] = 0.0;
        delete [] coef;
        coef = 0;
        max_grado = 0;
        grado = 0;
        cout << "debug: Polinomio destruido..." << endl;
    }   
}
void Polinomio::setcoef(float *p){
	for (int i = 0; i < getmax_grado();i++){
		*p = coef[i];
	}
}
/**
 * @brief metodos que introduce dentro de coef los grados
 */
void Polinomio::set_introducir_coef(){
	//coef = new float[getmax_grado];
	 cout << "debug: introducir coef Polinomio " << endl;
	float guardar = 0;
	for (int i = 0; i < getmax_grado();i++){
		cout << " introduce el grado " << endl;
		cin >> guardar;
		coef[i] = guardar;
	}
}
void Polinomio::resize2(){
    float *vector2;
         
    vector2 = new float[getgrado()+2];
    
    for(int i=0; i < getgrado(); i++){
            
        vector2[i]=getcoef(i);
    }
    setmax_grado(max_grado +1);
    setgrado(getgrado()+1);
    vector2 = 0;
}
float Polinomio::getcoef2(int grado){
    return coef[grado];
}
void Polinomio::setcoef2(int coeficiente, float grado){
    
    bool encontrado=false;
    
    if (grado==0){
        for(int i = getgrado()-1;(i > 0) && (encontrado==false);i--){
            if(getcoef(i)!=0){
                setgrado(i);
                encontrado=true;                
            }
        }
    }
    else{
        if(coeficiente >= 0){
            //si el max_grado es igual que el grado, hace resize.
            if(max_grado <= coeficiente){
                setgrado(coeficiente);
                resize2();
            }
            if(grado < coeficiente){
            	setgrado(grado);
            }
            //cuando el grado es mayor que el coeficiente.
            if(grado > coeficiente){
            	setgrado(coeficiente);
            }
            coef[coeficiente] = grado;
            
        }
        else{
        cout << " No puede ser negativo el coeficiente" << endl;
    	}
    }
        
}
int Polinomio::getcoef(int grado){
    
    return coef[grado];

}
int Polinomio::getgrado(){
    return grado;
}

void Polinomio::setgrado(int nuevo_grado){
    grado = nuevo_grado;
}
/**
 * @brief metodos que imprime los polinomios
 * @info imprimira hasta el max_grado
 */
void Polinomio::imprimir(){
    cout << " p(x) = ";
    for (int i= getmax_grado(); i >= 0; i--)
        if (coef[i] != 0.0)
            cout << " + (" << coef[i] << ")x^" << i;
    cout << endl;
}

void Polinomio::setmax_grado(int nuevo_maxgrado){
    max_grado = nuevo_maxgrado;
}

int Polinomio::getmax_grado(){
    return max_grado;
}

void Polinomio::setCoeficiente(float nuevo_coeficiente, int grado){
    bool encontrado = false;
    if(grado >= 0){
       // cout << grado << endl;
        if(grado < getgrado()){ // CASO 1 y 2
            coef[grado] = nuevo_coeficiente;
        }
        else if(grado > getgrado() && grado <= getmax_grado()){ //CASO 3
            coef[grado] = nuevo_coeficiente;
            setgrado(grado);
        }
        
        else if(grado > getgrado() && grado > getmax_grado()){ //CASO 4
            
            resize(nuevo_coeficiente, grado);
            // 6: Añadir el nuevo coeficiente y actualizar grado y max_grado
            setgrado(grado);
            setmax_grado(grado);
            coef[grado] = nuevo_coeficiente;
        }
        else if(grado == getgrado() && nuevo_coeficiente == 0){ //CASO 5
            coef[grado] = 0;
            for (int i = grado; i >= 0 && encontrado == false;i--) {
                if (coef[i]!=0) {
                	setgrado(i);
                    setmax_grado(i);
                    encontrado = true;
                    //cout<< "debug"<< grado;
                  	resize(nuevo_coeficiente, grado);
                    
                    coef[grado]=nuevo_coeficiente;
                }
            }
        }
    }
    else{
        cout<<"WARNING: EL GRADO DEL MONOMIO DEBE SER POSITIVO"<<endl;
    }
}
void Polinomio::resize(float nuevo_coeficiente, int grado){
            // 1: Reservo un vector auxiliar de tamaño adecuado de tipo float.
            float *aux = new float[grado+1];
            if (aux == 0){
                cerr << "Error. No hay memoria suficiente. Se abortará la ejecución" << endl;
                exit(-1);
            }
            // 2: Inicializo a 0 todos los coeficientes del vector auxiliar
            for (int i = 0; i < grado+1; i++) {
                aux[i] = 0.0;
            }
            // 3: Copio el contenido del antiguo vector de coeficientes
            for (int i = 0; i <= getmax_grado(); i++){
                    aux[i] = coef[i];
            }
            // 4: Borramos la memoria del vector antiguo
            delete [] coef;
            // 5: Reasigno el puntero del objeto a la direccion de memoria donde se ubica el nuevo vector
            coef = aux;
            aux = 0;
}
/**
 * @brief metodos que suma el los dos polinomios
 * @info modulo que suma los dos polinomios 
 * @pre pasadle los polinomios ya creado
 * @post devolver los polinomios ya sumados
 */
void Polinomio::sumar(Polinomio &p2){
    
    if (getgrado() <= p2.getgrado()){
       	setgrado(p2.getgrado());

    }
    int max_aux;
    max_aux = getmax_grado() + p2.getmax_grado();
    float *aux = new float [max_aux];
    for(int i=0; i < max_aux; i++){
        aux[i] = getcoef(i) + p2.getcoef(i);
    }
    delete [] coef;
    coef = aux;
    aux = 0;
}

void Polinomio::sumarv2(Polinomio &p2, Polinomio &p3){
    int gradomenor;
    
    if(p3.getgrado() > p2.getgrado()){
        gradomenor = p2.getgrado();
    }
    else if(p3.getgrado() < p2.getgrado()) {
        gradomenor = p3.getgrado();

    }

    else if(p3.getgrado() == p2.getgrado()){
        gradomenor = p3.getgrado();
    }

    cout <<"el grado mayor es "<< gradomenor << endl;
    for(int i = 0; i <= gradomenor; i++){
    	setcoef2(i,(p3.getcoef2(i)) + (p2.getcoef2(i)));
    }
}
Polinomio Polinomio::sumav3(Polinomio &p2){
    Polinomio res;
    int gradomenor;
    

    if (this->getgrado() > p2.getgrado()){
        //construcion del objeto a nivel local
        Polinomio res(*this); 
        gradomenor = p2.getgrado();
    }
    else if (this->getgrado() < p2.getgrado()) {
        Polinomio res(p2);
        gradomenor=this->getgrado();
    }

    else if (this->getgrado() == p2.getgrado()){
        // lo construimos por copia
        Polinomio res(p2);
        gradomenor = p2.getgrado();
    }
    for (int i = 0; i <= gradomenor; i++){
        res.setcoef2(i,(this->getcoef(i)) + (p2.getcoef(i)));
         }
    
    cout << "resultado dentro" << endl;
    res.imprimir();
    return res;
}
int main(){
	Polinomio p1(4);
	Polinomio p2(2);
	Polinomio p3;
	//introduzco de forma manual el grado
	p1.setgrado(3);
	p2.setgrado(2);

	cout << "p1 grado " << p1.getgrado() << " max_grado " <<p1.getmax_grado() << endl;
	//introduzco todos los monomios con el setintroducir
	//p1.set_introducir_coef();
	//p2.set_introducir_coef();
	cout << "p2 grado " << p2.getgrado() << " max_grado " <<p2.getmax_grado() << endl;

	cout << " imprimiendo polinomio p1 "  << endl;
	//imprimp el polinomio p1
	p1.imprimir();
	cout << " imprimiendo polinomio p2 " << endl;
	p2.imprimir();



    cout << "El grado del polinomio p1 es: " << p1.getgrado() << endl;
    
    p1.setCoeficiente(2,4);
    p1.setCoeficiente(1,3); // test caso 1:

    cout<<"Test caso 1: "; p1.imprimir();
    cout<<"El grado actual es: "<< p1.getgrado() << endl;
    cout<<"El max_grado actual es: "<< p1.getmax_grado() << endl;
    cout<<"--------------------------------------------"<<endl;
    
    p1.setCoeficiente(5,-2); // test caso 2
    cout<<"Test caso 2: "; p1.imprimir();

    //cout<<"--------------------------------------------"<<endl;
    p1.setCoeficiente(1,7); // test caso 3
    //cout<<"Test caso 3: "; p1.imprimir();
  
    p1.setCoeficiente(8,14); // test caso 4
    //cout<<"--------------------------------------------"<<endl;
    //cout<<"Test caso 4: "; p1.imprimir();
    p1.setCoeficiente(0,14); // test caso 5
    
    //cout<<"--------------------------------------------"<<endl;
    cout<<"Test caso 5: "; p1.imprimir();

    cout <<"--------------sumav1-----------------------"<<endl;
    cout <<" caso1 " << endl;
    //sumo el polinomio p1 con el p2
	p2.setCoeficiente(2,5);
	p2.setCoeficiente(1,4);
	p2.setCoeficiente(5,2);
	p2.sumar(p1);
	p1.imprimir();

    cout <<"--------------sumav2-----------------------"<<endl;
    cout <<" caso2 " << endl;
    //sumo p1 y p2 y lo guardo en p3
    p3.sumarv2(p1, p2);
    p3.imprimir();
    cout << " ----------------sumav3---------------------" <<endl;
    cout << " caso 3 " << endl;
   
    Polinomio res = p1.sumav3(p2); 
    cout << " resultado fuera " << endl;
    res.imprimir();

}
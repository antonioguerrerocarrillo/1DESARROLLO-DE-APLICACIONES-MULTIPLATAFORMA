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
		float getcoef2(int grado);
		void setcoef2(int coeficiente, float grado);
		void resize2();
		void sumar(Polinomio &p2);
		void setCoeficiente(float nuevo_coeficiente, int grado);
		void sumarv2(Polinomio &p2, Polinomio &p3);
		Polinomio sumav3(Polinomio &p2);
        Polinomio* sumarv4(Polinomio *p2);
        Polinomio& operator=(Polinomio &pol);
        Polinomio operator+(Polinomio &p2);

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
Polinomio& Polinomio::operator=(Polinomio &pol){
    if(&pol != this){
        delete this -> coef;
        this -> max_grado = pol.max_grado;
        this -> grado = pol.grado;
        this -> coef = new float[this ->max_grado+1];
        for (int i = 0; i < max_grado;i++){
            this -> coef[i] = pol.coef[i];
        }
    }
    return *this;
}
Polinomio Polinomio::operator+(Polinomio &p2){
    Polinomio res;
    int gradomenor;
    //cout << " debug entrando en sumar v3" << endl;

    if (this -> getgrado() >= p2.getgrado()){
        cout << " debug entrando en v4 if" << endl;
        Polinomio aux(*this); //construcion del objeto a nivel local
        gradomenor = p2.getgrado();

        for (int i = 0; i <= gradomenor; i++){
            //cout << " debug entrando en sumar v3 entrando en el for" << endl;
            aux.setCoeficiente(i,(this->getcoef(i)) + (p2.getcoef(i)));
        }
         res = aux;
    }
    else{
        cout << " debug entrando en sumar v4 else if" << endl;
        //res=p2; //invoco al constructor por copia
        Polinomio aux(p2);
        gradomenor = this-> getgrado();
        for (int i = 0; i <= gradomenor; i++){
            //cout << " debug entrando en sumar v3 entrando en el for" << endl;
            aux.setCoeficiente(i,(this->getcoef(i)) + (p2.getcoef(i)));
        }
        res = aux;
    }

    return res;
}
ostream& operator<<(ostream &flujo, Polinomio &p){
    flujo << p.getcoef(p.getgrado());
    if(p.getgrado() > 0){
        flujo << " x " << p.getgrado();
    }
    for(int i = p.getgrado()-1; i >= 0;i--){
        if(p.getcoef(i) != 0){
            flujo << " - " << p.getcoef(i);
            if( i > 0)
                cout << " x~ " << i;
        }
    }
    flujo << endl;

    return flujo;
}
istream& operator>>(std::istream &flujo, Polinomio &p){
    int g;
    float v;
    do{
        flujo >> v >> g;
        if(g >= 0)
            p.setCoeficiente(g,v);
    }while(g >= 0);
    
    return flujo;
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
    //cout << " debug entrando en sumar v3" << endl;

    if (this -> getgrado() >= p2.getgrado()){
        Polinomio aux(*this); //construcion del objeto a nivel local
        gradomenor = p2.getgrado();

        for (int i = 0; i <= gradomenor; i++){
            //cout << " debug entrando en sumar v3 entrando en el for" << endl;
            aux.setCoeficiente(i,(this->getcoef(i)) + (p2.getcoef(i)));
        }
         res = aux;
    }
    else{
        //res=p2; //invoco al constructor por copia
        Polinomio aux(p2);
        gradomenor = this-> getgrado();
        for (int i = 0; i <= gradomenor; i++){
            //cout << " debug entrando en sumar v3 entrando en el for" << endl;
            aux.setCoeficiente(i,(this->getcoef(i)) + (p2.getcoef(i)));
        }
        res = aux;
    }

    return res;
}

Polinomio* Polinomio::sumarv4(Polinomio *p2){
    Polinomio *res;
    int gradomenor;
    cout << " debug entrando en sumar v4" << endl;
  
    if (this -> getgrado() >= p2->getgrado()){
        Polinomio *aux;
        aux = this; //construcion del objeto a nivel local
        gradomenor = p2->getgrado();

        for (int i = 0; i <= gradomenor; i++){
            //cout << " debug entrando en sumar v3 entrando en el for" << endl;
            aux->setCoeficiente(i,(this->getcoef(i)) + (p2->getcoef(i)));
        }
        cout << " reveinta aqui " << endl;
        res = aux;
    }
    else{
        //res=p2; //invoco al constructor por copia
        Polinomio *aux;
        aux = p2;
        gradomenor = this-> getgrado();
        for (int i = 0; i <= gradomenor; i++){
            //cout << " debug entrando en sumar v3 entrando en el for" << endl;
            aux->setCoeficiente(i,(this->getcoef(i)) + (p2->getcoef(i)));
        }
        cout << " revienta aqui " << endl;
        res = aux;
    }

    cout << "-------------resultado dentro-------------" << endl;
    cout << *res << endl;


    return res; //devuelve una copia de res
}
class Vista{
    private: 
        int dimension_Vector = 5;
        Polinomio *v_polinomios = new Polinomio[dimension_Vector];
        int dim;
        int util;
    
    public:
        Vista();
        Vista ( Vista &vista2);
        ~Vista();
        friend ostream& operator<< (ostream &flujo, Vista &v);
        void menu();
        void crear_polinomio ();
        void eliminar_polinomio ();

};

Vista::Vista () {
    this->util = 0;

    for (int i = 0; i < dimension_Vector; i++) {
       //this->v_polinomios[i]= Polinomio(0);
    }
}

Vista::Vista ( Vista &vista) {

    this->util = vista.util;
    
    for (int i=0; i < vista.dim; i++) {
        this->v_polinomios[i] = vista.v_polinomios[i];
    }
}

Vista::~Vista () {
    cout << "DEBUG: Entra en el destructor " << endl;
    if (v_polinomios != 0){
        cout << RED_COLOR << "debug: Destruyendo polinomio..." << RESTORE_DEFAULT_COLOR << "\t" << endl;
        for (int i = 0; i <= dimension_Vector; i++)
           // v_polinomios[i] = 0;
        delete [] v_polinomios;
    }
}

ostream& operator<< (ostream &flujo, Vista &v) {
    for(int i = 0; i< v.util; i++) {
        flujo << 1 << v.v_polinomios[i] << endl;
    }
}

void Vista::menu() {
    cout << " DEBUG entra en menu  " << endl;
    int menu = 0;

    do{
        cout  << " Pulsa [1] para crear o Pulsa [2] para eliminar" << endl;
        cin >> menu;
    }while ((menu != 1) && (menu != 2));

    if (menu == 1) {
        crear_polinomio();
    } else {
        eliminar_polinomio();
    }
}


void Vista::crear_polinomio () {
    cout  << "DEBUG  entra en crear polinomio" << endl;
    
    Polinomio v1;
    cin >> v1;

    this->v_polinomios[util] = v1;
    this->util = this->util+1;
}

void Vista::eliminar_polinomio () {
    cout << " DEBUG entra en eliminar polinomio " << endl;
    
    int pos;
    Polinomio aux;

    cout << this << endl;

    do {
        cout <<  " pon [0], en qué posicion esta el polinomio que quieres borrar" << endl;
        cin >> pos;
    } while ((pos < 0) && (pos > this->util));

    if (pos != this->util) {
        aux = this->v_polinomios[util];
        this->v_polinomios[util] = this->v_polinomios[pos];
        this->v_polinomios[pos] = aux;
    }

    this->util= this->util-1;
}

int main(){
    Vista v1;

    v1.menu();
    cout << v1;

}
//
//  juego del bingo
//  
//
//  Created by Antonio Guerrero y Pedro Infantes 02/02/2018
//
//
#include <iostream>
#define BLACK_COLOR "\033[1;30m"
#define RED_COLOR "\033[1;31m"
#define GREEN_COLOR "\033[1;32m"
#define YELLOW_COLOR "\033[1;33m"
#define BLUE_COLOR "\033[1;34m"
#define PURPLE_COLOR "\033[1;35m"
#define CYAN_COLOR "\033[1;36m"
#define WHITE_COLOR "\033[1;39m"

#define RESTORE_DEFAULT_COLOR "\033[0m"

#include <iostream>
#include <iomanip>
#include <stdio.h>
#include<time.h>
//libreria de los numeros aleatorios srand
#include<stdlib.h>
#include <cstdlib>
using namespace std;

const int DIM_FIL_CARTON = 5; // utiles de la fila del carton
const int DIM_COL_CARTON = 11; //utiles de la columna del carton
/**
 * @brief Módulo que vamos a realizar la comprobacion de linea y posteriorermente bingo.
 * @param matriz llamada carton y [columna del carton] que ya hemos creado en el main
 * @param util_col para saber las columnas que necesitamos maximas.
 * @param util_fil las filas del carton contando con las partes de decoracion
 * @post realizar todo para pasarlo ya con bingo cantado y linea.
 * @vers 2.0
 */
void sacarbola(unsigned char carton[][DIM_COL_CARTON],int util_col, int util_fil){
    int bola=0;
    int c=0;
    srand(time(NULL));
    bool bingo=false;
    bool linea = true;
    
       for (int f = 1; f < 90 || bingo == true; f++){ 
            for(int c =0;c == bingo || bingo == true;c++){
                bola=1+rand()%(100-1);
                cout<<"La bola numero : "<< f << " es la :"<< bola <<endl;
                if(bola==carton[1][c] || bola==carton[2][c] || bola==carton[3][c]){
                    cout<<"Has cantado linea "<<endl;
                    linea == true;
                }
                if(bola==carton[f][1] || bola==carton[f][2] || bola==carton[f][3]){
                    cout<<"Te has marcado un bingo "<<endl;
                    bingo==true;
                }
            }
        }
}
/**
 * @brief Módulo que vamor a ordenar de menor a mayor la matriz. 
 * @param pasamos el vector[] 
 * @param util_col para saber las columnas que necesitamos maximas.
 * @vers 1.0
 */
int ordenacionvector(int vector[],int util_col){
    int menor=0;
    int aux=0;
    for(int i =0;i<util_col-1;i++){
        for(int j=0;i<util_col-1;j++){
            if(vector[j]<vector[i]){
                menor=j;
                aux=vector[i];
                vector[i]=vector[menor];
                vector[menor]=aux;
                
            }
        }   
    }
}

int Posminimo(const int Vector[],int izq,int dcha){
    
    double minimo=Vector[izq];
    int posicion_minimo=izq;
    for(int i=izq+1;i<=dcha;i++){
        if(Vector[i]<minimo){
            minimo=Vector[i];
            posicion_minimo=i;
        }
        
    }
    return posicion_minimo;
}
/**
 * @brief Módulo este modulo va agenerar el carton haciendo los numeros aleatorios entre el 1 a 99, 
 * @param matriz llamada carton y [columna del carton] que ya hemos creado en el main
 * @param util_col para saber las columnas que necesitamos maximas.
 * @param util_fil las filas del carton contando con las partes de decoracion
 * @param en este modulo tambien vamos a ordenar los numeros y para ello vamos a usar un do while. para que lo use en el bucle de
 * de las filas,
 * @param ordenar los numeros de menor a mayor por filas. con un numero min(minimo), med(media) y max (maximo)  
 * @post realizar todo para pasarlo a la funcion de mostrar ya listo.
 * @vers 2.0
 */
void generar3bool (bool vectora[], bool num1){
   int contadora=0;

    if (num1 == true){
         do {
            contadora = 0;
            for (int i=0; i < 3; i++){
                vectora[i]= rand () % 2;
                if (vectora[i]==1){
                    contadora++;
                } 
            }
        } while (contadora != 1) ;
    }
    else {
        do {
            contadora = 0;
            for (int i=0; i < 3; i++){
                vectora[i]= rand () % 2;
                if (vectora[i]==1){
                    contadora++;
                } 
            }
        }  while (contadora != 2) ;
    }
   
}
void generar9bool (bool vector []){
    int contadora = 0;


    do {
        contadora = 0;
        for (int i=0; i < 9; i++){
            vector[i]= rand () % 2;
            if (vector[i]==1){
                contadora++;

            } 
        }    cout << contadora << endl;

    } while (contadora != 6);
}
void ordenarfilacarton(char carton[][DIM_COL_CARTON], int util_col, int util_fil ){
    
    //srand sirve para que genere numeros aleatorios y el 100 en base a srand te selecciona unos numeros predeterminados;
    srand(time(NULL));
    int num=1;
    int DIM = 90;
    int vector [DIM]; //vector local.
    int util_vector = util_fil; // util del vector local
    //Lo hacemos a la inversa para poder imprimir el vector ordenado
    for (int c = 0; c < DIM_COL_CARTON; c++){ //bucle de la fila 
    int min = 90;
    int max = 1;
    int med=0;
    do{
        for (int f = 0; f < DIM_FIL_CARTON; f++){ //bucle de la columna.
            //num = 1 + rand() % (100 - 1);
            //carton[f][c] = num;
            num=1+rand()%10+10*(c-1);
            if(min > num){
                min = num;
            }
            else if(max < num){
                max = num;
                   
            }else
                {
                 med=num;
                }
            }
            carton[1][c] = min; // la posicion 1 de la matriz y el numero mas pequeño
            carton[2][c] = med; // la posicion 2 de la matriz donde estara la mitad
            carton[3][c] = max; // la posicion 3 de la matriz donde pondremos el numero max

        }while(min==med || med==max);
    }
}
void rellenarmarco_izqyder (char carton[][DIM_COL_CARTON] ) {
    //1 º) Rellenamos el marco superior
    for (int c=0; c < DIM_COL_CARTON; c++){
        carton[0][c] = '=';
    
    //2 º) Rellenamos marco izquierdo
int s = 0;
    for (int f=1; f < DIM_FIL_CARTON; f++){
        carton[f][0] = '|'; // el sÃ­mbolo grÃ¡fico de las dos barras
        if(s==0){
            carton[f][1] = 'x';
            s++;
            }on[1][9] = 'x';
        } 
}
void rellenarmarco(char carton[][DIM_COL_CARTON], int util_col,int util_fil) {
    //3 º) Rellenamos marco derecho
    for (int f=1; f < DIM_FIL_CARTON; f++)
        carton[f][util_col+1] = '|'; // el sÃ­mbolo grÃ¡fico de las dos barras
    
    //4 º) Rellenamos marco inferior
    for (int c=0; c < DIM_COL_CARTON; c++)
        carton[util_fil+1][c] = '=';
    // Rellenamos los huecos de forma aleatoria

}
void generar9_bool (char carton[][DIM_COL_CARTON],  int util_col,int util_fil) {
    bool vectora[9]; //que genera la x aleatoria en el bingo.
    int contadora = 0;
    bool vectorb[3];
    int contadorb = 0;
    generar9bool(vectora);    
    for (int c=1; c < DIM_COL_CARTON -1; c++){
        generar3bool(vectorb, vectora[contadora]);

        for (int f =1; f < DIM_FIL_CARTON -1; f++){
            if (vectorb[contadorb] == 0) {
                carton[f][c]= '+';
                contadorb ++;
            }

        }

        contadorb = 0;
        contadora ++;
    }
}
    //5 º) Tocamos las esquinas para ponerlas bonitas
        
    //6 º) Rellenamos los nÃºmeros
    // AquÃ­ tendrÃ­an que llamar a mÃ³dulos para ir generando las columnas de nÃºmeros
    // En total 15 nÃºmeros en el cartÃ³n
    // No pueden existir columnas sin nÃºmero y la columna tiene que tener como mÃ¡ximo un nÃºmero.
    // Cada columna genera nÃºmeros aleatorios entre su rango
/**
 * @brief modulo para mostrar por pantalla. tambien rellenamos el carton, pondremos bonito, y le pondremos las x dentro de el.
 * @param matriz llamada carton y [columna del carton] que ya hemos creado en el main, la pasamos como constante.
 * @post mostrar el carton por patanlla ya creado.
 */
 
void imprimirCarton( char carton[][DIM_COL_CARTON]){
    for (int f = 0; f < DIM_FIL_CARTON; f++){
        for (int c = 0; c < DIM_COL_CARTON; c++){

        if(c==0 || f==0|| c==DIM_COL_CARTON-1|| f==DIM_FIL_CARTON-1)
            cout << GREEN_COLOR << carton[f][c] << RESTORE_DEFAULT_COLOR<<"\t";
        else      
            //El caracter char lo convertimos en numeros con el int para que nos de el número     
            if(carton[f][c] == 'x'){
                cout << GREEN_COLOR << carton[f][c] << RESTORE_DEFAULT_COLOR<< "\t";
            } else {
                cout << GREEN_COLOR << (int)carton[f][c] << RESTORE_DEFAULT_COLOR<< "\t";
            }       
            //cout << GREEN_COLOR << (int)carton[f][c] << RESTORE_DEFAULT_COLOR<< "\t";
        // para devolverlo en tipo int
        }
        cout << endl;
    }
}

void imprimirBien (const char carton[][DIM_COL_CARTON]) {
    for (int f = 0; f < DIM_FIL_CARTON; f++)
    {
        for (int c = 0; c < DIM_COL_CARTON; c++)
        {
            cout << carton [f] [c];
        }
        cout << endl;
    }
}
     /**
@brief hacemos los menus aqui mostraremos al usuario a que programa queremos ir pulsando la tecla correspondiente
@param para el menu usamos el switch
@pre no tenemos que usar
@return  no tiene return.
@post introduce [i] para imprimirCarton el carton, [j] para jugar solo, [v] para jugar 2 personas: y [s] para salir
    **/
void meterX(char carton [DIM_FIL_CARTON][DIM_COL_CARTON],int util_col, int util_fil)
{
     for (int c = 0; c < DIM_COL_CARTON; c++){ //bucle de la fila 
   
        if(c%2==0)
        {

        }else
        {
            
        }
    }
}
char menu_en_pantalla(char carton [DIM_FIL_CARTON][DIM_COL_CARTON],int util_col, int util_fil) {
        char menu ;    
        
        do{ //filtro
        cout << " introduce [i] para imprimirCarton el carton, [j] para jugar solo, [v] para jugar 2 personas: y [s] para salir" << endl;
        cin >> menu;
        }
        while(menu!='i' && menu!= 'j'&& menu !='v' && menu !='s'); 
         
          switch (menu) {
            case 'i':
          
             //algoritmoSeleccion(int Vector[],int util)
             //imprimirBien(carton);
            //sacarbola(carton,util_col, util_fil);
             //generar9_bool (carton,util_fil, util_col);
             rellenarmarco(carton, util_fil, util_col);
             rellenarmarco_izqyder (carton);
             ordenarfilacarton(carton, util_fil, util_col);
             imprimirCarton(carton);
             meterX(carton);
            break;
            case 'a': 
             //invocacion de la variable para que lo coja y el sepa donde se tiene que ir al pulsar           
            break;
            case 'n':               
            break;
            case 's':
            break;
                
        }
    
    }

int main(){
    const int TOTAL_NUMEROS_CARTON = 15;
    char carton [DIM_FIL_CARTON][DIM_COL_CARTON];
    
    int util_col = 9;
    int util_fil = 3;
    
    menu_en_pantalla (carton, util_col, util_fil);
    //generarCarton(carton, util_col, util_fil);
    //algoritmoSeleccion(int Vector[],int util)
    //imprimirCarton(carton);
        
}


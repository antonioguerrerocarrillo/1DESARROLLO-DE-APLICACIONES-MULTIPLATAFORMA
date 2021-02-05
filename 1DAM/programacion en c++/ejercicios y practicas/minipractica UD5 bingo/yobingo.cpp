
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
const int DIM_bola=100;
int generarbola(int vector_bola[], int util_bola){
    srand(time(NULL));
    int bola= rand()%90;
    bool encontrado=false;    
   
    for(int i = 0; i < util_bola ; i++ ){
         if(vector_bola[i]==bola)
         {
            encontrado=true;
         }        
     }
     if(encontrado==true)
     {
        return bola;
        vector_bola[util_bola]=bola;
        util_bola++;
     }

}
/**
 * @brief Módulo que vamos a realizar la comprobacion de line
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

void generarCarton(char carton[][DIM_COL_CARTON], int util_col, int util_fil ){
    
    //srand sirve para que genere numeros aleatorios y el 100 en base a srand te selecciona unos numeros predeterminados;
    srand(time(NULL));
    
    int DIM = 100;
    int vector [DIM]; //vector local.
    int util_vector = util_fil; // util del vector local
    //Lo hacemos a la inversa para poder imprimir el vector ordenado
    for (int c = 1; c < DIM_COL_CARTON; c++){ //bucle de la fila 
        int min = 100;
        int max = 0;
        int med=0;
         do{
                for (int f = 1; f < DIM_FIL_CARTON; f++){ //bucle de la columna.
                  
                 //num = 1 + rand() % (100 - 1);
                    //carton[f][c] = num;
                    int num=rand()%10+10*(c-1);
                    if(num <= min){
                        if(min!=90){
                               med=min; 
                        }
                        min= num;
                    }
                    if(num >=max){
                        if(max!=0){
                            med=max;
                        }
                     max=num;  
                    }
            }
                carton[1][c] = min; // la posicion 1 de la matriz y el numero mas pequeño
                carton[2][c] = med; // la posicion 2 de la matriz donde estara la mitad
                carton[3][c] = max; // la posicion 3 de la matriz donde pondremos el numero max
        }while(min==med || med==max || min==max);
    }
}
/**
 * @brief Módulo que vamos a usar para rellenar el carton poniendole la de coracion pertinente y necesaria.
 * @param matriz llamada carton y [columna del carton] que ya hemos creado en el main
 * @param util_col para saber las columnas que necesitamos maximas.
 * @param util_fil las filas del carton contando con las partes de decoracion
 * @param rrellenar la parte izquierda del vector, superior, inferior y derecha.
 * @post despues lo pasaremos a imprimircarton
 * @vers 2.0
 */
void rellenarcarton (char carton[][DIM_COL_CARTON], int util_col, int util_fil) {
    //1 º) Rellenamos el marco superior
    for (int c=0; c < DIM_COL_CARTON; c++)
        carton[0][c] = '=';
    
    //2 º) Rellenamos marco izquierdo
    int s = 0;
    for (int f=1; f < DIM_FIL_CARTON; f++){
        carton[f][0] = '|'; // el sÃ­mbolo grÃ¡fico de las dos barras
        if(s==0){
            carton[f][1] = 'x';
            s++;
        }
        //else if(s == 1 && f == 3){
        //} 
    }
    
    //3 º) Rellenamos marco derecho
    for (int f=1; f < DIM_FIL_CARTON; f++)
        carton[f][util_col+1] = '|'; // el sÃ­mbolo grÃ¡fico de las dos barras
    
    //4 º) Rellenamos marco inferior
    for (int c=0; c < DIM_COL_CARTON; c++)
        carton[util_fil+1][c] = '=';
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
 
void imprimirCarton(const char carton[][DIM_COL_CARTON]){
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
/**
 * @brief modulo que imprime la bola tachar el numero y cambiar la matriz el numero y cambiar por un $
 * @param le pasamos la bola .
 * @post mostrar el carton por patanlla ya creado.
 */
void imprimirCartonbola(const char carton[][DIM_COL_CARTON]){
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
/**
 * @brief modulo que vamos a meter las x dentro del carton
 * @param matriz llamada carton y [columna del carton] que ya hemos creado en el main, la pasamos como constante.
 * @post mostrar el carton ya con las x incluidas.
 */
void meterX(char carton [DIM_FIL_CARTON][DIM_COL_CARTON],int util_col, int util_fil){
     for (int c = 0; c < DIM_COL_CARTON; c++){ //bucle de la fila 
   
        if(c%2==0)
        {

        }else
        {
            
        }
    }
}
     /**
@brief hacemos los menus aqui mostraremos al usuario a que programa queremos ir pulsando la tecla correspondiente
@param para el menu usamos el switch
@pre no tenemos que usar
@return  no tiene return.
@post introduce [i] para imprimirCarton el carton, [j] para jugar solo, [v] para jugar 2 personas: y [s] para salir
    **/
char menu_en_pantalla (char carton [DIM_FIL_CARTON][DIM_COL_CARTON],int util_col, int util_fil, int vector_bola[], int util_bola) {
        char menu ;    
        
        do{ //filtro
        cout << " introduce [i] para imprimirCarton el carton, [j] para jugar solo, [v] para jugar 2 personas: y [s] para salir" << endl;
        cin >> menu;
        }
        while(menu!='i' && menu!= 'j'&& menu !='v' && menu !='s'); 
         
          switch (menu) {
            case 'i':
            generarCarton(carton, util_col, util_fil);
            rellenarcarton ( carton, util_col, util_fil);
            imprimirCarton(carton);
            meterX(carton,util_col,util_fil);
            generarbola(vector_bola, util_bola);
            imprimirCarton(carton);
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

    int vector_bola[DIM_bola];
    int util_bola = 0;
    
    int util_col = 9;
    int util_fil = 3;
    
    menu_en_pantalla (carton, util_col, util_fil, vector_bola, util_bola);
    //generarCarton(carton, util_col, util_fil);
    //algoritmoSeleccion(int Vector[],int util)
    //imprimirCarton(carton);
        
}


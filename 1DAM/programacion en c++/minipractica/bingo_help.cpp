

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
#include <cstdlib>
using namespace std;

const int DIM_FIL_CARTON = 5;
const int DIM_COL_CARTON = 11;

void generarCarton(unsigned char carton[][DIM_COL_CARTON], int util_col, int util_fil ){
    
    //0) Inicializamos el cartón
   /* for (int f = 0; f < DIM_FIL_CARTON; f++)
        for (int c = 0; c < DIM_COL_CARTON; c++)
            carton[f][c] = '-';
  */
    //1º) Rellenamos el marco superior
    for (int c=0; c < DIM_COL_CARTON; c++)
        carton[0][c] = '=';
    
    //2º) Rellenamos marco izquierdo
    for (int f=1; f < DIM_FIL_CARTON; f++)
        carton[f][0] = '|'; // el símbolo gráfico de las dos barras
    
    //3º) Rellenamos marco derecho
    for (int f=1; f < DIM_FIL_CARTON; f++)
        carton[f][util_col+1] = '|'; // el símbolo gráfico de las dos barras
    
    //4º) Rellenamos marco inferior
    for (int c=0; c < DIM_COL_CARTON; c++)
        carton[util_fil+1][c] = '=';
    
    //5º) Tocamos las esquinas para ponerlas bonitas
        
    //6º) Rellenamos los números
    // Aquí tendrían que llamar a módulos para ir generando las columnas de números
    // En total 15 números en el cartón
    // No pueden existir columnas sin número y la columna tiene que tener como máximo un número.
    // Cada columna genera números aleatorios entre su rango
    
}

void imprimirCarton(const unsigned char carton[][DIM_COL_CARTON]){
    for (int f = 0; f < DIM_FIL_CARTON; f++){
        for (int c = 0; c < DIM_COL_CARTON; c++){
            cout << GREEN_COLOR << carton[f][c] << RESTORE_DEFAULT_COLOR;
        }
        cout << endl;
    }
}

void imprimirChar(){
   cout << "Hello, ф or \u0444!\n";

}

int main(){
    const int TOTAL_NUMEROS_CARTON = 15;
    unsigned char carton [DIM_FIL_CARTON][DIM_COL_CARTON] = {{' ','1','2','3','4','5','6','7',' '}, {' ', 4','5','6','4','5','6','8',' '}, {' ', '4','5','6','7','9','8','5',' '}};
    int util_col = 9;
    int util_fil = 5;
    
    generarCarton(carton, util_col, util_fil);
    imprimirCarton(carton);
    
    imprimirChar();
    
}

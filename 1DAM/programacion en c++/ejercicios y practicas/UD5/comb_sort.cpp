#include <bits/stdc++.h> 
#include <iostream>
#include <cmath>
using namespace std;
int cuenta (int a){ 

    a = (a * 10) / 13; 
  
    if (a < 1){
        return 1; 
    }

    return a; 
} 
void intercambio (int &x, int &y){
    //intercambio de los valores usando un aux(una variable auxiliar)
    int aux = x;
    x = y;
    y = aux;
}
void comb_sort(int v[], int util) { 
    int numero = util; 
    bool entra = true; 
    //para que este repitiendose hasta que entra sea true
    while(numero != 1 || entra == true){ 
        //hago la cuenta y lo guardo en numero llamando a la funcion
        numero = cuenta(numero); 
        entra = false; 
        // Comparo todos los numeros de ordenacion y paro cuando sea la util - numero para que no haga bucle infinito
        for (int i = 0; i < util - numero; i++) { 
            if (v[i] > v[i + numero]){
                //llamo a la funcion e intercambio los valores para porder ordenar los numeros. 
                intercambio(v[i], v[i + numero]); 
                entra = true; 
            } 
        } 
    } 
} 

void imprimir(int util, int v[]){
    cout << " lo que hay dentro de las celdas del vector es ";

    for (int i = 0; i < util; i++){
        cout << v[i] << ", ";
    }
    cout << " " << endl;
}
int main() { 
    const int dim = 100;
    int vector[dim] = { 8, 4, 1, 56, 3, -44, 23, -6, 28, 0 }; 
    int util = 10; 
  
    cout << " imprimiendo el vector desordenado " << endl;
    imprimir(util, vector);

    comb_sort(vector, util); 
  
    cout << " imprimiendo el vector ordenado " << endl;
    imprimir(util, vector);
} 


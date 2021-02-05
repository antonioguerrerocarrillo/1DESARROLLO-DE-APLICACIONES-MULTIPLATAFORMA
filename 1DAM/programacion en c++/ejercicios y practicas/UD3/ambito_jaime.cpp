/*
 * File:   ambito.cpp
 * Author: neozizou
 *
 * Created on 24 de noviembre de 2011, 8:28
 */
#include <iostream>
#include <cstdlib>

using namespace std;

double f1 (double x, double y){
    double i=1000, j;
    double z=3;
    
    for (double i=x; i<y; i++){
        double z;
        cout << "El resultado de z dentro del for antes de hacer algo con ella es: " << z << endl;
        z=(i-x);
        j=z/(y-x);
        cout << "El resultado de j dentro del for es " << j << endl;
        cout << "El resultado de z dentro del for es " << z << endl;
        cout << "El resultado de la i dentro del for es " << i << endl;
    }
    cout << "El resultado de j es " << j << endl; // es el mismo del bucle porque está declarado para el ámbito de la función y no lo he redeclarado dentro del bucle
    cout << "El resultado de i es " << i << endl; //el resultado de i es el de la primera declarada, la i del bucle for es otra variable distinta
    cout << "El resultado de z es " << z << endl; //La variable z se crea en el for (par√°metro local) y cuando termina la funci√≥n la variable z se elimina.
    return z;
}


int main(int argc, char** argv) {
    double resultado;
    
    resultado = f1(2,3);
    cout << "El resultado de z (almacenado ahora en otra variable que es local en el main), fuera de la función (y gracias a la comunicación entre funciones) es: " << resultado << endl;
    
    return 0;
}
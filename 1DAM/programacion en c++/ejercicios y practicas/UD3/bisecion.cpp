#include <iostream>
#include <cmath>
#include <sstream>
using namespace std;
/**
 * @brief funcion que le pedira los datos al usuario
 * @info funcion que le pide al usuario
 * @param p va a ser el numero para hacer la sumatoria lo pasamos por parametros ya que es de salida
 * @pre la variable tiene que venir declarada.
 * @post mandar el valor ya cambiado para luego poder usuarlo
 */
void pedir(double &p){

	cout << " escribe la precision deseada " << endl;
	cin >> p;
}
/**
 * @brief funcion que se va a repetir para poder realizar la precision deseada
 * @info esta funciona va a cambiar los valores y hara una multiplicacion al cubo del centro
 * @param le pasamos; der, precision, izq y centro por referencia ya que le vamos a cambiar los valores
 * @pre pasarle los valores ya que der (parte derecha) valdra por defecto 1 
 * @post devolvemos los valores ya ordenados de izquierda a centro y despues derecha
 */
void bucle(double &der, double &precision, double &izq, double &centro){
	while(der - izq > precision){
		centro = (der + izq) / 2;
		if (centro * centro * centro * centro-1 < 0)
			izq = centro;
		else 
			der = centro;
	}
	//cout << " solucion " << (der + izq) / 2 << endl;
}
/**
 * @brief funcion que imprime la solucion de la biseccion
 * @info el resultado es dividir der + izq / 2 
 * @param der y izq sera por copia
 * @pre le pasamos ya todo resulto para mostrar el resultado 
 * @post ni de volvemos nada
 */
void imprimir_res (double der, double izq){
	cout << " solucion " << (der + izq) / 2 << endl;
}

int main(){
	double precision = 0.0;
	double izq = 0.0, der = 1, centro = 0.0;

	pedir(precision);
	bucle(der, precision, izq, centro);
	imprimir_res(der,izq);
}
#include <iostream>
#include <cmath>
using namespace std;
/**
 * @brief modulo que va realizar la sumatoria de un numero
 * @info este modulo realiazara la sumatoria de ese numero realizando un bucle hasta que sea <= numero
 * @param sumatoria, que sera las veces que entra en el bucle
 * @param res = 1 para poder hacer la operacion
 * @pre le pasamos por copia el numero
 * @post ndevolvemos el resultado total de la sumatoria que sera res
 */
int sumatoria(int numero){
	int i = 0, sumatoria = 0;
	double res = 1;

	for ( i = 1; i <= numero; i++){
		res *= i;
		sumatoria++;
	
		cout << numero << " = " << res << endl;
	}
	return res;
}
/**
 * @brief funcion que le pedira los datos al usuario y despues mostrara el resultado
 * @info funcion que le pide al usuario el numero y imprime el resultado de la sumatoria
 * @param numero va a ser el numero para hacer la sumatoria
 * @pre no le pasamos nada
 * @post ni de volvemos nada
 */
void imprime(){
	int numero = 0;

	cout << " introduce un numero " << endl;
	cin >> numero;

	cout << " la sumatoria total es " << sumatoria(numero) << endl;
}
int main () {
	imprime();

}
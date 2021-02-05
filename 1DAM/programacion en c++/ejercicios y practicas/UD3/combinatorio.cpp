#include <iostream>
#include <cmath>
using namespace std;
/**
 * @brief funcion que calcula el facorial
 * @pre le pasamos numero por copia ya que no lo vamos a modificar
 * @param res valdra 1 para poder multiplicarla por numero y por i.
 * @return devolvemos el resultado de la sumatoria llamada res
 */
int factorial (int numero) {
	int res = 1;

	for (int i = 1; i <= numero; i++){
		res = numero * i;
		//cout << numero << " = " << res << endl;
	}
	return res;
}
/**
 * @brief funcion que combina el factorial llamada combinatorio
 * @info llamamos a la funcion para hacer la division y multiplicacion
 * @pre le pasams numero1 y numero2 por copia ya que no lo vamos a modificar
 * @param resultado que guardaremos el total de todas las operaciones.
 * @return devolvemos el resultado del combinatorio com resultado
 */
int combinatorio(int numero1,int numero2){
	int resultado = 0;
	
	resultado = factorial(numero1) / (factorial(numero2) * factorial(numero1 - numero2));

	return resultado;
}
/**
 * @brief funcion que le imprime el resultado de factorial (n)
 */
void imprime_factorial(int n){
	cout << " el factorial de " << n << " es " << factorial(n) << endl;
}
int main (){
	int numero = 0;
	
	cout << " introduce un numero para sacar el factorial y combinatorio " << endl;
	cin >> numero;

	imprime_factorial(numero);

	cout << " el combinatorio es " << combinatorio(numero, 2) << endl;
}
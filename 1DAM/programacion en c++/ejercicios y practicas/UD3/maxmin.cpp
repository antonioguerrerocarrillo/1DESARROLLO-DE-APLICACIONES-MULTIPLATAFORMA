#include <iostream>
#include <cmath>

using namespace std;
/**
 * @brief funcion que le pedira los datos al usuario	
 * @info la pasamos por referencia ya que vamos a cambiar siempre que no sea 0 lo vamos a volver a pedir
 * @pre le pasamos n lo hacemos por referencia ya que vamos a cambiar el valor de estas 
 * @post al pulsar la tecla cambiaremos el valor del numero introducido entero
 */
int leernumero (int &n) {

	cout << " introduce un numero hasta que sea distinto de 0 " << endl;
	cin >> n;

}
/**
 * @brief funcion que igualara el numero a maximo y a minimo para comparar cuando vayamos introduciendo numeros
 * @info la pasamos por referencia los 3 numeros
 * @pre que sea un numero entero.
 * @param maximo lo vamos a igualar al numero
 * @param minimo lo vamos a igualar
 * @param vamos a realizar un bucle repitiendo mientras que no sea cero y vamos a ir comparando y guardando el numero mayor y menor
 * @post devolveremos el numero mayor y menor ya guardado en la variable.
 */
void maxmin(int &numero,int &minimo, int &maximo){
	
	maximo = numero;
	minimo = numero;

	while (numero != 0){
		
		if(numero > minimo){
			minimo = numero;
		}
		if(numero < maximo){
			maximo = numero;
		}
		cout << " introduce un numero hasta que sea distinto de 0 " << endl;
		cin >> numero;
	}

}
/**
 * @brief funcion que le imprime el resultado de minimo y maximo
 */
void mostrarnumero (int minimo, int maximo){

	cout << " estos son los numeros minimo " << minimo << ": maximo: "<< maximo << endl;
}
int main () {
	int maximo = 0, minimo = 0, numero = 0;

	leernumero(numero);
	maxmin(numero, minimo, maximo);
	mostrarnumero(minimo, maximo);
}
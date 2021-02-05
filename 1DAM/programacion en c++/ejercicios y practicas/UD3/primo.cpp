#include <iostream>
#include <cmath>
using namespace std;
/**
 * @brief funcion que nos va a decir si un numero es primo devolviendo una funcion booleana
 * @info de volvera si es verdad o es falso
 * @param le pasamos el numero con int numero, y la funcion bool contador
 * @pre le pasamos ya el numero para que calcule el numero primo
 * @post de volvera si es true o false  despues de realizar el for
 * @return contador de vovlera 1 o 0
 */
bool primo(int numero, bool contador){

	for (int i = 2; i <= numero -1 && contador != true; i++){	
		if(numero % i == 0)
			contador = true;
	}
	return contador;
}
/**
 * @brief funcion que le pedira los datos al usuario	
 * @info la pasamos por referencia ya que vamos a cambiar el valor de estas	, filtramos tambien para que el primer
 * numero sea mayor que 1 y menor que el 2 numero.
 * @param le pasamos numero y numero2 lo hacemos por referencia ya que vamos a cambiar el valor de estas 
 * @post al pulsar la tecla cambiaremos el valor de las 2 variables
 */
void imprime_numero(int &numero, int &numero2){
	do{
		cout << " introduce un numero para saber desde el numero 1 " << endl;
		cin >> numero;
		cout << " introduce el 2 numero para decirte cuantos primos tiene " << endl;
		cin >> numero2;
	}while(numero <= 1 && numero < numero2);
}
/**
 * @brief funcion que repetira el bucle hasta llegar al numero maximo introducido 	
 * @info mostrara todos los numeros primos entre el numero y numero2 parando en este.
 * @pre le pasamos ya el numero pedido por el usario.
 * @param numero y numero2 y contador por refencia ya que lo vamos a cambiar
 * @post cambiamos el valor de contador para ello lo pasamos por referencia
 */
void primobucle(int numero, int numero2,int &contador){
	bool numero_primo = false;
	int i = 0;

	for (i = 1; i <= numero2; i++){
		if(primo(numero, numero_primo) == true){
			numero++;
			
		}
		else{ 
			numero++;
			contador++;
			//cout << " numero primo: " << numero << endl;
		}
	}
}
/**
 * @brief funcion que le imprime el resultado de todos los numeros primos desde a y b
 * @param pasamos res, a y b por copia.
 * @pre le pasamos ya el resultado del numero para poder imprimirlo
 * @pos mostramos el resultado y no deolvemos nada
 */
void imprime_res (int res, int a, int b){
	cout << " en el numero entre " << a << " y " << b << " tiene  " << res << " numeros primos" << endl;
}
int main(){
	int numero = 0, numero2 = 0, contador = 0;
	
	imprime_numero(numero, numero2);
	primobucle(numero, numero2, contador);
	imprime_res(contador, numero, numero2);
}
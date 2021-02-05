#include <iostream>
#include <cmath>
using namespace std;
/**
 * @brief esta funcion le va a pedir al usuario que introduzca los datos por pantalla y mostrala las opciones del menu
 * @info guardamos por parametros los valores
 * @pre le pasamos los valores que queremos cambiar por referencia a,b ,c
 * @post cambiaremos los valores de a,b y c.
 */
void introducir(double &a, double &b, char &c){
	
	cout << "pulsa	[s] para sumar [r] para restar [m] para multiplicar [d] para dividir: ";
	cin >> c;
	cout << "introduce el 1 numero: " << endl;
	cin >> a;
	cout << " introduce el 2 numero: " << endl;
	cin >> b;
}
/**
 * @brief funcion que nos va sumar dos numeros y guardar en una variable local
 * @info de volvera el resultado
 * @pre le pasamos el numero a y b(los numeros pedidos por el usuario anterior mente)
 * @post de volvera el resultado de la operacion
 * @return res. que va ser el resultado
 */
double sumar (double a, double b){
	 double res = 0;
	
	 res = a + b;

	 return res;
}
/**
 * @brief funcion que nos va restar dos numeros y guardar en una variable local
 * @info de volvera el resultado
 * @pre le pasamos el numero a y b(los numeros pedidos por el usuario anterior mente)
 * @post de volvera el resultado de la operacion
 * @return res. que va ser el resultado
 */
double restar (double a, double b){
	 double res = 0;
	 
	 res = a - b;

	 return res;
}
/**
 * @brief funcion que nos va dividir dos numeros y guardar en una variable local
 * @info de volvera el resultado
 * @pre le pasamos el numero a y b(los numeros pedidos por el usuario anterior mente)
 * @post de volvera el resultado de la operacion
 * @return res. que va ser el resultado
 */
double dividir (double a, double b){
	 double res = 0;

	 res = a / b;

	 return res;
}
/**
 * @brief funcion que nos va multiplicar dos numeros y guardar en una variable local
 * @info de volvera el resultado
 * @pre le pasamos el numero a y b(los numeros pedidos por el usuario anterior mente)
 * @post de volvera el resultado de la operacion
 * @return res. que va ser el resultado
 */
double multiplicar (double a, double b){
	 double res = 0;

	 res = a * b;

	 return res;
}
/**
 * @brief este modulo es el menu que hara y llamara a otro modulo para realizar diferentes operacion dependiendo de lo que pulse el usuario
 * @info sera de tipo void ya que no va a devolver nada
 * @pre le pasamos el numero valor1 y valor2(los numeros pedidos por el usuario anterior mente) tambien la letra pulsada que sera a
 * @post no de vuelve nada
 */
void menu(char a, double valor1,double valor2){
	double res = 0;

	switch (a) {
		case 's': 
			res = sumar(valor1, valor2);
			cout << res << endl;
		break;
		case 'r': 
			res = restar(valor1, valor2);
			cout << res << endl;
		break;
		case 'm': 
			res = multiplicar(valor1, valor2);
			cout << res << endl;
		break;
		case 'd': 
			res = dividir(valor1, valor2);
			cout << res << endl;
		break; 	
		default:
			cout << " pulse una letra para hacer una cuenta: " << endl;
	}
}

int main () {
	double numero1, numero2; 
	char calculadora;
	
	introducir(numero1, numero2, calculadora);
	menu(calculadora, numero1, numero2);
	
}

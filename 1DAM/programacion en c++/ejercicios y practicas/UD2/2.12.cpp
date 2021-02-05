#include <iostream>
#include <cmath>
using namespace std;
int main () {
	double numero1, numero2, sumar, restar, multiplicar, dividir; 
	char calculadora;
	
	cout << " hola esta en el programa de la calculadora introduce un numero y depues otra para hacer operacion despues " << endl;
	cout << "introduce 1 numeros: " << endl;
	cin >> numero1;
	cout << " introduce el 2 numero  " << endl;
	cin >> numero2;
	cout << "pulsa	[s] para sumar [r] para restar [m] para multiplicar [d] para dividir ";
	cin >> calculadora;
	
	sumar = numero1 + numero2;
	restar = numero1 - numero2;
	multiplicar = numero1 * numero2;
	dividir = numero1 / numero2;
	
	switch (calculadora) {
		case 's': 
			cout << sumar << endl;
		break;
		case 'r': 
			cout << restar << endl;
		break;
		case 'm': 
			cout << multiplicar << endl;
		break;
		case 'd': 
			cout << dividir << endl;
		break; 	
		default:
			cout << "pulse una letra para hacer una cuenta " << endl;
	}
}

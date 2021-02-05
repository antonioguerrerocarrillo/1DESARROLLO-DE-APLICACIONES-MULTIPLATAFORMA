#include <iostream>
#include <cmath>
using namespace std;
int main () {
	int numero = 0, i = 0;
	
	cout << "introduce el numero para saber si el cuadrado es perfecto " << endl;
	cin >> numero;
	
	for (i = 0; i <= numero; i++) {
		numero = i * i;
		if ((pow(numero, 2)) == numero) {
			cout << "es un cuadrado perfecto " << endl;
		}
	else 
		cout << " no es un cuadrado perfecto " << endl;
	}
} 

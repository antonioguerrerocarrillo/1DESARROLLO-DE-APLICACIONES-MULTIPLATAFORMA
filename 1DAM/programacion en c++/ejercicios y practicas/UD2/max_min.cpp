#include <iostream>
#include <cmath>

using namespace std;

int main () {
	int maximo = 0, minimo = 0, numero = 0;

	cout << " introduce un numero hasta que sea distinto de 0 " << endl;
	cin >> numero;

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
	cout << " estos son los numeros minimo " << minimo << ": maximo: "<< maximo << endl;
}
#include <iostream>
#include <cmath>
using namespace std;
int main () {
	int respuesta = 0, resultado = 0;

	cout << " introduce un numero " << endl;
	cin >> respuesta;

	while (respuesta >= 0){
		cout << " recibiendo " << endl;
		cin >> respuesta;
		
		resultado ++;
	}

	cout << " fin de transmision " << endl;
	cout << " el numero de veces que has recibido señal es de  " << resultado << endl;

}
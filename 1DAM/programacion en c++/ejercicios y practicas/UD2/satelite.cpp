#include <iostream>
#include <cmath>

using namespace std;

int main () {
	int dato;
	do {
		cout << " introduce un numero mayor que  0 " << endl;
		cin >> dato;
		cout << "recibido: " << dato << endl; 	
			if  (dato >= 0)
				cout << " procesando: " << dato << endl;
		} while (dato <= 0);
			cout << "fin de trasmision" << endl;
	
}
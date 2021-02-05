#include <iostream>
#include <cmath>

using namespace std;

int main () {
	int dato = 0;
	
	cout << " introduce un numero mayor que  0 " << endl;
	cin >> dato;
	if (dato > 0){
		for (int i = 1; i <= dato; i++){		
			cout << "recibido: " << dato << endl; 
			cout << " procesando: " << dato << endl;
		}
	}	
	cout << "fin de trasmision" << endl;
	
}
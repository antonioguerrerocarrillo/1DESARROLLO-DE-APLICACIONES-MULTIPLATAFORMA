#include <iostream>
#include <cmath>
using namespace std;
int main () {
	int i = 2, numero = 0;
	bool contador = false;
	
	do {
	cout << " introduce un numero para saber si es primo " << endl;
	cin >> numero;
	
	}while( numero < 0);

	for (int i = 2; i <= numero -1 && contador != true; i++){	
		if(numero % i == 0)
			contador = true;
	}
	if(contador == true)
		cout << " este numero no es primo " << endl;
	else 
		cout << "este numero es primo " << endl;
}
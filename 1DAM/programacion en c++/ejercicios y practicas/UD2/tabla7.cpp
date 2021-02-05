#include <iostream>
#include <cmath>
using namespace std;
int main () {
	int multiplicar = +1, resultado = 0;
	
	cout << " vamos hacer 10 veces la tabla del 7 "<< endl;
	
	resultado = multiplicar * multiplicar;

	do {
		cout << " 7 x " << resultado << " = " << multiplicar * 7 << endl;
		resultado = resultado +1;
	}
	while (resultado <= 10);
}

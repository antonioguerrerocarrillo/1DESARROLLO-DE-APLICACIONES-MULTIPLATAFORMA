#include <iostream>
#include <cmath>
using namespace std;
int main () {
	int multiplicar = +1, resultado = 0;
	
	cout << " dime que numero quieres multiplicar "<< endl;
	cin >> multiplicar;


	do {
		cout << resultado << "  x " << multiplicar << " = " << resultado * multiplicar << endl;
		resultado = resultado +1;
	}
	while (resultado <= 10);
}

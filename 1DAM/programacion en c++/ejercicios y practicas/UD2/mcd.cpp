#include <iostream>
#include <cmath>
using namespace std;
int main () {
	int a= 0, b = 0, resto = 0;

	cout << "introduce 1 numero para calcular MCD: " << endl;
	cin >> a;
	cout << "introduce el 2 numero para calcular MCD: " << endl;
	cin >> b;

	resto = a % b;

	while (resto !=0) {
		a = b;
		b = resto;
		resto = a % b;
	}
	cout << " El MCD es " << b << endl;
}	

#include <iostream>
#include <cmath>
using namespace std;
int main (){
	double a, b, resultado_suma, resultado_resta, resultado_multi, resultado_division;

	cout << "introduce un numero: " << endl;
	cin >> a;

	cout << " introduce el 2 numero: " << endl;
	cin >> b;

	resultado_suma = a + b;
	resultado_resta = a - b;
	resultado_division = a / b;
	resultado_multi = a * b;

	cout << "el resultado de la suma es " << resultado_suma << endl;
	cout << " el resultado de la resta es " << resultado_resta << endl;
	cout << " el resultado de la division es " << resultado_division << endl;
	cout << " el resultado de la multiplicacion es " << resultado_multi << endl;
}
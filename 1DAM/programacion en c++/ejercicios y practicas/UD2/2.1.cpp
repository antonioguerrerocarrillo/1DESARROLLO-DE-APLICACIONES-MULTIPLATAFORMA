#include <iostream>
#include <cmath>

using namespace std;

int main(){
	int a, b;

	cout << "introduce un numero para comparar cual de los dos es mayor " << endl;
	cin >> a;

	cout << " introduce el 2 numero de la comparativa " << endl;
	cin >> b;

	if(a > b)
		cout << " el 1 numero es mayor concretamente el numero " << a << endl;
	
	if (b > a) 
		cout << " el 2 numero es mayor concretamente el numero " << b << endl;

	if (a == b)
		cout << " los 2 numeros son iguales " << a << " y "<< b << endl;


}
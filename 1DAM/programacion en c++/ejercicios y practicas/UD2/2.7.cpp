#include <iostream>
#include <cmath>

using namespace std;

int main(){
	int a = 0, b = 0, c = 0;

	cout << " introduzca 1 numero para comprobar cual de los 3 numero es mayor " << endl;
	cin >> a;
	cout << " introduce el 2 numero " << endl;
	cin >> b;
	cout << " introduce el 3 numero " << endl;
	cin >> c;
	
	if (a > b && a > c){ 
		cout << " el 1 numero es el mayor que es el numero " << a << endl;
	}
	if (b > a && b > c){
		cout << " el 2 numero es el mayor que es el numero " << b << endl;
	}
	if (c > a && c > b){
		cout << " el 3 numero es el mayor que es el numero " << c << endl;
	}
	if (a == b || b == c || c == a){
		cout << " los numeros son iguales " << endl;
	}
}
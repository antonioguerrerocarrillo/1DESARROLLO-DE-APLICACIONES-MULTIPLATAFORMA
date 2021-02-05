#include <iostream>
#include <cmath>

using namespace std;

int main(){
	int a, b;

	cout << "introduce un numero para saber si es par o impar " << endl;
	cin >> a;

	if (a % 2==0 && a > 0)
		cout << " el numero es par " << endl;
	if (a == 0)
		cout << " el numero 0 no se pude saber si es par o impar introduzca un numero mayor " << endl;
	else if (a % 2==1)
		cout << " el numero es impar " << endl;
}
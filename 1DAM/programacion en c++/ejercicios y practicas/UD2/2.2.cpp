#include <iostream>
#include <cmath>

using namespace std;

int main(){
	int a, b;

	cout << "introduce un numero para saber si es par o impar " << endl;
	cin >> a;

	if (a % 2==0)
		cout << " el numero es par " << endl;
	else 
		cout << " el numero es impar " << endl;
}
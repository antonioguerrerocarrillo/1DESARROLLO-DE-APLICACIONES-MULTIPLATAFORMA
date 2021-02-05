#include <iostream>
#include <cmath>
using namespace std;
int main () {
	int resultado = 0;
	
	cout << " dime que numero quieres multiplicar "<< endl;
	cin >> resultado;


	for (int a = 1; a <= 10; a++ ){
		cout << resultado << "  x " << a << " = " << resultado * a << endl;
	}
}

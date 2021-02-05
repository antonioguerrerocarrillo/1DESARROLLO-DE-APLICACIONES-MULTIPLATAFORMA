#include <iostream>
#include <cmath>

using namespace std;

int main () {
	int dato = 7;
	
	cout << " vamos a hacer la tabla de multiplicar del 7" << endl;

	for (int i = 1; i <= 10; i++){		
		cout << " 7 x " << i << " = " << dato * i << endl;
	}	
}
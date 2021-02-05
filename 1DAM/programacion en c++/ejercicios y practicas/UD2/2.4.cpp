#include <iostream>
#include <cmath>

using namespace std;

int main(){
	double pi = 3.14159265;
	double radio = 0, area = 0, longitud = 0;

	cout << " introduce el radio para calcular el area del circulo y su longitud; " << endl;
	cin >> radio;

	if (radio >= 0){
		area = pi * (radio * radio);
		longitud = 2 * pi * radio;

		cout << " el area del circulo es " << area << endl;
		cout << " la longitud del circulo es " << longitud << endl;
	} else 
		cout << " el valor introducido tiene que ser positivo " << endl;

}
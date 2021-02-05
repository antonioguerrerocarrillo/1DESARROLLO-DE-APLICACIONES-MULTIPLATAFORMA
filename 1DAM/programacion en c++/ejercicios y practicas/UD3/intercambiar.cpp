#include <iostream>
#include <cstdlib>

using namespace std;
void intercambiar (int &x, int &y){
	int aux = x;
	x = y;
	y = aux;

	cout <<"DENTRO a = " << x << " y b = " << y << endl;
}

int main (){
	int a = 2;
	int b = 1;
	int aux = 0;

	intercambiar(a, b);

	cout <<"FUERA a = " << a << " y b = " << b << endl;
}
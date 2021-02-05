#include <iostream>
#include <cmath>
using namespace std;
int main () {
	int vector[10];
	int numero;
	//tabla de multiplicar
	cout << " introduce el numero que quieres multiplicar: " << endl;
	cin >> numero;
	
	for (int i=0; i<10; i++){
		vector[i] =numero*i;
	}		
	for(int i=0;i<10;i++)
	{
			cout << " este es el resultado: " << vector [i] << endl;
	}
}

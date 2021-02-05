#include <iostream>
#include <cmath>
using namespace std;
int main () {
	int numero = 0, i = 0, sumatoria = 0;
	double res = 1;

	cout << " introduce un numero " << endl;
	cin >> numero;

	for ( i = 1; i <= numero; i++){
		res *= i;
		sumatoria++;
	
		cout << numero << " = " << res << endl;
	}
	cout << " la sumatoria total es " << sumatoria << endl;
}
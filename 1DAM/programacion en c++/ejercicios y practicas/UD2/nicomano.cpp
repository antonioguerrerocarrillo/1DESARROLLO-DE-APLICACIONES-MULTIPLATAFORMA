#include <iostream>
#include <cmath>
using namespace std;
int main () {
	int aux = 0, n = 0, contador = 0, sum = 0;
	bool parada = false;

	cout << "vamos hacer la secuencia de nicomano, escribe el numero de veces que quieres hacer nicomano " << endl;
	cin >> n;

	aux = n * n * n;
	
	for (int i = 1; i <= aux; i++){

		if (i % 2 == 1 && i >= contador){	
			cout << i <<  " * " << i << endl;
			contador++;
			if (i == contador){
			}
		}
	}
	for (int i = 1; i <= n && parada == false; i++){
		if (i <= n){
			parada = true;
			cout << " n * "<< n * n * n << endl;
		}

	}
	cout << " el valor de n es : " << n <<  " sumatoria " << sum << endl;
}
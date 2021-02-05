#include <iostream>
#include <cmath>
using namespace std;
int main () {
	int intervalo_menor = -100, intervalo_mayor = 100;
	int multiplos = 0, i = 0;

	for ( i = intervalo_menor; i <= intervalo_mayor; i++){
		if(i % 3 == 0){
			multiplos++;
			cout << "hay " << multiplos << "multiplos de 3 " << endl;   
		}
	}
}
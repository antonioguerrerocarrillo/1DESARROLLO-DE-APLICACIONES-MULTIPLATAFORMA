#include <iostream>
#include <cmath>
using namespace std;
int main () {
	int mayor=0, menor=99999999;
	const int N_NUMEROS=40;
	int numeros[N_NUMEROS];
	int util_numeros=0;	
	int a;

	cout << " introduce numero que quieres guardar. " << endl;
	cin >> util_numeros;
	
	
	
	for (int i; i < util_numeros; i++){
	cout << " introduce un numero" << endl;
	cin >> numeros[i] ;	
		
	}
	for (int a=0 ;a < util_numeros; a++) {
		if (mayor < numeros[a]) {
			mayor=numeros[a];
			
		}
		if (menor > numeros[a]) {
			menor = numeros[a];
			
		} 
	}
	cout << " este es el numero menor " << menor;	
	cout << " es te es el numero mayor " << mayor;	
}

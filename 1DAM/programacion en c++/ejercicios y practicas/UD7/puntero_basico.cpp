#include <iostream>
using namespace std;
int main(){
	int *puntero1 = 0, *puntero2 = 0;
	int m = 3, n = 69, res = 0;
	puntero1 = &m;
	puntero2 = &n;

	cout << " igualamos lo que tiene dentro puntero1 " << *puntero1 << "y puntero2 = " << *puntero2 << endl;
	*puntero2 = *puntero1;
	cout << " imprimiendo lo que contiene puntero2 " << *puntero2  << " puntero1 " << *puntero1 << endl;
	
	cout << " imprimiendo la direccion de memoria del puntero1 " << puntero1 << endl;

	
	*puntero2 = 23;
	res = *puntero2 + *puntero1 * 10;

	cout << " haciendo una cuenta basica usando punteros puntero2 + puntero1 * 10 = " << res << endl;
}
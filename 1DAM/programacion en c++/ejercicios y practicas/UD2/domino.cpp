#include <iostream>
#include <cmath>
using namespace std;
int main () {
	int numero = 0, contador = 0;
	bool entra = false;
	cout << "vienvenido al programa del domino " << endl;

	for (int i = 0; i <= 6 && entra == false ; i++){	
		cout << " ficha de domino del numero " <<  i << endl;

		for(int a = 0; a <= 6; a++){
			if(contador != a-1)
				cout << " ficha del domino anidada " << i << " x " << a << endl;
		}
		contador++;
	}


}
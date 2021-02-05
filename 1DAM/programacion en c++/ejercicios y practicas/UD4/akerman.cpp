#include <iostream>
#include <cmath>
using namespace std;
int akerman (int valor1, int valor2) {
	int resultado = 0;
	
	if (valor1 == 0){
		resultado = valor2 +1;
	}	
	else if (valor1 > 0 && valor2 == 0){
		resultado = akerman(valor1 -1, 1);		
	}	
	else if (valor1 > 0 && valor2 > 0) {
		resultado = akerman (valor1 -1, akerman(valor1, valor2-1));
	}

	return resultado;
}
void introducir_valores (int n1, int n2){
	cout << " introduce dos numeros para hacer Ackermann: " << endl;
	cin >> n1 >> n2;
}
void resultado (int resultado){
	cout << " el resultado es : " << resultado << endl;
}
int main (){
	int n1 = 0, n2 = 0, res = 0;
	
	introducir_valores(n1, n2);
	
	res = akerman(n1, n2);
	
	resultado(res);
}

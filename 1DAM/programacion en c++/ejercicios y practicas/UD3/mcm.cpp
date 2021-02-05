
#include <iostream>
#include <cmath>
using namespace std;
void introduce_usuario(int &a, int &b){
	
	cout << "Introduce el primer numero para calcular su MCM: " << endl;
	cin >> a;
	cout << "Introduce el segundo numero para calcular su MCM: " << endl;
	cin >> b;

}
int mcd (int a, int b){

	int resto = 0;
	resto = (a % b);

	while (resto != 0){
	
			a = b;
			b = resto;
			resto = (a % b);
	}
	return b;
 }
 int mcm (int &a, int &b){
 	int res = 0;

 	res = (a * b) / mcd (a, b);
 	
 	return res;
 }
void resultado (int a, int b){

	cout << "El mcm de " << a << " y " << b << " = " << mcm(a,b) << endl;

}
int main () {
	int a = 0, b = 0;
	
	introduce_usuario(a,b);
	mcm (a, b);
	resultado(a,b);
}
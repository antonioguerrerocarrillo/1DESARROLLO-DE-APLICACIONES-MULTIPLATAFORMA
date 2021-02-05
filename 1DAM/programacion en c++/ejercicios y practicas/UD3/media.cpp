#include <iostream>
#include <cmath>

using namespace std;
double media( double numero1,double numero2, double numero3){
	double resultado = 0;

	resultado = (numero1 + numero2 + numero3) / 3;
	
	return resultado;
}
void imprime(){
	double a = 0, b = 0, c = 0;

	cout << " intrduce los 3 numeros con espacios para hacer la media de un numero " << endl;
	cin >> a >> b >> c;

	cout << " el resultado de la media es " << media(a, b, c) << endl; 
	
}
int main () {

	imprime();

}
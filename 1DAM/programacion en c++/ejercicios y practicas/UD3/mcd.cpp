#include <iostream>
#include <cmath>
using namespace std;
/**
 * @brief funcion que le pedira los datos al usuario	
 * @info la pasamos por referencia ya que vamos a cambiar
 * @pre le pasamos a y b lo hacemos por referencia ya que vamos a cambiar el valor de estas 
 * @post cambiamos el valor de estas ya que esta por referencia
 */
void leerdato (int &a, int &b){

	cout << "introduce 1 numero para calcular MCD: " << endl;
	cin >> a;
	cout << "introduce el 2 numero para calcular MCD: " << endl;
	cin >> b;

}
int mcd(int a, int b){
	int resto;
	
	resto = a % b;

	while (resto != 0) {
		a = b;
		b = resto;
		resto = a % b;
	}
	//cout << "dentro El MCD es b " << b << endl;
	//cout << "dentro El MCD es  resto " << resto << endl;
	//cout << "dentro El MCD es a " << a << endl;

	return b;
}
void mostradato (int res){

	cout << " El MCD es " << res << endl;
}
int main () {
	int a = 0, b = 0;
	int resultado;
	
	leerdato(a,b);
	resultado = mcd(a,b);
	mostradato(resultado);
	
}	

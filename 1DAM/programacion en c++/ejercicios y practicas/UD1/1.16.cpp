#include <iostream>
#include <cmath>
using namespace std;
int main (){
	int precio = 0, dinero_entregado = 0, vuelta = 0;

	cout << " introduce el precio del articulo (en centimos): " << endl;
	cin >> precio;
	cout << " introduce el dinero entregado (en centimos): " << endl;
	cin >> dinero_entregado;
	
	vuelta = dinero_entregado - precio;

	cout << " la vuelta es: " << vuelta << endl;
}

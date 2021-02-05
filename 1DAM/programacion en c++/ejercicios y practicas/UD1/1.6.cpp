#include <iostream>
#include <cmath>
using namespace std;
int main (){
	int precio, dinero_entregado, vuelta;

	cout << " introduce el precio del articulo (en centimos): " << endl;
	cin >> precio;
	cout << " introduce el dinero entregado (en centimos): " << endl;
	cin >> dinero_entregado;
	
	vuelta = dinero_entregado - precio;

	cout << " la vuelta es: " << vuelta << endl;
}

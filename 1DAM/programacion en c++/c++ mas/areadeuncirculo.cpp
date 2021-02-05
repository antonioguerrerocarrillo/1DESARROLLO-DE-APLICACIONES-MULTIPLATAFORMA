#include <iostream>
#include <cmath>
using namespace std;
int circulo(double radio ){
	double pi=3.14;
	return pi * radio*radio;
		
}
// menu de parcelas introduce una parcela si o no, lo realize y lo vuelva a repetir.
int menu (){
	char menu='s';
	double resultado=0;
	double radio;
	while (menu == 's') {
	
		cout << " pulsa 's' si quieres introducir otra area o 'n' si no quieres introducir mas ";
		cin >> menu;
		if(menu == 's'){
			cout << " introduce el radio del circulo" ;
			cin >> radio;
			resultado+=circulo(radio);
		
		}
	}
	cout << " el resultado es: " << resultado;
}
int main (){
	menu ();
	
}

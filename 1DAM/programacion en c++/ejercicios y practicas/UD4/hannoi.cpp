#include <iostream>
#include <cmath>
using namespace std;
void hannoi (int altura, char origen,char medio, char destino){
	
	if (altura == 1) {
		cout << " se mueve de " << origen << " al "<< medio << " == :-) " << destino << endl;
	}
	else {
		hannoi (altura -1, origen, destino, medio);
		cout << " la pieza " << altura << " se mueve de " << origen << " al "<< medio << destino << endl;	
		hannoi (altura -1, destino, medio, origen);		
	}
}
void introducir_valores(int &a, char &o, char &d){
	cout << " introduce la altura: " << endl;
	cin >> a;
	cout << " introduce el numero de origen: (tipo char) " << endl;
	cin >> o;
	cout << " introduce el numero de destino:(tipo char) " << endl; 
	cin >> d;
}
int main () {
	int altura = 0;
	char origen, destino, medio;
	
	introducir_valores(altura, origen, destino);
	
	hannoi (altura, origen, medio, destino);

}

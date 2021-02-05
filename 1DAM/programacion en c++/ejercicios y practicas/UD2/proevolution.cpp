#include <iostream>
#include <cmath>
using namespace std;
int main () {
	double	 x1 = 0, y1 = 0, x2 = 0, y2 = 0, xt = 0, yt = 0;

	do{
		cout << "Introduce las coordenadas para poner la porteria (esquina arriba izquierda) " << endl;
		cin >> x1 >> y1;
		cout << "Introduce las coordenadas para situar la porteria (esquina abajo derecha) " << endl;
		cin >> x2 >> y2;

	}while ((x1 < 0) && (x2 < 0) && (y1 < 0) && (y2 < 0));
		cout << "Porteria correcta" << endl;

	cout << "Introduce las coordenadas para pegarle al balon" << endl;
	cin >> xt >> yt;

	if ((x1 < xt) && (x2 > xt) && (y1 > yt) && (y2 < yt)){
		cout << "Golazo primo" << endl;
	}
	else if ((x1 == xt) && (y1 < yt)) {
		cout << "Al palo, Al paloo!" << endl;	
	}
	else if ((x1 == xt) &&	(x2 > xt) && (y1 > yt) && ( y2 < yt)) {
		cout << "uy! al palo izquierdo" << endl;
	}
	else if ((x1 < xt) && (xt == x2) && (y1 > yt) && (yt > y2)){
		cout << "uy! al palo derecho " << endl;
	}
	else if ((x1 < xt) && (x2 < xt) && (y2 < yt) && (y1 > yt)) {
		cout << "fuera por el lado derecho " << endl; 		
	}
	else if ((x1 < xt) && (x2 < xt) && (y1 < yt) && (y2 > yt)) {
		cout << " fuera por el lado izquierdo " << endl;
	}
	else if ((y1 < yt) && (y2 < yt) && (x1 > xt) && (x2 < xt)) {
		cout << " casi! rozando la escuadra izquierda" << endl;
	}
	else if ((y1 < yt) && (y2 < yt) && (x1 < xt) && (x2 < xt)) {
		cout << " casi! rozando la escuadra derecha " << endl;
º	}
	else if ((y1 > yt) && (y2 > yt) && (x1 > xt) && (x2 > xt)) {
		cout << "  cerca de la esquina esquina izquierda le diste al topo " << endl;
	}
	else if ((y1 < yt) && (y2 < yt) && (x1 < xt) && (x2 < xt)) {
		cout << " le diste al portero enterrado (suelo) " << endl;
	}
	else  if ((y1 < yt) && (y2 < yt) && (x1 < xt) && (x2 > xt)) {
		cout << " golazo por la escuadra derecha " << endl;
	}
	else if ((y1 > yt) && (y2 < yt) && (x1 < xt) && (x2 > xt)) {
		cout << " golazo por la escuadra izquierda " << endl;
	}
 
} 

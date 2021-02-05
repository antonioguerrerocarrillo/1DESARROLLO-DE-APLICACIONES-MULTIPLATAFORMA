#include <iostream>
#include <cmath>
using namespace std;
int main () {
	// los numeros del 1 al 8 seran el lateral_izq y derecho
	// desde a hasta h sera declarado con parte_inferior
	int parte_inferior, parte_superior, lateral_izq, lateral_der;
	char menu;
	
	cout << "   JUEGO DE AJEDREZ TABLERO " << endl;  
	cout << "        parte superior " << endl;  
	cout << "1 [ ][+][ ][+][ ][+][ ][+] 1" << endl;
	cout << "2 [+][ ][+][ ][+][ ][+][ ] 2" << endl;
	cout << "3 [ ][+][ ][+][ ][+][ ][+] 3" << endl;
	cout << "4 [+][ ][+][ ][+][ ][+][ ] 4" << endl;
	cout << "5 [ ][+][ ][+][ ][+][ ][+] 5" << endl;
	cout << "6 [+][ ][+][ ][+][ ][+][ ] 6" << endl;
	cout << "7 [ ][+][ ][+][ ][+][ ][+] 7" << endl;
	cout << "8 [+][ ][+][ ][+][ ][+][ ] 8" << endl;
	cout << "   a  b  c  d  e  f  g  h " << endl;
	cout << "        parte inferior " << endl;  
	
	do {
	cout << " introduce la opcion que quieres hacer [1] para mover la torre de lateral [2] para mover la torre inferior/superior [3] mover el alfil laterla [4] mover el alfil inferior/superior [5] para mover la reina de la parte inferior al lateral [6] para mover desde el lateral a la parte inferior/superior [0] para salir" << endl;
	cin >> menu;
	 }	while(menu != '1' && menu != '2' && menu !='3' && menu != '4' && menu != '5' && menu != '6'&& menu != '0'); 
	
	switch (menu) {
		case '1': 
			//movimiento 1 de la parte superior a x lateral
		do{
			cout << " movimiento de la torre introduce desde la parte inferior de la a hasta h con un numero del 1 al 8 donde quieres colocar la torre " << endl;
			cin >> parte_inferior;
			cout << "  introduce del 1 al 8 hasta donde la quieres mover " << endl;
			cin >> lateral_izq;
		}	while (parte_inferior >= 8 || lateral_izq >= 8);

		parte_superior = parte_inferior;
		lateral_der = lateral_izq;

		if (lateral_izq <= 8 || lateral_izq != parte_inferior)
			cout << " movimiento realizado la torre esta en " << lateral_izq << endl;
		else 
			cout << " movimiento no realizado " << endl;
		break;
		case '2': 
			do{
				cout << " movimiento de la torre introduce desde la parte lateral de la 1 hasta 8 con un numero del 1 al 8 donde quieres mover la torre " << endl;
				cin >> lateral_izq;
				cout << "  introduce del 1 al 8 hasta donde la quieres mover " << endl;
				cin >> parte_inferior;
			}	while (parte_inferior >= 8 || lateral_izq >= 8);

			parte_superior = parte_inferior;
			lateral_der = lateral_izq;

			if (lateral_izq <= 8 || lateral_izq != parte_inferior)
				cout << " movimiento realizado la torre esta en " << lateral_izq << endl;
			else 
				cout << " movimiento no realizado " << endl;
		break;
		case '3': 
			do{
				cout << " movimiento del alfil desde la parte lateral desde a hasta h con un numero del 1 al 8 donde lo quieres mover " << endl;
				cin >> lateral_izq;
				cout << "  introduce del 1 al 8 hasta donde la quieres mover " << endl;
				cin >> parte_inferior;
			}	while (parte_inferior >= 8 || lateral_izq >= 8);

			parte_superior = parte_inferior;
			lateral_der = lateral_izq;

			if (parte_inferior != parte_superior || parte_inferior != lateral_izq)
				cout << " movimiento realizado el alfil esta en " << parte_inferior<< endl;
			else 
				cout << " movimiento no realizado " << endl;
		break;
		case '4': 
			do{
				cout << " movimiento del alfil introduce desde la parte lateral de la 1 hasta 8 con un numero del 1 al 8 donde quieres moverlo " << endl;
				cin >> lateral_izq;
				cout << "  introduce del 1 al 8 hasta donde la quieres mover " << endl;
				cin >> parte_inferior;
			}	while (parte_inferior >= 8 || lateral_izq >= 8);

			parte_superior = parte_inferior;
			lateral_der = lateral_izq;

			if (parte_inferior != parte_superior || parte_inferior != lateral_izq)
				cout << " movimiento realizado el alfil esta en " << lateral_izq << endl;
			else 
				cout << " movimiento no realizado " << endl;
		break; 	
		case '5': 
			do{
				cout << " movimiento de la reina introduce desde la parte lateral de la 1 hasta 8 con un numero del 1 al 8 donde quieres moverla " << endl;
				cin >> parte_inferior;
				cout << "  introduce del 1 al 8 hasta donde la quieres mover " << endl;
				cin >> lateral_izq;
			}	while (parte_inferior >= 8 && lateral_izq >= 8);
			if (parte_inferior <= 8 && lateral_izq <= 8)
				cout << " movimiento realizado la reina esta en " << lateral_izq << endl;
		break; 
		case '6': 
			do{
				cout << " movimiento de la reina introduce desde la parte lateral de la 1 hasta 8 con un numero del 1 al 8 donde quieres moverla " << endl;
				cin >> lateral_izq;
				cout << "  introduce del 1 al 8 hasta donde la quieres mover " << endl;
				cin >> parte_inferior;
			}	while (parte_inferior >= 8 || lateral_izq >= 8);
			if (parte_inferior <= 8 && lateral_izq <= 8)
				cout << " movimiento realizado la reina esta en " << parte_inferior << endl;
		break; 
		case '0': 
			
		break; 	
		default:
			cout << "pulse un numero para hacer un movimiento " << endl;
	}
}
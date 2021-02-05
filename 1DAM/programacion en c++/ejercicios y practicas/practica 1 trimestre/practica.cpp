	#include <iostream>
	#include <cmath>
	using namespace std;
	double amenaza () {
		double r=0, x=0, y=0 , z=0;//base
		double z1=0, x1, y1;
		char opcion;
		int contadoraereo=0, contadorterrestre=0;
	
		cout << "introduce 3 numeros reales separados con espacios, radio, y la ubicacion1 y 2: " << endl;
		cin >> r >> x >> y;
		
		while (opcion != 'd' )
		{
			do{ 
				cout << " pulsa [a] si la amenaza es aerea, [t] si es terrestre, y [d] si quieres salir: " << endl;
				cin >> opcion;
			}while(opcion!='a' && opcion!= 't'&& opcion !='d' ); //filtro para que si no es esa tecla lo repita (do)
			
				
			if (opcion !='d')
			{
				if(opcion == 'a')
				{
					cout << " introduce la x, y, z (con espacios)";
					cin >> x1 >> y1 >> z1;
				}
				else
				{
					cout << "introduce la x, y:";
					cin >> x1 >> y1;
					z1=0;
				}
					
				if (pow (x-x1,2)+pow(y-y1,2)+pow(z-z1,2) < r*r)
				{
				
					switch (opcion) {
						case 'a':
							
							contadoraereo ++;
						break;
						case 't':
							contadorterrestre ++;
						break;
						
					
					}
			
				
				
				}
				
			}	
			
		}
		cout << " total de amenazas terrestres " << contadorterrestre << "total de amenazas aereas:  " << contadoraereo << endl;
		
	}
	int elefante () {
		int res= 0;
		int peso = 0;
		int elefante = 1;
		int contador = 0;
		
		cout << " introduce el peso de la tela de arana: " << endl;
		cin >> peso;
		
		while (elefante !=0) {
			if (res < peso) {
				contador++;
				}
				cout << "introduce el peso del elefante: " << endl;
				cin >> elefante;
				res = res + elefante;
			
		}
		cout << contador << " " << endl;
		// cuando llega al numero de por ejemplo le pongo que la tela pesa 100 cuand o pasa o llega a cien se queda pillado
	}	
	char menu_en_pantalla () {
	 	char menus ;	
		
		cout << " introduce [e] para ir al problema de los elefantes, [a] para ir al de la amenaza, [n] para ir al del la nasa: y [s] para salir" << endl;
		cin >> menus;
		
		switch (menus) {
			case 'e':
			elefante();
			break;
			case 'a': 
			amenaza(); //invocacion de la variable para que lo coja y el sepa donde se tiene que ir al pulsar			
			break;
			case 'n':				
			break;
			case 's':
			break;
			 	
		}
	
	}
	
	void bienvenida(){
		cout << " bienvenido al programa de antonio. " << endl; 
		cout << " practica final del primer trimestre. " << endl;
	}
	int main () {
		bienvenida();
		menu_en_pantalla();
	}

#include <iostream>
	#include <cmath>
	using namespace std;
/**
@brief dado que este ejercicio es mas largo, 1 pedir radio y la ubicacion. 2 que diga si la ameneza es 
aerea, o de tierra. poner que pulsando un boton se salga. y mostrar el total de amenazas.
@param tiene que hacerlo siempre que sea diferente de (d), y tenemos que poner donde esta la base para 
poder saber si el ataque que nos van hacer seria peligroso.
@pre mientras que sea diferente de (d) opcion != 0. 
@return no devuelve nada
@post mostrar cuantas amenazas son si son por aire o por tierra.
**/
	double amenaza () {
		double r=0, x=0, y=0 , z=0;//base
		double z1=0, x1, y1;
		char opcion;
		int contadoraereo=0, contadorterrestre=0; //contadores

		cout << "introduce 3 numeros reales separados con espacios, radio, y la ubicacion1 y 2: " << endl;
		cin >> r >> x >> y;
		while(cin.fail()){
		cout << "introduce 3 numeros reales separados con espacios, radio, y la ubicacion1 y 2: " << endl;
		cin.clear();
		cin.ignore(256,'\n');
		cin >> r >> x >> y;
		}
		
		while (opcion != 'd' )
		{
			do{ 
				cout << " pulsa [a] si la amenaza es aerea, [t] si es terrestre, y [d] si quieres salir: " << endl;
				cin >> opcion;
			}while(opcion!='a' && opcion!= 't'&& opcion !='d' ); //filtro para que si no es esa tecla lo repita (do)
			
				
			if (opcion !='d')
			{
				if(opcion == 'a')
				// si la opcion es aerea.
				{
					cout << " introduce la x, y, z (con espacios)";
					cin >> x1 >> y1 >> z1;
					while(cin.fail()){
						cout << " introduce la x, y, z (con espacios)";
						cin.clear();
						cin.ignore(256,'\n');
						cin >> x1 >> y1 >> z1;
						}
					}
				else // si no esterrestre.
				{
					cout << "introduce la x, y:";
					cin >> x1 >> y1;
					z1=0;
					while(cin.fail()){
						cout << " introduce la x, y: (con espacios)";
						cin.clear();
						cin.ignore(256,'\n');
						cin >> x1 >> y1;
					}
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
		cout << " total de amenazas terrestres: " << contadorterrestre << " total de amenazas aereas:  " << contadoraereo << endl;
		//cout muestra el total de amenazas, con los contadores.
	}
	int elefante () {
	
	/**
@brief el programa tiene que contar, el numero de veces que entra los elefantes, hasta que pase del numero
maximo que hayamos puesto en la tela de la araña. pero el programa lo seguira pidiendo. elefantes hasta que
pulsemos 0.
@param le ponemos la condicion para que lo repita siempre que sea diferente de 0.
@pre elenfante !=0
@return no devuelve nada
@post muestra el contador total.
**/
		int res= 0;
		int peso = 0;
		int elefante = 1;
		int contador = 0;
	
		cout << " introduce el peso de la tela de arana: " << endl; //pedir el peso.
		cin >> peso; //guardar el peso de la tela
		
		while(cin.fail()){
			cout << " introduce el peso de la tela de arana: " << endl;
			cin.clear();
			cin.ignore(256,'\n');
			cin >> peso;
			}
		while (elefante !=0) {
			//mientras que elefante sea distinto de 0 seguimos haciendolo.
			if(res>0 && res == 10) {
				if (res < peso) {
					//condicion
					contador++;
					//cuenta las veces que entra
					}
				}
				cout << "introduce el peso del elefante: " << endl; //pide el peso de los elefantes
				cin >> elefante; //guarda el peso
		while(cin.fail()){
			cout << " introduce el peso del elefante: " << endl;
			cin.clear();
			cin.ignore(256,'\n');
			cin >> elefante;
			}
		res = res + elefante; //operacion
		
			
		}
		cout << contador << " " << endl;
		// cuando llega al numero de por ejemplo le pongo que la tela pesa 100 cuand o pasa o llega a cien se queda pillado
	}	
	char menu_en_pantalla () {
	 /**
@brief hacemos los menus aqui mostraremos al usuario a que programa queremos ir pulsando la tecla correspondiente
@param para el menu usamos el switch
@pre no tenemos que usar
@return  no tiene return.
@post al pulsar (e) el programa se dirige a elefantes, (a) amenzas. y cuando pulsamos la (s) el programa se sale
	**/
		char menus ;	
	
		do{ //filtro
		cout << " introduce [e] para ir al problema de los elefantes, [a] para ir al de la amenaza, y [s] para salir" << endl;
		cin >> menus;
			}
		while(menus!='e' && menus!= 'a'&& menus !='s' ); 
		
		switch (menus) {
			case 'e':
			elefante();
			break;
			case 'a': 
			amenaza(); //invocacion de la variable para que lo coja y el sepa donde se tiene que ir al pulsar			
			break;
			case 's':
			break;
			 	
		}
	
	}
	
	void bienvenida(){
		//ensenamos con los cout bienvenidos.
		cout << " bienvenido al programa de antonio. " << endl; 
		cout << " practica final del primer trimestre. " << endl;
	}
	int main () {
		// declaramos menu para que el programa se diriga a bienvenida y menu de pantalla despues.
		bienvenida();
		menu_en_pantalla();
	}

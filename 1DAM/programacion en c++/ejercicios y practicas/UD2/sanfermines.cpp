#include <iostream>
#include <cmath>
using namespace std;
int main () {
	int  toros = 1, corredor = 0, num_toros = 0, resultado = 0, contador = 2;
	bool pasado = false;
	
	cout << " vienvenido al programa de los san fermines introduce el numero de toros que van a correr " << endl;
	cin >> num_toros;

	cout << " introduce la velocidad de los toros que no sea mayor de 100 " << endl;
	cin >> toros;
	
	if (toros >= 100){
		pasado = true;
		cout << " amigo te has pasado de la velocidad " << endl;
	}else{ 
		resultado = toros;
		corredor = toros;
	}
	for (int i = 0; contador <= num_toros && pasado == false; i++){
		do {
			cout << " introduce la velocidad de los toros que no sea mayor de 100 " << endl;
			cin >> toros;
			contador++;

			if (toros >= 100){
				cout << " amigo te has pasado de velocidad " << endl;
				pasado = true;
			}

			
			cout << " corredor vale " << corredor << " resultado vale " << resultado << endl;
			
			if(toros > resultado && toros <= 100){
				corredor = toros;
				//cout << " entra en el if de corredor " << corredor << endl;
			}
		}while (contador <= num_toros && toros <= 100);
		
		
	}
	cout << " los corredores tienen que ir a la velocidad de " << corredor << " para que no lo pille el toro " << endl; 
}
#include <iostream>
#include <cmath>
using namespace std;

struct Tiempo{
	int hora;
	int minuto;
	bool am;
	int segundos;
};

void introducir(Tiempo &a){
	cout << " introducela  hora  minuto  segundo  am con espacios " << endl;
	cin >>  a.hora >>  a.minuto >>  a.segundos >>  a.segundos >>  a.am;
}
void resultado (Tiempo ahora){
	cout <<" hora = " << ahora.hora << " minuto " << ahora.minuto << " segundo " << ahora.segundos << " am " << ahora.am << endl;
}
int main(){
	Tiempo ahora;

	ahora.hora = 2;
	ahora.minuto = 30;
	ahora.am = false;
	ahora.segundos = 15;
	
	cout << " la hora es con valores introducidos en el main " << endl;
	resultado(ahora);

	introducir(ahora);

	cout << " la hora con valores introducidos por el usuario " << endl;
	resultado(ahora);

}
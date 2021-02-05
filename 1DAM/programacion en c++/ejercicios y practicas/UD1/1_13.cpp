#include <iostream>
#include <cmath>
#include <iostream>
using namespace std;
int main () {
	int segundos;	
	double horas, minutos, dias; 
	
	cout << "itroduce la cantidad de segundos:";
	cin >> segundos;
	
	horas=segundos/3600;
	minutos= segundos/60;
	dias= horas/24;
	
	cout<< "minutos:" << minutos<< endl;
	cout<< "horas:" << horas << endl;
	cout<< "dias:" << dias << endl;
}

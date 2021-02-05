#include <iostream>
#include <cmath>
using namespace std;
int main () {
	// 5 notas de un alumno guardarlas en la misma funcion y decir si esta aprobado o suspenso.
	int nota[5];
	int media=0;
	int suma=0;
	
	for (int i=0; i<5; i++){
	cout << "introduce las notas del examen" << endl;
	cin >> nota[i];
	suma += nota[i];
	}	
	media= suma/5;
	cout << media << endl;
	
	if (media>=5){
		cout << " estas aprobado";
	}
	else if (media<5) {
		cout << " estas suspenso ";
	}
}

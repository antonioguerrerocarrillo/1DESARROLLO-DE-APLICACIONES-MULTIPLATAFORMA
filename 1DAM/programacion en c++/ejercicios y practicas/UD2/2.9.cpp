#include <iostream>
#include <cmath>

using namespace std;
int main (){
	int nota = 0;

	cout << " introduce la nota del alumno " << endl;
	cin >> nota;

	if (nota < 5){
		cout << " estas suspenso " << endl;
	}
	else if (nota<=7)	
		 cout << "aprobado" << endl;
		 
		else if (nota<=9)
		 cout << "notable" << endl ;

		else if (nota<=10)
		 cout << "sobresaliente" << endl; 		
}

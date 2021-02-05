#include <iostream>
#include <cmath>
using namespace std;
int main () {
	int c1 = 0, r1 = 0, x1 = 0, y1 = 0;
	int c2 = 0, r2 = 0, x2 = 0, y2 = 0;
	int diametro = 0;
	//declaramos las variables.
	cout << "introduce 1 la cordenadas y su radio. " << endl;
	cin >> x1 >> y1 >> r1;
	//pedimos las cordenadas.	
	
	cout << " introduce 2 cordenadas y su radio. " << endl;
	cin >> x2 >> y2 >> r2;
	
	diametro = sqrt ((pow((x1-x2),2)) + (pow ((y1-y2),2)));
	
	if ((x1 == x2) && (y1 == y2) && (r1 == r2)) {
	cout << "la circuferencia esta super puesta " << endl; 
	}

	else if (diametro > (r1+r2));
	cout << "la circuferencia no se tocan " << endl;
	
	else if (diametro < (r1+r2));
	cout << "la circuferencia se cortan " << endl;
	
	else if ((x1 == x2) && (x1 == y2) && (r1 > r2) || (r2 > r1));
	cout << "tienen el mismo radio pero uno es mas pequeño " << endl;
	
	else if ((diametro == r1) || (diametro == r2) && (r1 < r2) || (r2 < r1));
	cout << " se encuentran dentro pero ni su diametro ni su radio son iguales " << endl;
	
}

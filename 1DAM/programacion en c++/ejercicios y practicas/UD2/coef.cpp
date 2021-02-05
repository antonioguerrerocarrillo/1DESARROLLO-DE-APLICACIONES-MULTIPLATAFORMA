#include <iostream>
#include <cmath>

using namespace std;

int main(){
	double x1 = 0, x2 = 0, a = 0, b = 0, c = 0; 

	cout << " introduce el coef 2 grado " << endl;
	cin >> a;

	cout << " introduce coef del 1 grado " << endl;
	cin >> b;

	cout << "introduce el coef independiente " << endl;
	cin >> c;

	if (a != 0) {
		x1 = (-b + sqrt( b*b -4 *a*c)) / (2*a);
		x2 = (-b - sqrt( b*b -4 *a*c)) / (2*a);

		cout << " las raices son " << x1 << " y " << x2 << endl;
	} else  
		cout << " solo una raiz "  << -c/b << endl;
}
#include <iostream>
#include <cmath>
using namespace std;
int main () {
	double a = 0, b = 0, c = 0, x1 = 0, x2 = 0, raiz = 0;
	
	cout << "introduce a: b: c: ";
	cin >> a >> b >> c;
	
	raiz = sqrt (b*b -4*a*c);
	x1= -b + raiz / 2*a;
	x2= -b - raiz / 2*a;
	
	cout << "x1= "<< x1 << endl;
	cout << "x2= " << x2 << endl;
}

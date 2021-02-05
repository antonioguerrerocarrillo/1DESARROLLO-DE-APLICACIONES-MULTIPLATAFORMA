#include <iostream>
#include <cmath>

using namespace std;

int main(){
	double pi0 = 0, pi1 = 0, pi2 = 0;
	double x0 = 0, x1 = 0, y1 = 0;
	double x2 = 0, y2 = 0;
	
	pi0 = 2 + sqrt(2.0);
	cout << "El valor de pi0 es: " << pi0 << endl;

	x0 = sqrt(2.0);
	y1 = pow(2,(1.0/4.0));
	x1 = (1.0/2.0)*(sqrt(x0)+(1.0/sqrt(x0)));
	pi1 = pi0 * ((x1+1)/(y1+1));
	cout << "El valor de pi1 es: " << pi1 << endl;
	
	x2 = (1.0/2.0)*(sqrt(x1)+(1.0/sqrt(x1)));
	y2 = (y1 * sqrt(x1) + (1.0/sqrt(x1)))/(y1 + 1);
	pi2 = pi1 * ((x2+1)/(y2+1));	
	cout << "El valor de pi2 es: " << pi2 << endl;
}

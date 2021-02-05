#include <iostream>
#include <cmath>
using namespace std;

double f1 (double x, double y){
	double i, j;
	double z = 3;

	for (double i = x; i < y; i++){
		double z;
		z = (i - x);
		j = z / (y-x);

		cout << " j = " << j << endl; 
		cout << " z = " << z << endl;
		cout << " i = " << i << endl;
	}
	cout << " x = " << x << " y = " << y << endl;

	return z;
}

int main(){
	double x1 = 8, y1 = 34;

	f1(x1, y1);

	cout << "main,  x = "  << x1 << " y = " << y1 << endl;
	cout << "por defecto x vale 2, y vale 4, z = " << f1(x1, y1) << endl;
}
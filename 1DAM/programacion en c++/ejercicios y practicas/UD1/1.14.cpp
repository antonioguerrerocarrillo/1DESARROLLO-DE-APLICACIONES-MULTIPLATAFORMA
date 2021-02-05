#include <iostream>
#include <cmath>
using namespace std;
int main () {
	double x1 = 0, x2 = 0, x3 = 0, m = 0, desviacion = 0;
	
	cout << "introduce el valor x1 x2 x3";
	cin>> x1 >> x2 >> x3;
	
	m= (x1+x2+x3)/3;
	desviacion= sqrt((pow(x1-m),2) +(pow (x2-m),2) +(pow (x3-m),2)/3);
	
	cout << "media:" << m << endl << "desviacion:" << desviacion << endl;
}

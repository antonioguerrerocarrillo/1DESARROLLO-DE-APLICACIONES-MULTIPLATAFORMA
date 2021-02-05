#include <iostream>
#include <cmath>
using namespace std;
int main () {
	int i = 0, a = 0;

	for (a = 1; a <= 10; a++){
		cout << " tabla del " << a << endl;
		for (i = 1; i <= 10;i++){
			cout << a << " x " << i << " = " << a * i << endl;
		}
 	}
}
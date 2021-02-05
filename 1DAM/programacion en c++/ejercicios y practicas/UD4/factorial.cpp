#include <iostream>
#include <cmath>
using namespace std;

int factorial(int n){
	int f = 0;

	if( n == 0){
		f = 1;
	}
	else {
		cout << " debug entra antes de llamada " << n << " su preme " << endl;
 		f = n * factorial(n-1);
		cout << " valor de n " << n;
		cout << " valor de f " << f << endl;
	}
	return f;
}
void pedir_usuario(int &n){
	
	cout << " introduce el numero del factorial que quieres calcular " << endl;
	cin >> n;
}
void resultado (int res){
	
	cout << " el resultado es " << res << endl;

}
int main(){
	int n = 0, res = 0;

	pedir_usuario(n);

	res = factorial(n);
	
	resultado(res);
	
}
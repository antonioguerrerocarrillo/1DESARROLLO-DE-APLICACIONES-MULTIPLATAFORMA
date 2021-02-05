#include <iostream>
#include <cmath>
using namespace std;
bool vectorprimo (int saberprimo) {;
	bool primo= true;
	int contador=0;
	
	for (int a=1; a<=saberprimo ;a++){
		if (saberprimo%a==0){
		contador++;		
			}
		}	
		if (contador==2){
			primo= true;
		}
		else 
			primo=false; 
	return primo;
}
int main () {
	int vector [1000];
	int contador=0;
	for (int i=0; i<1000; i++){
		if (vectorprimo(i)){//funcion primo
			vector[contador]= i;
			contador++;
		}
	}
	for (int i=0; i<contador; i++){
		cout << vector [i]<< endl;
	}
}

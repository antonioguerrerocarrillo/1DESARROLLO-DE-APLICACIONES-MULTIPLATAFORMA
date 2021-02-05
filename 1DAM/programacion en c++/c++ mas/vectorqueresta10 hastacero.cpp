#include <iostream>
#include <cmath>
using namespace std;
int hola () {
	int vector[10];
	
	for (int i=0; i<10; i++){
		vector [i]=10 -i; // hacer dos vectores siempre, en este haces la operacion
		
	}	
	for(int i=0;i<10;i++)
	{
		cout << vector[i] << endl; // el mismo for solo que mostramos el cout
	}
}
int main (){
	hola();
}

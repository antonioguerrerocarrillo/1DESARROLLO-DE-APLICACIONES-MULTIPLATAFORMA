#include <iostream>
#include <cmath>
using namespace std;
	int hola (){
	int vector[1000];
	int res=0;
	
	for (int i=0; i<1000; i++){
		vector [i]=2*i; // hacer dos vectores siempre, en este haces la operacion
		res +=vector [i];  
			
	}	
	for(int i=0;i<1000;i++)
	{
		cout << vector[i] << endl; // el mismo for solo que mostramos el cout
	
	}
	cout <<" resultado "<< res << endl;
}
int main (){
	hola ();
}

#include <iostream>
#include <cmath>
using namespace std;

void imprime (int vector[], int util_vector){
	
	for (int i = 0; i < util_vector; i++){
		cout << " imprimiendo el numero por 2 = " << vector[i] << endl;


	}
}

void calculo (int vector[], int util_vector){

	for (int i = 0; i < util_vector; i++){
		vector[i] *= 2;
	}

}


int main (){
	int dim_v = 100;
	int vector[dim_v] = {2,3,4};
	int util_vector = 3;

	calculo(vector, util_vector);
	imprime(vector, util_vector);


}
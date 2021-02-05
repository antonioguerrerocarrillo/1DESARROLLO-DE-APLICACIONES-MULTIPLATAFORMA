#include <iostream>
#include <cmath>
using namespace std;
int main (){
	// la dimension del vector 2 sera igual de grande que la dimension del vector1
	int dim_vec1 = 30, dim_vec2 = dim_vec1;
	//declaramos 3 valores para poder intercambiarlos
	int vector1[dim_vec1] = {1,2,3}, vector2[dim_vec2];
	// la util del vector2 llegara hasta la util del vector1
	int util_vector1 = 3, util_vector2 = util_vector1;

	for (int i = 0; i < util_vector1; i++){
		vector2[i] = vector1[i];

		cout << " lo que hay dentro de las celdas del vector 2 es " << vector2[i] << endl;
	}
}
#include <iostream>
#include <cmath>
using namespace std;
void borrar_numero(int vector[], int &util_vector, int vector2[], int &util_vector2){
	
	for (int i = 0; i < util_vector; i++){
		if (vector[i] != vector[i-1]){
			//cout << "entrada en el for. "<< endl;
			vector2[util_vector2] = vector [i];
			util_vector2++;
		}
	}
}
void imprimir(int vector[], int util_vector){
	cout << " mostrando el vector; " ;
	for (int i = 0; i < util_vector; i++){
		cout << vector[i] << " ";			
	} 
	cout << " ; " << endl; 
}
int main (){
	int dim = 1000;
	int vector[dim] = {1,2,4,3,4,5,5,6,6,7}, vector2[dim] = {0};
	int util_vector = 10, util_vector2 = 0;

	borrar_numero(vector, util_vector, vector2, util_vector2);
	
	cout << " mostrando el vector con numeros repetidos " << endl;
	imprimir(vector, util_vector);

	cout << " mostrando el vector sin numeros repetidos " << endl;
	imprimir(vector2, util_vector2);

}
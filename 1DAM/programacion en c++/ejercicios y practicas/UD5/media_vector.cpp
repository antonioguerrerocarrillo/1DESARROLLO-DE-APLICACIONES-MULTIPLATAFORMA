#include <iostream>
#include <cmath>
using namespace std;
void pedir (int NUM_NOTAS, double notas[]){

	for (int i = 0; i < NUM_NOTAS; i++){
		do{
			cout << " introduce las notas " << endl;
			cin >> notas[i];
		}while (notas[i] >= 10);
	}	
}

double calcular_media (int NUM_NOTAS, double media, double notas[]){

	for (int i = 0; i < NUM_NOTAS; i++){
		media = media += notas[i];
	}

	media = media / NUM_NOTAS;

	return media;
}
void mostrar_res(double res){
	cout << " la media es " << res << endl;
}
int main (){
	const int NUM_NOTAS = 5;
	double notas[NUM_NOTAS];
	double media = 0, res = 0;

	pedir (NUM_NOTAS, notas);
	res = calcular_media(NUM_NOTAS, media, notas);
	mostrar_res(res);

}
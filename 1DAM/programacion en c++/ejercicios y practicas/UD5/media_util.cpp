#include <iostream>
#include <cmath>
using namespace std;
void pedir_util (int &dimension_util, int dimension){
	cout << " introduce todas las notas que vas a poner 1 y " << dimension << endl;
	cin >> dimension_util;
}
void pedir_notas (int util_notas, double media, double notas[]){

	for (int i = 0; i < util_notas; i++){
		do{
			cout << " introduce las notas " << endl;
			cin >> notas[i];
		}while (notas[i] >= 10);
	}	
}

double calcular_media (double media, double notas[], int &util_notas){

	for (int i = 0; i < util_notas; i++){
		media = media += notas[i];
	}

	media = media / util_notas;

	return media;
}
void mostrar_res(double res){
	cout << " la media es " << res << endl;
}
int main (){
	int util_notas = 0;
	const int NUM_NOTAS = 100;
	double notas[NUM_NOTAS];
	double media = 0, res = 0;

	pedir_util(util_notas, NUM_NOTAS);
	pedir_notas (util_notas, media, notas);
	res = calcular_media(media, notas, util_notas);
	mostrar_res(res);

}
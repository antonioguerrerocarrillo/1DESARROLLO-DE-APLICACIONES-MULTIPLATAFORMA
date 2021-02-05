#include <iostream>
#include <cmath>
using namespace std;

void pedir_util (int &dimension_util, int dimension){
	cout << " introduce todas las notas que vas a poner 1 y " << dimension << endl;
	cin >> dimension_util;
}

void pedir (int util_notas, double notas[]){

	for (int i = 0; i < util_notas; i++){
		do{
			cout << " introduce las notas " << endl;
			cin >> notas[i];
		}while (notas[i] >= 12);
	}	
}

double calcular_media (int util_notas, double media, double notas[]){

	for (int i = 0; i < util_notas; i++){
		media = media += notas[i];
	}

	media = media / util_notas;

	return media;
}
void calcularvarianza (const int util_notas, double nota[], double &varianza, double media) {
	//la varianza es la suma de la media 
	for (int i=0; i < util_notas; i++) { //esta es la varianza 
		varianza += (pow(media,2)); //+= es la sumatoria
	}	
}
double desviacion_tipica(double varianza){
	double res = 0;

	res = sqrt(varianza);

	return res;
}

void mostrar_res(double res, double desviacion_res, double varianza){
	cout << " la media es " << res << endl;
	cout << " el resultado de las desviacion tipica es " << desviacion_res << endl;
	cout << " la varianza es " << varianza << endl;
}
int main (){
	const int NUM_NOTAS = 100;
	double notas[NUM_NOTAS];
	int util_notas = 0;
	double media = 0, res = 0, res_desviacion = 0, varianza = 0;

	pedir_util(util_notas, NUM_NOTAS);
	pedir (util_notas, notas);
	res = calcular_media(util_notas, media, notas);
	calcularvarianza (util_notas, notas, varianza, res); 
	res_desviacion = desviacion_tipica(varianza);
	mostrar_res(res, res_desviacion, varianza);

}
#include <iostream>
#include <cmath>
using namespace std;
void pedir (int NUM_NOTAS, double notas[]){

	for (int i = 0; i < NUM_NOTAS; i++){
		do{
			cout << " introduce las notas " << endl;
			cin >> notas[i];
		}while (notas[i] >= 12);
	}	
}

double calcular_media (int NUM_NOTAS, double media, double notas[]){

	for (int i = 0; i < NUM_NOTAS; i++){
		media = media += notas[i];
	}

	media = media / NUM_NOTAS;

	return media;
}
void calcularvarianza (const int NUM_NOTAS, double nota[], double &varianza, double media) {
	//la varianza es la suma de la media 
	for (int i=0; i < NUM_NOTAS; i++) { //esta es la varianza 
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
	const int NUM_NOTAS = 5;
	double notas[NUM_NOTAS];
	double media = 0, res = 0, res_desviacion = 0, varianza = 0;

	pedir (NUM_NOTAS, notas);
	res = calcular_media(NUM_NOTAS, media, notas);
	calcularvarianza (NUM_NOTAS, notas, varianza, res); 
	res_desviacion = desviacion_tipica(varianza);
	mostrar_res(res, res_desviacion, varianza);

}
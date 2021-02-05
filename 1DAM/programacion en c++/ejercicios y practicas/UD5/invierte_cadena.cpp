#include <iostream>
#include <cmath>
using namespace std;

void imprimecadena(int util, char v[]){
	for (int i = 0; i < util; i++){
		cout << v[i];
	}
	cout << " " << endl;
}
int longitud (const char cadena[]){
	int i = 0;
	
	while (cadena[i] != '\0'){
		i++;
	}

	return i;
}
void imprime_longitud (const int longitud){
	cout << " la longitud de la cadena es " << longitud << endl;
}
void invierte_cadena (const char v[], const int util, char v_salida[], int &util_salida){
	util_salida = util;
	for (int i = 0; i < util; i++){
		v_salida[util_salida] = v[i];
		util_salida--;
	}
	util_salida = util +1;
}
int main (){
	int dim = 100;
	char entrada[dim] = {'o','l','i',' ','v','i','a','\0'};
	int util_salida = 0;
	char salida[dim];
	int res_util = 0;

	res_util = longitud(entrada);
	imprime_longitud(res_util);

	cout << " imprimiendo antes de quitar_espacios " << endl;
	imprimecadena(res_util, entrada);

	invierte_cadena(entrada, res_util, salida, util_salida);

	cout << " imprimiendo despues de invertir la cadena " << endl;
	imprimecadena(util_salida, salida);


}
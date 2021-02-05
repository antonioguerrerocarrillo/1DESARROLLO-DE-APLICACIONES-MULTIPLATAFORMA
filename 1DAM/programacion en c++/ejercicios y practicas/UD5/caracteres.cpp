#include <iostream>
#include <cmath>
using namespace std;
void quitar_espacios(char entrada[], int util_ent, char salida[], int &util_s){
	for (int i = 0; i < util_ent; i++){
		if (entrada[i] != ' '){
			salida[util_s] = entrada[i];
			util_s++;
		}
	}
}
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

	quitar_espacios(entrada, res_util, salida, util_salida);

	cout << " imprimiendo despues de quitar_espacios " << endl;
	imprimecadena(util_salida, salida);


}
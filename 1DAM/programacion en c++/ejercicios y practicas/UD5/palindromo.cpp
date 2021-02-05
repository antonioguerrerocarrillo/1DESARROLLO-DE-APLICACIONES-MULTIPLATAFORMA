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
void quitar_espacios(char entrada[], int util_ent, char salida[], int &util_s){
	for (int i = 0; i < util_ent; i++){
		if (entrada[i] != ' '){
			salida[util_s] = entrada[i];
			util_s++;
		}
	}
}
void imprime_longitud (const int longitud){
	cout << " la longitud de la cadena es " << longitud << endl;
}

bool espalindromo( char v[], int util, int dim){
	char v2[dim];
	int longitud = 0;
	bool palindromo = true;
	//llama a la funcion para quitar los espacios, asi tengo tambien la longitud, y todo lo que contiene el vector
	quitar_espacios(v, util, v2, longitud);

	for (int i = 0; i < longitud /2 && palindromo; i++){
		if (v2[i] != v2[longitud-1-i])
			palindromo = false;
	}

	return palindromo;
}
int main (){
	int dim = 100;
	char entrada[dim] = {'a','m','i','s',' ','a','\0'};
	int util_salida = 0;
	char salida[dim];
	int res_util = 0;

	//llamamos a la funcion para calcular cuanto mide la util total
	res_util = longitud(entrada);
	//imprime la longitud
	imprime_longitud(res_util);
	//imprime la cadena de caracteres
	imprimecadena(res_util, entrada);
	//te dice si es palindromo
	if (espalindromo(entrada, res_util, dim)){
		cout << " es palindromo " << endl;
	}
	else {
		cout << " no es palindromo " << endl;
	}

}
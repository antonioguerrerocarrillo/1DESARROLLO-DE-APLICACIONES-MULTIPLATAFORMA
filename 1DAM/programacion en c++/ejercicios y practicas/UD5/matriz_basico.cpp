#include <iostream>
#include <cmath>
using namespace std;
//declaracioin para poder usar las columnas y filas del vector
const int COL = 100, FIL = 100;

void pedir_usuario(int &util_col,int &util_fil){
	cout << " dime cuantas filas vas a usar " << endl;
	cin >> util_fil;

	cout << " dime cuantas columnas vas a usar " << endl;
	cin >> util_col;
}
void introducir_elementos (double matriz[][COL], int util_col,int util_fil){
	for (int f = 0; f < util_fil; f++){
		for (int c = 0; c < util_col; c++){
			cout << " introducir elemento " << f << " y " << c << endl;
			cin >> matriz[f][c]; 
		}
	}
}
void imprimir_matriz (double matriz[][COL], int util_col,int util_fil){
	cout << " imprimiendo matriz " << endl;

	for (int f = 0; f < util_fil; f++){
		for (int c = 0; c < util_col; c++){
			cout << " " << matriz[f][c];
		}
		cout << " "<< endl; 
	}
}
/**
 * @brief funcion que pide al usuario el numero que quiere buscar
 * @info lo guardamos en n
 * @param n lo pasamos por referencia ya que la vamos a cambiar
 * @post devolvemos el numero que queremos buscar
 */
void pide_usuario(double &n){
	cout << " de los numeros cuales quieres buscar " << endl;
	cin >> n;
} 
void ordenacion_selecion (double vector[], int util_vector){
	int pos_min = 0;
	int aux = 0;
	//cout << " ordenando el vector " << endl;
	//util <= para que pare en una antes de lo que suele parar
	for (int i = 0; i <= util_vector; i++) {
		//guardo la i en posicion_min
		pos_min = i;
		//j = i+1 ya que sera la siguiente posicion... cada vez que lo ejecute, parara en la util estricto
		for (int j = i+1; j < util_vector; j++) {
			//si lo que hay en la posicion de [j] que es la siguiente es menor que la anterior entra 
			// asi vamos a ordenar si lo pusiera > lo ordenaria de mayor a menor, asi lo ordenara de menor a mayor
			if (vector[j] < vector[pos_min]){
				//guardo en la poscion j ya que es menor
				pos_min = j;
			}
		}
		// guardo la posicion de i en aux
		aux = vector[i];
		//guardo la pos_min en el vector
		vector[i] = vector[pos_min];
		// y por ultimo lo que contiene el aux lo guardo en la pos_min y ya estaria ordenado el vector
		vector[pos_min] = aux;
	}
}
/**
 * @brief funcion que busca el numero que nos ha introducido el usario
 * @info usaremos un bucle y un if para cuando sea corrector entrar en dicho vector, guardamos en otro vector todas las veces encontrado y la posicion de dicho numero
 * @param le pasamos el v como constate ya que no lo vamos a modificar solo vamos a leer
 * @para le pasamos la utiles como constante ya que es hasta donde vamos a repetir el bucle y no lo vamos a modificar
 * @post devolvemos la posicion donde esta ese numero una vez encontrado
 * @return devolvemos la posicion donde esta el numero encontrado
 */
double busqueda_usuario (double m[][COL], int util_col, int util_fil, double n, bool &encontrado, double &fila,double &posicion){
	double res = 0;
	//cout << " dentro de la busqueda_usuario " << endl;

	for (int f = 0; f < util_fil && encontrado != true; f++){
		//cout << "primer for valor de f " << f << endl;
		for(int c = 0; c < util_col && encontrado != true; c++){
			ordenacion_selecion(m[c], util_col);
			//cout << " 2 for valor de c " << c << endl;
			if(m[f][c] == n){
				//cout << " dentro del if valor de f " << f << " valor de c " << c << endl;
				res = m[f][c];
				fila = f;
				posicion = c;
				encontrado = true;
			}
		}
	}
	return res;
}
void resultado_busqueda(bool bus, double resultado, double fila, double posicion){

	if(bus == true){
		cout << " ten encuenta que empieza en la fila 0 y posicion 0 " << endl;
		cout << " mostrando fila " << fila << " mostrando posicion " << posicion << endl;
		cout << " hemos encontrado el numero que es " << resultado<< endl;
	}else
		cout << " no se a encontrado el numero " << endl;
}
void llamada_busqueda(double matriz[][COL], int util_col, int util_fil){
	//busqueda y ordenacion de una matriz
	int aux = 0;
	for (int f = 0; f < util_fil; f++){
		//cout << "primer for valor de f " << f << endl;
		for(int c = 0; c < util_col; c++){

			for (int k = 0; f < util_fil; f++){
		//cout << "primer for valor de f " << f << endl;
				for(int l = 0; c < util_col; c++){
					if(matriz[k][l] > matriz[f][c]){
						aux = matriz[f][c];
						matriz[f][c] = matriz[k][l];
						matriz[k][l] = aux;
					}
				}
			}
		}
	}
}
int main(){
	double matriz[FIL][COL] = {0};
	int util_col = 0, util_fil = 0;
	bool buscado = false;
	double numero = 0, res = 0, fila = 0, posicion = 0;

	pedir_usuario(util_col, util_fil);

	introducir_elementos(matriz, util_col, util_fil);

	imprimir_matriz(matriz, util_col, util_fil);

	pide_usuario(numero);

	res = busqueda_usuario (matriz, util_col, util_fil, numero, buscado, fila, posicion);

	resultado_busqueda(buscado, res, fila, posicion);

	llamada_busqueda(matriz, util_col, util_fil);

	cout << "imprimiendo columnas ordenadas " << endl;
	imprimir_matriz(matriz, util_col, util_fil);

}

/**
 * @brief vamos a mostrar los numeros del vector con repetidos y del vector2 sin repetidos.
 * @param ponemos el for para que lo repita hasta que llegue al numero maaximo del util.
 * @param lo mostramos con un cout.
 */

int mostrarvector (const int vector[],const int util_vector, int vector2[], int contador) {
	cout << DEBUG << "debug: Entrada para mostrar resultado..." << RESTORE << endl;
	
	for (int i; i < util_vector; i++){
		cout << DEBUG << "debug: Entrada en el bucle para mostrar .." << RESTORE << endl;
		cout << vector[i] << endl; 
		cout << vector2[contador] << endl;
	}	
}
void numerovector (const int vector[], const int util_vector, int &contador) {

	int N_VECTOR2 = 1000;
	int vector2 [N_VECTOR2];
	const int util_vector2 = 0;	
	int rep = 0;

	//cout << DEBUG << "debug: Entrada numero vector..." << RESTORE << endl;
		
	for (int i; i < util_vector; i++){
		if (rep == vector [i+i]){
			rep = vector [i];
			vector2 [contador] = vector [i];
			contador++;
		}
	} 

	mostrarvector(vector,util_vector, vector2,contador);
	mostrarvector(vector,util_vector, vector2,contador);
	
}

int main (){

	int N_VECTOR = 1000;
	int vector [N_VECTOR];
	int util_vector = 0;
	int contador = 0;
	
	cout<< "introduce el util: " << endl;
	cin >> util_vector;
	
	for(int i=0; i < util_vector; i++)
	{
		cout << " escribe los numeros para saber si son contiguos: ";
		cin >> vector[i];
	}
	
	numerovector (vector, util_vector, contador);
}

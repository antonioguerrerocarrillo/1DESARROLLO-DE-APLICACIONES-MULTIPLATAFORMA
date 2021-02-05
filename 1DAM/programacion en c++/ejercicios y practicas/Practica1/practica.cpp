/** 
* @autor Antonio José Guerrero Carrillo
* @info practica del 1 trimestre
* @info usando variables, funciones, bucles y algunas bibliotecas. UD1, UD2 y UD3.
*/
#include <iostream>
#include <cmath>
#include <stdio.h>
#include <string>
#include <stdlib.h>
#include <iomanip>
// define son los colores para algunos cout
#define BLACK_COLOR "\033[1;30m"
#define RED_COLOR "\033[1;31m"
#define GREEN_COLOR "\033[1;32m"
#define YELLOW_COLOR "\033[1;33m"
#define BLUE_COLOR "\033[1;34m"
#define PURPLE_COLOR "\033[1;35m"
#define CYAN_COLOR "\033[1;36m"
#define WHITE_COLOR "\033[1;39m"
#define RESTORE_DEFAULT_COLOR "\033[0m"

using namespace std;
/**
 * @brief funcion que nos va a decir si un numero es primo devolviendo una funcion booleana
 * @info de volvera si es verdad o es falso
 * @pre le pasamos el numero con int numero, y la funcion bool contador
 * @post de volvera si es true o false  despues de realizar el for
 * @return contador de vovlera 1 o 0
 */
bool primo(int numero, bool contador){

for (int i = 2; i <= numero -1 && contador != true; i++){	
		if(numero % i == 0)
			contador = true;
	}
	return contador;
}
/**
 * @brief funcion usada para filtrar numeros enteros
 * @info no va a devolver nada, usamos cin.fail con su biblioteca correspondiente para que funcione esta funcion que llamamos
 * @pre le pasamos el numero que deseamos filtrar
 */
int filtros (int numero){

	while(cin.fail()){
		cout<< "Repite el valor "<<endl; 
		cin.clear();
		cin.ignore(256,'\n');        	
		cin >> numero;
	}
}
/**
 * @brief funcion usada para filtra los char
 * @info no va a devolver nada, usamos cin.fail con su biblioteca correspondiente para que funcione esta funcion que llamamos
 * @pre le pasamos el numero que deseamos filtrar
 * @param cuando usemos un valor que no sea el que nosotros queremos como podria ser una @ le decimos que vuelva a introducir uno correcto
 */
char filtro_char(char menu){
	while(cin.fail()){
		cout<< "Repite el valor "<<endl; 
		cin.clear();
		cin.ignore(256,'\n');        	
		cin >> menu;
	}
}
string filtro_string(string menu){
	while(cin.fail()){
		cout<< "Repite el valor "<<endl; 
		cin.clear();
		cin.ignore(100,'\n');        	
		cin >> menu;
	}
}
/**
 * @brief número cabalístico. Este número estaría descompuesto en sus factores primos y cada
 * factor aparecería en la secuencia como la longitud de cada secuencia concreta de valores 1. Por ejemplo la secuencia anterior codificaría
 * los números primos 3, 2, 2 y 7, lo que nos da el número cabalístico 84 = 3 x 2 x 2 x 7. Se pide construir un programa
 * que lea la secuencia de números, calcule el número codificado y determine si el número oculto es cabalístico o no.
 * @pre no le pasamos nada
 * @post como es void no va a devolver nada
 * @param para es la varible que va contar cuantos 0 seguidos pulsamos para cuando llevemos 5 parar el bucle
 * @param numero es la variable donde guardamos los numeros introducidos por el teclado
 * @param sumatoria2 es donde vamos almacenar resultado total
 * @param auxiliar el contador total
 * @param numero_primo cuando el numero sea primo la pondremos a true.
  */
void cabalistico() {
	int numero = 0, para = 0, auxiliar = 0, sumatoria2 = 1, cabalistico_contador = 0;
	bool numero_primo = false;
	
	cout << " introduce los numeros para realizar el cabalistico parara cuando introduzcas " << endl;
	
	while (para < 5){
		cin >> numero;
		filtros(numero);

		if (numero == 0){
				para++;
				//entrada++;
		}
		else {
			para = 0;
		}

		
		if (numero != 0){
			auxiliar++;
			//cout << " valor de auxiliar " << auxiliar << endl;
			
		} else if(numero != 0 || auxiliar != 0) {
				sumatoria2 = sumatoria2 * auxiliar;
				cout << " " << auxiliar << " * " ;
				
				if(primo(auxiliar, numero_primo) == true){
					//cout << " este numero no es primo " << endl;
					cabalistico_contador++;
					}
				auxiliar = 0;	
			}
	}
	//cout << " valor de cabalistico_contador " << cabalistico_contador << endl;
	if(cabalistico_contador == 0)
		cout << " = " << BLUE_COLOR << sumatoria2 << " si -> es cabalastico " << RESTORE_DEFAULT_COLOR<< "\t" << endl;
	else
		cout << " = " << RED_COLOR << sumatoria2 << " no -> es cabalastico " << RESTORE_DEFAULT_COLOR<< "\t" << endl;	//cout << " los numeros cabalisticos son " <<  sumatoria << endl;
	//cout << " resultado " << resultado << endl;
}
/**
 * @brief ENTRADAS: El programa deberá leer, de la entrada estándar, un primer número indicando cuántos casos de prueba vendrán a
 * continuación. Cada caso de prueba constará de dos líneas, ambas de no más de 100 caracteres sin espacios. La primera conten-
 * drá el nombre del personaje y la segunda el parentesco.
 * @pre no le pasamos nada
 * @post como es void no va a devolver nada
 * @param varible sera donde almacenamos nombre del personaje y variable2 el parentesco
 * @param casos_prueba donde vamos a guardar las veces que queremos que se repita.
 * @param contador es un contador para repetir hasta que casos de prueba sea diferente de contador.
  */
void star_wars(){
	string variable = " " , variable2 = " ";
	int casos_prueba = 0, contador = 0;

	cout << YELLOW_COLOR  << " introduce cuantos casos de prueba van a ser " << RESTORE_DEFAULT_COLOR<< "\t" << endl;
	cin >> casos_prueba;
	filtros(casos_prueba);
	
	while(casos_prueba != contador){
		cout << " introduce el nombre " << endl;
		cin >> variable;
		//filtro_string(variable);
		cout << " introduce el parentesco " << endl;
		cin >> variable2;
		//filtro_string(variable2);
		contador++;
	
	if (variable == "Luke"  && variable2 == "padre"){
			cout << RED_COLOR << " TOP-SECRET "  << RESTORE_DEFAULT_COLOR<< "\t" << endl;
		}else
			cout << GREEN_COLOR << variable << " yo soy tu " << variable2 << RESTORE_DEFAULT_COLOR<< "\t" << endl;
	}

}
void star_wars_grafico(){
	cout << " programa 2 de la saga " << endl;
}
void bienvenida(){
	//ensenamos con los cout bienvenidos.
	cout << PURPLE_COLOR <<" bienvenido al programa de Antonio otro año mas ya que estamos muy agusto en el infierno. "<< RESTORE_DEFAULT_COLOR<< "\t" << endl; 
	cout << PURPLE_COLOR <<" practica final del primer trimestre. espero sacar un 10 minimo " << RESTORE_DEFAULT_COLOR<< "\t" << endl;
}

void salida(){
	cout << PURPLE_COLOR << " hasta luego amigo " << RESTORE_DEFAULT_COLOR<< "\t" << endl;
}

 /**
@brief hacemos los menus aqui mostraremos al usuario a que programa queremos ir pulsando la tecla correspondiente
@param para el menu usamos el switch
@return  no devuelve nada
@param al pulsar (a) el programa haremos el problema cabalistico, (b) star wars. (c) para el 2 ejerccio de star wars (s) para salir 
@info llamaremos a la funcion para filtrar los numeros y que solo funcione con los que nosotros le digamos.
**/
char menu_en_pantalla () {
	char menu ;	
	
	do{ //filtro
		cout << " introduce [a] para ir al problema del cabalistico " << endl;
		cout << " introduce [b] programa de star wars " << endl;
		cout << " introduce [c] programa de star wars monitor " << endl;
		cout << " o [s] para salir" << endl;
		cin >> menu;
		filtro_char (menu);
	}
	while(menu!='a' && menu!= 'b' && menu !='c' && menu !='s' ); 
	
	switch (menu) {
		case 'a':
			cabalistico();
			menu_en_pantalla();
		break;
		case 'b': 
			star_wars(); //invocacion de la variable para que lo coja y el sepa donde se tiene que ir al pulsar
			menu_en_pantalla();			
		break;
		case 'c':
			star_wars_grafico();
			menu_en_pantalla();		
		break;
		case 's':
			salida();
		break;
		 	
	}
	
}

int main () {
	// declaramos menu para que el programa se diriga a bienvenida y menu de pantalla despues.
	bienvenida();
	menu_en_pantalla();
}

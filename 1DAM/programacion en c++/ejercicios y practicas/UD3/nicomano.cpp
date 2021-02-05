#include <iostream>
#include <math.h>

using namespace std;
/**
 * @brief secuencia en el que se va a repetir hasta llegar al final y mostrara el resultado por pantalla.
 * @info llamamos a la funcion para sacar todos los numeros que vamos a multiplicar.
 * @pre le pasamos nicomano y aux por referencia, empezar por copia
 * @param resultado que guardaremos el total de todas las operaciones.
 * @param final que sera final donde empieza por nicomano por 2
 */
void secuencia(int &nicomano, int &aux, int empezar){
	int final = 0,resultado = 0;
	
	final = empezar + (nicomano * 2) -1;		

	for(int i = empezar;i < final; i = i +2){

		resultado = resultado +i;
		if (i == empezar){

			cout << i ;

		}else{
			cout << " + " << j;
		}
	}

	cout << " = " << resultado << endl;

}
/**
 * @brief una funcion que va empezara hasta llegar al numero nicomano
 * @pre le pasamos nicomano y aux por referencia
 * @param res sera donde guardaos el resultado  
 * @post cambiamos los valores de aux
 * @return devolvemos el resultado de aux *2 
 */
int empezarfun(int &nicomano,int &aux){
	int res = 0;

	for (int i = 0;i < nicomano; i++){

			aux = aux + i;
	
	}

	res = (aux * 2 ) + 1;

	return res;
}
/**
 * @brief funcion que le pedira los datos al usuario	
 * @info la pasamos por referencia ya que vamos a cambiar el valor de estas	
 * @pre le pasamos numero y numero2 lo hacemos por referencia ya que vamos a cambiar el valor de estas 
 * @post al pulsar la tecla cambiaremos el valor de las 2 variables
 */
void pedirnumero(int &a){
   
	cout << "escribe un numero:  ";
	cin>>a;
}
/**
 * @brief funcion que le imprime el resultado de todos los numeros del nicomano y la secuencia de numeros.
 * @pre le pasamos a,b y c por copia para poder imprimirlo 
 */
void imprimir(int a,int b,int c){

	cout << "el numero nicomano es = " << a << endl;
	secuencia(a,b,c);

}
int main (){
	int n = 0,aux = 0, res = 0, final = 0;

	pedirnumero(n);
	res = empezarfun(n,aux);
	imprimir(n,aux,res);
	
}
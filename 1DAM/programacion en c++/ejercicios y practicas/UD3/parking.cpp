#include <iostream>
#include <cmath>
#include <sstream>
using namespace std;
/**
 * @brief funcion que aplicara el valor del estacionamiento dependiendo del tiempo que lleve coche significara las horas
 * @info de volvera el resultado dependiendo del estacionamiento y del tiempo que lleve
 * @param coche por copia(horas), estacionamiento que es el valor por defecto 
 * @pre le pasamos el valor por defecto de estacionamiento y las horas que le hayamos pedido ya al usuario de los coches
 * @post de vuelve el res (valor que tenga dependiendo de las horas que lleve)
 * @return res ( resultado dependidendo de las horas que lleve)
 */
 double calculo(double coche, double estacionamiento){
 	double res = 0;

 	if (coche <= 3.0){
 		res =  2.0;
 	}
 	if (coche > 3.0){
 		//cout << " estacionamiento vale " << estacionamiento << endl;
 		res = estacionamiento + 0.50;
 	}
 	if (coche == 24.0){
 		res = 10;
 	}
 	if (coche >24.0){
 		res = 0;
 	}

 	return res;
 }
 /**
 * @brief funcion que convierte doublle en string 
 * @info llamamos a la biblioteca de string para poder convertir aux en un string 
 * @param aux es el valor para modificar por copia
 * @pre pasar ya el valor y llamar a la biblioteca de string
 * @post devolver este valor ya convertido
 * @return convertidor.str()
 */
 string convertidor (double aux){
 		
 		ostringstream convertidor;
 		
 		convertidor << aux;

 		return convertidor.str();
 }
  /**
 * @brief funcion que alamacena todo en un unico string para poder mostrar una vez hayamos cabado todo
 * @info almacena la cadena de caracteres para un uso posterior
 * @param posicion, horas, res por copia
 * @param cadena por referencia ya que le vamos a cambiar el valor de esta 
 * @pre pasar los valores para poder guardarlos
 * @post mostrar todos los valores juntos
 */
 void almacenarcadena(int posicion,double horas,string &cadena,double res){


 	if(posicion == 1){
 		//alamcena automovil horas y cargo, lo suma.
 		cadena += "Automovil\tHoras\tCargo\n";
 		//llama al convertidor y guardamos la posicion, las horas y res en el string para luego sumarlo
 		cadena += convertidor(posicion) + "\t\t" + convertidor(horas) + "\t" + convertidor(res) + "\n";
 	}
 	else{
 		cadena += convertidor(posicion) + "\t\t" + convertidor(horas) + "\t" + convertidor(res) + "\n";
 	}
 }
  /**
 * @brief este es el modulo mas complejo ya que sera un bucle que se repetira y va a llamar a mas funciones
 * @info vamos a pedirle al usuario las horas, y que siempre lleve por lo menos 1min
 * @param coche, res_total, horas_totales y cadena por referencia ya que van a ser de salida 
 * @oaram estacionamiento por copia ya que no queremos modificar su valor
 * @pre pasarle los valores por defecto
 * @post devolver las horas totales que lleva, el valor total, alamacenar todo en un string y imprimirlo
 */
 void imprimir(double &coche, double estacionamiento,double &res_total,double &horas_totales, string &cadena){
	double res = 0.0;

	for (int i = 1; i <= 3; i++){
		do{
			cout << " introduce las horas del vehiculo " << endl;
			cin >> coche;
		}while (coche <= 0.01);

		horas_totales = horas_totales + coche;
		res = calculo(coche, estacionamiento);
		//le paso i que es la posicion del "vector", las horas para convertirlo y res 
		almacenarcadena(i,coche,cadena,res);
		res_total = res + res_total;
	}
	//muestro el total de la cadena del string

}
 /**
 * @brief este es el modulo imprime el string y resultado total(el dinero total) y (horas totales), las horas y precio de cada vehiculo 
 * @info se lo pasamos ya todo 
 * @param res_total, horas_totales por referencia ya que van a ser de entrada y salida 
 * @oaram cadena por copia ya que no queremos modificar su valor
 * @pre pasarle ya todo resuelto para poder imprimirlo por pantalla
 * @post mostrar todo por pantalla al usuario	
 */	
void imprimir_res(double &res_total,double &horas_totales, string cadena){
	cout << cadena << endl;
	cout << " total del importe es: " << res_total -1 << " y  las horas totales es: " << horas_totales -1 << endl;
}
 int main(){
 	double estacionamiento = 2.0, conversion = 0.0;
 	double res_total = 1.0, horas_totales = 1.0;
	string cadena;
 	//el valor del coche es igual a las horas.
 	double coche = 0;

 	imprimir(coche, estacionamiento, res_total, horas_totales, cadena);
 	imprimir_res(res_total, horas_totales, cadena);

 	
 }
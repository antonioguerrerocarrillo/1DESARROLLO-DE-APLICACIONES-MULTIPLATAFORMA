#include <iostream>
using namespace std;
/**
 * @brief funcion que le pedira los datos al usuario	
 * @info la pasamos por referencia ya que vamos a cambiar el valor de esta
 * @pre le pasamos a y lo hacemos por referencia ya que vamos a cambiar el valor de esta
 * @post al pulsar la tecla cambiaremos el valor de las variable
 */
void introduce (double &a){
	
	cout << " itroduce la cantidad de segundos: " << endl;
	cin >> a;
}
/**
 * @brief calculo de horas, minutos y dias de los segundos introducidos		
 * @pre le pasamos horas, segundos, dias y minutos, lo hacemos por referencia ya que vamos a cambiar el valor de estas 
 * @post devolveremos la variables ya con las operaciones cambiadas.
 */
void calculo(double &horas, double &segundos, double &dias, double &minutos){

	horas = segundos / 3600;
	minutos = segundos / 60;
	dias = horas / 24;
}
/**
 * @brief mostramos por cout el resultado de minutos, horas y dias	
 */
void resultado (double a, double b, double c){
	cout<< " minutos: " << a << endl;
	cout<< " horas: " << b << endl;
	cout<< " dias: " << c << endl;
}


int main () {
	double segundos = 0, horas = 0, minutos = 0, dias = 0;
	
	introduce(segundos);
	calculo(horas, segundos, dias, minutos);
	resultado(minutos, horas, dias);

}

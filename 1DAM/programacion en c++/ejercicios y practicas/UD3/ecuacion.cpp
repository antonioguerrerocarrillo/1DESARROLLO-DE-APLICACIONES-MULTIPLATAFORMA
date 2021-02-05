#include <iostream>
#include <cmath>
using namespace std;
/**
 * @brief funcion que le pedira los datos al usuario	
 * @info la pasamos por referencia ya que vamos a cambiar el valor de estas	
 * @pre le pasamos a,b y c y lo hacemos por referencia ya que vamos a cambiar el valor de estas 
 * @post al pulsar la tecla cambiaremos el valor de las 3 variables
 */
void introduce(double &a, double &b, double &c){
	
	cout << "introduce a: b: c: ";
	cin >> a >> b >> c;
}
/**
 * @brief funcion que va a calcular la ecuacion de 2 grado 
 * @info sacamos la raiz, x1 y x2
 * @pre pasamos a, b, c, raiz, x1, x2. la pasamos por referencia ya que vamos a cambiar el valor de estas
 * @post cambiamos los valores en las operaciones
 */
void calculo(double &a, double &b, double &c, double &raiz, double &x1, double &x2){
	
	raiz = sqrt (b*b -4*a*c);
	x1 = -b + raiz / 2*a;
	x2 = -b - raiz / 2*a;
}
/**
 * @brief mostramos el resultado de x1 y x2
 * @info imprimir por pantalla el resultado
 */
void resultado(double a, double b){
	
	cout << " x1 = "<< a << endl;
	cout << " x2 = " << b << endl;
}

int main () {
	double a = 0, b = 0, c = 0, x1 = 0, x2 = 0, raiz = 0;
	
	introduce(a, b, c);
	calculo(a, b, c, raiz, x1, x2);
	resultado(x1, x2);
}

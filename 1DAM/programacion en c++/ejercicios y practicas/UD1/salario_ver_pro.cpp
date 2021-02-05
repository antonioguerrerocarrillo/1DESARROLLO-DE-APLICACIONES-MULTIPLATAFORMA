#include <iostream>
#include <cmath>
using namespace std;
int main (){
	const double contingencias = 0.025;
	const double retenciones = 0.17;
	const double formacion = 0.015;
	const double hipoteca = 0.21;
	const double telefono = 58;
	double gasolina = 0, tabaco = 0, fiesta = 0;
	double salario_bruto = 0 , salario_neto = 0, impuestos = 0, resultado_retenciones = 0;

	cout << " introduce el salario bruto " << endl;
	cin >> salario_bruto;
	cout << " cuanto te has gastado en gasolina " << endl;
	cin >> gasolina;
	cout << " cuanto en tabaco (espacio) y fiesta" << endl;
	cin >> tabaco >> fiesta;

	resultado_retenciones = contingencias + retenciones + formacion + hipoteca;
	impuestos = salario_bruto * resultado_retenciones;
	salario_neto = salario_bruto - impuestos - telefono - gasolina - tabaco - fiesta;

	cout << " tu salario neto es " << salario_neto << endl;
}
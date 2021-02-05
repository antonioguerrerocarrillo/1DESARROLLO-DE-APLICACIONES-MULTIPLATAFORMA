#include <iostream>
#include <cmath>
using namespace std;
int main (){
	const double contingencias = 0.025;
	const double retenciones = 0.17;
	const double formacion = 0.015;
	double salario_bruto = 0 , salario_neto = 0, impuestos = 0, resultado_retenciones = 0;

	cout << " introduce el salario bruto " << endl;
	cin >> salario_bruto;

	resultado_retenciones = contingencias + retenciones + formacion;
	impuestos = salario_bruto * resultado_retenciones;
	salario_neto = salario_bruto - impuestos;

	cout << " tu salario neto es " << salario_neto << endl;
}
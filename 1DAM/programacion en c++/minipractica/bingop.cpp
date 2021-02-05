#include <iostream>
#include <math.h>
#include <ctime>
using namespace std;

struct carton {
string letras[5];
int numeros[5][5];
};

int main() {
// define los cartones de bingo
carton bingo[10];

// define la incializacion del random
srand((unsigned)time(0));

// define las variables a utilizar y su inicializacion
int numeroRandom, inicio, fin;
int rango;

// prepara los cartones de bingo
// con las letras y el espacio del medio que debe ser vacio
for(int i=0;i<10;i++) {
bingo[i].letras[0] = “B”;
bingo[i].letras[1] = “I”;
bingo[i].letras[2] = “N”;
bingo[i].letras[3] = “G”;
bingo[i].letras[4] = “O”;
bingo[i].numeros[2][2]=0;
}

// llena los cartones del bingo
for(int i=0;i<10;i++) {
// llena la columna B ([0] de los cartones del bingo)
inicio = 1, fin=15;
rango = (fin-inicio) + 1;
for(int j=0;j<5;j++) {
numeroRandom = inicio +
int(rango * rand() / (RAND_MAX + 1.0));
bingo[i].numeros[0][j]=numeroRandom;
}

// llena la columna I ([1] de los cartones del bingo)
inicio = 16, fin=30;
rango = (fin-inicio) + 1;
for(int j=0;j<5;j++) {
numeroRandom = inicio +
int(rango * rand() / (RAND_MAX + 1.0));
bingo[i].numeros[1][j]=numeroRandom;
}

// llena la columna N ([2] de los cartones del bingo)
inicio = 31, fin=45;
rango = (fin-inicio) + 1;
for(int j=0;j<5;j++) {
numeroRandom = inicio +
int(rango * rand() / (RAND_MAX + 1.0));
if (j!=2) bingo[i].numeros[2][j]=numeroRandom;
}

// llena la columna G ([3] de los cartones del bingo)
inicio = 46, fin=60;
rango = (fin-inicio) + 1;
for(int j=0;j<5;j++) {
numeroRandom = inicio +
int(rango * rand() / (RAND_MAX + 1.0));
bingo[i].numeros[3][j]=numeroRandom;
}

// llena la columna O ([4] de los cartones del bingo)
inicio = 61, fin=75;
rango = (fin-inicio) + 1;
for(int j=0;j<5;j++) {
numeroRandom = inicio +
int(rango * rand() / (RAND_MAX + 1.0));
bingo[i].numeros[4][j]=numeroRandom;
}
}

// imprime los cartones del bingo
for(int i=0;i<10;i++) {
cout<<bingo[i].letras[0]<<”\t”;
cout<<bingo[i].letras[1]<<”\t”;
cout<<bingo[i].letras[2]<<”\t”;
cout<<bingo[i].letras[3]<<”\t”;
cout<<bingo[i].letras[4]<<”\t”;
cout<<endl;
for(int k=0;k<5;k++) {
cout<<bingo[i].numeros[0][k]<<”\t”;
cout<<bingo[i].numeros[1][k]<<”\t”;
if (k==2) cout<<”Libre”<<”\t”;
else cout<<bingo[i].numeros[2][k]<<”\t”;
cout<<bingo[i].numeros[3][k]<<”\t”;
cout<<bingo[i].numeros[4][k]<<”\t”<<endl;
}
cout<<endl;
}
cout<<endl<<endl;
system(“pause”);
}
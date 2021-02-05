#include <iostream>
#include <cmath>
using namespace std;

int fibonacci(int n){

    if(n < 2)
        return n;

    return fibonacci(n-1) + fibonacci(n-2);
}
void pedir_usuario(int &n){
  
  cout << " introduce el numero del factorial que quieres calcular " << endl;
  cin >> n;
}

void resultado(int n){
    for(int i =0; i <= n; i++){
    cout << " " << fibonacci(i);
  }
  cout << endl;
}
int main() {
  int n = 0;

  pedir_usuario(n);

  fibonacci(n);
  
  resultado(n);

}
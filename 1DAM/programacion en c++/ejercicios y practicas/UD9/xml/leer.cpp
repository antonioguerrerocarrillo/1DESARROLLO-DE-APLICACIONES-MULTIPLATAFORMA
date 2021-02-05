#include "pugixml.cpp"
#include <iostream>
#include <fstream>
#include <typeinfo>
#include <string.h>
#include <stdlib.h>
#include <stdlib.h>
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
class Vista{
protected:
    Usuario **lista_usuarios;
    int total_usuarios;
    Usuario *usuario_activo;
    Media **vector_media;
    int total_media;
    string login;
    string paswd;
    Media ** resultado_busqueda;
    int total_busqueda;
    Usuario** resize(Usuario **u, int util_v, int &dim_v_actual, int dim_nueva);
public:
    Vista();
    ~Vista();
    Vista& operator= (Vista &v);
    void bienvenida();
    /*
    void imoportarxml();
    void importar_fichero();
    void exportar_fichero();
    void buscar_media (Media **tp, string nombre);
    void agregarmedia();
    void importarxml();
    void importarxmljugador();*/
    void menu_en_pantalla();
    void menu_en_pantalla_usuario();
    
    void agregarnuevousuario(); 
    void anadirusuarios(Usuario *lista_usuarios, int id, string login, string passwd, double dinero);
    void buscarusuarios (Usuario **lista_usuarios, string login);
    void imprimir_un_usuario (Usuario *u);
    void settotal_usuarios( int total_usuarios);
    void settotal_media (int total_media);
    void settotal_busqueda (int total_busqueda);
    string getlogin();
    int gettotal_media();
    int gettotal_busqueda();
    void setpasswd(string passwd);
    string getpasswd();
    void setlogin(int id);
    Usuario* crear_usuario();
    void imprimir_media(Media *m); 
    void imprimir_todos_los_media(Media *u);
    void imprimir_todos_los_usuarios();
    void anadir_usuario(Usuario *u);
    void buscar_usuario();
    void borrar_usuarios();
    bool comprobar_si_existe(int id);
    string devuelve(string valor);
    void importarxmlusuario()
    /*
    Media** resizemedia(Media **m, int util_v, int &dim_v_actual, int dim_nueva);
    void borrar_usuario (Usuario *t, string login);
    void borrar_Media (Media *m, int id);
    */

};

Vista::Vista(){
    cout << " entrando en el constructosr del vista:" << endl;
    lista_usuarios = new Usuario*[0];
    this->total_usuarios = 0;
    this->usuario_activo = new Usuario;
    this->vector_media = new Media*[0];
    this->total_media = 0;
    this->login = "NULL";
    this->paswd = "NULL";
    resultado_busqueda;
    this->total_busqueda = 0;

}
Vista::~Vista(){
    cout << " entrando en el destructor del vista." << endl;

    delete lista_usuarios;
    total_usuarios = 0;
    delete usuario_activo;
    //vector_media = Media*[0];
    total_media = 0;
    login = "NULL";
    paswd = "NULL";
    //resultado_busqueda;
    total_busqueda = 0;
}
Usuario** Vista::resize(Usuario **u, int util_v, int &dim_v_actual, int dim_nueva){
    Usuario **nuevo = 0;
    nuevo = new Usuario*[dim_nueva];
    if (nuevo == 0){
        cerr << "Error. No hay memoria suficiente. Se abortará la ejecución" << endl;
        exit(-1);
    }
    
    //1.1) Discusión acerca de hasta donde copio en el escenario de disminución
    if (util_v > dim_nueva) //recorto
        util_v = dim_nueva;
    
    
    //2º Copio las componentes del vector antiguo en el nuevo
    for(int i =0; i < util_v; i++)
        nuevo[i] = u[i];
    //3º Libero la memoria del antiguo vector
    delete [] u;
    //4º Devuelvo el puntero del nuevo vector, para que se guarde en la variable del módulo llamante y cambio la dimensión del vector actual
    dim_v_actual = dim_nueva;
    return nuevo;
}
string Vista::devuelve(string valor){
    //cout<<"entradevuelve";
  bool guarda=false;
  int total_res= 0;
  char *resultado = new char[total_res];

  int contador=0;
  int contadorcierres=0;
  for(int i=0; i< valor.length(); i++){
    if (valor.at (i) == '<')
      guarda = false;
    if(guarda==true)
    {
        
        if(valor.at(i)!=' ')
        {
            //cout<< "d"<< (int)valor.at(i)<<endl;
            resultado= resize_char(resultado, total_res, total_res, total_res+1);
            resultado[contador]=valor.at(i);
            contador++;

        }
      
    }
    if(valor.at(i)=='>' && contadorcierres==0)
    {
      guarda=true;
     contadorcierres++;
    }
    
  }
  return (string)resultado;
}
void Vista::importarxmlusuario(){
    cout<<"debugimportando"<<endl;
    char cadena[128];
   bool catalogo=false;
   bool jugador=false;
   Usuario *nuevo_jugador = new Jugador;
    
    // Abre un fichero de entrada
    ifstream fe("cristofinity.xml");
    //nuevo_coche->setid(1);
    // Leeremos mediante getline, si lo hiciéramos
    // mediante el operador << sólo leeríamos
    // parte de la cadena:
    //hacer que se repita hasta que acabe la cadena de caracteres.
    while(fe.getline(cadena, 128))
    {
          //cout << cadena << endl;
          string cadena2=(string)cadena; //convierto el tipo char en string

         if (cadena2 == "   <usuario>") {
              jugador=true;
          }
         if(cadena2.find("<tipousuario>") !=string::npos && jugador==true){        ;
            //cout<< devuelve(cadena2) <<endl; 
            // para convertir con int
            nuevo_jugador-> setidjugador(stoi(devuelve(cadena2)));
            }
         if(cadena2.find("<login>") !=string::npos && jugador==true){     
            nuevo_jugador-> setlogin(devuelve(cadena2));
            }
         if (cadena2.find("<nombre>") !=string::npos && jugador==true){
            nuevo_jugador-> setpasswd(devuelve(cadena2));
         }
         if (cadena2.find("<apellidos>") !=string::npos && jugador==true){
            nuevo_jugador-> setcreditos(stod(devuelve(cadena2)));
            //stod para convertir de char a double
         }
         if (cadena2.find("</usuario>") !=string::npos && jugador==true){
            jugador=false;
            lista_player = resize(lista_player, total_player, total_player, total_player+1);
            lista_player[total_player-1]=nuevo_jugador;
        }
    }
}
int main(){
    imoportarxml();
}
//#endif
#ifndef CRISTURISMO_H
#define CRISTURISMO_H
#include <iostream>
#include <fstream>
#include <typeinfo>
#include <string.h>
#include "Jugador.h"
#include "Vehiculo.h"
#include "Pieza.h"
#include "Coche.h"
#include "Moto.h"
#include "Camion.h"
using namespace std;
/*
*@param lista player es un doble puntero donde estaran todos los usuarios
*@param catalogo vehiculo es un doble puntero de vehiculos donde estaran todos los vehiculos
*@param catalogo piezas es un puntero donde estaran todas las piezas

crear player
*@info vamos a crear el  player con un puntero de tipo jugador.
*@param le pasamos de tipo string el id, nombre, contraseña y creditos
*@param creo un funcion tipo que devuelve un puntero de jugador
*@param creo el vector de fotos dinamico para asignarselo para devolver el jugador

resize
 * @brief Módulo que aumenta/disminuye la dimensión del vector de punteros a jugador, cuya dirección se le pasa por copia.
 * @info Si las dim_nueva < dim_v_actual
 * @pre util_v <= dim_v_actual
 * @post util_v y dim_v_actual se modifican apropiadamente en el interior, por lo tanto fuera se verán también afectada
 * @return La dirección de memoria del vector nuevo que ya tiene la dimensión nueva, y copiados los elementos del vector antiguo (hasta donde quepa).

añadir player
*@pre al resize le pasamos la tabla que queremos redimensionar y le sumamanos uno
*@param creamos un puntero de tipo usuario y creamos el usuario
*@param asignamos a la ultima posicion que hemos redimensionado el usuario. le ponemos -1 para que no se salga del vector

borrar jugador o vehiculo 
*@info vamos a borrar un jugador o vehiculo
*@param pasamos un puntero de tipo usuario o vehiculo.
*@param le pasamos el login de tipo string.
*@param creamos un puntero que apunta a una tabla de puteros dinamico
*@param realizamos un for que recorra el jugador o vehiculo que queremos borrar
*@param si el login es diferente que el getlogin guardo en v el t. (t es el usuario o vehiculo
*@ en vehiciulo lo borraremos por id  que queramos borrar)
*@param  v sera igual que el resize
*@param el jugador o vehiculo aux lo pasamos a ultima posicion para borrarlo
@post borramos v. 

*@pre haremos todas lass llamadas y todas las funciones en el menu.
*@param todas las funciones las llamamos desde el menu.
*@param cuando acabe el modulo volveremos a mostrar el menu para hacer otro.

*/
class Cristurismo{
protected:
	Jugador ** lista_player;
	int total_player;
	Jugador * jugador_activo;
	Vehiculo **catalogo_vehiculo;
	int total_vehiculos;
	int total_modelos;
	Pieza ** catalogo_pieza;
	int total_piezas;
	double precio_gasolina;
	double precio_diesel;
	string login;
	string paswd;
	Vehiculo ** resultado_busqueda;
	int total_busqueda;
public:
	Cristurismo();
	~Cristurismo();
	void bienvenida();
	void imoportarxmlvehiculo();
	void importar_fichero();
	void exportar_fichero();
	void buscar_vehiculo (Vehiculo **tp, string marca);
	void agregarnuevovehiculo();
	void importarxmlvehiculo();
	void importarxmljugador();
	void importarpiezaxml();
	void menu_en_pantalla();
	void menu_en_pantalla_usuario();
	void autologin();
	void agregarnuevojugador();
	Pieza** resizepiezas(Pieza **u, int util_v, int &dim_v_actual, int dim_nueva);
	char* resize_char(char *u, int util_v, int &dim_v_actual, int dim_nueva);
	void anadirusuarios(Jugador *lp, int id, string login, string passwd, double creditos);
	string devuelve(string valor);
	void resizedos(Jugador** u, int grado);
	Jugador** resize(Jugador **u, int util_v, int &dim_v_actual, int dim_nueva);
	Jugador* agregarnuevojugador (int id, string login, string passwd, double creditos);
	void buscarusuarios (Jugador **lp, string login);
	void imprimirusuario (Jugador *u);
	Vehiculo** resizevehiculo(Vehiculo **u, int util_v, int &dim_v_actual, int dim_nueva);
	Vehiculo** resizev4(Vehiculo **u, int util_v, int dim_v_actual, int dim_nueva);
	void borrar_player (Jugador *t, string login);
	void imprimirtabla ();
	void imprimir_vehiculo(); 
	void borrar_vehiculo (Vehiculo *v, int id);
	void consultar_garaje(Jugador *usuario, Vehiculo *nuevo_vehiculo);
	void comprar_vehiculo(int id);
	void imprimirvehiculo (Vehiculo *u);
	void imprimirpieza (Pieza *u);
	void imprimir_pieza();
	void agregarnuevapieza();
	void modificar_vehiculo(Vehiculo **tp, string marca);
	void modificar_jugador(Jugador **tj, string nombre);
	Pieza* buscarpieza (Pieza **tp, int id);
	Vehiculo *buscar_vehiculo_por_id (Vehiculo **tp, int marca);
	void asignar_pieza_vehiculo(Vehiculo *v, Pieza *p);
	void designar_pieza_vehiculo(Vehiculo *v, Pieza *p);
	Vehiculo* buscar_vehiculo_por_id_garaje (Vehiculo **tp, int id);
};
#endif
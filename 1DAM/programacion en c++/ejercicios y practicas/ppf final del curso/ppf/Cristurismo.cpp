#include "Cristurismo.h"
#include <iostream>
#include <fstream>
#include <typeinfo>
#include <string.h>
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
Cristurismo::Cristurismo(){
	//cout << " entrando en el constructosr del Cristurismo:" << endl;
	lista_player=new Jugador*[0];
	total_player=0;
	catalogo_vehiculo = new Vehiculo*[0];
	total_vehiculos=0;

	total_player = 0;
	jugador_activo = new Jugador;
	total_vehiculos = 0;
	total_modelos = 0;
	catalogo_pieza = new Pieza*[0];
	total_piezas = 0;
	precio_gasolina = 0.0;
	precio_diesel = 0.0;
	login = "NULL";
	paswd = "NULL";
	//resultado_busqueda = Vehiculo *[0];
	total_busqueda = 0;
}
Cristurismo::~Cristurismo(){
	//cout << " entrando en el destructor del Cristurismo." << endl;
	delete lista_player;
	delete catalogo_vehiculo;
	total_player=0;
	total_vehiculos=0;
	total_player = 0;
	delete jugador_activo;
	total_vehiculos = 0;
	total_modelos = 0;
	delete catalogo_pieza;
	total_piezas = 0;
	precio_gasolina = 0.0;
	precio_diesel = 0.0;
	login = "NULL";
	paswd = "NULL";
	//resultado_busqueda = Vehiculo *[0];
	total_busqueda = 0;
}


void Cristurismo::bienvenida(){
	cout << "*************************************************************************** " << endl;
	cout << "***		Bienvenido a Cristurismo				*** " << endl;
	cout << "***		solo para vosotros jugadores 				*** " << endl;
	cout << "***		version gratuita, recuerde este programa esta 		*** " << endl;
	cout << "***		todavia en desarroyo, disfrute :-)	 		*** " << endl;
	cout << "*************************************************************************** " << endl;
}
Vehiculo** vehiculo_resize(Vehiculo **catalogo_vehiculo, Vehiculo * vei,int util_v, int &dim_v_actual, int dim_nueva){
	Vehiculo **nuevo = 0; //DOBLE PUNTERO AUXILIAR
    nuevo = new Vehiculo*[dim_nueva];
    if (nuevo == 0){
        cerr << "Error. No hay memoria suficiente. Se abortará la ejecución" << endl;
        //exit(-1);
    }
    
    //1.1) Discusión acerca de hasta donde copio en el escenario de disminución
    if (util_v > dim_nueva) //recorto
        util_v = dim_nueva;
	
    
    //2º Copio las componentes del vector antiguo en el nuevo
    for(int i =0; i < util_v; i++)
        nuevo[i] = catalogo_vehiculo[i];
    //3º Libero la memoria del antiguo vector
    catalogo_vehiculo = 0;
    delete [] catalogo_vehiculo;
    //4º Devuelvo el puntero del nuevo vector, para que se guarde en la variable del módulo llamante y cambio la dimensión del vector actual
    dim_v_actual = dim_nueva;
    return nuevo;
}
void Cristurismo::agregarnuevovehiculo(){
	 string modelo, marca, combustible;
	 int id, velocidad, aerodinamica, frenada, cilindrada;


	 cout << "introduce el id: "<< endl;
	 cin >> id;
	 cout <<"Introduce la marca del nuevo vehiculo" << endl;
	 cin >> marca;
	 cout << " introduce el modelo " << endl;
	 cin >> modelo;
	 cout << " introduce el combustible:" << endl;
	 cin >> combustible;
	 cout << "introduce la cilindrada: " << endl;
	 cin >> cilindrada;
	 cout << "velocidad:" << endl;
	 cin >> velocidad;
	 cout << " aerodinamica: " << endl;
	 cin >> aerodinamica;
	 cout << " frenada: " << endl;
	 cin >> frenada;

	 Vehiculo *auto1= new Vehiculo;
	 auto1 -> setid(id);
	 auto1 -> setmarca(marca);
	 auto1 -> setmodelo(modelo);
	 auto1 -> settipo_combustible(combustible);
	 auto1 -> setcilindrada(cilindrada);
	 auto1 -> setvelocidad_max(velocidad);
	 auto1 -> setaerodinamica(aerodinamica);
	 auto1 -> setfrenada(frenada);

	catalogo_vehiculo = resizevehiculo(catalogo_vehiculo, total_vehiculos, total_vehiculos, total_vehiculos+1);
	catalogo_vehiculo[total_vehiculos-1]=auto1;
}
void Cristurismo::agregarnuevapieza(){
	 string nombre;
	 int id, maxima, aerodinamica, frenada, velocidad, precio, aceleracion;


	 cout << "introduce el id: "<< endl;
	 cin >> id;
	 cout << "introduce el nombre "<< endl;
	 cin >> nombre;
	 cout << " introduce el la aceleracion " << endl;
	 cin >> aceleracion;
	 cout << " introduce el precio:" << endl;
	 cin >> precio;
	 cout << "la velocidad Maxima: " << endl;
	 cin >> maxima;
	 cout << "velocidad:" << endl;
	 cin >> velocidad;
	 cout << " aerodinamica: " << endl;
	 cin >> aerodinamica;
	 cout << " frenada: " << endl;
	 cin >> frenada;

	 Pieza *pi= new Pieza;
	 pi -> setid(id);
	 pi -> setnombre(nombre);
	 pi -> setaceleracion(aceleracion);
	 pi -> setprecio(precio);
	 pi -> setvelocidad_max(maxima);
	 pi -> setvelocidad_max(velocidad);
	 pi -> setaerodinamica(aerodinamica);
	 pi -> setfrenada(frenada);

	catalogo_pieza = resizepiezas(catalogo_pieza, total_piezas, total_piezas, total_piezas+1);
	catalogo_pieza[total_piezas-1]=pi;
	pi = 0;
	delete pi;
}
string Cristurismo::devuelve(string valor){
	//cout<<"entradevuelve";
  bool guarda=false;
  int total_res= 0;
  char *resultado = 0; 
  resultado= new char[total_res];

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
void Cristurismo::importarxmlvehiculo(){
	//cout<<"debugimportando"<<endl;
   char cadena[128];
   bool catalogo=false;
   bool coche=false;
   bool camion = false;
   bool moto = false;
   Coche *nuevo_coche;
   Camion *nuevo_camion;
   Moto *nuevo_moto;
    //vehiculo *h1 = new vehiculo;
    
    // Abre un fichero de entrada
    ifstream fe("catalogo.xml");
    //nuevo_coche->setid(1);
    // Leeremos mediante getline, si lo hiciéramos
    // mediante el operador << sólo leeríamos
    // parte de la cadena:
    //hacer que se repita hasta que acabe la cadena de caracteres.
    while(fe.getline(cadena, 128))
    {
	      //cout << cadena << endl;
	      string cadena2=(string)cadena; //convierto el tipo char en string

	     if (cadena2 == "	<coche>") {
	          coche=true;
	         nuevo_coche = new Coche;
	      }
	     if(cadena2.find("<id>") !=string::npos && coche==true){        
	     	//cout<< devuelve(cadena2) <<endl; 
	     	// para convertir con int
	     	nuevo_coche-> setid(stoi(devuelve(cadena2)));
	     	}
	     if(cadena2.find("<marca>") !=string::npos && coche==true){        	
	     	//cout<< devuelve(cadena2) <<endl; 
	     	nuevo_coche-> setmarca(devuelve(cadena2));
	     	}
	     if (cadena2.find("<modelo>") !=string::npos && coche==true){
	     	nuevo_coche-> setmodelo(devuelve(cadena2));
	     }
	     if (cadena2.find("<tipoCombustible>") !=string::npos && coche==true){
	     	nuevo_coche-> settipo_combustible(devuelve(cadena2));
	     }
	     if (cadena2.find("<cilindrada>") !=string::npos && coche==true){
	     	nuevo_coche-> setcilindrada(stoi(devuelve(cadena2)));
	     }
	     if (cadena2.find("<capacidadDepositoMax>") !=string::npos && coche==true){
	     	nuevo_coche->setgasolina_max(stoi(devuelve(cadena2)));
	     }
	     if (cadena2.find("<caballos>") !=string::npos && coche==true){
	     	nuevo_coche->setcaballos(stoi(devuelve(cadena2)));
	     }

	     if (cadena2.find("<aerodinamica>") !=string::npos && coche==true){
	     	nuevo_coche->setaerodinamica(stoi(devuelve(cadena2)));
	     }
	     if (cadena2.find("<aceleracion>") !=string::npos && coche==true){
	     	nuevo_coche->setaceleracion(stoi(devuelve(cadena2)));
	     }
	     if (cadena2.find("<menejo>") !=string::npos && coche==true){
	     	nuevo_coche->setmanejo(stoi(devuelve(cadena2)));
	     }
	     if (cadena2.find("<velocidadMax>") !=string::npos && coche==true){
	     	nuevo_coche->setvelocidad_max(stoi(devuelve(cadena2)));
	     }
		 if (cadena2.find("<frenada>") !=string::npos && coche==true){
	     	nuevo_coche->setfrenada(stoi(devuelve(cadena2)));
	     }
	     if (cadena2.find("<combustibleActual>") !=string::npos && coche==true){
	     	//para convertir double stod
	     	nuevo_coche-> setgasolina_actual(stod(devuelve(cadena2)));
	     }
	     if (cadena2.find("<totalPiezas>") !=string::npos && coche==true){
	     	nuevo_coche->settotal_piezas(stoi(devuelve(cadena2)));

	     }
	     if (cadena2.find("precioBase") !=string::npos && coche==true){
	     	nuevo_coche->setprecio_base(stoi(devuelve(cadena2)));
	     }
	     if (cadena2.find("<precioActual>") !=string::npos && coche==true){
	     	nuevo_coche->setprecio_actual(stoi(devuelve(cadena2)));

	     }
	     if (cadena2.find("</coche>") !=string::npos && coche==true){
	     	//acaba de leer coche
	     	coche=false;
	     	catalogo_vehiculo = resizevehiculo(catalogo_vehiculo, total_vehiculos, total_vehiculos, total_vehiculos+1);
	 		catalogo_vehiculo[total_vehiculos-1]=nuevo_coche;
	 		nuevo_coche = 0;
	 		delete nuevo_coche;
    	}
    	
    	 if (cadena2 == "	<moto>") {
	          moto=true;
	          nuevo_moto = new Moto;
	      }
	      if(cadena2.find("<id>") !=string::npos && moto==true){
	     	nuevo_moto->setid(stoi(devuelve(cadena2)));
	     	}
	     if (cadena2.find("<marca>") !=string::npos && moto==true){
	     	nuevo_moto->setmarca(devuelve(cadena2));
	     }
	     if(cadena2.find("<modelo>") !=string::npos && moto==true){         
	     	nuevo_moto->setmodelo(devuelve(cadena2));
	     	}
	     if (cadena2.find("<tipoCombustible>") !=string::npos && moto==true){
	     	nuevo_moto->settipo_combustible(devuelve(cadena2));
	     }
	     if (cadena2.find("<cilindrada>") !=string::npos && moto==true){
	     	nuevo_moto->setcilindrada(stoi(devuelve(cadena2)));
	     }
	     if (cadena2.find("<capacidadDepositoMax>") !=string::npos && moto==true){
	     	nuevo_moto->setgasolina_max(stod(devuelve(cadena2)));
	     }
	     if (cadena2.find("<caballos>") !=string::npos && moto==true){
	     	nuevo_moto->setcaballos(stoi(devuelve(cadena2)));
	     }
	     if (cadena2.find("<aerodinamica>") !=string::npos && moto==true){
	     	nuevo_moto->setaerodinamica(stoi(devuelve(cadena2)));
	     }
	     if (cadena2.find("<aceleracion>") !=string::npos && moto==true){
	     	nuevo_moto->setaceleracion(stoi(devuelve(cadena2)));
	     }
	     if (cadena2.find("<menejo>") !=string::npos && moto==true){
	     	nuevo_moto->setmanejo(stoi(devuelve(cadena2)));
	     }
	     if (cadena2.find("<velocidadMax>") !=string::npos && moto==true){
	     	nuevo_moto->setvelocidad_max(stoi(devuelve(cadena2)));
	     }
		 if (cadena2.find("<frenada>") !=string::npos && moto==true){
	     	nuevo_moto->setfrenada(stoi(devuelve(cadena2)));
	     }
	     if (cadena2.find("<combustibleActual>") !=string::npos && moto==true){
	     	nuevo_moto->setgasolina_actual(stod(devuelve(cadena2)));
	     }
	     if (cadena2.find("<totalPiezas>") !=string::npos && moto==true){
	     	nuevo_moto->settotal_piezas(stoi(devuelve(cadena2)));
	     }
	     if (cadena2.find("precioBase") !=string::npos && moto==true){
	     	nuevo_moto->setprecio_base(stoi(devuelve(cadena2)));
	     }
	     if (cadena2.find("<precioActual>") !=string::npos && moto==true){
	     	nuevo_moto->setprecio_actual(stoi(devuelve(cadena2)));
	     }
	     if (cadena2.find("</moto>") !=string::npos && moto==true)//acaba de leer el xml
	     {
	     	moto=false;
	     	catalogo_vehiculo = resizevehiculo(catalogo_vehiculo, total_vehiculos, total_vehiculos, total_vehiculos+1);
	 		catalogo_vehiculo[total_vehiculos-1]=nuevo_moto;
	 		nuevo_moto = 0;
	 		delete nuevo_moto;
    	} 
    	
    	 if (cadena2 == "	<camion>") {
	          camion=true;
	          nuevo_camion = new Camion;
	      }
	      if(cadena2.find("<id>") !=string::npos && camion==true){   
	     	nuevo_camion->setid(stoi(devuelve(cadena2)));
	     	}
	     if (cadena2.find("<marca>") !=string::npos && camion==true){
	     	nuevo_camion->setmarca(devuelve(cadena2));
	     }
	     if(cadena2.find("<modelo>") !=string::npos && camion==true){        
	     	nuevo_camion->setmodelo(devuelve(cadena2)); 
	     	}
	     if (cadena2.find("<tipoCombustible>") !=string::npos && camion==true){
	     	nuevo_camion->settipo_combustible(devuelve(cadena2));
	     }
	     if (cadena2.find("<cilindrada>") !=string::npos && camion==true){
	     	nuevo_camion->setcilindrada(stoi(devuelve(cadena2)));
	     }
	     if (cadena2.find("<capacidadDepositoMax>") !=string::npos && camion==true){
	     	nuevo_camion->setgasolina_max(stoi(devuelve(cadena2)));
	     }
	     if (cadena2.find("<caballos>") !=string::npos && camion==true){
	     	nuevo_camion->setcaballos(stoi(devuelve(cadena2)));
	     }
	     if (cadena2.find("<aerodinamica>") !=string::npos && camion==true){
	     	nuevo_camion->setaerodinamica(stoi(devuelve(cadena2)));
	     }
	     if (cadena2.find("<aceleracion>") !=string::npos && camion==true){
	     	nuevo_camion->setaceleracion(stoi(devuelve(cadena2)));
	     }
	     if (cadena2.find("<menejo>") !=string::npos && camion==true){
	     	nuevo_camion->setmanejo(stoi(devuelve(cadena2)));
	     }
	     if (cadena2.find("<velocidadMax>") !=string::npos && camion==true){
	     	nuevo_camion->setvelocidad_max(stoi(devuelve(cadena2)));
	     }
		 if (cadena2.find("<frenada>") !=string::npos && camion==true){
	     	nuevo_camion->setfrenada(stoi(devuelve(cadena2)));
	     }
	     if (cadena2.find("<combustibleActual>") !=string::npos && camion==true){
	     	nuevo_camion->setgasolina_actual(stoi(devuelve(cadena2)));
	     }
	     if (cadena2.find("<totalPiezas>") !=string::npos && camion==true){
	     	nuevo_camion->settotal_piezas(stoi(devuelve(cadena2)));
	     }
	     if (cadena2.find("precioBase") !=string::npos && camion==true){
	     	nuevo_camion->setprecio_base(stoi(devuelve(cadena2)));
	     }
	     if (cadena2.find("<precioActual>") !=string::npos && camion==true){
	     	nuevo_camion->setprecio_actual(stoi(devuelve(cadena2)));
	     }
	     if (cadena2.find("</camion>") !=string::npos && camion==true)//acaba de leer el xml
	     {
	     	camion=false;
	     	catalogo_vehiculo = resizevehiculo(catalogo_vehiculo, total_vehiculos, total_vehiculos, total_vehiculos+1);
	 		catalogo_vehiculo[total_vehiculos-1]=nuevo_camion;
	 		nuevo_camion = 0;
	 		delete nuevo_camion;
    	} 
    }
}
void Cristurismo::importarxmljugador(){
	//cout<<"debugimportando"<<endl;
	char cadena[128];
   bool catalogo=false;
   bool jugador=false;

   Jugador *nuevo_jugador;
    bool coche=false;
	Vehiculo *nuevo_coche;
    // Abre un fichero de entrada
    ifstream fe("jugadores.xml");
    //nuevo_coche->setid(1);
    // Leeremos mediante getline, si lo hiciéramos
    // mediante el operador << sólo leeríamos
    // parte de la cadena:
    //hacer que se repita hasta que acabe la cadena de caracteres.
    while(fe.getline(cadena, 128))
    {
	      //cout << cadena << endl;
	      string cadena2=(string)cadena; //convierto el tipo char en string

	     if (cadena2 == "	<jugador>") {
	          jugador=true;
	          nuevo_jugador = new Jugador;
	          //cout<<"entra"<<endl;
	      }
	     if(cadena2.find("<id>") !=string::npos && jugador==true){        ;
	     	//cout << "id" <<endl;
	     	//cout<< devuelve(cadena2) <<endl; 
	     	// para convertir con int
	     	nuevo_jugador-> setidjugador(stoi(devuelve(cadena2)));
	     	}
	     if(cadena2.find("<login>") !=string::npos && jugador==true){     
	     	nuevo_jugador-> setlogin(devuelve(cadena2));
	     	//cout << "login"<<endl;
	     	//cout<< devuelve(cadena2) <<endl; 
	     	}
	     if (cadena2.find("<passwd>") !=string::npos && jugador==true){
	     	nuevo_jugador-> setpasswd(devuelve(cadena2));
	     	//cout << "contraseña"<<endl;
	     	//cout<< devuelve(cadena2) <<endl; 
	     }
	     if (cadena2.find("<creditos>") !=string::npos && jugador==true){
	     	nuevo_jugador-> setcreditos(stod(devuelve(cadena2)));
	     	//stod para convertir de char a double
	     	//cout << "creditos"<<endl;
	     	//cout<< devuelve(cadena2) <<endl; 
	     }
	      if (cadena2.find("<numeroVictorias>") !=string::npos && jugador==true){
	     	nuevo_jugador-> setnumerovictorias(stoi(devuelve(cadena2)));
	     	//stod para convertir de char a double
	     	//cout << "numero de victoras"<< endl;
	     	//cout<< devuelve(cadena2) <<endl; 

	     }
	      if (cadena2.find("<coche>") !=string::npos) {
	          coche=true;
	         nuevo_coche = new Vehiculo; 
	      }
	     if(cadena2.find("<id>") !=string::npos && coche==true){        
	     	
	     	//cout << "debug id coche " << endl; 
	     	// para convertir con int
	     	//nuevo_coche-> setid(stoi(devuelve(cadena2)));
	     	Vehiculo *aux = buscar_vehiculo_por_id(catalogo_vehiculo, stoi(devuelve(cadena2)));
	     	nuevo_coche = new Vehiculo(aux);
	     	}
	     if (cadena2.find("</coche>") !=string::npos && coche==true){
	     	//acaba de leer coche
	     	coche=false;
	     	nuevo_jugador -> setgaraje(resizev4(nuevo_jugador->getgaraje(),nuevo_jugador-> gettotatal_vehiculo_garaje(), nuevo_jugador-> gettotatal_vehiculo_garaje(), nuevo_jugador-> gettotatal_vehiculo_garaje()+1));
	 		nuevo_jugador -> settotatal_vehiculo_garaje(nuevo_jugador-> gettotatal_vehiculo_garaje()+1);
	 		nuevo_jugador -> getgaraje()[nuevo_jugador-> gettotatal_vehiculo_garaje()-1]=nuevo_coche;
	 		//cout << " nuevo coche " << nuevo_jugador -> getgaraje()[nuevo_jugador-> gettotatal_vehiculo_garaje()-1]->getid()<< endl;
	 		//nuevo_coche = 0;
	 		//delete nuevo_coche;
    		}
    		/*
    	if (cadena2.find("<moto>") !=string::npos) {
	          coche=true;
	         nuevo_coche = new Moto; 
	      }
	     if(cadena2.find("<id>") !=string::npos && coche==true){        
	     	
	     	cout << "debug id coche " << endl; 
	     	// para convertir con int
	     	//nuevo_coche-> setid(stoi(devuelve(cadena2)));
	     	Moto *aux = buscar_vehiculo_por_id(catalogo_vehiculo, stoi(devuelve(cadena2)));
	     	nuevo_coche = new Moto(aux);
	     	}
	     if (cadena2.find("</moto>") !=string::npos && coche==true){
	     	//acaba de leer coche
	     	coche=false;
	     	nuevo_jugador -> setgaraje(resizev4(nuevo_jugador->getgaraje(),nuevo_jugador-> gettotatal_vehiculo_garaje(), nuevo_jugador-> gettotatal_vehiculo_garaje(), nuevo_jugador-> gettotatal_vehiculo_garaje()+1));
	 		nuevo_jugador -> settotatal_vehiculo_garaje(nuevo_jugador-> gettotatal_vehiculo_garaje()+1);
	 		nuevo_jugador -> getgaraje()[nuevo_jugador-> gettotatal_vehiculo_garaje()-1]=nuevo_coche;
	 		cout << " nueva moto " << nuevo_jugador -> getgaraje()[nuevo_jugador-> gettotatal_vehiculo_garaje()-1]->getid()<< endl;
	 		//nuevo_coche = 0;
	 		//delete nuevo_coche;
    		}

    	 if (cadena2.find("<camion>") !=string::npos) {
	          coche=true;
	         nuevo_coche = new Camion; 
	      }
	     if(cadena2.find("<id>") !=string::npos && coche==true){        
	     	
	     	cout << "debug id coche " << endl; 
	     	// para convertir con int
	     	//nuevo_coche-> setid(stoi(devuelve(cadena2)));
	     	Moto *aux = buscar_vehiculo_por_id(catalogo_vehiculo, stoi(devuelve(cadena2)));
	     	nuevo_coche = new Camion(aux);
	     	}
	     if (cadena2.find("</camion>") !=string::npos && coche==true){
	     	//acaba de leer coche
	     	coche=false;
	     	nuevo_jugador -> setgaraje(resizev4(nuevo_jugador->getgaraje(),nuevo_jugador-> gettotatal_vehiculo_garaje(), nuevo_jugador-> gettotatal_vehiculo_garaje(), nuevo_jugador-> gettotatal_vehiculo_garaje()+1));
	 		nuevo_jugador -> settotatal_vehiculo_garaje(nuevo_jugador-> gettotatal_vehiculo_garaje()+1);
	 		nuevo_jugador -> getgaraje()[nuevo_jugador-> gettotatal_vehiculo_garaje()-1]=nuevo_coche;
	 		cout << " nuevo camion " << nuevo_jugador -> getgaraje()[nuevo_jugador-> gettotatal_vehiculo_garaje()-1]->getid()<< endl;
	 		//nuevo_coche = 0;
	 		//delete nuevo_coche;
    		}
    		*/
    		
	     if (cadena2.find("</jugador>") !=string::npos && jugador==true){
	     	jugador=false;
	     	lista_player = resize(lista_player, total_player, total_player, total_player+1);
			lista_player[total_player-1]=nuevo_jugador;
			nuevo_jugador = 0;
    		delete nuevo_jugador;
    	}
    	
    }
   
}

void Cristurismo::importarpiezaxml(){
	char cadena[1000];
	bool catalogo=false;
	bool jugador=false;
	Pieza *nueva_pieza;
    
    // Abre un fichero de entrada
    ifstream fe("piezas.xml");
    //nuevo_coche->setid(1);
    // Leeremos mediante getline, si lo hiciéramos
    // mediante el operador << sólo leeríamos
    // parte de la cadena:
    //hacer que se repita hasta que acabe la cadena de caracteres.
    while(fe.getline(cadena, 1000))
    {
	      //cout << cadena << endl;
	      string cadena2=(string)cadena; //convierto el tipo char en string

	     if (cadena2 == "	<pieza>") {
	          jugador=true;
	          nueva_pieza = new Pieza;
	      }
	     if(cadena2.find("<id>") !=string::npos && jugador==true){        ;
	     	//cout << "id" <<endl;
	     	//cout<< devuelve(cadena2) <<endl; 
	     	// para convertir con int
	     	nueva_pieza-> setid(stoi(devuelve(cadena2)));
	     	}
	     if(cadena2.find("<nombre>") !=string::npos && jugador==true){     
	     	nueva_pieza-> setnombre(devuelve(cadena2));
	     	//cout << "login"<<endl;
	     	//cout<< devuelve(cadena2) <<endl; 
	     	}
	     	
	     if (cadena2.find("<aerodinamica>") !=string::npos && jugador==true){
	     	nueva_pieza-> setaerodinamica(stoi(devuelve(cadena2)));
	     	//cout << "contraseña"<<endl;
	     	//cout<< devuelve(cadena2) <<endl; 
	     }
	     if (cadena2.find("<aceleracion>") !=string::npos && jugador==true){
	     	nueva_pieza-> setaceleracion(stoi(devuelve(cadena2)));
	     	//stoi para convertir de char a int
	     	//cout << "creditos"<<endl;
	     	//cout<< devuelve(cadena2) <<endl; 
	     }
	      if (cadena2.find("<manejo>") !=string::npos && jugador==true){
	     	nueva_pieza-> setmanejo(stoi(devuelve(cadena2)));
	     	//cout << "numero de victoras"<< endl;
	     	//cout<< devuelve(cadena2) <<endl; 
	     }
	      if (cadena2.find("<velocidadMax>") !=string::npos && jugador==true){
	     	nueva_pieza-> setvelocidad_max(stoi(devuelve(cadena2)));
	     	//cout << "numero de victoras"<< endl;
	     	//cout<< devuelve(cadena2) <<endl; 
	     }
	      if (cadena2.find("<frenada>") !=string::npos && jugador==true){
	     	nueva_pieza-> setfrenada(stoi(devuelve(cadena2)));
	     	//cout << "numero de victoras"<< endl;
	     	//cout<< devuelve(cadena2) <<endl; 
	     }
	     if (cadena2.find("<precio>") !=string::npos && jugador==true){
	     	nueva_pieza-> setprecio(stoi(devuelve(cadena2)));
	     	//cout << "numero de victoras"<< endl;
	     	//cout<< devuelve(cadena2) <<endl; 
	     }
	     if (cadena2.find("</pieza>") !=string::npos && jugador==true){
	     	jugador=false;
	     	catalogo_pieza = resizepiezas(catalogo_pieza, total_piezas, total_piezas, total_piezas+1);
			//resizedos(lista_player, total_player);
			catalogo_pieza[total_piezas-1]=nueva_pieza;
			nueva_pieza = 0;
    		delete nueva_pieza;
     	}
    }
}
void Cristurismo::imprimirusuario (Jugador *u){
	cout << BLUE_COLOR << "ID: " << u->getidjugador() << RESTORE_DEFAULT_COLOR<<"\t" << endl;
	cout << GREEN_COLOR << "Login: " << u->getlogin() << RESTORE_DEFAULT_COLOR<<"\t" << endl;
	cout << GREEN_COLOR << "Passwd: "<<u->getpasswd () << RESTORE_DEFAULT_COLOR<<"\t" << endl;
	cout << PURPLE_COLOR << "Creditos: "<<u->getcreditos ()<< RESTORE_DEFAULT_COLOR<<"\t" << endl;
	cout << BLUE_COLOR << "Numero de victorias: "<<u->getnumerovictorias ()<< RESTORE_DEFAULT_COLOR<<"\t" << endl;
}

void Cristurismo::imprimirvehiculo (Vehiculo *u){
	cout << BLUE_COLOR << "ID: " << u->getid() << RESTORE_DEFAULT_COLOR<<"\t" << endl;
	cout << BLUE_COLOR << "marca: " << u->getmarca() << RESTORE_DEFAULT_COLOR<<"\t" << endl;
	cout << GREEN_COLOR << "modelo: " << u->getmodelo() << RESTORE_DEFAULT_COLOR<<"\t" << endl;
	cout << GREEN_COLOR << "tipo de combustible: "<<u->gettipo_combustible () << RESTORE_DEFAULT_COLOR<<"\t" << endl;
	cout << PURPLE_COLOR << "cilindrada: "<<u->getcilindrada ()<< RESTORE_DEFAULT_COLOR<<"\t" << endl;
	cout << BLUE_COLOR << "velocidad maxima: " << u->getvelocidad_max() << RESTORE_DEFAULT_COLOR<<"\t" << endl;
	cout << GREEN_COLOR << "aerodinamica: " << u->getaerodinamica() << RESTORE_DEFAULT_COLOR<<"\t" << endl;
	cout << GREEN_COLOR << "frenada: "<<u->getfrenada () << RESTORE_DEFAULT_COLOR<<"\t" << endl;
	cout << GREEN_COLOR << "aceleracion: " << u->getaceleracion() << RESTORE_DEFAULT_COLOR<<"\t" << endl;
	cout << BLUE_COLOR << "manejo: " << u->getmanejo() << RESTORE_DEFAULT_COLOR<<"\t" << endl;
	cout << GREEN_COLOR << "imprimiendo pieza " << RESTORE_DEFAULT_COLOR<<"\t" << endl; 
	Pieza **p=u->gettuning();
	cout << BLUE_COLOR <<  "total de piezas: "<< u->gettotal_piezas() << RESTORE_DEFAULT_COLOR<<"\t" << endl;
	for (int i=0; i < u-> gettotal_piezas(); i++){
		this-> imprimirpieza(p[i]);

	}
	cout << PURPLE_COLOR << "imprimiendo pieza tunnig " << RESTORE_DEFAULT_COLOR << "\t" <<endl;
	u->calcularmedia();
	//llamo a calcular media que ya esta el cout no hace falta repetirlo
}
void Cristurismo::imprimirpieza (Pieza *u){
	cout << BLUE_COLOR << "ID: " << u->getid() << RESTORE_DEFAULT_COLOR<<"\t" << endl;
	cout << BLUE_COLOR << "nombre: " << u->getnombre() << RESTORE_DEFAULT_COLOR<<"\t" << endl;
	cout << GREEN_COLOR << "aerodinamica: " << u->getaerodinamica() << RESTORE_DEFAULT_COLOR<<"\t" << endl;
	cout << GREEN_COLOR << "frenada: "<<u->getfrenada () << RESTORE_DEFAULT_COLOR<<"\t" << endl;
	cout << PURPLE_COLOR << "velocidad maxima: "<<u->getvelocidad_max ()<< RESTORE_DEFAULT_COLOR<<"\t" << endl;
	cout << BLUE_COLOR << "manejo: " << u->getmanejo() << RESTORE_DEFAULT_COLOR<<"\t" << endl;
	cout << GREEN_COLOR << "aceleracion: " << u->getaceleracion() << RESTORE_DEFAULT_COLOR<<"\t" << endl;
	cout << GREEN_COLOR << "precio: "<<u->getprecio() << RESTORE_DEFAULT_COLOR<<"\t" << endl;
}
void Cristurismo::borrar_player (Jugador *t, string login){
	Jugador *aux=new Jugador;
	bool  encontrado = false;
	for (int i= 0; i < total_player; i++){
		if (login == lista_player[i]-> getlogin()){
			aux = lista_player[i];

			lista_player[i]=lista_player[total_player-1];
			lista_player[total_player-1]=aux;
			encontrado=true;

		}
	}
	if(encontrado == true){
		lista_player= resize(lista_player, total_player ,total_player,total_player-1);
		
	}
	else
		cout << RED_COLOR << "No se a encontrado el usuario"<< RESTORE_DEFAULT_COLOR <<"\t" << endl;
	
}
void Cristurismo::borrar_vehiculo (Vehiculo *v, int id){
	Vehiculo *aux=new Vehiculo;
	bool  encontrado = false;
	for (int i= 0; i < total_vehiculos; i++){
		if (id == catalogo_vehiculo[i]-> getid()){
			aux = catalogo_vehiculo[i];

			catalogo_vehiculo[i]=catalogo_vehiculo[total_vehiculos-1];
			catalogo_vehiculo[total_vehiculos-1]=aux;
			encontrado=true;

		}
	}
	if(encontrado == true){
		catalogo_vehiculo= resizevehiculo(catalogo_vehiculo,total_vehiculos, total_vehiculos,total_vehiculos-1);
		 //lista_player = resize (lista_player, total_player ,total_player,total_player+1);
	}
	else
		cout << RED_COLOR << "No se a encontrado el usuario"<< RESTORE_DEFAULT_COLOR <<"\t" << endl;
	

}
void Cristurismo::imprimirtabla (){
	//cout << " estos son los total_player" << total_player <<endl;
	for (int i=0; i < total_player; i++){
		//cout<<"aeeee"<<endl;
		imprimirusuario(lista_player[i]);
	}
}
void Cristurismo::imprimir_vehiculo (){
	for (int i=0; i < total_vehiculos; i++){
		imprimirvehiculo(catalogo_vehiculo[i]);
	}
}

void Cristurismo::imprimir_pieza (){
	for (int i=0; i < total_piezas; i++){
		imprimirpieza(catalogo_pieza[i]);
	}
}
void Cristurismo::buscarusuarios (Jugador **tp, string login){
	bool encontrado = false;
	for (int i= 0; i < total_player; i++){
		if (login == tp[i]->getlogin()){			
			encontrado = true;
			cout << " el usuario es" << endl;
			imprimirusuario (tp[i]);
		}
	}
	if (encontrado == false ){
		cout << RED_COLOR << "usuario no encontrado, por favor introduzca el nombre correctamente"<< RESTORE_DEFAULT_COLOR <<"\t" << endl;
	}
	
}
Pieza* Cristurismo::buscarpieza (Pieza **tp, int id){
	Pieza *aux = new Pieza;
	bool encontrado = false;
	for (int i= 0; i < total_piezas; i++){
		if (id == tp[i]->getid()){			
			encontrado = true;
			imprimirpieza (tp[i]);
			aux = tp[i];
		}
	}
	if (encontrado == false ){
		cout << RED_COLOR << "pieza no encontrada, por favor introduzca el nombre correctamente"<< RESTORE_DEFAULT_COLOR <<"\t" << endl;
	}
	return aux;
}
void Cristurismo::buscar_vehiculo (Vehiculo **tp, string marca){
	Vehiculo **v = new Vehiculo*[0];//un vector que contiene el total de player
	int totaltemp=0;
	bool encontrado = false;
	int pos=0;
	for (int i= 0; i < total_vehiculos; i++){
		if (marca== tp[i]->getmarca()){			
			v = resizevehiculo (v, totaltemp ,totaltemp,totaltemp+1);
			v[totaltemp-1] = tp[i];
			encontrado = true;
			cout << " el vehiculo es" << endl;
			imprimirvehiculo (tp[i]);
		}
	}
	if (encontrado == false ){
		cout << RED_COLOR << "vehiculo no encontrado, por favor introduzca el nombre correctamente"<< RESTORE_DEFAULT_COLOR <<"\t" << endl;
	}
}
Vehiculo* Cristurismo::buscar_vehiculo_por_id (Vehiculo **tp, int id){
	Vehiculo *aux = new Vehiculo;
	bool encontrado = false;

	for (int i= 0; i < total_vehiculos; i++){
		if (id == tp[i]->getid()){			
			encontrado = true;
			aux = tp[i];
		}
	}
	if (encontrado == false ){
		cout << RED_COLOR << "Vehiculo no encontrado, por favor introduzca el nombre correctamente"<< RESTORE_DEFAULT_COLOR <<"\t" << endl;
	}
	return aux;
}
Vehiculo* Cristurismo::buscar_vehiculo_por_id_garaje (Vehiculo **tp, int id){
	Vehiculo *aux = new Vehiculo;
	bool encontrado = false;
	for (int i= 0; i < jugador_activo -> gettotatal_vehiculo_garaje(); i++){
		if (id == tp[i]->getid()){			
			encontrado = true;
			aux = tp[i];
		}
	}
	if (encontrado == false ){
		cout << RED_COLOR << "Vehiculo no encontrado, por favor introduzca el nombre correctamente"<< RESTORE_DEFAULT_COLOR <<"\t" << endl;
	}
	return aux;
}

void Cristurismo::asignar_pieza_vehiculo(Vehiculo *v, Pieza *p){
	//Vehiculo *v1=v;
	Pieza *p1 = new Pieza(p);
	Pieza **vt= v->gettuning();

	vt=v-> resizepiezas(vt, v-> gettotal_piezas(),v-> gettotal_piezas(),v-> gettotal_piezas()+1);
	
	v->settotal_piezas(v->gettotal_piezas()+1);
	
	vt[v->gettotal_piezas()-1] = p1;
	
	//imprimirvehiculo(v1);
}
void Cristurismo::designar_pieza_vehiculo(Vehiculo *v, Pieza *p){
	Pieza *p1 = new Pieza(p);
	Pieza **vt= v->gettuning();

	vt=v-> resizepiezas_borrar(vt, v-> gettotal_piezas(),v-> gettotal_piezas(),v-> gettotal_piezas()-1, p1->getid());
	
	v->settotal_piezas(v->gettotal_piezas()-1);

}

void Cristurismo::modificar_vehiculo(Vehiculo **tp, string marca){
	string nueva_marca, nuevo_modelo;
	int totaltemp=0;
	bool encontrado = false;
	int pos=0;
	cout << " entrando en modificar vehiculo " << endl;
	for (int i= 0; i < total_vehiculos; i++){
		if (marca== tp[i]->getmarca()){			
			encontrado = true;
			cout << " introduce la nueca marca." << endl;	
			cin >> nueva_marca;
			tp[i]->setmarca(nueva_marca);
			cout << " introduce el nuevo modelo. " << endl;
			cin >> nuevo_modelo; 
			tp[i]->setmodelo(nuevo_modelo);
		}
	}
	
	
	if (encontrado == false ){
		cout << RED_COLOR << "vehiculo no encontrado, por favor introduzca el nombre correctamente"<< RESTORE_DEFAULT_COLOR <<"\t" << endl;
	}
}
void Cristurismo::modificar_jugador(Jugador **tj, string nombre){
	string nuevo_nombre, nueva_contrasena;
	bool encontrado = false;
	int pos=0;
	cout << " entrando en modificar jugador " << endl;
	for (int i= 0; i < total_player; i++){
		if (nombre== tj[i]->getlogin()){			
			encontrado = true;
			cout << " introduce el nuevo login." << endl;	
			cin >> nuevo_nombre;
			tj[i]->setlogin(nuevo_nombre);
			cout << " introduce la nueva contraseña " << endl;
			cin >> nueva_contrasena; 
			tj[i]->setpasswd(nueva_contrasena);
		}
	}
	
	
	if (encontrado == false ){
		cout << RED_COLOR << "vehiculo no encontrado, por favor introduzca el nombre correctamente"<< RESTORE_DEFAULT_COLOR <<"\t" << endl;
	}
}
void Cristurismo::autologin(){
	string usuario, contrasena;
	bool entra = false;
	int aux=-1;
	importarxmlvehiculo(); 
	importarpiezaxml();
	importarxmljugador();
	 
	
	imprimirtabla();
	//Jugador *primer_jugador = new Jugador;
    //Jugador *segundo_jugador = new Jugador;
     
    //anadirusuarios(primer_jugador, 100, "pancrasio", "granturismo", 11111);
    //anadirusuarios(segundo_jugador, 110, "manue", "manue", 33332);
	
    cout << " indentificate para poder entrar en mi programa como usuario o administrador: " << endl; 
    cin >> usuario;
    cout << "introduce la contraseña: "<< endl;
    cin >> contrasena;
    if (usuario =="admin" && contrasena == "admin"){
			cout<<"entra en menu:" << endl;
			menu_en_pantalla();
			}
		else {
			for(int i=0; i < total_player; i++){
				if(lista_player[i]->getlogin()==usuario && lista_player[i]->getpasswd()==contrasena){
					aux=i;
					entra = true;
					 
				}
			}
			if(entra)
			{
				jugador_activo=lista_player[aux];
				menu_en_pantalla_usuario();
			}
		}
}
Jugador* Cristurismo::agregarnuevojugador (int id, string login, string passwd, double creditos) {
	// falta el tipo carnet bool tipoCarnet[]
	Jugador *nuevo_jug = new Jugador;
	if (nuevo_jug == 0) {
		cerr << "Error. No hay memoria suficiente. Se abortará la ejecución" << endl;
        exit(-1);
    }
    nuevo_jug->setidjugador(id);
	nuevo_jug->setlogin(login);
	nuevo_jug->setpasswd(passwd);
	nuevo_jug->setcreditos(creditos);
	//settipocarnet(u);
    
    return nuevo_jug;
}
char* Cristurismo::resize_char(char *u, int util_v, int &dim_v_actual, int dim_nueva){
	char *nuevo = 0;
    nuevo = new char;
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
   	u = 0;
    delete [] u;
    //4º Devuelvo el puntero del nuevo vector, para que se guarde en la variable del módulo llamante y cambio la dimensión del vector actual
    dim_v_actual = dim_nueva;
    return nuevo;
}
Pieza** Cristurismo::resizepiezas(Pieza **u, int util_v, int &dim_v_actual, int dim_nueva){
	Pieza **nuevo = 0;
    nuevo = new Pieza*[dim_nueva];
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
    u = 0;
    delete [] u;
    //4º Devuelvo el puntero del nuevo vector, para que se guarde en la variable del módulo llamante y cambio la dimensión del vector actual
    dim_v_actual = dim_nueva;
    return nuevo;
}

Jugador** Cristurismo::resize(Jugador **u, int util_v, int &dim_v_actual, int dim_nueva){
	Jugador **nuevo = 0;
    nuevo = new Jugador*[dim_nueva];
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
    u = 0;
    delete [] u;
    //4º Devuelvo el puntero del nuevo vector, para que se guarde en la variable del módulo llamante y cambio la dimensión del vector actual
    dim_v_actual = dim_nueva;
    return nuevo;
}


void Cristurismo::resizedos(Jugador** u, int grado){
            // 1: Reservo un vector auxiliar de tamaño adecuado de tipo float.
            Jugador **aux = new Jugador*[grado+1];
            if (aux == 0){
                cerr << "Error. No hay memoria suficiente. Se abortará la ejecución" << endl;
                exit(-1);
            }
            // 2: Inicializo a 0 todos los coeficientes del vector auxiliar
            for (int i=0; i < grado+1; i++) {
                aux[i]=0;
            }
            // 3: Copio el contenido del antiguo vector de coeficientes
            for (int i = 0; i <total_player; i++){
                    aux[i] = u[i];
            }
            // 4: Borramos la memoria del vector antiguo
            u = 0;
            delete [] u;
            // 5: Reasigno el puntero del objeto a la direccion de memoria donde se ubica el nuevo vector
            u =aux;
            aux = 0;
}
Vehiculo** Cristurismo::resizev4(Vehiculo **u, int util_v, int dim_v_actual, int dim_nueva){
	//cout<<"dn: "<<dim_nueva<<endl;
	Vehiculo **nuevo = new Vehiculo*[dim_nueva];
    if (nuevo == 0){
        cerr << "Error. No hay memoria suficiente. Se abortará la ejecución" << endl;
        exit(-1);
    }
    
    //1.1) Discusión acerca de hasta donde copio en el escenario de disminución
    if (util_v > dim_nueva) //recorto
        util_v = dim_nueva;
	
    //cout << " despues el if util v: "<<util_v << endl;
    //cout << "dim acutla: " << dim_v_actual << endl;
    //2º Copio las componentes del vector antiguo en el nuevo
    for(int i =0; i < util_v; i++){
        nuevo[i] = u[i];
        //cout << "reisze for " <<endl;
    }
    //cout << " despues del for " << endl;
    //3º Libero la memoria del antiguo vector
    u = 0;
    delete [] u;

    //4º Devuelvo el puntero del nuevo vector, para que se guarde en la variable del módulo llamante y cambio la dimensión del vector actual
    //dim_v_actual = dim_nueva;
    //cout <<"dva: " << dim_v_actual << endl;
    return nuevo;
}
Vehiculo** Cristurismo::resizevehiculo(Vehiculo **u, int util_v, int &dim_v_actual, int dim_nueva){
	Vehiculo **nuevo = 0;
    nuevo = new Vehiculo*[dim_nueva];
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
    u = 0;
    delete [] u;
    //4º Devuelvo el puntero del nuevo vector, para que se guarde en la variable del módulo llamante y cambio la dimensión del vector actual
    dim_v_actual = dim_nueva;
    return nuevo;
}
void Cristurismo::comprar_vehiculo(int id){
	Vehiculo *nuevo_vehiculo = new Vehiculo;
	int resultado= 0;
	for(int i=0; i< total_vehiculos; i++){
		if (catalogo_vehiculo[i]-> getid() == id){
			nuevo_vehiculo =catalogo_vehiculo[i];
			int creditos_vehiculo = nuevo_vehiculo->getprecio_actual();

			resultado = jugador_activo -> getcreditos() - creditos_vehiculo ;

			jugador_activo->setcreditos(resultado);
				
		}
	}

	int creditos = jugador_activo -> getcreditos();
	cout << "chachi has comprado el vehiculo "<< endl;
	cout << YELLOW_COLOR <<  "te quedan " << resultado << " creditos" << RESTORE_DEFAULT_COLOR <<"\t" << endl;
}

void Cristurismo::anadirusuarios(Jugador *new_jug, int id, string login, string passwd, double creditos){
	
	 lista_player = resize (lista_player, total_player ,total_player,total_player+1);

	new_jug = agregarnuevojugador(id, login , passwd, creditos);
	lista_player [total_player-1]=new_jug;
	cout<<lista_player[total_player-1]->getlogin() <<endl;

}

void Cristurismo::menu_en_pantalla() {
    int menu, tam, si;  
    int id, id2, idpieza, idvehiculo; 
    string login, passwd, login2, vehiculo, vehiculo2, ju; 
    double creditos; 
    Jugador *j = new Jugador;
    Vehiculo *v =new Vehiculo;
    Pieza *p = new Pieza;
      //bool tipoCarnet[3];
    
    //TablaUsuarios *tu=0;
    do{ //filtro
    cout << " pulsa 1 para importar xml vehiculos: " << endl; 
	cout << " pulsa 2 para imprimir los vehiculos del catalogo: "<< endl;
	cout << " pulsa 3 Imprimir todos los Usuarios actuales "<< endl;
	cout << " pulsa 4 para añadir un jugador " <<  endl;
	cout << " pulsa 5 para buscar un jugador " <<  endl;
	cout << " pulsa 6 para agregar un nuevo vehiculo a catalogo" << endl;
	cout << " pulsa 7 para buscar un vehiculo " << endl;
	cout << " pulsa 8 para borrar un jugador del catalogo" << endl;
	cout << " pulse 9 imprimir todos los vehiculos: " << endl;
	cout << " pulsa 10 para borrar un vehiculo del catalogo" << endl;
	cout << " pulsa 11 para importar xml de jugador: " << endl; 
	cout << " pulsa 12 para imprimir todos los juagadores" << endl;
	cout << " pulsa 13 para imprimir pieza " << endl;
	cout << " pulsa 14 crear una pieza " << endl;
	cout << " pulsa 15 importar todas las piezas " << endl;
	cout << " pulsa 16 para imprimir todas las piezas " << endl;
	cout << " pulsa 17 para modificar los datos del jugador" << endl;
	cout << " pulsa 18 para modificar los datos del Vehiculo " << endl;
	cout << " pulsa 19 para buscar pieza por id" << endl;
	cout << " pulsa 20 para asignar pieza a Vehiculo " << endl;
	cout << " pulsa 21 para designar una pieza a un Vehiculo " << endl;
	cout << " pulsa 25 para salir del administrador y ir al menu del usuario " << endl;
	cout << " pulsa 26 para salir "<< endl;
    cin >> menu;
    	switch (menu) {
        	case 1:
       	 	
				cout << "Acabas de importar el xml: "<< endl;
				//importarxmlvehiculo();         
    		break; 
    		case 2:
    			cout << "vamos a imprimir el xml: " << endl;
    			imprimir_vehiculo();

    		break; 
    		case 3:
    			cout << "vamos a imprimir todos los usuarios: " << endl;
    			imprimirtabla ();
    		break; 
    		
    		case 4:
        	//añadimos los usuarios
        	cout << CYAN_COLOR << "Vamos añadir a un jugador: "<< RESTORE_DEFAULT_COLOR <<"\t" << endl;

			cout << YELLOW_COLOR << "introduce id el jugador"<< RESTORE_DEFAULT_COLOR <<"\t" << endl;
			cin >> id;
			cout << YELLOW_COLOR << "introduce login el jugador"<< RESTORE_DEFAULT_COLOR <<"\t" << endl;
			cin >> login;
			cout << YELLOW_COLOR << "introduce contraseña"<< RESTORE_DEFAULT_COLOR <<"\t" << endl;
			cin >> passwd;
			cout << YELLOW_COLOR << "introduce los creditos "<< RESTORE_DEFAULT_COLOR <<"\t" << endl;
			cin >> creditos;
			anadirusuarios(j, id, login, passwd, creditos);
        break;
        case 5:
   			cout << "vamos a buscar un jugador: " << endl;
   			cout << CYAN_COLOR << "Introduce el login del jugador que quieres buscar."<< RESTORE_DEFAULT_COLOR <<"\t" << endl;
			cin >> login2;
   			buscarusuarios(lista_player, login2);
    	break; 
    	case 6:
    		cout << "vamos a buscar añadir un nuevo vehiculo " << endl;
   			agregarnuevovehiculo();
    	break; 
    	case 7:
    		cout << "vamos a buscar un vehiculo: " << endl;
    		cout << CYAN_COLOR << "Introduce la marca del vehiculo quieres buscar."<< RESTORE_DEFAULT_COLOR <<"\t" << endl;
			cin >> vehiculo;
    		buscar_vehiculo(catalogo_vehiculo, vehiculo);
    	break; 
    	case 8:
        		cout << RED_COLOR << "¿Seguro que quieres borrar a un player?: "<< RESTORE_DEFAULT_COLOR <<"\t" << endl;
        		cout << CYAN_COLOR << "Introduce el nombre del player que quieres borrar"<< RESTORE_DEFAULT_COLOR <<"\t" << endl;
        		cin >> login;
        		borrar_player (j, login);
			break; 
    	
    	
    	case 9:
    			cout << "vamos a imprimir todos los vehiculos: " << endl;
    			imprimir_vehiculo();
    		break; 
    	case 10:
        		cout << RED_COLOR << "¿Seguro que quieres borrar a un vehiculo: "<< RESTORE_DEFAULT_COLOR <<"\t" << endl;
        		cout << CYAN_COLOR << "Introduce el id del Vehiculo que quieres borrar"<< RESTORE_DEFAULT_COLOR <<"\t" << endl;
        		cin >> id;
        		borrar_vehiculo (v, id);
			break;
		case 11:
       	 	
				cout << "Acabas de importar el xml: "<< endl;
				//importarxmljugador();         
    		break;
    	case 12:
    			cout << "vamos a imprimir todos los jugadores: " << endl;
    			imprimirtabla();
    		break; 
    	case 13:
    			cout << "vamos a imprimir todos las piezas: " << endl;
    			imprimir_pieza();
    		break; 
    	case 14:
    			cout << "vamos a crear una pieza: " << endl;
    			agregarnuevapieza();
    	break; 
    	case 15:
    			cout << "vamos a importar una pieza: " << endl;
    			//importarpiezaxml();
    	break;
    	case 16:
    			cout << "vamos a imprimir todas las piezas: " << endl;
    			imprimir_pieza();
    	break;
    	case 17:
    		cout << "vamos modificar los datos del jugador " << endl;
    		cout << CYAN_COLOR << "Introduce el nombre del jugador quieres modificar."<< RESTORE_DEFAULT_COLOR <<"\t" << endl;
			cin >> ju;
    		modificar_jugador(lista_player, ju);
    	break; 
    	case 18:
    		cout << "vamos a modificar los datos a un vehiculo: " << endl;
    		cout << CYAN_COLOR << "Introduce la marca del vehiculo quieres modificar."<< RESTORE_DEFAULT_COLOR <<"\t" << endl;
			cin >> vehiculo2;
    		modificar_vehiculo(catalogo_vehiculo, vehiculo2);
    	break; 
    	case 19:
    		cout << "vamos a buscar una pieza por id " << endl;
    		cout << CYAN_COLOR << "Introduce la pieza que quieres buscar."<< RESTORE_DEFAULT_COLOR <<"\t" << endl;
			cin >> id2;
    		buscarpieza(catalogo_pieza, id2);
    	break; 
    	case 20:
    		cout << "escriba la id del vehiculo que le quiere asignar la pieza " << endl;
    		cin >> idvehiculo;
    		cout << "escriba la id de la pieza que quieres asignar " << endl;
    		cin >> idpieza; 
    		v= this-> buscar_vehiculo_por_id_garaje(catalogo_vehiculo, idvehiculo);
    		p= this->buscarpieza(catalogo_pieza, idpieza);
    		asignar_pieza_vehiculo(v, p);
    	break;
    	case 21:
    			imprimir_pieza();
	    		cout << "escriba la id del vehiculo que le quiere quitar la pieza " << endl;
	    		cin >> idvehiculo;
	    		cout << "escriba la id de la pieza que quieres quitar " << endl;
	    		cin >> idpieza; 
	    		v = this-> buscar_vehiculo_por_id_garaje(jugador_activo -> getgaraje(), idvehiculo);
	    		//cout << " despues de buscar vehiculo id "<< endl;
	    		p = this->buscarpieza(catalogo_pieza, idpieza);
	    	
	    		//cout << "llmando a asignar pieza " << endl;
	    		designar_pieza_vehiculo(v, p);	
    	break;
		case 25:
        	menu_en_pantalla_usuario();
		break;
    	} 
	}while(menu != 26 ); 
}
void Cristurismo::menu_en_pantalla_usuario() {
    int menu, tam, si;  
    int id, idvehiculo, idpieza; 
    double creditos_pieza, creditos_vehiculo;
    int resultado;
    string login, passwd, login2, vehiculo; 
    double creditos; 
    Jugador *j = new Jugador;
    Vehiculo *v =new Vehiculo;
    Pieza *p = new Pieza;
    Camion *camion_virtual = new Camion;
    Coche *coche_virtual = new Coche;
    Moto *moto_virtual = new Moto;
    //bool tipoCarnet[3];
  
    //TablaUsuarios *tu=0;
    do{ //filtro
    cout << " pulsa 1 comprar vehiculo " << endl; 
	cout << " pulsa 2 para imprimir los vehiculos del catalogo: "<< endl;
	cout << " pulsa 3 buscar un vehiculo "<< endl;
	cout << " pulsa 4 consultar el estado del garaje "<< endl;
	cout << " pulsa 5 para comprar una pieza a vehiculo "<< endl;
	cout << " pulsa 6 para vender un vehiculo" << endl;
	cout << " pulsa 7 para vender una pieza de vehiculo " << endl;
	cout << " pulsa 8 para hacer funciones virtuales " << endl;
	cout << " pulsa 11 para salir "<< endl;
    cin >> menu;
    	switch (menu) {
        	case 1:
       	 	
				cout << "vamos a comprar un nuevo vehiculo dime el id " << endl;
   				cin >> id;
   				comprar_vehiculo(id);       
    		break;

    		case 2:
    			cout << "vamos a imprimir todos los vehiculos: " << endl;
    			
    			imprimir_vehiculo();
    			
    		break; 
    		case 3:
    			
	   			cout << "vamos a buscar un vehiculo: " << endl;
    			cout << CYAN_COLOR << "Introduce la marca del vehiculo quieres buscar."<< RESTORE_DEFAULT_COLOR <<"\t" << endl;
				cin >> vehiculo;
    			buscar_vehiculo(catalogo_vehiculo, vehiculo);
    			
    		break;
    		case 4:
    			cout << "mostrando todos los vehiculos del garaje " << endl;     
    			jugador_activo ->consultargaraje();
    			
    		break;
    		case 5:
    			imprimir_pieza();
	    		cout << "escriba la id del vehiculo que le quiere asignar la pieza " << endl;
	    		cin >> idvehiculo;
	    		cout << "escriba la id de la pieza que quieres asignar " << endl;
	    		cin >> idpieza; 
	    		v = this-> buscar_vehiculo_por_id_garaje(jugador_activo -> getgaraje(), idvehiculo);
	    		//cout << " despues de buscar vehiculo id "<< endl;
	    		p = this->buscarpieza(catalogo_pieza, idpieza);
	    	
	    		creditos_pieza = p->getprecio();

				resultado = jugador_activo -> getcreditos() - creditos_pieza;

				jugador_activo->setcreditos(resultado);
				creditos = jugador_activo -> getcreditos();
				cout << YELLOW_COLOR <<  "te quedan " << resultado << " creditos" << RESTORE_DEFAULT_COLOR <<"\t" << endl;

	    		//cout << "llmando a asignar pieza " << endl;
	    		asignar_pieza_vehiculo(v, p);	
    			
    		break;
    		case 6:
    			cout << "vamos a vender un nuevo vehiculo dime el id " << endl;
   			
	    		cout << "escriba la id del vehiculo que le quiere vender" << endl;
	    		cin >> idvehiculo;
	
	    		v = this-> buscar_vehiculo_por_id_garaje(jugador_activo -> getgaraje(), idvehiculo);
	    		creditos_vehiculo = v->getprecio_base();

				resultado = creditos_vehiculo + jugador_activo -> getcreditos();

				jugador_activo->setcreditos(resultado);
				creditos = jugador_activo -> getcreditos();
				cout << YELLOW_COLOR <<  "te quedan " << resultado << " creditos" << RESTORE_DEFAULT_COLOR <<"\t" << endl;
    			
    			
    		break;
    		case 7:
    			   
    			imprimir_pieza();
	    		cout << "escriba la id del vehiculo que le quiere quitar la pieza " << endl;
	    		cin >> idvehiculo;
	    		cout << "escriba la id de la pieza que quieres quitar " << endl;
	    		cin >> idpieza; 
	    		v = this-> buscar_vehiculo_por_id_garaje(jugador_activo -> getgaraje(), idvehiculo);
	    		//cout << " despues de buscar vehiculo id "<< endl;
	    		p = this->buscarpieza(catalogo_pieza, idpieza);
	    	
	    		creditos_pieza = p->getprecio();

				resultado = jugador_activo -> getcreditos() + creditos_pieza;

				jugador_activo->setcreditos(resultado);
				creditos = jugador_activo -> getcreditos();
				cout << YELLOW_COLOR <<  "te quedan " << resultado << " creditos" << RESTORE_DEFAULT_COLOR <<"\t" << endl;

	    		//cout << "llmando a asignar pieza " << endl;
	    		designar_pieza_vehiculo(v, p);	
    			
    		break;
    		case 8:
    			
    			cout << "opciones virtuales " << endl;  
    			cout << YELLOW_COLOR <<  "la moto hace: " << RESTORE_DEFAULT_COLOR <<"\t" << endl;   
    			moto_virtual -> imprimir();
    			cout << YELLOW_COLOR <<  "el coche tuneado hace: " << RESTORE_DEFAULT_COLOR <<"\t" << endl; 
    			coche_virtual -> imprimir();
    			cout << YELLOW_COLOR <<  " el camionero: " << RESTORE_DEFAULT_COLOR <<"\t" << endl; 
    			camion_virtual -> imprimir();
    			
    		break;
    	}
	}while(menu != 11); 
}
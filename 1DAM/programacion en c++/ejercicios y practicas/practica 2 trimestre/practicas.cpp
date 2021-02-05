#include <iostream>
#include <string>
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

#include <iostream>
#include <iomanip>
#include <stdio.h>
using namespace std;
/**********************************************************
 ** Definición de sus Prototipos del Tipo de Dato Foto **
 **********************************************************/
struct Foto{
	string ruta;
	string tipo;
	unsigned long int tamanio;
	
};
/**********************************************************
 ** Definición de sus Prototipos del Tipo de Dato Usuario **
 **********************************************************/
struct Usuario{
	string login;
	string nombre;
	string apellido;
	string perfilusuario;
	Foto *v_foto;
	int dim_v_foto;
	int totalfotosusuario;
};
/**********************************************************
 ** Definición de sus Prototipos del Tipo de Dato TablaUsuarios **
 **********************************************************/
struct TablaUsuarios{
	Usuario **tabla;
	int totaltuplas;
};
/**********************************************************
 ** Definición de sus Prototipos del Tipo de Dato Alumno **
 **********************************************************/
void setruta (Foto *f, string ruta);
void settipo (Foto *f, string tipo);
void settamanio (Foto *f, long int tamanio);
void setlogin (Usuario *u, string login);
void setnombre (Usuario *u, string nombre);
void setapellido (Usuario *u, string apellido);
void setperfilusuario (Usuario *u, string perfilusuario);
void setdimvfoto (Usuario *u, int dim_v_foto);
void settotalfotosusuario (Usuario *u, int totalfotosusuario);
string getruta (Foto *f);
string gettipo (Foto *f);
long int gettamanio (Foto *f);
string getlogin (Usuario *u);
string getnombre (Usuario *u);
string getapellido (Usuario *u);
string getperfilusuario (Usuario *u);
int getdimvfoto (Usuario *u);
int gettotalfotosusuario (Usuario *u);
void addUsuario (TablaUsuarios *tu, Usuario *u);
Usuario* crearusuario (string login, string nombre, string apellido, string perfilusuario);
TablaUsuarios* InicializarTabla ();
void imprimirusuario (Usuario *u);
void borrartabla(TablaUsuarios *tu);
void imprimirtabla (TablaUsuarios *tu);
Usuario** resize(Usuario **u, int util_v, int &dim_v_actual, int dim_nueva);
Foto* resizeFotos(Foto *f, int util_v, int &dim_v_actual, int dim_nueva);
void anadirusuarios(TablaUsuarios *tu,string login, string nombre, string apellido, string administrador);
void imprimirfotos(TablaUsuarios *tu,string login);
void introducirfoto(TablaUsuarios *tu ,string login, string ruta, string tipo, int tamanio);
void borrarusuarios (TablaUsuarios *t, string login);
Usuario* buscarusuarios (TablaUsuarios *t, string login);
void menu_en_pantalla();


 /**************************************************************
 ** Implementación de los Prototipos del Tipo de Dato Alumno **
 **************************************************************/

/**
*@ brief le asgina la ruta donde esta la foto es de tipo Foto
*/
void setruta (Foto *f, string ruta){
	f -> ruta = ruta; 
}
/**
*@ brief le asgina el tipo de foto si es jtp, jpg etc...
*/
void settipo (Foto *f, string tipo){
	f -> tipo = tipo;
}
/**
*@ brief le asgina el tamaño de la foto de tipo Foto
*/
void settamanio (Foto *f, long int tamanio){
	f -> tamanio = tamanio;
}
/**
*@brief le pasamos el login de tipo Usuario, el usuario tiene que ser unico.
*/
void setlogin (Usuario *u, string login){
	u -> login = login;
} 
/**
 * @brief Asigna a la variable estructurada de tipo Usuario, el nombre que se pasa a través de la cadena de caracteres.
 */
void setnombre (Usuario *u, string nombre){
	u -> nombre = nombre;
}
/**
 * @brief Asigna a la variable estructurada de tipo Usuario, el apellido que se pasa a través de la cadena de caracteres.
 */
void setapellido (Usuario *u, string apellido){
	u -> apellido = apellido;
}
/**
*@ brief le asgina el perfil del usuario que es de tipo Usuario, y sera string.
*/
void setperfilusuario (Usuario *u, string perfilusuario){
	u -> perfilusuario = perfilusuario;
}

/**
*@ brief le asgina el dimension de la foto, es de tipo Foto.
*/
void setdimvfoto (Usuario *u, int dim_v_foto){
	u -> dim_v_foto = dim_v_foto;
}
/**
*@ brief le asgina el total de fotos de los usuarios, es de tipo Foto.
*/
void settotalfotosusuario (Usuario *u, int totalfotosusuario){
	u -> totalfotosusuario = totalfotosusuario;
}
/**
 * @brief Devuelve por referencia la cadena de caracteres de una variable estructurada de tipo Foto.  
*/
string getruta (Foto *f){
	return f -> ruta; 
}
/**
 * @brief Devuelve por referencia la cadena de caracteres de una variable estructurada de tipo Foto.  
*/
string gettipo (Foto *f){
	return f -> tipo;
}
/**
 * @brief Devuelve por referencia la cadena de caracteres de una variable estructurada de tipo Foto.  
*/
long int gettamanio (Foto *f){
	return f -> tamanio;
}
/**
 * @brief Devuelve por referencia la cadena de caracteres de una variable estructurada de tipo Usuario.
 * @pre Tamaño del vector nombre. La dimensión no puede ser superior a 31 caracteres máximo  
*/
string getlogin (Usuario *u){
	return u -> login;
} 
/**
 * @brief Devuelve por referencia la cadena de caracteres de una variable estructurada de tipo Usuario.
 * @pre Tamaño del vector nombre. La dimensión no puede ser superior a 31 caracteres máximo  
*/
string getnombre (Usuario *u){
	return u -> nombre;
}
/**
 * @brief Devuelve por referencia la cadena de caracteres de una variable estructurada de tipo Usuario.
 * @pre Tamaño del vector nombre. La dimensión no puede ser superior a 31 caracteres máximo  
*/
string getapellido (Usuario *u){
	return u -> apellido;
}
/**
 * @brief Devuelve por referencia la cadena de caracteres de una variable estructurada de tipo Usuario.
 * @pre Tamaño del vector nombre. La dimensión no puede ser superior a 31 caracteres máximo  
*/
string getperfilusuario (Usuario *u){
	return u -> perfilusuario;
}


int getdimvfoto (Usuario *u){
	return u -> dim_v_foto;
}
int gettotalfotosusuario (Usuario *u){
	return u -> totalfotosusuario;
}
/*
*@param vamos añadir a tabla totaltablas es igual a usuario. 
*@param le añadimos un usuario a totaltablas. es un puntero de tipo usuario.
*@param u es un puntero de tipo tabla de usuario.
*/
void addUsuario (TablaUsuarios *tu, Usuario *u){
	//vamos añadir un usuario a la tabla de usuarios. acedo al struc y el struct tiene el totaltuplas.
	
	tu->tabla[tu ->totaltuplas]=u;
	tu -> totaltuplas++;
}
/*
*@info vamos a crear el usuario con un puntero de tipo Usuario.
*@param le pasamos de tipo string el login, nombre, apellido y el perfilusuario
*@param creo un funcion tipo que devuelve un puntero de usuario
*@param creo el vector de fotos dinamico para asignarselo para devolver el usuario
*/
Usuario* crearusuario (string login, string nombre, string apellido, string perfilusuario){
	Foto *f = new Foto [100];
	Usuario *u = new Usuario;
	if (u == 0)
	{
		cerr << "Error. No hay memoria suficiente. Se abortará la ejecución" << endl;
        exit(-1);
    }
    u-> v_foto = f;
    u-> totalfotosusuario = 2;
    setlogin (u, login);
    setnombre(u,nombre);
    setapellido(u, apellido);
    setperfilusuario(u, perfilusuario);
    
    return u;
}
/**
 * @brief Cambia la dimensión del vector a una nueva dim_nueva
 *  1) Creo un vector nuevo con la nueva dimension
 *  2) Copio el contenido del vector que me pasan, en el nuevo vector (OJO SI ES MÁS GRANDE O MÁS CHICO)
 *  3) Libero la memoria del vector que me pasan
 *  4) Devuelvo el puntero del nuevo vector
 */
TablaUsuarios* InicializarTabla () {
	TablaUsuarios *tu=new TablaUsuarios;
	tu ->totaltuplas = 7;
	Usuario **v_pun=new Usuario*[7];
	
	if(tu==0){
		cerr<< "No hay memoria suficiente";
		exit(-1);	
	}

	tu->tabla= v_pun; //asignamos a puntero a puntero para que sea dinamico.
	tu->tabla[0] = crearusuario ("antonioerdelamalaha","antonio","guerrero", "administrador");
	tu->tabla[1] = crearusuario ("jezu","jesus","maestro", "limitado");
	tu->tabla[2] = crearusuario ("señoadarvez","pepe","adarvez", "administrador");
	tu->tabla[3] = crearusuario ("pedroelorejas","Pedro","infantes", "limitado");
	tu->tabla[4] = crearusuario ("shunoe","noe","king", "limitado");
	tu->tabla[5] = crearusuario ("erpepe","pepe","puentes", "administrador");
	tu->tabla[6] = crearusuario ("donramon","ramon","sinpelo", "limitado");

	return tu;
}

void imprimirusuario (Usuario *u){
	cout << BLUE_COLOR << "Login: " << getlogin (u) << RESTORE_DEFAULT_COLOR<<"\t" << endl;
	cout << GREEN_COLOR << "Nombre: " << getnombre(u) << RESTORE_DEFAULT_COLOR<<"\t" << endl;
	cout << GREEN_COLOR << "Apellido: "<<getapellido (u) << RESTORE_DEFAULT_COLOR<<"\t" << endl;
	cout << PURPLE_COLOR << "Perfil: "<<getperfilusuario (u)<< RESTORE_DEFAULT_COLOR<<"\t" << endl;
}

/**
*@brief vamos a borrar la tabla de usuarios
*@brief pasamos la tabla de usuarios
*@brief la igualamos a cero y despues borramos
*@param tabla es un puntero a puntero,
*/

void borrartabla(TablaUsuarios *tu){
	if(tu != 0){
		for (int i = 0; i < tu->totaltuplas; i++){
		
			delete [] tu->tabla[i]->v_foto; //borra el vector fotos de la tabla de usuarios
			delete tu->tabla[i]; // borramos todos los usuarios.
		}


		tu->tabla=0;

		delete tu->tabla;
		tu = 0;
    	delete tu;
    }
    else { 
    	cout << RED_COLOR << "la tabla ya asido borrada no se puede volver a borrar"<< RESTORE_DEFAULT_COLOR <<"\t" << endl;
    }    
}
/**
*@brief vamos a imprimer la tabla de todos los usuarios
*@param le pasamos la tabla de usuarios de tipo puntero.
*@param recorremos un bucle para que recorra todos los usuarios mostrando todos los datos de estos
*@param nombre, apellido, login, foto, etc.
*/
void imprimirtabla (TablaUsuarios *tu){
	for (int i=0; i < tu -> totaltuplas; i++){
		imprimirusuario(tu -> tabla[i]);
	}
}


/**
 * @brief Módulo que aumenta/disminuye la dimensión del vector de punteros a usuario, cuya dirección se le pasa por copia.
 * @info Si las dim_nueva < dim_v_actual --> OJETE: SE PIERDE INFORMACIÓN!!!!!!!
 * @pre util_v <= dim_v_actual
 * @post util_v y dim_v_actual se modifican apropiadamente en el interior, por lo tanto fuera se verán también afectadas!!!!!!!!!!!!!!!!!!!!!!!
 * @return La dirección de memoria del vector nuevo que ya tiene la dimensión nueva, y copiados los elementos del vector antiguo (hasta donde quepa).
 */
Usuario** resize(Usuario **u, int util_v, int &dim_v_actual, int dim_nueva){
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

Foto* resizeFotos(Foto *f, int util_v, int &dim_v_actual, int dim_nueva){
	Foto *vfoto= new Foto;
  
    
    //1.1) Discusión acerca de hasta donde copio en el escenario de disminución
    if (util_v > dim_nueva) //recorto
        util_v = dim_nueva;
	
    
    //2º Copio las componentes del vector antiguo en el nuevo
    for(int i =0; i < util_v; i++)
        vfoto[i] = f[i];
    //3º Libero la memoria del antiguo vector
    delete [] f;
    //4º Devuelvo el puntero del nuevo vector, para que se guarde en la variable del módulo llamante y cambio la dimensión del vector actual
    dim_v_actual = dim_nueva;
    return vfoto;
}
/*
*@pre al resize le pasamos la tabla que queremos redimensionar y le sumamanos uno
*@param creamos un puntero de tipo usuario y creamos el usuario
*@param asignamos a la ultima posicion que hemos redimensionado el usuario. le ponemos -1 para que no se salga del vector.
*/
void anadirusuarios(TablaUsuarios *tu,string login, string nombre, string apellido, string administrador){
	
	tu->tabla = resize (tu->tabla, tu->totaltuplas,tu->totaltuplas,tu->totaltuplas+1);
	Usuario *u = crearusuario(login, nombre, apellido, administrador);
	tu->tabla[tu->totaltuplas-1]=u;

}
/*
*@pre pasamos los usuarios ya creados para poder añadir las fotos
*@pre pasarle el usuario que queremos buscar
*@param creamos un puntero dinamico que vamos a borrar
*@param le pasamos el usuario que es de tipo puntero
*@post devolvemos las fotos que hayamos creado
*/
void imprimirfotos(TablaUsuarios *tu,string login){

	bool encontrado=false;
	for(int i=0; i< tu->totaltuplas;i++){
		if(login == getlogin(tu->tabla[i])){
			encontrado = true;
			imprimirusuario(tu->tabla[i]);
			for(int j =0; j < tu->tabla[i]->dim_v_foto; j++){
				
				cout <<BLUE_COLOR<< "Foto: "<< BLUE_COLOR<< endl;
				cout << PURPLE_COLOR <<"El Tipo(pjg, png): " << gettipo(&tu->tabla[i]->v_foto[j]) << RESTORE_DEFAULT_COLOR << endl;
				cout << PURPLE_COLOR <<"La Ruta: "<<getruta(&tu->tabla[i]->v_foto[j]) << RESTORE_DEFAULT_COLOR << endl;
				cout << PURPLE_COLOR<<"EL tamaño:"<< gettamanio(&tu->tabla[i]->v_foto[j]) << RESTORE_DEFAULT_COLOR << endl;
				

			}				
		}	
	}
	if(encontrado == false)
		cout << "el usuario no ha sido encontrado" << endl;		
}
/*
*@pre vamos a introducir las fotos
*@param creamos un puntero dinamico que vamos de un puntero.
*@param realizamos un for para poder introducirle todas las fotos al usuario
*@param if si el login es igual que get login entonces le introducimos la foto
*@param le vamos a sumar una posicion al resize
*@param creamos un puntero de foto llamado f.
*@param le decimos que el puntero de tu(totalusuarios) se lo copiamos a f
*@post devolvemos las fotos que hayamos creado
*/
void introducirfoto(TablaUsuarios *tu ,string login, string ruta, string tipo, int tamanio){

	Usuario **v = new Usuario*[tu->totaltuplas];
	bool encontrado = false;
	for(int i=0; i< tu->totaltuplas;i++){
		cout << tu->totaltuplas << endl;
		cout <<i;
		if(login == getlogin(tu->tabla[i])){
			//for (int j = 0 ; j< getdim_v_foto(tu->punteroapuntero[i]); j++){	
				tu->tabla[i]->v_foto=resizeFotos(tu->tabla[i]->v_foto,tu->tabla[i]->dim_v_foto,tu->tabla[i]->dim_v_foto ,tu->tabla[i]->dim_v_foto+1);			
				encontrado=true;
				Foto *f;
				f=&tu ->tabla[i]-> v_foto[tu->tabla[i]->dim_v_foto-1];
				setruta(f,ruta);
				settipo(f,tipo);
				settamanio(f,tamanio);
			
		}
	}
	if (encontrado == false ){
		cout << RED_COLOR << "usuario no encontrado, por favor introduzca el nombre correctamente"<< RESTORE_DEFAULT_COLOR <<"\t" << endl;
	}
	
}
/*
*@info vamos a borrar un usuario
*@param pasamos un puntero de tipo tablausuarios.
*@param le pasamos el login de tipo string.
*@param creamos un puntero que apunta a una tabla de puteros dinamico
*@param realizamos un for que recorra el usuario que queremos borrar
*@param si el login es diferente que el getlogin guardo en v el t. (t es el usuario que queramos borrar)
*@param  v sera igual que el resize
*@param el usuario aux lo pasamos a ultima posicion para borrarlo
@post borramos v. 
*/
void borrarusuarios (TablaUsuarios *t, string login){
	Usuario *aux=new Usuario;
	bool  encontrado = false;
	for (int i= 0; i < t -> totaltuplas; i++){
		if (login == getlogin(t-> tabla[i])){
			aux = t-> tabla[i];
			t-> tabla[i]=t-> tabla[t->totaltuplas-1];
			t-> tabla[t->totaltuplas-1]=aux;
			encontrado=true;

		}
		
	}
	//cout << "debug " << endl;
	if(encontrado == true){
		t->tabla = resize (t->tabla, t->totaltuplas,t->totaltuplas,t->totaltuplas-1);
		
	}
	else
		cout << RED_COLOR << "No se a encontrado el usuario"<< RESTORE_DEFAULT_COLOR <<"\t" << endl;
	

}
/*
*@pre pasar la foto que queremos borrar
*@param pasar un puntero de tipo foto
*@param pasar el nombre de la foto que vamos a borrar
*
*/
/*
void borrarfoto (Foto *f, string foto){
	Foto *aux=new Foto;
	bool  encontrado = false;
	for (int i= 0; i < t -> totaltuplas; i++){
		if (foto == getfoto(f-> tabla[i])){
			aux = f-> tabla[i];
			f-> tabla[i]=t-> tabla[t->totaltuplas-1];
			f-> tabla[f->totaltuplas-1]=aux;
			encontrado=true;

		}
		
	}
	//cout << "debug " << endl;
	if(encontrado == true){
		f->tabla = resize (f->tabla, f->totaltuplas,f->totaltuplas,f->totaltuplas-1);
		
	}
	else
		cout << RED_COLOR << "No se a encontrado la foto"<< RESTORE_DEFAULT_COLOR <<"\t" << endl;

}
*/


Usuario* buscarusuarios (TablaUsuarios *t, string login){
	Usuario **v = new Usuario*[t->totaltuplas];
	bool encontrado = false;
	for (int i= 0; i < t -> totaltuplas; i++){
		if (login == getlogin(t-> tabla[i])){
			v[i] = t-> tabla[i];
			encontrado = true;
			cout << " el usuario es" << endl;
			imprimirusuario (t->tabla[i]);
		}
	}
	if (encontrado == false ){
		cout << RED_COLOR << "usuario no encontrado, por favor introduzca el nombre correctamente"<< RESTORE_DEFAULT_COLOR <<"\t" << endl;
	}
}


/*
*@pre haremos todas lass llamadas y todas las funciones en el menu.
*@param todas las funciones las llamamos desde el menu.
*@param cuando acabe el modulo volveremos a mostrar el menu para hacer otro.
* 1) Crear tabla Usuarios 
* 2) Eliminar tabla Usuarios. 
* 3) Imprimir tabla Usuarios 
* 4) Insertar Usuario en tabla Usuarios.
* 5) Eliminar Usuario en tabla Usuarios. 
* 6) Buscar Usuario por Atributo Login en tabla Usuarios
* 7) Ordenar tabla Usuarios por Atributo totalFotosUsuario 
* 8) Añadir Fotografía a Usuario. 
* 9) Eliminar Fotografía de un Usuario
* 10) Imprimir las Fotografías de un Usuario. 
* 11) Salir ojo!!!! tambien es eliminar ya que tenemos que liberar la memoria.
*/

void menu_en_pantalla() {
    string name, lastname, user, tipo, login, rute, tipe, photo, fous;
    int menu, tam, si;  
    TablaUsuarios *tu=0;
    do{ //filtro
    cout << " pulsa 1 Crear tabla Usuarios " << endl; 
	cout << " pulsa 2 Eliminar tabla Usuarios. "<< endl;
	cout << " pulsa 3 Imprimir tabla Usuarios "<< endl;
	cout << " pulsa 4 Insertar Usuario en tabla Usuarios. "<< endl;
	cout << " pulsa 5 Eliminar Usuario en tabla Usuarios. "<< endl;
	cout << " pulsa 6 Buscar Usuario por Atributo Login en tabla Usuarios "<< endl;
	cout << " pulsa 7 Ordenar tabla Usuarios por Atributo totalFotosUsuario "<< endl;
	cout << " pulsa 8 Añadir Fotografía a Usuario. "<< endl;
	cout << " pulsa 9 Eliminar Fotografía de un Usuario "<< endl;
	cout << " pulsa 10 Imprimir las Fotografías de un Usuario." << endl;
	cout << " pulsa 11 Salir " << endl;
    cin >> menu;
    switch (menu) {
        case 1:
       	 	if(tu!=0){
	
    		cerr << "Error. La tabla ya ha sido creada, borrela antes de volver a generarla" << endl;   
			}
			else
			{
				tu=InicializarTabla();
				cout << BLUE_COLOR << "Acabas de crear la tabla: "<< RESTORE_DEFAULT_COLOR <<"\t" << endl;
			}
	
        break;
        case 2: 
         	//borramos la tabla
			borrartabla(tu);
			tu=0;
			cout << RED_COLOR << "Has borrado la tabla: "<< RESTORE_DEFAULT_COLOR <<"\t" << endl;
         //invocacion de la variable para que lo coja y el sepa donde se tiene que ir al pulsar           
        break;
        case 3:  
        	// llamamos a imprimir los usuarios de la tabla
			cout << CYAN_COLOR << "Imprimiendo la tabla: "<< RESTORE_DEFAULT_COLOR <<"\t" << endl;
			imprimirtabla (tu);  

        break;
        case 4:
        	//añadimos los usuarios
        	cout << CYAN_COLOR << "Vamos añadir a un usuario: "<< RESTORE_DEFAULT_COLOR <<"\t" << endl;

			cout << YELLOW_COLOR << "introduce nombre el usuario"<< RESTORE_DEFAULT_COLOR <<"\t" << endl;
			cin >> user;
			cout << YELLOW_COLOR << "introduce nombre"<< RESTORE_DEFAULT_COLOR <<"\t" << endl;
			cin >> name;
			cout << YELLOW_COLOR << "introduce apellido"<< RESTORE_DEFAULT_COLOR <<"\t" << endl;
			cin >> lastname;
			cout << YELLOW_COLOR << "introduce el tipo usuario (administrador, limitado)"<< RESTORE_DEFAULT_COLOR <<"\t" << endl;
			cin >> tipo;
			
			anadirusuarios (tu, user, name, lastname, tipo);

			//addUsuario(tu, inma);
        break;
        
        case 5:
        		cout << RED_COLOR << "¿Seguro que quieres borrar a tu amigo?: "<< RESTORE_DEFAULT_COLOR <<"\t" << endl;
        		cout << CYAN_COLOR << "Introduce el nombre del usuario que quieres borrar"<< RESTORE_DEFAULT_COLOR <<"\t" << endl;
        		cin >> login;
        		borrarusuarios (tu, login);
			break; 
			case 6:
				cout << BLUE_COLOR << "Vamos a buscar a tu amigo: "<< RESTORE_DEFAULT_COLOR <<"\t" << endl;
				cout << CYAN_COLOR << "Introduce el login del usuario que quieres buscar."<< RESTORE_DEFAULT_COLOR <<"\t" << endl;
				cin >> login;
			buscarusuarios (tu, login);
			break;  
			case 7:
			break;  
			case 8:
				
				cout << CYAN_COLOR << "Vamos añadir fotos al usuario: "<< RESTORE_DEFAULT_COLOR <<"\t" << endl;
				cout << YELLOW_COLOR << "introduce el usuario al que se la quieres crear" << RESTORE_DEFAULT_COLOR <<"\t" << endl;
				cin >> fous;
				cout << YELLOW_COLOR << "introduce la ruta"<< RESTORE_DEFAULT_COLOR <<"\t" << endl;
				cin >> rute;
				cout << YELLOW_COLOR << "introduce el tipo(jpg, png)"<< RESTORE_DEFAULT_COLOR <<"\t" << endl;
				cin >> tipe;
				cout << YELLOW_COLOR << "introduce el tamaño"<< RESTORE_DEFAULT_COLOR <<"\t" << endl;
				cin >> tam;
				
				introducirfoto(tu, fous, rute, tipe, tam);
			break;  
			case 9:
				/*
				cout << CYAN_COLOR << "Vamos eliminar fotos del usuario: "<< RESTORE_DEFAULT_COLOR <<"\t" << endl;
				cout << CYAN_COLOR << "De acuerdo vamos a enseñarte las fotos: "<< RESTORE_DEFAULT_COLOR <<"\t" << endl;
        		cout << CYAN_COLOR << "Introduce el nombre del usuario que quieres borrar"<< RESTORE_DEFAULT_COLOR <<"\t" << endl;
        		cin >> photo;
				//borrarfoto(f, foto);
				*/
			break;  
			case 10:
				
				cout << BLUE_COLOR << "Vamos a buscar a la foto: "<< RESTORE_DEFAULT_COLOR <<"\t" << endl;
				cout << CYAN_COLOR << "Introduce el foto del usuario que quieres buscar."<< RESTORE_DEFAULT_COLOR <<"\t" << endl;
				cin >> login;
				
				imprimirfotos(tu,login);
			break;
			case 11:
			cout << CYAN_COLOR << "Hasta luego compi!!!"<< RESTORE_DEFAULT_COLOR <<"\t" << endl;
			break;    
    }
    
     
                
    }while(menu != 11); 

}
int main (){
	menu_en_pantalla();

}
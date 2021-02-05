//  tipoalumno_plantilla1.cpp
//  
//
//  Created by Jaime Matas Bustos on 13/2/18.
//

#include <iostream>
using namespace std;
/***************************************
** Definición del TIPO DE DATO fecha **
****************************************/
struct Fecha{
    int dia;
    int mes;
    int anio;
};

/***************************************
** Definición del TIPO DE DATO Alumno **
****************************************/
struct Alumno{
    string nombre; //nombre del alumno como máximo de 30 de caracteres
    unsigned int edad;
    string nombres_asignaturas[6];
    int notas[6]; //vector con las notas
    Fecha *fecha_alumno;
    float nota_media;
};

/**********************************************************
 ** Definición de sus Prototipos del Tipo de Dato Alumno **
 **********************************************************/
string getNombre(Alumno *a,string nombre);
int getTamanioNombre(Alumno *a);
unsigned int getEdad(Alumno *a);
void setNombre(Alumno *a, string nombre);
void setUtilNombre(Alumno *a, int util_nombre);
void setEdad(Alumno *a, unsigned int edad);
void setNotas(Alumno *a, int notas[],int util_notas);
void setNombresAsignaturas(Alumno *a);
void printAlumno(Alumno *a);
//void intercambiarAlumnos(Alumno &a, Alumno &b);
float calcularMediaCalificacionesAlumno(Alumno *a,int util_notas);
void setfecha_alumno(Alumno *a, Fecha fecha_alumno);
/**********************************************************
 ** Definición de sus Prototipos del Tipo de Dato fecha **
 **********************************************************/
int getdia(Fecha *a, int dia);
int getmes(Fecha *a, int fecha);
int getanio(Fecha *a, int anio);
void setdia(Fecha *a, int dia);
void setmes(Fecha *a, int mes);
void setanio(Fecha *a, int fecha);
/**************************************************************
 ** Implementación de los Prototipos del Tipo de Dato Fecha **
 **************************************************************/

int getdia(Fecha *a, int dia){
    return a->dia = dia;
}
int getmes(Fecha *a, int mes){
    return a->mes = mes;
}
int getanio(Fecha *a, int anio){
    return a->anio = anio;
}
void setdia(Fecha *a, int dia){
    a->dia = dia;
}
void setmes(Fecha *a, int mes){
    a->mes = mes;
}
void setanio(Fecha *a, int anio){
    a->anio = anio;
}



void setfecha_alumno(Alumno *a, Fecha *fecha_alumno){
    a->fecha_alumno = fecha_alumno;
 
}
/**************************************************************
 ** Implementación de los Prototipos del Tipo de Dato Alumno **
 **************************************************************/
/**
 * @brief Devuelve por copia la cadena de caracteres de una variable estructurada de tipo Alumno.
 */
string getNombre(Alumno *a){
    return a->nombre;
}

/**
 * @brief Devuelve la edad una variable estructurada de tipo Alumno.
 */
unsigned int getEdad(Alumno *a){
    return a->edad;
}
float getnota_media(Alumno *a){
    return a->nota_media;
}
void getNotas (Alumno *a, int notas[]){
    for (int i=0; i < 6; i++){
         notas [i] = a->notas[i]; 
    }
}
/**
 * @brief Asigna a la variable estructurada de tipo Alumno, el nombre que se pasa a través de la cadena de caracteres.
 * @pre El tamaño del vector nombre debe estar filtrado a 30 caracteres (+ el /0).
 */
void setNombre(Alumno *a, string nombre){
    for(int i = 0; i <= 30; i++)
        a->nombre = nombre;
}

/**
 * @brief Asigna a la variable estructurada de tipo Alumno, la edad que se le pasa como parámetro.
 * @pre La edad debe de estar filtrada entre 0 y 120.
 */
void setEdad(Alumno *a, unsigned int edad){
    
    a->edad = edad;
}
void setnotamedia(Alumno *a, float nota_media){
    a->nota_media = nota_media;
}
/**
 * @brief Asigna a la variable estructurada de tipo Alumno, un vector con sus calificaciones en cada asignatura. El orden de las asignaturas será PRO, BD, ED, SI, FOL, LM.
 * @pre El tamaño del vector notas debe estar filtrado e incluir 6 notas (ni más ni menos).
 */
void setNotas(Alumno *a, int notas[], int util_notas){
    for (int i = 0; i < util_notas; i++){
        a->notas[i] = notas[i];
    }
}


/**
 * @brief Establece en la matriz de nombres de asignaturas de una variable de tipo Alumno, los siguientes nombres: PRO, BD, ED, SI, FOL, LM.
 */
void setNombresAsignaturas(Alumno *a){
    a->nombres_asignaturas[0] = "PRO";
    a->nombres_asignaturas[1] = "BD";
    a->nombres_asignaturas[2] = "ED";
    a->nombres_asignaturas[3] = "SI";
    a->nombres_asignaturas[4] = "FOL";
    a->nombres_asignaturas[5] = "LM";
}
void imprime_tiempo(Fecha *a){
    cout << " dia " << getdia(a, a->dia) << endl;
    cout << " mes " << getmes(a, a->mes) << endl;
    cout << " año " << getanio(a, a->anio) << endl;
}

/**
 * @brief Imprime por pantalla el contenido de una variable de tipo Alumno.
 */
void printAlumno(Alumno *a){
    //OBSERVAR EL USO DE LOS MÓDULOS GET VS NO UTILIZARLOS...
    //¿QUÉ PASARÍA SI CAMBIÁSEMOS EL NOMBRE DEL VECTOR DE NOTAS?
    cout << "Nombre Alumno: " << getNombre(a) << endl;
    cout << "Edad: " << getEdad(a) << endl;
    cout << "-----Calificaciones-----" << endl;
    for(int i=0; i < 6; i++)
        cout << " - " << a->nombres_asignaturas[i] << ": " << a->notas[i] << endl;
    
    cout << " nota media " << a->nota_media << endl;

}

/**
 * @brief Imprime el contenido del vector de alumnos
 */
void printVectorAlumno( Alumno v[], int util_v){
    for(int i = 0; i < util_v; i++){
        cout << " print vector alumno " << endl;
        printAlumno(&v[i]);
    }
}
void setAlumnoEnVector(Alumno *v[], int DIM_v, int &util_v, Alumno *a){
    if (util_v < DIM_v){
        v[util_v] = a; //LA VIN QUE POTENSIA (Vuelvo la hacer automáticamente la asignación campo a campo)
        util_v++;
    }else
        cerr << "ERROR: NO HAY ESPACIO PARA EL ALUMNO QUE SE QUIERE INSERTAR" << endl;
}

/**
 * @brief Calcula y devuelve la media de calificaciones de una variable de tipo Alumno.
 */

int calcular_media (int NUM_NOTAS, int media, int notas[]){

    for (int i = 0; i < NUM_NOTAS; i++){
        media = media += notas[i];
    }

    media = media / NUM_NOTAS;

    return media;
}
void intercambiar_eliminar( int posicion, int util, Alumno *vectorAlumnosDAM[], string usuario_eliminado){
    Alumno *aux = new Alumno;
    aux = vectorAlumnosDAM[posicion];
    vectorAlumnosDAM [posicion] = vectorAlumnosDAM [util-1];
    vectorAlumnosDAM[util-1] = aux;

}

Alumno* buscar (Alumno *vectorAlumnosDAM[], int util){
    string pedir;

    cout << " introduce el nombre del alumno que quieres eliminar " << endl;
    cin >> pedir;

    for (int i = 0; i < util; i++){
        if(pedir == vectorAlumnosDAM[i]->nombre){
            cout << " alumno encontrado " << endl;
            printAlumno(vectorAlumnosDAM[i]);
        }
    }
} 
void eliminar_un_alumno (Alumno *alumno){
    delete alumno->fecha_alumno;
    alumno->fecha_alumno = 0;
    
    delete alumno;
    alumno = 0;
}
void eliminar_una_fecha(Fecha *fecha){
    
    delete fecha;
    fecha = 0; 
}

Alumno* crearPersona(){
    Alumno *p = new Alumno;
    Fecha *f = new Fecha;
    p -> fecha_alumno = f;
   
    if (p == 0){
        cerr << "Error. No hay memoria suficiente. Se abortará la ejecución" << endl;
        //exit(-1);
    }
    return p;
}
Fecha* crearFecha(){
    Fecha *f = new Fecha;
    if(f == 0){
        cerr << "Error. No hay memoria suficiente. Se abortará la ejecución" << endl;
        //exit(-1);
    }
    return f;
}

int main(){
    Alumno *Berrios;
    Alumno *Jaime; 
    Alumno *alumnocopiado;
    
    Jaime = crearPersona();
    Berrios = crearPersona();
    alumnocopiado = crearPersona();

    string nombreberrios = "berrios";
    int notasberrios[6] = {8,9,9,9,9,9};
    string nombrejaime = "jaime";
    int notasjaime[6] = {1,1,1,1,7,6};
    int util_notas = 6, media = 0;
    
    //Preparo los datos del Alumno Berrios
    setNombre(Berrios, nombreberrios);
    setEdad(Berrios, 22);
    setNombresAsignaturas(Berrios);
    setNotas(Berrios, notasberrios, util_notas);
    setnotamedia(Berrios, 5.6);
    printAlumno(Berrios);
    
    //Preparo los datos del Alumno Jaime
    setNombre(Jaime, nombrejaime);
    setEdad(Jaime, 23);
    setNombresAsignaturas(Jaime);
    setNotas(Jaime, notasjaime, util_notas);
    setnotamedia(Jaime, 2.2);
    printAlumno(Jaime);
    
    //Fijaros como la asignación de estructuras HACE LA COPIA DE VECTORES AUTOMÁTICAMENTE
    //alumnocopiado = Berrios; //"QUÉ POTEEEEENSIAAAAAA QUE ME LO COPIA TÓ COMPAE VIEO SIN TENER QUE HASER UN FOR NI NÁ"
  
    media = calcular_media(util_notas, media, notasberrios);
    cout << " la media de berrios es " << media << endl;
    
    media = 0;

    media = calcular_media(util_notas, media, notasjaime);
    cout << " la media de jaime es " << media << endl;

    cout << " vamos añadir una fecha al alumno jaime " << endl;
    Fecha *fecha_jaime = 0, *fecha_berrios = 0;
    fecha_jaime= crearFecha();
    fecha_berrios = crearFecha();

    cout << " imprime_tiempo " << endl;

    setfecha_alumno(Jaime, fecha_jaime);
    setfecha_alumno(Berrios, fecha_berrios);

    cout << " imprime_tiempo  de Jaime" << endl;
    setdia(Jaime->fecha_alumno, 1);
    setmes(Jaime->fecha_alumno, 32);
    setanio(Jaime->fecha_alumno, 1933);
    imprime_tiempo(Jaime->fecha_alumno);

    cout << " imprimiendo tiempo de berrios " << endl;
    setdia(Berrios->fecha_alumno, 21);
    setmes(Berrios->fecha_alumno, 2);
    setanio(Berrios->fecha_alumno,1999);
    imprime_tiempo(Berrios->fecha_alumno);

    cout << "/** AMPLIAMOS EL CÓDIGO PARA INCORPORAR VECTORES DE ALUMNOS **/" << endl;
    //Declaro mi vector de Alumnos
    int DIM_vectorAlumnosDAM = 22; //declaro las plazas disponibles
    int util_vectorAlumnosDAM = 3; //declaro las plazas ocupadas en la actualidad
    Alumno *vectorAlumnosDAM;
    vectorAlumnosDAM = new Alumno [DIM_vectorAlumnosDAM];
    
    cout << " borrando los alumnos " << endl;
    eliminar_un_alumno(Jaime);
    eliminar_un_alumno(Berrios);

    cout << " borrando las fechas " << endl;
    eliminar_una_fecha(fecha_jaime);
    eliminar_una_fecha(fecha_berrios);

}
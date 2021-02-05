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
    Fecha fecha_alumno;
};

/**********************************************************
 ** Definición de sus Prototipos del Tipo de Dato Alumno **
 **********************************************************/
string getNombre(Alumno &a,string nombre);
int getTamanioNombre(Alumno &a);
unsigned int getEdad(Alumno &a);
void setNombre(Alumno &a, string nombre);
void setUtilNombre(Alumno &a, int util_nombre);
void setEdad(Alumno &a, unsigned int edad);
void setNotas(Alumno &a, int notas[],int util_notas);
void setNombresAsignaturas(Alumno &a);
void printAlumno(Alumno &a);
void intercambiarAlumnos(Alumno &a, Alumno &b);
float calcularMediaCalificacionesAlumno(Alumno &a,int util_notas);
void setfecha_alumno(Alumno &a, Fecha fecha_alumno);
/**********************************************************
 ** Definición de sus Prototipos del Tipo de Dato fecha **
 **********************************************************/
int getdia(Alumno &f, int dia);
int getmes(Alumno &f, int fecha);
int getanio(Alumno &f, int anio);
void setdia(Alumno &f, int dia);
void setmes(Alumno &f, int mes);
void setanio(Alumno &f, int fecha);
/**************************************************************
 ** Implementación de los Prototipos del Tipo de Dato Fecha **
 **************************************************************/

int getdia(Alumno &f, int dia){
    return f.fecha_alumno.dia = dia;
}
int getmes(Alumno &f, int mes){
    return f.fecha_alumno.mes = mes;
}
int getanio(Alumno &f, int anio){
    return f.fecha_alumno.anio = anio;
}
void setdia(Alumno &f, int dia){
    f.fecha_alumno.dia = dia;
}
void setmes(Alumno &f, int mes){
    f.fecha_alumno.mes = mes;
}
void setanio(Alumno &f, int anio){
    f.fecha_alumno.anio = anio;
}



void setfecha_alumno(Alumno &a, Fecha fecha_alumno){
    a.fecha_alumno = fecha_alumno;
   // cout << " f es = " << fecha_alumno << endl;
}
/**************************************************************
 ** Implementación de los Prototipos del Tipo de Dato Alumno **
 **************************************************************/
/**
 * @brief Devuelve por copia la cadena de caracteres de una variable estructurada de tipo Alumno.
 */
string getNombre(Alumno &a, string nombre){
    return a.nombre = nombre;
}

/**
 * @brief Devuelve la edad una variable estructurada de tipo Alumno.
 */
unsigned int getEdad(Alumno &a, int edad){
    return a.edad = edad;
}

void getNotas (Alumno &a, int notas[]){
    for (int i=0; i <= 6; i++){
         notas [i] = a.notas[i]; 
    }
}
/**
 * @brief Asigna a la variable estructurada de tipo Alumno, el nombre que se pasa a través de la cadena de caracteres.
 * @pre El tamaño del vector nombre debe estar filtrado a 30 caracteres (+ el /0).
 */
void setNombre(Alumno &a, string nombre){
    for(int i = 0; i <= 30; i++)
        a.nombre = nombre;
}

/**
 * @brief Asigna a la variable estructurada de tipo Alumno, la edad que se le pasa como parámetro.
 * @pre La edad debe de estar filtrada entre 0 y 120.
 */
void setEdad(Alumno &a, unsigned int edad){
    a.edad = edad;
}

/**
 * @brief Asigna a la variable estructurada de tipo Alumno, un vector con sus calificaciones en cada asignatura. El orden de las asignaturas será PRO, BD, ED, SI, FOL, LM.
 * @pre El tamaño del vector notas debe estar filtrado e incluir 6 notas (ni más ni menos).
 */
void setNotas(Alumno &a, int notas[], int util_notas){
    for (int i = 0; i < util_notas; i++){
        a.notas[i] = notas[i];
    }
}

/**
 * @brief Establece en la matriz de nombres de asignaturas de una variable de tipo Alumno, los siguientes nombres: PRO, BD, ED, SI, FOL, LM.
 */
void setNombresAsignaturas(Alumno &a){
    a.nombres_asignaturas[0] = "PRO";
    a.nombres_asignaturas[1] = "BD";
    a.nombres_asignaturas[2] = "ED";
    a.nombres_asignaturas[3] = "SI";
    a.nombres_asignaturas[4] = "FOL";
    a.nombres_asignaturas[5] = "LM";
}

/**
 * @brief Imprime por pantalla el contenido de una variable de tipo Alumno.
 */
void printAlumno(Alumno &a){
    //OBSERVAR EL USO DE LOS MÓDULOS GET VS NO UTILIZARLOS...
    //¿QUÉ PASARÍA SI CAMBIÁSEMOS EL NOMBRE DEL VECTOR DE NOTAS?
    cout << "Nombre Alumno: " << getNombre(a, a.nombre) << endl;
    cout << "Edad: " << getEdad(a, a.edad) << endl;
    cout << "-----Calificaciones-----" << endl;
    for(int i=0; i < 6; i++)
        cout << " - " << a.nombres_asignaturas[i] << ": " << a.notas[i] << endl;
}
void imprime_tiempo(Alumno &f){
    cout << " dia " << getdia(f, f.fecha_alumno.dia) << endl;
    cout << " mes " << getmes(f, f.fecha_alumno.mes) << endl;
    cout << " año " << getanio(f, f.fecha_alumno.anio) << endl;
}
/**
 * @brief Intercambia el contenido de dos variables de tipo Alumno.
 */
void intercambiarAlumnos(Alumno &a, Alumno &b){
    Alumno aux = a;
    a = b;
    b = aux;
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
int main(){
    Alumno Berrios, Jaime, alumnocopiado;
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
    printAlumno(Berrios);
    
    //Preparo los datos del Alumno Jaime
    setNombre(Jaime, nombrejaime);
    setEdad(Jaime, 23);
    setNombresAsignaturas(Jaime);
    setNotas(Jaime, notasjaime, util_notas);
    printAlumno(Jaime);
    
    //Fijaros como la asignación de estructuras HACE LA COPIA DE VECTORES AUTOMÁTICAMENTE
    alumnocopiado = Berrios; //"QUÉ POTEEEEENSIAAAAAA QUE ME LO COPIA TÓ COMPAE VIEO SIN TENER QUE HASER UN FOR NI NÁ"
    setNombre(alumnocopiado, nombreberrios);
    printAlumno(alumnocopiado);
    
    /*Aquí habría que incluir el código para probar los módulos Intercambiar Alumnos y Calcular Calificaciones Medias*/
    
    // 1) Probamos Intercambiar Alumnos y mostramos por pantalla los alumnos intercambiados.
    intercambiarAlumnos(Berrios, Jaime);   
    cout << " berrrios intercambiados " << endl;
    printAlumno(Berrios);
    cout << " jaime intercambiados " << endl;
    printAlumno(Jaime);
    intercambiarAlumnos(Jaime, Berrios);
    // 2) Probamos Calcular Calificación Media de los Alumnos y las mostramos por pantalla.
    media = calcular_media(util_notas, media, notasberrios);
    cout << " la media de berrios es " << media << endl;

    media = 0;

    media = calcular_media(util_notas, media, notasjaime);
    cout << " la media de jaime es " << media << endl;

    cout << " vamos añadir una fecha al alumno jaime " << endl;
    setdia(Jaime, 22);
    setmes(Jaime, 1);
    setanio(Jaime, 1111);
    setdia(Berrios, 2);
    setmes(Berrios, 22);
    setanio(Berrios, 1899);

    cout << " imprime_tiempo  de Jaime" << endl;
    imprime_tiempo(Jaime);

    cout << " imprimiendo tiempo de berrios " << endl;
    imprime_tiempo(Berrios);
    
}

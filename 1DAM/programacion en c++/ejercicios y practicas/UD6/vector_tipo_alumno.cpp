#include <iostream>
using namespace std;

struct Alumno{
    char nombre[31]; //nombre del alumno como máximo de 30 de caracteres
    unsigned int edad;
    char nombres_asignaturas[6][4];
    int notas[6]; //vector con las notas
};

/**
 * @brief Asigna a la variable estructurada de tipo Alumno, el nombre que se pasa a través de la cadena de caracteres.
 * @pre El tamaño del vector nombre debe estar filtrado a 30 caracteres (+ el /0).
 */
void setNombre(Alumno &a, char nombre[]){
    for(int i=0; i <= 30; i++)
        a.nombre[i] = nombre[i];
}

/**
 * @brief Asigna a la variable estructurada de tipo Alumno, la edad que se le pasa como parámetro.
 * @pre La edad debe de estar filtrada entre 0 y 120.
 */
void setEdad(Alumno &a, unsigned int edad){
    a.edad = edad;
}

/**
 * @brief Asigna a la variable estructurada de tipo Alumno, un vector con sus calificaciones en cada asignatura.
 * El orden es PRO, BD, ED, SI, FOL, LM.
 * @pre El tamaño del vector notas debe estar filtrado e incluir 6 notas (ni más ni menos).
 */
void setNotas(Alumno &a, int notas[]){
    for(int i=0; i < 6; i++)
        a.notas[i] = notas[i];
}

/**
 * @brief Establece en la matriz de nombres de asignaturas los siguientes nombres: PRO, BD, ED, SI, FOL, LM.
 */
void setNombresAsignaturas(Alumno &a){
    //a.nombres_asignaturas[0] = {'P','R','O','\0'};
    //a.nombres_asignaturas[1] = {'B','D','\0'};
    //a.nombres_asignaturas[2] = {'E','D','\0'};
    //a.nombres_asignaturas[3] = {'S','I','\0'};
    //a.nombres_asignaturas[4] = {'F','O','L','\0'};
    //a.nombres_asignaturas[5] = {'L','M','\0'};
}
void printAlumno(const Alumno &a){
    cout << "Nombre Alumno: " << a.nombre << endl;
    cout << "Edad: " << a.edad << endl;
    cout << "-----Calificaciones-----" << endl;
    for(int i=0; i < 6; i++)
        cout << " - " << a.nombres_asignaturas[i] << ": " << a.notas[i] << endl;
}

/**
 * @brief Agrego al vector de Alumnos, el alumno a que le paso por referencia
 */
void setAlumnoEnVector(Alumno v[], const int DIM_v, int &util_v, const Alumno &a){
    if (util_v < DIM_v){
        v[util_v] = a; //LA VIN QUE POTENSIA (Vuelvo la hacer automáticamente la asignación campo a campo)
        util_v++;
    }else
        cerr << "ERROR: NO HAY ESPACIO PARA EL ALUMNO QUE SE QUIERE INSERTAR" << endl;
}

/**
 * @brief Imprime el contenido del vector de alumnos
 */
void printVectorAlumno(const Alumno v[], int util_v){
    for(int i = 0; i < util_v; i++)
        printAlumno(v[i]);
}
void eliminar_alumno(Alumno v[], int util, char nombre[]){
    Alumno aux_nombre[util];
    char aux[7];
    bool encontrado = false;
    int util2 = 0;

    cout << " introduce el nombre del usuario que quieres eliminar " << endl;
    cin >> aux;


    for (int i = 0; i < util; i++){
        //cout << " i vale " << i << endl;
        if(nombre == aux){
            aux_nombre[util2] = v[i];
            util2++;
            encontrado == true; 
           // cout << " v " << printAlumno[i] << " util2 " << util2 << endl; 
        }
    }

    util = 0;
    for(int i = 0; i < util2; i++){
        v[util++] = aux_nombre[i];
        util++;
    }

    if(encontrado == true){
        cout << " el alumno se a encontrado " << endl;
    }else
        cout << " alumno no encontrado " << endl;
}

int main(){
    Alumno Berrios, Jaime, alumnocopiado;
    char nombreberrios[31] = {'B','e','r','r','i','o','s','\0'};
    int notasberrios[6] = {5,6,5,8,6,7};
    char nombrejaime[31] = {'J','a','i','m','e','\0'};
    int notasjaime[6] = {5,6,5,7,7,6};
    
    //Preparo los datos de Berrios
    setNombre(Berrios, nombreberrios);
    setEdad(Berrios, 22);
    setNombresAsignaturas(Berrios);
    setNotas(Berrios, notasberrios);
    printAlumno(Berrios);
    
    //Preparo los datos de Jaime
    setNombre(Jaime, nombrejaime);
    setEdad(Jaime, 23);
    setNombresAsignaturas(Jaime);
    setNotas(Jaime, notasjaime);
    printAlumno(Jaime);
    
    //Fijaros como la asignación de estructuras HACE LA COPIA DE VECTORES AUTOMÁTICAMENTE
    alumnocopiado = Berrios; //"QUÉ POTEEEEENSIAAAAAA QUE ME LO COPIA TÓ COMPAE VIEO SIN TENER QUE HASER UN FOR NI NÁ"
    //setNombre(alumnocopiado,"POTENSIA");
    printAlumno(alumnocopiado);
    
    
    cout << "/** AMPLIAMOS EL CÓDIGO PARA INCORPORAR VECTORES DE ALUMNOS **/" << endl;
    //Declaro mi vector de Alumnos
    const int DIM_vectorAlumnosDAM = 22; //declaro las plazas disponibles
    int util_vectorAlumnosDAM = 0; //declaro las plazas ocupadas en la actualidad
    Alumno vectorAlumnosDAM[DIM_vectorAlumnosDAM];
    
    cout << "/** AGREGO ALUMNO AL VECTOR SIN MÓDULO **/"<< endl;
    //Agregamos un elemento al vector de Alumnos de DAM
    vectorAlumnosDAM[0] = Berrios; // LA VIN VIEOOO QUE POTENSIAAAA (RECUERDA SE ASIGNA CAMPO A CAMPO AUTOMÁTICAMENTE)
    printAlumno(vectorAlumnosDAM[0]); //Para incrédulos que no tienen FE, voy imprimir la primera posición del vector...
    util_vectorAlumnosDAM++; //aumento sus útiles como en cualquier vector de antes
    
    cout << "/** AGREGO ALUMNO AL VECTOR CON MÓDULO **/"<< endl;
    cout << "-!!! "<< util_vectorAlumnosDAM << endl;
    //Agregamos un elemento al vector de Alumnos de DAM USANDO MÓDULOS
    setAlumnoEnVector(vectorAlumnosDAM,DIM_vectorAlumnosDAM,util_vectorAlumnosDAM,Jaime);
    cout << "-!!! "<< util_vectorAlumnosDAM << endl;
    //Y ahora imprimo TOOOOODO el vector de Alumnos para incrédulos
    for(int i = 0; i < util_vectorAlumnosDAM; i++)
        printAlumno(vectorAlumnosDAM[i]);
    
    cout << "/** IMPRIMO AHORA CON EL MÓDULO IMPRIME VECTOR DE ALUMNOS **/"<< endl;
    setAlumnoEnVector(vectorAlumnosDAM,DIM_vectorAlumnosDAM,util_vectorAlumnosDAM,alumnocopiado);
    printVectorAlumno(vectorAlumnosDAM,util_vectorAlumnosDAM);
    
    eliminar_alumno(vectorAlumnosDAM, util_vectorAlumnosDAM, nombreberrios);

    /** 1º) Módulo para Buscar en el Vector de Alumnos, el alumno con nombre X **/
    /** 2º) Modificar la estructura y agregarle un campo llamado NOTA MEDIA, que tiene la media de las notas de cada      uno, y tendréis que hacer un módulo que calcule la media de un vector para almacenarlo después en la estructura
     void setNotaMedia (Alumno &a) OJO LA PRECONDICIÓN!! **/
    /** 3º) Módulo que Ordene un vector de Alumnos por nota media de mayor a menor **/
    
}
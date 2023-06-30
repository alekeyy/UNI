// #include "Archivos.h"
//ayuda carga cadenas
#include "funciones.h"
#include <cstdio>
#include <iostream>
using namespace std;

void cargarCadena(char *pal, int tam){
    int i;
    fflush(stdin);
    for(i=0;i<tam;i++){
        pal[i]=cin.get();
        if(pal[i]=='\n') break;
    }
    pal[i]='\0';
    fflush(stdin);
}

int menu(){
    int opc;
    cout << "------------------------" << endl;
    cout << " M    E    N    U" << endl;
    cout << "------------------------" << endl;
    cout << "10 - Crear Archivo" << endl;
    cout << "11 - Agregar Registro" << endl;
    cout << "12 - Modificar Registro" << endl;
    cout << "13 - Agregar Registro" << endl;
    cout << "14 - Modificar Registro" << endl;
    cout << "------------------------" << endl;
    cout << "  P   U   N   T   O   S  " << endl;
    cout << "------------------------" << endl;
    cout << "1 - Ordenar Decreciente" << endl;
    cout << "2 - Agregar Ciudad A Pais" << endl;
    cout << "3 - Ranking Ciudad Mundial" << endl;
    cout << "4 - Actualizar Poblacion Pais Por ID" << endl;
    cout << "5 - CREAR ARCHIVO MUNDO" << endl;
    cout << "0 - Salir" << endl;
    cin >> opc;
    return opc;
}

void evaluarDecision(int opc){
    switch(opc){
        case 1:
            break;
        case 2:
            break;

        case 3:
            break;

        case 4:
            break;

        case 5:
            break;

        case 10:
            break;

        case 11:
            break;

        case 12:
            break;

        case 13:
            break;

        case 14:
            break;

        case 0:
            break;

        default:
            break;
    }
}
//demas
//buscar pos, ir a pos
/*ArchivoCiudad* crearArchivo(const char* nombre){
    ArchivoCiudad* archivo = new ArchivoCiudad(nombre);
    return archivo;
}*/

//alta

//modificacion

//baja

#include "Archivos.h"
#include "Ciudad.h"
#include "cstring"
#include <iostream>

ArchivoCiudad::ArchivoCiudad(const char *nombre){
    strcpy(_nombre, nombre);
}
void ArchivoCiudad::setNombre(const char *nombre){
    strcpy(_nombre, nombre);
}
const char* ArchivoCiudad::getNombre(){
    return _nombre;
}

void ArchivoCiudad::Cargar(){
    FILE *pArch;
    pArch = fopen(_nombre, "wb");
    if(pArch==NULL){return;}
    Ciudad pruebaCiudad;
    pruebaCiudad.cargar();
    fwrite(&pruebaCiudad, sizeof(Ciudad), 1, pArch);
    fclose(pArch);
}

void ArchivoCiudad::Leer(){
    FILE *pArch;
    pArch = fopen(_nombre, "rb");
    if(pArch==NULL){return;}
    Ciudad pruebaCiudad;
    if(fread(&pruebaCiudad, sizeof(Ciudad), 1, pArch)){
        pruebaCiudad.mostrar();
    }
    fclose(pArch);
}

/*
 cout << "10 - Crear Archivo" << endl;
    cout << "11 - Agregar Registro" << endl;
    cout << "12 - Modificar Registro" << endl;
    cout << "13 - Agregar Registro" << endl;
    cout << "14 - Modificar Registro" << endl;
 */

ArchivoPais::ArchivoPais(const char *nombre){
    strcpy(_nombre, nombre);
}
void ArchivoPais::setNombre(const char *nombre){
    strcpy(_nombre, nombre);
}
const char* ArchivoPais::getNombre(){
    return _nombre;
}
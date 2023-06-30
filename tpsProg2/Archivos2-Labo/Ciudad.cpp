#include "Ciudad.h"
#include "Funciones.h"
#include <iostream>
#include <cstring>
using namespace std;

int  Ciudad::getID()
{
    return _ID;
}
char * Ciudad::getNombre()
{
    return _nombre;
}
char * Ciudad::getIDPais()
{
    return _idpais;
}
int  Ciudad::getPoblacion()
{
    return _poblacion;
}
void Ciudad::setID(int val)
{
    _ID = val;
}
void Ciudad::setNombre(const char * val)
{
    strcpy(_nombre, val);
}
void Ciudad::setIDPais(const char * val)
{
    strcpy(_idpais, val);
}
void Ciudad::setPoblacion(int val)
{
    _poblacion = val;
}
void Ciudad::mostrar(){
    cout << _ID << " " << _idpais << " " << _nombre << " " << _poblacion << endl;
}

void Ciudad::cargar(){
    char nomb[35];
    char id[4];
    cout << "Ingrese ID: ";
    cin >> _ID;
    cout << "Ingrese Nombre Ciudad: ";
    cargarCadena(nomb, 35);
    strcpy(_nombre, nomb);
    cout << "Ingrese ID Pais: ";
    cargarCadena(id, 4);
    strcpy(_idpais, id);
    cout << "Ingrese poblacion: ";
    cin >> _poblacion;
    cout << "--------------------" << endl;
}


#include <iostream>
using namespace std;
#include "Pais.h"
#include "Ciudad.h"
#include "Archivos.h"
// #include "Funciones.cpp"

ArchivoCiudad* crearArchivo(const char* nombre){
    ArchivoCiudad* archivo = new ArchivoCiudad(nombre);
    return archivo;
}

int main()
{
    ArchivoCiudad* ciudad = crearArchivo("ciudades.dat");
    ciudad->Cargar();
    ciudad->Leer();

    return 0;
}

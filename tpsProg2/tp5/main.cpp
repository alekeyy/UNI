#include <iostream>
#include <cstring>
const int TAM = 20;

class Tarjeta{
private:
    int _numTarjeta;
    Fecha _fechaAlta;
    int _dni;
    float _saldo;
    bool _estado; //1-on 0-off

public:
    //constrc

    //setters

    //getters

    //metodos
};

class ArchivoTarjeta{
private:
    char nombre[TAM];

public:
    //constrc

    //setters

    //getters

    //metodos
};

class Viajes{
private:
    int _numViaje;
    int _numTarjeta;
    int _medioTransporte;
    Fecha _fechaViaje;
    float _impViaje;

public:
    //constrc

    //setters

    //getters

    //metodos
};

class ArchivoViajes{
private:
    char nombre[TAM];

public:
    //constrc

    //setters

    //getters

    //metodos
};

using namespace std;
int main() {
    cout << "Hello, World!" << endl;
    return 0;
}

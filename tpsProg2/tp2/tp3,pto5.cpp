#include <iostream>
#include <string.h>
#include <string>

const int TAM = 20;

using namespace std;

//ayuda carga cadenas
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

//clase auxiliar
class Fecha{
private:
    int dia;
    int mes;
    int anio;
public:
    Fecha(int dia = 1, int mes = 1, int anio = 2000){
        this->dia = dia;
        this->mes = mes;
        this->anio = anio;
    }

    void setDia(int d);
    void setMes(int m);
    void setAnio(int a);
    int getDia();
    int getMes();
    int getAnio();

    void Cargar();
    void Mostrar();
};

void Fecha::setDia(int d){dia = d;}
void Fecha::setMes(int m){mes = m;}
void Fecha::setAnio(int a){anio = a;}
int Fecha::getDia(){return dia;}
int Fecha::getMes(){return mes;}
int Fecha::getAnio(){return anio;}

void Fecha::Cargar(){
    int variable;
    int _anio;
    cout << "Ingrese el dia: ";
    cin >> variable;
    dia = variable;
    cout << "Ingrese el mes: ";
    cin >> variable;
    mes = variable;
    cout << "Ingrese el anio: ";
    cin >> _anio;
    anio = _anio;
}

void Fecha::Mostrar(){
    cout << dia << "|" << mes << "|" << anio << endl;
}

class Direccion{
private:
    char _calle[TAM];
    int _numero;
    char _codPostal[TAM];
    char _localidad[TAM];
    char _piso[TAM];

public:
    void setCalle(const char* calle);
    void setNumero(int numero);
    void setCodPostal(const char* codPostal);
    void setLocalidad(const char* localidad);
    void setPiso(const char* piso);

    const char* getCalle();
    int getNumero();
    const char*  getCodPostal();
    const char*  getLocalidad();
    const char*  getPiso();

    void Cargar();
    void Mostrar();
};

void Direccion::setCalle(const char* calle){strcpy(_calle, calle);}
void Direccion::setNumero(int numero){_numero = numero;}
void Direccion::setCodPostal(const char* codPostal){ strcpy(_codPostal, codPostal);}
void Direccion::setLocalidad(const char* localidad){strcpy(_localidad, localidad);}
void Direccion::setPiso(const char* piso){ strcpy(_piso, piso);}

const char* Direccion::getCalle(){return _calle;}
int Direccion::getNumero(){return _numero;}
const char*  Direccion::getCodPostal(){return _codPostal;}
const char*  Direccion::getLocalidad(){return _localidad;}
const char*  Direccion::getPiso(){return _piso;}

void Direccion::Cargar(){
    char aux[TAM];
    int auxN;
    cout << "INGRESE CALLE: ";
    cargarCadena(aux, TAM);
    strcpy(_calle, aux);

    cout << "INGRESE NUMERO: ";
    cin >> auxN;
    _numero = auxN;

    cout << "INGRESE COD POSTAL: ";
    cargarCadena(aux, TAM);
    strcpy(_codPostal, aux);

    cout << "INGRESE LOCALIDAD: ";
    cargarCadena(aux, TAM);
    strcpy(_localidad, aux);

    cout << "INGRESE PISO: ";
    cargarCadena(aux, TAM);
    strcpy(_piso, aux);

    cout << "CARGA SATISFACTORIA" << endl;
}

void Direccion::Mostrar(){
    cout << "CALLE: " << _calle << " n°" << _numero << ", Piso: " << _piso << endl;
    cout << "COD POSTAL: " << _codPostal << ", Localidad: " << _localidad << endl;
}

class Inmobiliaria{
private:
    Direccion ubicacion;
    Fecha ingreso;
    Fecha operacion;
    int superficie;
    char tipo;

public:
    void Cargar();
    void Mostrar();
};

void Inmobiliaria::Mostrar(){
    cout << "UBICACION: "; ubicacion.Mostrar(); cout << endl;
    cout << "FECHA INGRESO: "; ingreso.Mostrar(); cout << endl;
    cout << "FECHA OPERACION: "; operacion.Mostrar(); cout << endl;
    cout << "SUPERFICIE: " << superficie;
    cout << "TIPO: " << tipo;
}

class Casa: public Inmobiliaria{
private:
    int _cantAmb;
    int _supConstruida;

public:
    void Mostrar();
    void Cargar();
};


class Departamento: public Inmobiliaria{
private:
    int _cantAmb;
    int _instalaciones;

public:
    void Mostrar();
    void Cargar();
};

class Local: public Inmobiliaria{
private:
    int _zona;

public:
    void Mostrar();
    void Cargar();
};

class Terreno: public Inmobiliaria{
private:
    char _mejoras;

public:
    void Mostrar();
    void Cargar();
};


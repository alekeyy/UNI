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

class ArchivoCliente{
private:
    char Nombre[TAM];
public:
    ArchivoCliente(const char* nombre);
    void setNombre(const char *nombre);
    const char* getNombre();
    void crearRegistro();
    void agregarRegistro();
    bool leerRegistro();
    bool buscarRegistro();
    void buscarYLeerRegistro();
    void mostrarFinal();
    void verPos(int pos);
};

ArchivoCliente::ArchivoCliente(const char* nombre) {
    strcpy(Nombre, nombre);
}
void ArchivoCliente::setNombre(const char *nombre){
    strcpy(Nombre, nombre);
}
const char* ArchivoCliente::getNombre(){
    return Nombre;
}

void ArchivoCliente::crearRegistro(){
    FILE *p;
    p=fopen(Nombre, "wb");
    if(p==NULL){
        cout << "CERRADO POR ERROR" << endl;
    } else {
        Direccion prueba;
        prueba.Cargar();
        fwrite(&prueba, sizeof(Direccion), 1, p);
        fclose(p);
    }
}

void ArchivoCliente::agregarRegistro(){
    FILE *p;
    p=fopen(Nombre, "ab");
    if(p==NULL){
        cout << "CERRADO POR ERROR" << endl;
    } else {
        Direccion prueba;
        prueba.Cargar();
        fwrite(&prueba, sizeof(Direccion), 1, p);
        fclose(p);
    }
}

bool ArchivoCliente::leerRegistro(){
    FILE *p;
    p=fopen(Nombre, "rb");
    if(p==NULL){
        cout << "CERRADO POR ERROR" << endl;
        return false;
    } else {
        Direccion prueba;
        while(fread(&prueba, sizeof(Direccion), 1, p)==1){
            prueba.Mostrar();
        }
    }
    return true;
}

bool ArchivoCliente::buscarRegistro(){
    FILE *p;
    p=fopen(Nombre, "rb");
    if(p==NULL){
        cout << "Error al abrir el archivo" << endl;
        return false;
    } else {
        Direccion prueba;
        char calle[TAM];
        cout << "Ingrese la calle a buscar: ";
        cargarCadena(calle, TAM);
        while(fread(&prueba, sizeof(Direccion), 1, p)==1){
            if(strcmp(prueba.getCalle(), calle) == 0){
                cout << "EXISTE" << endl;
                return true;
            }
        }
    }
}

void ArchivoCliente::buscarYLeerRegistro(){
    FILE *p;
    p=fopen(Nombre, "rb");
    if(p==NULL){
        cout << "Error al abrir el archivo" << endl;
        //return 0;
    } else {
        Direccion prueba;
        char calle[TAM];
        cout << "Ingrese la calle a buscar: ";
        cargarCadena(calle, TAM);
        while(fread(&prueba, sizeof(Direccion), 1, p)==1){
            if(strcmp(prueba.getCalle(), calle) == 0){
                cout << "EXISTE" << endl;
                prueba.Mostrar();
                //return 1;
            }
        }
    }
}

void ArchivoCliente::mostrarFinal() {
    FILE *p;
    p=fopen(Nombre, "rb");
    if(p==NULL){
        cout << "Error al abrir el archivo" << endl;
        //return 0;
    } else {
        Direccion Prueba;
        fseek(p, -sizeof(Prueba), 2);
        fread(&Prueba, sizeof(Direccion), 1, p);
        Prueba.Mostrar();
        fclose(p);
    }
}

void ArchivoCliente::verPos(int pos){
    FILE *p;
    p=fopen(Nombre, "rb");
    if(p==NULL){
        cout << "Error al abrir el archivo" << endl;
        //return 0;
    } else {
        Direccion Prueba;
        fseek(p, (pos-1)*sizeof(Prueba), 0);
        fread(&Prueba, sizeof(Direccion), 1, p);
        cout << "--EN LA POSICION " << pos << " SE ENCUENTRA EL REGISTRO: " << endl;
        Prueba.Mostrar();
        cout << endl;
        fclose(p);
    }
}
//TP 2 EJERCICIO
// 1- listar de manera decreciente


int main(void){
    int opc;
    bool accedido = false;
    ArchivoCliente cliente("ciudades.dat");
    while(true){
        cout << "MENU" << endl;
        cout << "1- Crear Archivo" << endl;
        cout << "2- Agregar registro al Archivo" << endl;
        cout << "3- Mostrar Archivos" << endl;
        cout << "4- Buscar por calle en Archivos" << endl;
        cout << "5- Buscar registros en 'x' Calle y mostrar" << endl;
        cout << "6- Mostrar Final" << endl;
        cout << "7- Buscar por posicion: ";
        cout << "0- Salir" << endl;
        cout << "OPC- ";
        cin >> opc;
        switch(opc){
            case 1:
                cliente.crearRegistro();
                break;
            case 0: return 0;
                break;
            case 2:
                cliente.agregarRegistro();
                break;
            case 3:
                accedido = cliente.leerRegistro();
                if(!accedido){
                    cout << "ER RO R" << endl;
                };
                break;
            case 4:
                accedido = cliente.buscarRegistro();
                if(!accedido){
                    cout << "ER RO R" << endl;
                };
                break;
            case 5:
                cliente.buscarYLeerRegistro();
                break;
            case 6:
                cliente.mostrarFinal();
                break;
            case 7: cout << "INGRESE EL N° DE POSICION: ";
                cin >> opc;
                cliente.verPos(opc);
                break;
            default:
                cout << "INCORRECTO" << endl;
                break;
        }
        system("pause");
    }
    return 0;
}
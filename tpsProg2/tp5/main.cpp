#include <iostream>
#include <cstring>
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

//ARRANCA PROG
class Tarjeta{
private:
    char _numTarjeta[16];
    Fecha _fechaAlta;
    long long int _dni;
    float _saldo;
    bool _estado; //1-on 0-off

public:
    //constrc
    Tarjeta();
    //setters
    void setNumTarjeta(const char* numTarjeta);
    void setFechaAlta(Fecha fechaAlta);
    void setDni(long long int dni);
    void setSaldo(float saldo);
    void setEstado(bool estado);

    //getters
    const char* getNumTarjeta();
    Fecha getFechaAlta();
    long long int getDni();
    float getSaldo();
    bool getEstado();

    //metodos
    void Cargar();
    void Mostrar();
};


Tarjeta::Tarjeta(){
    strcpy(_numTarjeta, "2040302050107010");
    _fechaAlta = Fecha(1, 1, 2020);
    _dni = 12000500;
    _saldo = 10000;
    _estado = false;
}

void Tarjeta::setNumTarjeta(const char* numTarjeta){
    strcpy(_numTarjeta, numTarjeta);
}
void Tarjeta::setFechaAlta(Fecha fechaAlta){
    _fechaAlta = fechaAlta;
}
void Tarjeta::setDni(long long int dni){
    _dni = dni;
}
void Tarjeta::setSaldo(float saldo){
    _saldo = saldo;
}
void Tarjeta::setEstado(bool estado){
    _estado = estado;
}


const char* Tarjeta::getNumTarjeta(){
    return _numTarjeta;
}
Fecha Tarjeta::getFechaAlta(){
    return _fechaAlta;
}
long long int Tarjeta::getDni(){
    return _dni;
}
float Tarjeta::getSaldo(){
    return _saldo;
}
bool Tarjeta::getEstado(){
    return _estado;
}

void Tarjeta::Cargar(){
    long long int Iaux;
    float Faux;
    Fecha FechaAux;
    bool Baux;
    cout << "Ingrese el numero de tarjeta: ";
    cargarCadena(_numTarjeta, 16);
    cout << "Ingrese la fecha de alta de la tarjeta: ";
    FechaAux.Cargar();
    _fechaAlta = FechaAux;
    cout << "Ingrese el documento que figura en la tarjeta: ";
    cin >> Iaux;
    _dni = Iaux;
    cout << "Ingrese el saldo de la tarjeta: ";
    cin >> Faux;
    _saldo = Faux;
    cout << "Ingrese el estado de la tarjeta de tarjeta(0-Baja | 1-Activa): ";
    cin >> Iaux;
    if(Iaux == 0){
        _estado = false;
    } else if(Iaux == 1){
        _estado = true;
    }
}
void Tarjeta::Mostrar(){
    if(_estado){
        cout << "\nNUMERO TARJETA: ";
        for(int i = 0; i < 16; i++){
            cout << _numTarjeta[i];
            if(i%4==0){
                cout<< " ";
            }
        }
        cout << endl;
        cout << "FECHA ALTA: ";
        _fechaAlta.Mostrar();
        cout << "DNI: " << _dni << endl;
        cout << "SALDO: " << _saldo << endl;
    }
}


class ArchivoTarjeta{
private:
    char _nombre[TAM];

public:
    //constrc
    ArchivoTarjeta(const char* nombre){strcpy(_nombre, nombre);}
    void setNombre(const char* nombre){strcpy(_nombre, nombre);}
    const char* getNombre(){return _nombre;}

    //metodos |ALTA-CREAR REGISTRO / AÑADIR REGISTRO(S)
    //         MODIFICACION - CAMBIAR REGISTRO
    //         BUSQUEDA - BUSCAR REGISTRO | MOSTRAR | VER SI EXISTE | VER POSICION
    //         BAJA - ELIMINAR REGISTRO/ARCHIVO - BAJA LOGICA
    void crearArchivo(){
        FILE *p;
        p=fopen(_nombre, "wb");
        if(p==NULL){
            cout << "ERROR EN EL INGRESO DE ARCHIVO" << endl;
        } else {
            cout << "ARCHIVO CREADO CORRECTAMENTE " << endl;
        }
        fclose(p);
    }
    bool agregarRegistro(){
        FILE *p;
        Tarjeta tarjAux;
        p=fopen(_nombre, "ab");
        if(p==NULL){
            cout << "ERROR EN EL INGRESO DE ARCHIVO" << endl;
            return false;
        } else {
            tarjAux.Cargar();
            fwrite(&tarjAux, sizeof(Tarjeta), 1, p);
        }
        fclose(p);
        return true;
    }

    void agregarRegistros(){
        int opc;
        bool cond = true;
        cout << "CUANTOS REGISTROS DESEA AGREGAR: ";
        cin >> opc;
        for(int i = 0; i < opc; i++){
                cond = agregarRegistro();
                if(!cond){break;}
        }
    }

    void irARegistro(int pos){
        FILE *p;
        p=fopen(_nombre, "rb");
        Tarjeta tarjAux;
        if(p==NULL){
            cout << "ERROR EN EL INGRESO DE ARCHIVO" << endl;
        } else {
            fseek(p, pos*sizeof(Tarjeta), 0);
            fread(&tarjAux, sizeof(Tarjeta), 1, p);
            tarjAux.Mostrar();
        }
        fclose(p);
    }

    bool existeDNI(long long int dni){
        FILE *p;
        p=fopen(_nombre, "rb");
        Tarjeta tarjAux;
        if(p==NULL){
            cout << "ERROR EN EL INGRESO DE ARCHIVO" << endl;
            return false;
        } else {
            while(fread(&tarjAux, sizeof(Tarjeta), 1, p) == 1){
                if(tarjAux.getDni() == dni){
                    return true;
                }
            }
        }
        fclose(p);
        return false;
    }

    int posDni(long long int dni){
        FILE *p;
        p=fopen(_nombre, "rb");
        Tarjeta tarjAux;
        int cont = 1;
        if(p==NULL){
            cout << "ERROR EN EL INGRESO DE ARCHIVO" << endl;
            return false;
        } else {
            if(existeDNI(dni)){
                while(fread(&tarjAux, sizeof(Tarjeta), 1, p) == 1){
                    if(tarjAux.getDni() == dni){
                        return cont;
                    }
                    cont++;
                }
            }

        }
        fclose(p);
        return false;
    }

    void cambiarDNI(long long int dni){
        FILE *p;
        long long int DNI;
        char respuesta;
        p=fopen(_nombre, "rb+");
        Tarjeta tarjAux;
        if(p==NULL){
            cout << "ERROR EN EL INGRESO DE ARCHIVO" << endl;
        } else {
            while(fread(&tarjAux, sizeof(Tarjeta), 1, p)==1){
                if(tarjAux.getDni()==dni){
                    cout << "INGRESE EL VALOR NUEVO: ";
                    cin >> DNI;
                    cout << "EL DOCUMENTO " << DNI << " SERA CAMBIADO, SEGURO(S/N): ";
                    cin >> respuesta;
                    while(respuesta != 's' || respuesta != 'S'){
                        cout << "INGRESE NUEVAMENTE: ";
                        cin >> respuesta;
                        if(respuesta == 's' || respuesta == 'S'){
                            tarjAux.setDni(DNI);
                            break;
                        } else if(respuesta=='n' || respuesta == 'N'){
                            break;
                        }
                    }
                }
            }
        }
        fclose(p);
    }

    void mostrarRegistros(){
        FILE *p;
        Tarjeta tarjAux;
        p = fopen(_nombre, "rb");
        if(p==NULL){
            cout << "ERROR EN LECTURA" << endl;
        } else {
            while(fread(&tarjAux, sizeof(Tarjeta), 1, p) == 1){
                tarjAux.Mostrar();
            }
        }
    }
};

class Viajes{
private:
    int _numViaje;
    char _numTarjeta[16];
    char _medioTransporte[16];
    Fecha _fechaViaje;
    float _impViaje;

public:
    //constrc
    Viajes();
    //setters
    void setNumViaje(int numViaje);
    void setNumTarjeta(const char* numTarjeta);
    void setMedioTransporte(const char* medioTransporte);
    void setFechaViaje(Fecha fechaViaje);
    void setImpViaje(float impViaje);

    //getters
    int getNumViaje();
    const char* getNumTarjeta();
    const char* getMedioTransporte();
    Fecha getFechaViaje();
    float getImpViaje();

    //metodos
    void Cargar();
    void Mostrar();

};

Viajes::Viajes(){
    _numViaje = 10001;
    strcpy(_numTarjeta, "1234432156788765");
    strcpy(_medioTransporte, "Colectivo");
    _fechaViaje = Fecha(1, 1, 2020);
    _impViaje = 50;
}

void Viajes::setNumViaje(int numViaje){
    _numViaje = numViaje;
}
void Viajes::setNumTarjeta(const char* numTarjeta){
    strcpy(_numTarjeta, numTarjeta);
}
void Viajes::setMedioTransporte(const char* medioTransporte){
    strcpy(_medioTransporte, medioTransporte);
}
void Viajes::setFechaViaje(Fecha fechaViaje){
    _fechaViaje = fechaViaje;
}
void Viajes::setImpViaje(float impViaje){
    _impViaje = impViaje;
}

int Viajes::getNumViaje(){return _numViaje;}
const char* Viajes::getNumTarjeta(){return _numTarjeta;}
const char* Viajes::getMedioTransporte(){return _medioTransporte;}
Fecha Viajes::getFechaViaje(){return _fechaViaje;}
float Viajes::getImpViaje(){return _impViaje;}

void Viajes::Cargar(){
    int Iaux;
    float Faux;
    char aux;
    cout << "Ingrese el numero de viaje: ";
    cin >> Iaux;
    _numViaje = Iaux;

    cout << "Ingrese el numero de tarjeta: ";
    cargarCadena(_numTarjeta, 16);
    while(aux != '1' || aux != '2' || aux != '3'){
        cout << "Ingrese el medio de transporte(1-Colectivo, 2-Subte, 3-Tren): ";
        cin >> aux;
    }
    if(aux == 1){
        strcpy(_medioTransporte, "Colectivo");
    } else if(aux == 2){
        strcpy(_medioTransporte, "Subte");
    } else if(aux == 3){
        strcpy(_medioTransporte, "Tren");
    }

    cout << "Ingrese la fecha de viaje: ";
    _fechaViaje.Cargar();

    cout << "Ingrese el importe del viaje: ";
    cin >> Faux;
    _impViaje = Faux;
}
void Viajes::Mostrar(){
    cout << "----------------" << endl;
    cout << "NUM VIAJE: " << _numViaje << endl;
    cout << "NUM TARJETA: " << _numTarjeta << endl;
    cout << "MEDIO TRANSPORTE: " << _medioTransporte << endl;
    cout << "FECHA VIAJE: "; _fechaViaje.Mostrar(); cout << endl;
    cout << "IMPORTE VIAJE: " << _impViaje << endl;
}

class ArchivoViajes{
private:
    char _nombre[TAM];

public:
    ArchivoViajes(const char* nombre){strcpy(_nombre, nombre);}
    void setNombre(const char* nombre){strcpy(_nombre, nombre);}
    const char* getNombre(){return _nombre;}

    //metodos
    //metodos |ALTA-CREAR REGISTRO / AÑADIR REGISTRO(S)
    //         MODIFICACION - CAMBIAR REGISTRO
    //         BUSQUEDA - BUSCAR REGISTRO | MOSTRAR | VER SI EXISTE | VER POSICION
    //         BAJA - ELIMINAR REGISTRO/ARCHIVO - BAJA LOGICA
    void crearArchivo(){
        FILE *p;
        p=fopen(_nombre, "wb");
        if(p==NULL){
            cout << "ERROR EN EL INGRESO DE ARCHIVO" << endl;
        } else {
            cout << "ARCHIVO CREADO CORRECTAMENTE " << endl;
        }
        fclose(p);
    }
    bool agregarRegistro(){
        FILE *p;
        Viajes viaje;
        p=fopen(_nombre, "ab");
        if(p==NULL){
            cout << "ERROR EN EL INGRESO DE ARCHIVO" << endl;
            return false;
        } else {
            viaje.Cargar();
            fwrite(&viaje, sizeof(Viajes), 1, p);
        }
        fclose(p);
        return true;
    }

    void agregarRegistros(){
        int opc;
        bool cond = true;
        cout << "CUANTOS REGISTROS DESEA AGREGAR: ";
        cin >> opc;
        for(int i = 0; i < opc; i++){
            cond = agregarRegistro();
            if(!cond){break;}
        }
    }

    void irARegistro(int pos){
        FILE *p;
        p=fopen(_nombre, "rb");
        Viajes viaje;
        if(p==NULL){
            cout << "ERROR EN EL INGRESO DE ARCHIVO" << endl;
        } else {
            fseek(p, pos*sizeof(Viajes), 0);
            fread(&viaje, sizeof(Viajes), 1, p);
            viaje.Mostrar();
        }
        fclose(p);
    }

    bool existeDNI(long long int dni){
        FILE *p;
        p=fopen(_nombre, "rb");
        Tarjeta tarjAux;
        if(p==NULL){
            cout << "ERROR EN EL INGRESO DE ARCHIVO" << endl;
            return false;
        } else {
            while(fread(&tarjAux, sizeof(Tarjeta), 1, p) == 1){
                if(tarjAux.getDni() == dni){
                    return true;
                }
            }
        }
        fclose(p);
        return false;
    }

    int posDni(long long int dni){
        FILE *p;
        p=fopen(_nombre, "rb");
        Tarjeta tarjAux;
        int cont = 1;
        if(p==NULL){
            cout << "ERROR EN EL INGRESO DE ARCHIVO" << endl;
            return false;
        } else {
            if(existeDNI(dni)){
                while(fread(&tarjAux, sizeof(Tarjeta), 1, p) == 1){
                    if(tarjAux.getDni() == dni){
                        return cont;
                    }
                    cont++;
                }
            }

        }
        fclose(p);
        return false;
    }

    void mostrarRegistros(){
        FILE *p;
        Viajes viaje;
        p = fopen(_nombre, "rb");
        if(p==NULL){
            cout << "ERROR EN LECTURA" << endl;
        } else {
            while(fread(&viaje, sizeof(Viajes), 1, p) == 1){
                viaje.Mostrar();
            }
        }
    }
};

int textoMenu(){
    int opc;
    cout << "---------------------" << endl;
    cout << "--  MENU TARJETA   --" << endl;
    cout << "-1) CREAR ARCHIVO " << endl;
    cout << "-2) AGREGAR REGISTRO A ARCHIVO" << endl;
    cout << "-3) MODIFICAR REGISTRO " << endl;
    cout << "-4) VERIFICAR EXISTENCIA REGISTRO" << endl;
    cout << "-5) BUSCAR Y MOSTRAR " << endl;
    cout << "-6) MOSTRAR REGISTROS" << endl;
    cout << "-7) BORRAR ARCHIVO " << endl;
    cout << "-0) SALIR " << endl;
    cout << "OPC: ";
    cin >> opc;
    return opc;
}
void menuTarjeta(){
    while(true){
        int opc = textoMenu();
        switch(opc){

        }
    }
}

void menuViaje(){
    while(true){
        int opc = textoMenu();
        switch(opc){

        }
    }
}

int main() {


    return 0;
}

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

class Empleados{
private:
    char _dni[TAM];
    char _nombre[TAM];
    char _apellido[TAM];
    char _domicilio[TAM];
    char _email[TAM];
    Fecha _fNacimiento;
    int _cargo;
public:
    Empleados();

    void setDni(const char* dni);
    void setNombre(const char* nombre);
    void setApellido(const char* dni);
    void setDomicilio(const char* nombre);
    void setFecha(Fecha fec);
    void setCargo(int cargo);

    const char* getDni();
    const char* getNombre();
    const char* getApellido();
    const char* getDomicilio();
    Fecha getFecha();
    int getCargo();

    void Cargar();
    void Mostrar();
};

Empleados::Empleados(){
    strcpy(_dni, "123456");
    strcpy(_nombre, "Nombre");
    strcpy(_apellido, "Apellido");
    strcpy(_domicilio, "Domicilio");
    _fNacimiento = Fecha(1, 1, 2000);
    _cargo = 1;
}

void Empleados::setDni(const char* dni){ strcpy(_dni, dni);}
void Empleados::setNombre(const char* nombre){ strcpy(_nombre, nombre);}
void Empleados::setApellido(const char* apellido){strcpy(_apellido, apellido);}
void Empleados::setDomicilio(const char* domicilio){ strcpy(_domicilio, domicilio);}
void Empleados::setFecha(Fecha fec){_fNacimiento = fec;}
void Empleados::setCargo(int cargo){_cargo = cargo;}

const char* Empleados::getDni(){return _dni;}
const char* Empleados::getNombre(){return _nombre;}
const char* Empleados::getApellido(){return _apellido;}
const char* Empleados::getDomicilio(){return _domicilio;}
Fecha Empleados::getFecha(){return _fNacimiento;}
int Empleados::getCargo(){return _cargo;}

void Empleados::Cargar(){
    int auxN = 0;
    char aux[TAM];
    Fecha auxF;
    cout << "Ingrese el numero de DOCUMENTO: ";
    cargarCadena(aux, TAM);
    strcpy(_dni, aux);

    cout << "Ingrese el NOMBRE: ";
    cargarCadena(aux, TAM);
    strcpy(_nombre, aux);

    cout << "Ingrese el APELLIDO: ";
    cargarCadena(aux, TAM);
    strcpy(_apellido, aux);

    cout << "Ingrese el DOMICILIO: ";
    cargarCadena(aux, TAM);
    strcpy(_domicilio, aux);

    cout << "Ingrese la fecha de Nacimiento: ";
    auxF.Cargar();
    _fNacimiento = auxF;

    while(auxN < 1 || auxN > 30){
        cout  << "Ingrese el numero de cargo: ";
        cin >> auxN;
        if(auxN >= 1 && auxN <= 30){
            _cargo = auxN;
        }
    }
    cout << "--- CARGA EXITOSA ---" << endl;
}

void Empleados::Mostrar(){
    cout << "------------------------" << endl;
    cout << "DNI: " << _dni << endl;
    cout << "NOMBRE: " << _nombre << endl;
    cout << "APELLIDO: " << _apellido << endl;
    cout << "DOMICILIO: " << _domicilio << endl;
    cout << "FECHA DE NACIMIENTO: "; _fNacimiento.Mostrar(); cout << endl;
    cout << "NUM CARGO: " << _cargo << endl;
    cout << "------------------------" << endl;

}

class Investigador: public Empleados{
private:
    int _categoria;    //1 a 5
    int _especialidad; //1 a 10
public:
    Investigador();

    void setCategoria(int categoria);
    void setEspecialidad(int especialidad);
    int getCategoria();
    int getEspecialidad();

    void Cargar();
    void Mostrar();
};

Investigador::Investigador() : Empleados(){
    _categoria = 1;
    _especialidad = 5;
}

void Investigador::setCategoria(int categoria){}
void Investigador::setEspecialidad(int especialidad){}
int Investigador::getCategoria(){}
int Investigador::getEspecialidad(){}

void Investigador::Cargar(){
    int opc = 0;
    Empleados::Cargar();
    while(opc < 0 || opc > 5){
        cout << "Ingrese la categoria(1-5): ";
        cin >> opc;
        if(opc >= 1 && opc <= 5){
            _categoria = opc;
        } else {
            cout << "CATEGORIA NO EXISTENTE, REINTENTE" << endl;
        }
    }
    opc = 0;
    while(opc < 0 || opc > 10){
        cout << "Ingrese la Especialidad(1-10): ";
        cin >> opc;
        if(opc >= 1 && opc <= 10){
            _especialidad = opc;
        } else {
            cout << "ESPECIALIDAD NO EXISTENTE, REINTENTE" << endl;
        }
    }

}

void Investigador::Mostrar(){
    Empleados::Mostrar();
    cout << "CATEGORIA: " << _categoria << endl;
    cout << "ESPECIALIDAD: " << _especialidad << endl;
}



int main() {
    Empleados Alex;
    Alex.Cargar();
    Alex.Mostrar();

    return 0;
}

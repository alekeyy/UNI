#include <iostream>
#include <string>
#include <string.h>
#include <stdlib.h>

using namespace std;
// ayuda
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

//punto 3
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
    cout << "Ingrese el dia: ";
    cin >> variable;
    dia = variable;
    cout << "Ingrese el mes: ";
    cin >> variable;
    mes = variable;
    cout << "Ingrese el anio: ";
    cin >> anio;
    anio = variable;
}

void Fecha::Mostrar(){
    cout << dia << "|" << mes << "|" << anio << endl;
}

//punto 4
class Cliente{
private:
    int DNI;
    Fecha nacimiento;
    char nombre[25];
    char apellido[25];
    char email[25];
    char telefono[25];

public:
    Cliente(){
        DNI = 12345;
        nacimiento = Fecha(1, 1, 2000);
        strcpy(nombre, "nombre");
        strcpy(apellido, "apellido");
        strcpy(email, "email");
        strcpy(telefono, "1123456789");
    };
    Cliente(char* n) {
        DNI = 12345;
        nacimiento = Fecha(1, 1, 2000);
        strcpy(nombre, n);
        strcpy(apellido, "apellido");
        strcpy(email, "email");
        strcpy(telefono, "1123456789");
    }

    void setDNI(int d);
    void setNacimiento(int d, int m, int a);
    void setNombre(const char* n);
    void setApellido(const char* a);
    void setEmail(const char* e);
    void setTelefono(const char* t);

    int getDNI();
    Fecha getNacimiento();
    const char *getNombre();
    const char *getApellido();
    const char *getEmail();
    const char *getTelefono();

    void Cargar();
    void Mostrar();
};

void Cliente::setDNI(int d){DNI = d;}
void Cliente::setNacimiento(int d, int m, int a){nacimiento = Fecha(d, m, a);}
void Cliente::setNombre(const char* n){strcpy(nombre, n);}
void Cliente::setApellido(const char* a){strcpy(apellido, a);}
void Cliente::setEmail(const char* e){strcpy(email, e);}
void Cliente::setTelefono(const char* t){strcpy(telefono, t);}

int Cliente::getDNI(){return DNI;}
Fecha Cliente::getNacimiento(){return nacimiento;}
const char *Cliente::getNombre(){return nombre;}
const char *Cliente::getApellido(){return apellido;}
const char *Cliente::getEmail(){return email;}
const char *Cliente::getTelefono(){return telefono;}

void Cliente::Cargar(){
    char aux[25];
    int n, d, m, a;
    cout << "---INICIO---" << endl;
    cout << "-Ingrese el documento: ";
    cin >> d;
    DNI = d;

    cout << "-Ingrese el dia de nacimiento: ";
    cin >> d;
    cout << "-Ingrese el mes de nacimiento: ";
    cin >> m;
    cout << "-Ingrese el anio de nacimiento: ";
    cin >> a;
    nacimiento = Fecha(d, m, a);

    cout << "-Ingrese el nombre: ";
    cargarCadena(aux, 25);
    strcpy(nombre, aux);

    cout << "-Ingrese el apellido: ";
    cargarCadena(aux, 25);
    strcpy(apellido, aux);

    cout << "-Ingrese el email: ";
    cargarCadena(aux, 25);
    strcpy(email, aux);

    cout << "-Ingrese el telefono: ";
    cargarCadena(aux, 25);
    strcpy(telefono, aux);
    cout << ".--CARGA COMPLETADA--." << endl;
};

void Cliente::Mostrar(){
    cout << "--------------------" << endl;
    cout << "DNI: " << DNI << endl;
    cout << "FECHA DE NACIMIENTO: "; nacimiento.Mostrar(); cout << endl;
    cout << "NOMBRE: " << nombre << endl;
    cout << "APELLIDO: " << apellido << endl;
    cout << "EMAIL: " << email << endl;
    cout << "TELEFONO: " << telefono << endl;
    cout << "--------------------" << endl;
}



//punto 5
//a
Cliente* cargarClientes(int tam){
    Cliente* vector = new Cliente();
    for(int i = 0; i < tam; i++){
        vector[i].Cargar();
    }
    return vector;
}

//b
void mostrarClientes(Cliente *vector, int tam){
    for(int i = 0; i < tam; i++){
        vector[i].Mostrar();
    }
}

//c
void listarDNI(Cliente *vector, int tam){
    int d;
    cout << "INGRESE EL NUMERO DE DNI A COMPARAR(EL PROGRAMA MOSTRARA LOS VALORES MAYORES): ";
    cin >> d;
    for(int i = 0; i < tam; i++){
        if(vector[i].getDNI() > d){
            cout << "El cliente " << vector[i].getApellido() << ", " << vector[i].getNombre() << " tiene un valor mayor al DNI a comparar." << endl;
            vector[i].Mostrar();
        }
    }
}

//d
int devolverPosDNI(Cliente *vector, int tam){
    int d;
    cout << "INGRESE EL NUMERO DE DNI A BUSCAR EN EL PROGRAMA: ";
    cin >> d;
    for(int i = 0; i < tam; i++){
        if(vector[i].getDNI() == d){
            return i + 1;
        }
    }
    return -1;
}

//e
Cliente devolverObjDNI(Cliente *vector, int tam){
    int d;
    Cliente aux;
    cout << "INGRESE EL NUMERO DE DNI A A BUSCAR EN EL PROGRAMA: ";
    cin >> d;
    for(int i = 0; i < tam; i++){
        if(vector[i].getDNI() == d){
            aux = vector[i];
            return aux;
        }
    }
    aux = Cliente();
    aux.setDNI(-1);
    return aux;
}

//f
int mismaFecha(Cliente *vector, int tam){
    int d, m, a, cont = 0;
    Fecha aux;
    cout << "A CONTINUACION LE VAMOS A REQUERIR DE COMPLETAR LA FECHA A BUSCAR EN EL REGISTRO DE OBJETOS" << endl;
    cout << "-Ingrese el dia de nacimiento: ";
    cin >> d;
    cout << "-Ingrese el mes de nacimiento: ";
    cin >> m;
    cout << "-Ingrese el anio de nacimiento: ";
    cin >> a;
    aux = Fecha(d, m, a);
    for(int i = 0; i < tam; i++){
        if(vector[i].getNacimiento().getDia() == aux.getDia() && vector[i].getNacimiento().getMes() == aux.getMes() && vector[i].getNacimiento().getAnio() == aux.getAnio()){
            cont++;
        }
    }
    return cont;
}

int main(void){
    int largoArr = 2;
    Cliente* objetos;
    Cliente temporal;
    int cantidadNacimientos;
    int opc;
    int pos;
    while(true){
        cout << "---   M E N U   ---" << endl;
        cout << "1- Cargar Clientes" << endl;
        cout << "2- Leer Clientes" << endl;
        cout << "3- Listar Clientes Documento" << endl;
        cout << "4- Buscar Documento Posicion" << endl;
        cout << "5- Devolver objeto por Documento" << endl;
        cout << "6- Contar Misma Fecha Nacimiento" << endl;
        cout << "0- SALIR" << endl;
        cout << "OPC: ";
        cin >> opc;
        switch(opc){
            case 1: objetos = cargarClientes(largoArr);
                break;
            case 2: mostrarClientes(objetos,largoArr);
                break;
            case 3: listarDNI(objetos, largoArr);
                break;
            case 4: pos = devolverPosDNI(objetos, largoArr);
                cout << "SE ENCUENTRA EN LA POSICION " << pos << endl;
                break;
            case 5:
                temporal = devolverObjDNI(objetos, largoArr);
                cout << "EL OBJETO ENCONTRADO QUE COINCIDE ES: " << endl;
                temporal.Mostrar();
                break;
            case 6: cantidadNacimientos = mismaFecha(objetos, largoArr);
                cout << "LA CANTIDAD DE NACIMIENTOS EN ESA FECHA ES DE: " << cantidadNacimientos << endl;
                break;
            case 0:
                delete[] objetos;
                return 0;
                break;
            default:
                cout << "ERROR EN EL VALOR INGRESADO" << endl;
                break;
        }
    }
}


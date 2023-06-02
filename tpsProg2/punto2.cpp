/*#include <iostream>
#include <string>
#include <string.h>
#include <stdlib.h>

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

class Articulo {
private:
    char _codigo[5];
    char _descripcion[30];
    float _precio;
    int _stock;
    bool _estado;

public:
    Articulo(){
        strcpy(_codigo, "1234");
        strcpy(_descripcion, ("El mejor Articulo"));
        _precio = 100;
        _stock = 5;
        _estado = true;
    }
    Articulo(const char *descripcion){
        strcpy(_codigo, "2345");
        strcpy(_descripcion, descripcion);
        _precio = 100;
        _stock = 5;
        _estado = true;
    }
    void setCodigo(const char *codigo);
    void setDescripcion(const char *descripcion);
    void setPrecio(float precio);
    void setStock(int stock);
    void setEstado(bool estado);

    const char * getCodigo();
    const char * getDescripcion();
    float getPrecio();
    int getStock();
    bool getEstado();

    void Cargar();
    void Mostrar();
};

void Articulo::setCodigo(const char *codigo) {strcpy(_codigo, codigo);}

void Articulo::setDescripcion(const char *descripcion) {strcpy(_descripcion, descripcion);}

void Articulo::setPrecio(float precio) {_precio = precio;}

void Articulo::setStock(int stock) {_stock = stock;}

void Articulo::setEstado(bool estado) {_estado = estado;}

const char *Articulo::getCodigo() {return _codigo;}

const char *Articulo::getDescripcion() {return _descripcion;}

float Articulo::getPrecio() {return _precio;}

int Articulo::getStock() {return _stock;}

bool Articulo::getEstado() {return _estado;}

void Articulo::Cargar(){
    char desc[30];
    int entero;
    float coma;
    cout << "---Bienvenido---" << endl;
    cout << "Ingrese el codigo: ";
    cargarCadena(_codigo, 4);
    cout << "Ingrese la descripcion: ";
    cargarCadena(_descripcion, 30);
    cout << "Ingrese el precio: ";
    cin >> coma;
    _precio = coma;
    cout << "Ingrese el stock: ";
    cin >> entero;
    _stock = entero;
    if(_stock > 0 && _precio > 0){
        _estado = true;
    }
};

void Articulo::Mostrar(){
    if(_estado){
        cout << "----------------------------" << endl;
        cout << "cod: " << _codigo << endl;
        cout << "Descripcion: " << _descripcion << endl;
        cout << "Precio: " << _precio << endl;
        cout << "Stock: " << _stock << endl;
        cout << "---------------------------" << endl;
    } else {
        cout << "ERROR - ARTICULO MAL CARGADO "  << endl;
    }

};

//punto - 2
// a
Articulo* crearObjetos(int cant){
    Articulo* Obj = new Articulo[cant];
    for(int i = 0; i < cant; i++){
        Obj[i].Cargar();
    }
    return Obj;
}

//b
void leerArticulos(Articulo* objeto, int largo){
    for(int i = 0; i < largo; i++){
        objeto[i].Mostrar();
        cout << " 1 " << endl;
    }
}

//c
void mayorA(Articulo* objetos, int largo){
    int valor;
    cout << "Ingrese el precio a comparar: ";
    cin >> valor;
    for(int i = 0; i < largo; i++){
        if(objetos[i].getPrecio() > valor){
            cout << "El objeto " << objetos[i].getCodigo() << " tiene mayor precio que el indicado"<< endl;
        }
    }
}

//d
int posCod(Articulo* objetos, int largo){
    int pos;
    char cod[5];
    cout << "Ingrese el codigo a buscar: ";
    cargarCadena(cod, 5);
    for(int i = 0; i < largo; i++){
        if(strcmp(objetos[i].getCodigo(), cod) == 0){
            cout << "El codigo se encuentra en la posicion " << i + 1 << endl;
            return i;
        }
    }
    return -1;
}

//e
Articulo devolverCod(Articulo* objetos, int largo){
    int pos;
    char cod[5];
    cout << "Ingrese el codigo a buscar: ";
    cargarCadena(cod, 5);
    for(int i = 0; i < largo; i++){
        if(strcmp(objetos[i].getCodigo(), cod) == 0){
            cout << "El codigo se encuentra en la posicion " << i + 1 << endl;
            return objetos[i];
        }
    }
    Articulo objeto;
    objeto.setStock(-1);
    return objeto;
}


//f
void mayorStock(Articulo* objetos, int largo){
    int stock;
    cout << "Ingrese el stock a comparar: ";
    cin >> stock;
    for(int i = 0; i < largo; i++){
        if(objetos[i].getStock() < stock){
            cout << "El objeto " << objetos[i].getCodigo() << " tiene menor stock que el indicado de "<< stock <<endl;
        }
    }
}

//g
void argSimulator(Articulo *objetos, int largo){
    float porc;
    cout << "Ingrese el porcentaje a aumentar en todos los objetos: ";
    cin >> porc;
    for(int i = 0; i < largo; i++){
        objetos[i].setPrecio((objetos[i].getPrecio()*1,porc)/100);
    }
}

int main() {
    //MENU//
    int largoArr = 2;
    Articulo* objetos;
    Articulo temporal;
    int opc;
    while(true){
        cout << "---   M E N U   ---" << endl;
        cout << "1- Cargar Articulos" << endl;
        cout << "2- Leer Articulos" << endl;
        cout << "3- Comparar precio Articulos" << endl;
        cout << "4- Buscar Posicion por Codigo en Articulos" << endl;
        cout << "5- Devolver objeto por Codigo en Articulos" << endl;
        cout << "6- Listar stock bajo Articulos" << endl;
        cout << "7- Aumentar Precio Articulos" << endl;
        cout << "0- SALIR" << endl;
        cout << "OPC: ";
        cin >> opc;
        switch(opc){
            case 1: objetos = crearObjetos(largoArr);
                break;
            case 2: leerArticulos(objetos,largoArr);
                break;
            case 3: mayorA(objetos, largoArr);
                break;
            case 4: posCod(objetos, largoArr);
                break;
            case 5: temporal = devolverCod(objetos, largoArr);
                    cout << "EL OBJETO ENCONTRADO QUE COINCIDE ES: " << endl;
                    temporal.Mostrar();
                    break;
            case 6: mayorStock(objetos, largoArr);
                break;
            case 7: argSimulator(objetos, largoArr);
                break;
            case 0:
                delete[] objetos;
                return false;
                break;
            default:
                cout << "ERROR EN EL VALOR INGRESADO" << endl;
                break;
        }
    }
    return 0;
}
*/
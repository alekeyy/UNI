#ifndef HOLAMUNDO_ARCHIVOS_H
#define HOLAMUNDO_ARCHIVOS_H


class ArchivoCiudad {
private:
    char _nombre[20];
public:
    ArchivoCiudad(const char *nombre);
    void setNombre(const char *nombre);
    const char * getNombre();

    void Cargar();
    void Leer();
};

class ArchivoPais{
private:
    char _nombre[20];
public:
    ArchivoPais(const char *nombre);
    void setNombre(const char *nombre);
    const char * getNombre();
};
#endif //HOLAMUNDO_ARCHIVOS_H

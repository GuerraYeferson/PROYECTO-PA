#ifndef CLSLIBRO_H
#define CLSLIBRO_H

#include <string>
using namespace std;

class clsLibro {
private:
    string nombre;
    string autor;
    int ndepaginas;
    string etiqueta;

public:
    clsLibro(string, string, int, string);
    void mostrarLibro();
    clsLibro();
};
#include "clsLibro.cpp"
#endif // CLSLIBRO_H

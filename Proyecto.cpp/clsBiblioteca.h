#ifndef CLSBIBLIOTECA_H
#define CLSBIBLIOTECA_H

#include "clsLibro.h"

class clsBiblioteca {
private:
    int nlibros;
    clsLibro *ListadeLibros[100];
    clsLibro Libro;

public:
    clsBiblioteca();
    void añadirLibro();
    void mostrarBiblioteca();
    void eliminarLibro_por_nombre();
    void buscarLibro_por_etiqueta();
    void modificarLibro_por_nombre();
    void mostrarMenu();
};
#include "clsBiblioteca.cpp"
#endif // CLSBIBLIOTECA_H

#include "clsLibro.h"
#include <iostream>
using namespace std;

clsLibro::clsLibro(string n, string a, int nd, string e) {
    nombre = n;
    autor = a;
    ndepaginas = nd;
    etiqueta = e;
}

void clsLibro::mostrarLibro() {
    cout << "Nombre: " << nombre << endl;
    cout << "Autor: " << autor << endl;
    cout << "Número de páginas: " << ndepaginas << endl;
    cout << "Etiqueta: " << etiqueta << endl;
}

clsLibro::clsLibro() {
    nombre = "";
    autor = "";
    ndepaginas = 0;
    etiqueta = "";
}

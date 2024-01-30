#ifndef CLSGESCONTRASENA_H
#define CLSGESCONTRASENA_H

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class clsGesContrasena {
protected:
    string Nombre, Email, Contrasenha;

public:
    void anadirContrasena();
    void mostContrasenha();
    void elimContrasenha();
    void buscarContrasena();
    void mostrarMenu();
};

#include "clsGesContrasena.cpp"

#endif
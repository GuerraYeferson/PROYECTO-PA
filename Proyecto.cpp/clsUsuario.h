#ifndef CLSUSUARIO_H
#define CLSUSUARIO_H

#include <iostream>
#include <string>
#include <fstream>

class clsUsuario {
private:
    std::string Nombre, Email, Telefono, Contrasenha;
    bool sesionIniciada;

public:
    clsUsuario(std::string N = "", std::string E = "", std::string T = "", std::string C = "");

    void crearCuenta();
    void iniciarSesion();
    void crearListaContactos();
    void mostrarListaContactos();
    void mostrarMenu();
};

#include "clsUsuario.cpp"

#endif // PUNTO_H

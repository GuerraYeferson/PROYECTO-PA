#ifndef CLSGESTORDEACTIVIDADES_H
#define CLSGESTORDEACTIVIDADES_H

#include <fstream>
#include <bits/stdc++.h>

using namespace std;

class clsGestorDeActividades {
private:
    int dia, mes, ano;
    string nombre, descripcion;

public:
    void AgregarActividad();
    void MostrarActividades();
    void EliminarActividad();
    void Menu();
};

#include "clsGestorDeActividades.cpp"

#endif // CLSGESTORDEACTIVIDADES_H


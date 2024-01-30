#include "clsGesContrasena.h"
#include <iostream>
#include <fstream>

using namespace std;

void clsGesContrasena::anadirContrasena()
{
    cout << " --- GESTOR DE CONTRASENHAS ---" << endl;

    // Abrir el archivo en modo append solo si está vacío
    ifstream archivoExistente("contrasenas.txt");
    if (!archivoExistente.is_open())
    {
        ofstream archivo("contrasenas.txt");
        archivo.close();
    }

    while (true)
    {
        cout << "Nombre del sitio web u otro (ingrese 'x' para salir): ";
        getline(cin, Nombre);

        if (Nombre == "x")
        {
            break;
        }

        cout << "Email asociado: ";
        getline(cin, Email);

        cout << "Contrasenhaa: ";
        getline(cin, Contrasenha);

        ofstream archivo("contrasenas.txt", ios::app);

        if (archivo.is_open())
        {
            archivo << "Sitio Web u otro: " << Nombre << endl;
            archivo << "Email: " << Email << endl;
            archivo << "Contrasenhaa: " << Contrasenha << endl;
            archivo << "------------------------" << endl;

            archivo.close();

            cout << "Contrasenhaa agregada exitosamente." << endl;
        }
        else
        {
            cout << "Error al abrir el archivo." << endl;
        }
    }
}

void clsGesContrasena::mostContrasenha()
{
    cout << " --- MOSTRAR CONTRASEÑAS ---" << endl;

    ifstream archivoEntrada("contrasenas.txt");

    if (archivoEntrada.is_open())
    {
        string linea;

        while (getline(archivoEntrada, linea))
        {
            cout << linea << endl;
        }

        archivoEntrada.close();
    }
    else
    {
        cout << "Error al abrir el archivo." << endl;
    }
}

void clsGesContrasena::elimContrasenha()
{
    cout << " --- ELIMINAR CONTRASEÑA ---" << endl;

    string sitioWebEliminar;
    cout << "Ingrese el nombre del sitio web cuya contraseña desea eliminar: ";
    getline(cin, sitioWebEliminar);

    ifstream archivoEntrada("contrasenas.txt");
    ofstream archivoTemporal("temporal.txt");

    if (archivoEntrada.is_open() && archivoTemporal.is_open())
    {
        string linea;
        bool encontrado = false;

        while (getline(archivoEntrada, linea))
        {
            // Buscar la línea que contiene el nombre del sitio web
            size_t pos = linea.find("Sitio Web u otro: " + sitioWebEliminar);
            if (pos != string::npos)
            {
                // Encontramos la contraseña a eliminar
                encontrado = true;

                // Leer y descartar las líneas restantes para eliminar toda la información
                for (int i = 0; i < 3; ++i)
                {
                    getline(archivoEntrada, linea);
                }

                cout << "Contrasenha eliminada exitosamente." << endl;
            }
            else
            {
                // No es la línea que buscamos, copiarla al archivo temporal
                archivoTemporal << linea << endl;
            }
        }

        archivoEntrada.close();
        archivoTemporal.close();

        // Renombrar el archivo temporal al original
        if (encontrado)
        {
            remove("contrasenas.txt");
            rename("temporal.txt", "contrasenas.txt");
        }
        else
        {
            cout << "No se encontro la contrasenha para eliminar." << endl;
            remove("temporal.txt"); // Eliminar el archivo temporal si no se eliminó nada
        }
    }
    else
    {
        cout << "Error al abrir los archivos." << endl;
    }
}

void clsGesContrasena::mostrarMenu()
{
    int opcion;

    do
    {
        cout << "\n --- MENU GESTOR DE CONTRASENHAS ---" << endl;
        cout << "1. Anhadir Contrasenha" << endl;
        cout << "2. Mostrar Contrasenhas" << endl;
        cout << "3. Eliminar Contrasenha" << endl;
        cout << "0. Salir" << endl;
        cout << "Seleccione una opción: ";
        cin >> opcion;
        cin.ignore();

        switch (opcion)
        {
        case 1:
            anadirContrasena();
            break;
        case 2:
            mostContrasenha();
            break;
        case 3:
            elimContrasenha();
            break;
        case 0:
            cout << "Saliendo del programa. ¡Hasta luego!" << endl;
            break;
        default:
            cout << "Opción no valida. Intentelo de nuevo." << endl;
        }
    } while (opcion != 0);
}


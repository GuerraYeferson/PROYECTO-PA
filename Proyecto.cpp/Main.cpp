#include<iostream>
#include<string>
#include<iomanip>
#include<fstream>
#include "Miproyecto.h"

using namespace std;

int main() 
{
    // Crear instancias de las clases
    clsGesContrasena gesContrasena;
    clsGestorDeActividades gestorActividades;
    clsUsuario usuario;
    clsBiblioteca biblioteca;
    clsLibro libro;


    int opcion;

    do {
        // Menú principal
        cout << "\n --- MENU PRINCIPAL ---" << endl;
        cout << "1. Acceder como Usuario" << endl;
        cout << "2. Gestionar Actividades" << endl;
        cout << "3. Gestionar Contrasenhas" << endl;
        cout << "4. Acceder a la Biblioteca" << endl;
        cout << "0. Salir" << endl;
        cout << "Seleccione una opcion: ";
        cin >> opcion;
        cin.ignore();

        switch (opcion) {
            case 1:
                usuario.mostrarMenu();
                break;
            case 2:
                gestorActividades.Menu();
                break;
            case 3:
                gesContrasena.mostrarMenu();
                break;
            case 4:
                biblioteca.mostrarMenu();
                break;
            case 0:
                cout << "Saliendo del programa. ¡Hasta luego!" << endl;
                break;
            default:
                cout << "Opcion no valida. Intentelo de nuevo." << endl;
        }
    } while (opcion != 0);

    return 0;
}

#include "clsGestorDeActividades.h"

void clsGestorDeActividades::AgregarActividad() {
    while (true) {
        cout << "Ingrese el nombre de la actividad ('x' para salir): ";
        cin.ignore();
        getline(cin, nombre);

        if (nombre == "x") {
            cout << "Saliendo al menu principal.\n";
            break;
        }

        cout << "Ingrese la descripcion de la actividad: ";
        getline(cin, descripcion);
        cout << "Ingrese la fecha (dia mes ano): ";
        cin >> dia >> mes >> ano;

        ofstream archivo("actividades.txt", ios::app);
        if (archivo.is_open()) {
            archivo << "Nombre: " << nombre << "\n";
            archivo << "Descripcion: " << descripcion << "\n";
            archivo << "Fecha: " << dia << "/" << mes << "/" << ano << "\n";
            archivo << "----------------\n";
            cout << "Actividad anadida correctamente.\n";
            archivo.close();
        } else {
            cout << "No se pudo abrir el archivo.\n";
        }
    }
}

void clsGestorDeActividades::MostrarActividades() {
    ifstream archivo("actividades.txt");
    if (archivo.is_open()) {
        string linea;
        cout << "ACTIVIDADES\n";
        cout << "-----------------------\n";
        while (getline(archivo, linea)) {
            if (linea == "----------------") {
                cout << "----------------\n";
            } else {
                cout << linea << "\n";
            }
        }
        archivo.close();
    } else {
        cout << "No se pudo abrir el archivo.\n";
    }
}

void clsGestorDeActividades::EliminarActividad() {
    cout << "Ingrese el nombre de la actividad que desea eliminar: ";
    cin.ignore();
    getline(cin, nombre);

    ifstream archivoEntrada("actividades.txt");
    ofstream archivoSalida("temp.txt");

    if (archivoEntrada.is_open() && archivoSalida.is_open()) {
        string linea;
        bool actividadEncontrada = false;
        while (getline(archivoEntrada, linea)) {
            size_t encontrado = linea.find("Nombre: " + nombre);
            if (encontrado != string::npos) {
                actividadEncontrada = true;
                cout << "Actividad eliminada correctamente.\n";
                getline(archivoEntrada, linea);
                getline(archivoEntrada, linea);
                getline(archivoEntrada, linea);
            } else {
                archivoSalida << linea << "\n";
            }
        }

        archivoEntrada.close();
        archivoSalida.close();

        if (!actividadEncontrada) {
            cout << "No se encontro la actividad.\n";
            remove("temp.txt");
        } else {
            remove("actividades.txt");
            rename("temp.txt", "actividades.txt");
        }
    } else {
        cout << "No se pudo abrir el archivo.\n";
    }
}

void clsGestorDeActividades::Menu() {
    int opcion;
    do {
        cout << "\n------ Menu ------\n";
        cout << "1. Anadir Actividad\n";
        cout << "2. Mostrar Actividades\n";
        cout << "3. Eliminar Actividad\n";
        cout << "0. Salir\n";
        cout << "Ingrese su opcion: ";
        cin >> opcion;

        switch (opcion) {
            case 1:
                AgregarActividad();
                break;
            case 2:
                MostrarActividades();
                break;
            case 3:
                EliminarActividad();
                break;
            case 0:
                cout << "Saliendo del programa.\n";
                break;
            default:
                cout << "Opcion no valida. Intente de nuevo.\n";
        }
    } while (opcion != 0);
}


#include "clsBiblioteca.h"
#include "clsLibro.h"
#include <fstream>
#include <iostream>
#include <iomanip>
using namespace std;

clsBiblioteca::clsBiblioteca() {
    nlibros = 0;
}

void clsBiblioteca::añadirLibro() {
    string nombre, autor, etiqueta; // Variables locales para almacenar los datos del libro
    int ndepaginas;

    cout << "Agregue un nuevo libro:\n";

    // Solicitar los datos del libro al usuario
    cout << "Nombre del Libro: ";
    cin.ignore();
    getline(cin, nombre);
    
    cout << "Autor del libro: ";
    getline(cin, autor);
    
    cout << "Numero de paginas: ";
    cin >> ndepaginas;
    
    cout << "Etiqueta: ";
    cin.ignore(); // Limpiar el buffer del teclado
    getline(cin, etiqueta);

    // Crear un nuevo objeto clsLibro y agregarlo al array de libros
    ListadeLibros[nlibros] = new clsLibro(nombre, autor, ndepaginas, etiqueta);
    nlibros++;

    // Abrir el archivo en modo de escritura (ios::app para agregar al final)
    ofstream archivobiblioteca("biblioteca.txt", ios::app);
    
    // Verificar si el archivo se abrió correctamente
    if (!archivobiblioteca.is_open()) {
        cout << "No se puede abrir el archivo" << endl;
    }
    else {
        // Escribir los datos del libro en el archivo
        archivobiblioteca << nombre << endl;
        archivobiblioteca << autor << endl;
        archivobiblioteca << ndepaginas << endl;
        archivobiblioteca << etiqueta << endl;

        // Cerrar el archivo
        archivobiblioteca.close();
        cout << "Datos del libro agregados al archivo" << endl;
    }
}

void clsBiblioteca::mostrarBiblioteca() {
    // Datos del libro
    string nombre, autor, etiqueta;
    int ndepaginas;

    // ifstream abre el archivo en forma de lectura
    ifstream archivobiblioteca("biblioteca.txt");

    // Verificar si el archivo se abrió correctamente
    if (!archivobiblioteca.is_open()) {
        cout << "No se puede abrir el archivo" << endl;
    }
    else {
        cout << "LISTA DE LIBROS REGISTRADOS\n\n";

        // Prepara encabezado de tabla a mostrar
        cout << left;
        cout << setw(30) << "Nombre" << setw(20) << "Autor" << setw(15);
        cout << "Num. Paginas" << setw(20) << "Etiqueta" << endl;

        // Lista cada registro en el archivo
        while (getline(archivobiblioteca, nombre)) {
            getline(archivobiblioteca, autor);
            archivobiblioteca >> ndepaginas;
            archivobiblioteca.ignore(); // Ignorar el salto de línea
            getline(archivobiblioteca, etiqueta);

            // Muestra resultados en pantalla
            cout << left;
            cout << setw(30) << nombre;
            cout << setw(20) << autor << setw(15) << ndepaginas;
            cout << setw(20) << etiqueta << endl;
        }
        archivobiblioteca.close();
    }
    cout<< endl;
}

void clsBiblioteca::eliminarLibro_por_nombre() {
    string nombre_a_eliminar;
    cout << "Ingrese el nombre del libro que desea eliminar: ";
    cin.ignore();
    getline(cin, nombre_a_eliminar);

    ifstream archivo_lectura("biblioteca.txt");
    ofstream archivo_temporal("temp.txt");

    if (!archivo_lectura.is_open() || !archivo_temporal.is_open()) {
        cout << "Error al abrir los archivos" << endl;
        return;
    }

    string nombre, autor, etiqueta;
    int ndepaginas;
    bool encontrado = false;

    while (getline(archivo_lectura, nombre)) {
        getline(archivo_lectura, autor);
        archivo_lectura >> ndepaginas;
        archivo_lectura.ignore();
        getline(archivo_lectura, etiqueta);

        if (nombre != nombre_a_eliminar) {
            // Si el nombre del libro no coincide con el nombre a eliminar, escribirlo en el archivo temporal
            archivo_temporal << nombre << endl;
            archivo_temporal << autor << endl;
            archivo_temporal << ndepaginas << endl;
            archivo_temporal << etiqueta << endl;
        } else {
            encontrado = true;
        }
    }

    archivo_lectura.close();
    archivo_temporal.close();

    if (encontrado) {
        // Eliminar el archivo original y renombrar el archivo temporal
        remove("biblioteca.txt");
        rename("temp.txt", "biblioteca.txt");
        cout << "Libro eliminado exitosamente." << endl;
    } else {
        cout << "No se encontró un libro con ese nombre." << endl;
    }
}

void clsBiblioteca::buscarLibro_por_etiqueta() {
    string etiqueta_a_buscar;
    cout << "Ingrese la etiqueta del libro que desea buscar: ";
    cin.ignore();
    getline(cin, etiqueta_a_buscar);
    ifstream archivo_lectura("biblioteca.txt");
    if (!archivo_lectura.is_open()) {
        cout << "No se puede abrir el archivo" << endl;
        return;
    }
    string nombre, autor, etiqueta;
    int ndepaginas;
    bool encontrado = false;
    cout << "Resultados de la búsqueda:\n\n";
    cout << left;
    cout << setw(30) << "Nombre" << setw(20) << "Autor" << setw(15);
    cout << "Num. Paginas" << setw(20) << "Etiqueta" << endl;
    while (getline(archivo_lectura, nombre)) {
        getline(archivo_lectura, autor);
        archivo_lectura >> ndepaginas;
        archivo_lectura.ignore();
        getline(archivo_lectura, etiqueta);

        if (etiqueta == etiqueta_a_buscar) {
            // Si la etiqueta del libro coincide con la etiqueta buscada, mostrar los detalles del libro
            cout << setw(30) << nombre;
            cout << setw(20) << autor << setw(15) << ndepaginas;
            cout << setw(20) << etiqueta << endl;
            encontrado = true;
        }
    }
    archivo_lectura.close();
    if (!encontrado) {
        cout << "No se encontraron libros con la etiqueta especificada." << endl;
    }
}

void clsBiblioteca::modificarLibro_por_nombre() {
    string nombre_a_modificar;
    cout << "Ingrese el nombre del libro que desea modificar: ";
    cin.ignore();
    getline(cin, nombre_a_modificar);

    ifstream archivo_lectura("biblioteca.txt");
    ofstream archivo_temporal("temp.txt");

    if (!archivo_lectura.is_open() || !archivo_temporal.is_open()) {
        cout << "Error al abrir los archivos" << endl;
        return;
    }

    string nombre, autor, etiqueta;
    int ndepaginas;
    bool encontrado = false;

    while (getline(archivo_lectura, nombre)) {
        getline(archivo_lectura, autor);
        archivo_lectura >> ndepaginas;
        archivo_lectura.ignore();
        getline(archivo_lectura, etiqueta);

        if (nombre == nombre_a_modificar) {
            encontrado = true;
            cout << "Libro encontrado. Modifique los datos:\n";

            // Solicitar los nuevos datos del libro al usuario
            cout << "Nuevo nombre del libro: ";
            getline(cin, nombre);
            
            cout << "Nuevo autor del libro: ";
            getline(cin, autor);
            
            cout << "Nuevo numero de paginas: ";
            cin >> ndepaginas;
            
            cout << "Nueva etiqueta: ";
            cin.ignore();
            getline(cin, etiqueta);
        }

        // Escribir los datos del libro en el archivo temporal
        archivo_temporal << nombre << endl;
        archivo_temporal << autor << endl;
        archivo_temporal << ndepaginas << endl;
        archivo_temporal << etiqueta << endl;
    }

    archivo_lectura.close();
    archivo_temporal.close();

    if (encontrado) {
        // Eliminar el archivo original y renombrar el archivo temporal
        remove("biblioteca.txt");
        rename("temp.txt", "biblioteca.txt");
        cout << "Libro modificado exitosamente." << endl;
    } else {
        cout << "No se encontró un libro con ese nombre." << endl;
    }
}
void clsBiblioteca :: mostrarMenu(){
    char opcion;
    do {
        cout << "Seleccione una opcion:\n";
        cout << "1. Agregar libro\n";
        cout << "2. Mostrar libros guardados\n";
        cout << "3. Eliminar libro por nombre\n";
        cout << "4. Modificar libro por nombre\n";
        cout << "5. Buscar libro por etiqueta\n";
        cout << "6. Salir\n";
        cout << "Opcion: ";
        cin >> opcion;
        switch (opcion) {
            case '1':
                añadirLibro();
                break;
            case '2':
                mostrarBiblioteca();
                break;
            case '3':
                eliminarLibro_por_nombre();
                break;
            case '4':
                modificarLibro_por_nombre();
                break;
            case '5':
                buscarLibro_por_etiqueta();
                break;
            case '6':
                cout << "Saliendo del programa...\n";
                break;
            default:
                cout << "Opcion invalida. Intente de nuevo.\n";
        }
    } while (opcion != '6');
}

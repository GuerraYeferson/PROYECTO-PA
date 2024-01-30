#include "clsUsuario.h"

clsUsuario::clsUsuario(std::string N, std::string E, std::string T, std::string C)
    : Nombre(N), Email(E), Telefono(T), Contrasenha(C), sesionIniciada(false) {}

void clsUsuario::crearCuenta() {
    std::cout << "\n --- CREAR CUENTA --- " << std::endl;
    std::cout << "Nombre de Usuario: ";
    std::getline(std::cin, Nombre);
    std::cout << "Contrasenha: ";
    std::getline(std::cin, Contrasenha);
    std::cout << "Nro de Celular: ";
    std::getline(std::cin, Telefono);
    std::cout << "Email: ";
    std::getline(std::cin, Email);
}

void clsUsuario::iniciarSesion() {
    if (sesionIniciada) {
        std::cout << "Ya has iniciado sesion. No es necesario volver a hacerlo." << std::endl;
        return;
    }

    std::string nombreUsuario, contrasena;

    std::cout << "\n --- INICIAR SESION --- " << std::endl;
    std::cout << "Ingrese su nombre de usuario: ";
    std::getline(std::cin, nombreUsuario);
    std::cout << "Ingrese su contrasena: ";
    std::getline(std::cin, contrasena);

    if (nombreUsuario == Nombre && contrasena == Contrasenha) {
        std::cout << "Inicio de sesion exitoso. Bienvenido, " << Nombre << "!" << std::endl;
        sesionIniciada = true;
    } else {
        std::cout << "Inicio de sesion fallido. Credenciales incorrectas." << std::endl;
    }
}

void clsUsuario::crearListaContactos() {
    if (!sesionIniciada) {
        std::cout << "Debes iniciar sesion antes de crear la lista de contactos." << std::endl;
        return;
    }

    std::string nombre, telefono, email;
    int cantidad = 0;

    std::cout << " --- CREANDO LISTA DE CONTACTOS ---" << std::endl;
    std::cout << " ** Lista de Contactos de " << Nombre << std::endl;

    std::ofstream Archivo("Lista de Contactos.txt", std::ios::app);

    if (Archivo.fail()) {
        std::cout << " ERROR: No se pudo abrir el archivo " << std::endl;
        return;
    }

    std::cout << "Ingrese el nombre del contacto (o 'x' para finalizar): ";
    std::getline(std::cin, nombre);
    std::cout << std::endl;

    while (nombre != "x") {
        std::cout << "Ingrese el telefono del contacto: ";
        std::getline(std::cin, telefono);
        std::cout << "Ingrese el email del contacto: ";
        std::getline(std::cin, email);

        Archivo << nombre << std::endl;
        Archivo << telefono << std::endl;
        Archivo << email << std::endl;

        cantidad++;

        std::cout << "Ingrese el nombre del siguiente contacto (o 'x' para finalizar): ";
        std::getline(std::cin, nombre);
    }

    Archivo.close();
}

void clsUsuario::mostrarListaContactos() {
    if (!sesionIniciada) {
        std::cout << "Debes iniciar sesion antes de mostrar la lista de contactos." << std::endl;
        return;
    }

    std::string nombre, telefono, email;
    int cantidad = 0;

    std::cout << " ** Lista de Contactos de " << Nombre << std::endl;

    std::ifstream Archivo("Lista de Contactos.txt");

    if (Archivo.fail()) {
        std::cout << " ERROR: No se pudo abrir el archivo " << std::endl;
        return;
    }

    std::getline(Archivo, nombre);

    while (!Archivo.eof()) {
        std::getline(Archivo, telefono);
        std::getline(Archivo, email);

        std::cout << "Nombre: " << nombre << std::endl;
        std::cout << "Telefono: " << telefono << std::endl;
        std::cout << "Email: " << email << std::endl;

        cantidad++;

        std::getline(Archivo, nombre);
    }

    Archivo.close();
}

void clsUsuario::mostrarMenu() {
    int opcion;
    do {
        std::cout << "\n --- MENU DE OPCIONES ---" << std::endl;
        std::cout << "1. Crear Cuenta" << std::endl;
        std::cout << "2. Iniciar Sesion" << std::endl;
        std::cout << "3. Crear Lista de Contactos" << std::endl;
        std::cout << "4. Mostrar Lista de Contactos" << std::endl;
        std::cout << "0. Salir" << std::endl;
        std::cout << "Seleccione una opcion: ";
        std::cin >> opcion;
        std::cin.ignore();  // Limpiar el buffer de entrada

        switch (opcion) {
            case 1:
                crearCuenta();
                break;
            case 2:
                iniciarSesion();
                break;
            case 3:
                crearListaContactos();
                break;
            case 4:
                mostrarListaContactos();
                break;
            case 0:
                std::cout << "Saliendo del programa. ¡Hasta luego!" << std::endl;
                break;
            default:
                std::cout << "Opcion no valida. Intentelo de nuevo." << std::endl;
        }
    } while (opcion != 0);
}

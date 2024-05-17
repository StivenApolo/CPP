/*
Definicion del Problema
Se desea implementar un sistema de gestión de biblioteca que permita agregar libros, buscar libros por título, autor o género, prestar libros y devolver libros.
specificación de los Datos de Entrada y Salida:
Entrada: 
    - Número máximo de libros que puede contener la biblioteca (numLibros).
Salida Esperada:
    - Mensajes interactivos en la consola según las acciones realizadas por el usuario:
    - Confirmación de la adición de un libro.
    - Resultados de búsqueda de libros según criterio.
    - Confirmación del préstamo o devolución de un libro.
Tipos de Datos de Entrada:
    int: Número máximo de libros (numLibros).
    char: Opción seleccionada del menú.
Restricciones y Requisitos Especiales:
    - El sistema debe limitar la cantidad de libros almacenados a un máximo especificado al inicio del programa.
    - El sistema debe controlar el ingreso de las opciones en el menu, controlando que unicamente se ingresen opciones validas 
    - Se debe controlar que un libro ya una ves prestado, no se pueda prestar nuevamente
    - Las operaciones de búsqueda, préstamo y devolución deben considerar el estado de la biblioteca (vacía o con libros disponibles).
*/


#include <iostream>
#include <string>

using namespace std;

const int MAX_LIBROS = 100;  // Número máximo de libros que puede contener la biblioteca

// Definición de la estructura Libro
struct Libro {
    string titulo; 
    string autor;
    string genero;
    int numPaginas;
    bool disponible;
};

// Clase que representa la biblioteca
class Biblioteca {
private:
    Libro libros[MAX_LIBROS];  // Arreglo de libros
    int numLibros;             // Número actual de libros en la biblioteca

public:
    // Constructor para inicializar la biblioteca
    Biblioteca() {
        numLibros = 0;  // Inicialmente no hay libros en la biblioteca
    }

    // Función para agregar un nuevo libro a la colección
    void agregarLibro() {
        if (numLibros < MAX_LIBROS) {
            cout << "Ingrese el titulo del libro: ";
            getline(cin >> ws, libros[numLibros].titulo);
            cout << "Ingrese el autor del libro: ";
            getline(cin >> ws, libros[numLibros].autor);
            cout << "Ingrese el genero del libro: ";
            getline(cin >> ws, libros[numLibros].genero);
            cout << "Ingrese el numero de paginas: ";
            cin >> libros[numLibros].numPaginas;
            libros[numLibros].disponible = true;  // Por defecto, el libro está disponible
            numLibros++;
            cout << "Libro agregado correctamente." << endl;
        } else {
            cout << "La biblioteca está llena, no se puede agregar mas libros." << endl;
        }
    }

    // Función para buscar libros por título, autor o género
    void buscarLibros() {
        string criterio;
        cout << "Ingrese criterio de busqueda (título, autor o género): ";
        getline(cin >> ws, criterio);

        bool encontrado = false;
        cout << "Resultados de busqueda para '" << criterio << "':" << endl;
        for (int i = 0; i < numLibros; i++) {
            if (libros[i].titulo.find(criterio) != string::npos ||
                libros[i].autor.find(criterio) != string::npos ||
                libros[i].genero.find(criterio) != string::npos) {
                cout << libros[i].titulo << " by " << libros[i].autor << " (" << libros[i].genero << ")" << endl;
                encontrado = true;
            }
        }

        if (!encontrado) {
            cout << "No se encontraron libros que coincidan con el criterio de busqueda." << endl;
        }
    }

    // Función para prestar un libro
    void prestarLibro() {
        string tituloLibro;
        cout << "Ingrese el titulo del libro que desea prestar: ";
        getline(cin >> ws, tituloLibro);

        bool encontrado = false;
        for (int i = 0; i < numLibros; i++) {
            if (libros[i].titulo == tituloLibro) {
                if (libros[i].disponible) {
                    libros[i].disponible = false;
                    cout << "Libro prestado correctamente." << endl;
                } else {
                    cout << "Este libro ya esta prestado." << endl;
                }
                encontrado = true;
                break;
            }
        }

        if (!encontrado) {
            cout << "Libro no encontrado." << endl;
        }
    }

    // Función para devolver un libro prestado
    void devolverLibro() {
        string tituloLibro;
        cout << "Ingrese el titulo del libro que desea devolver: ";
        getline(cin >> ws, tituloLibro);

        bool encontrado = false;
        for (int i = 0; i < numLibros; i++) {
            if (libros[i].titulo == tituloLibro) {
                libros[i].disponible = true;
                cout << "Libro devuelto correctamente." << endl;
                encontrado = true;
                break;
            }
        }

        if (!encontrado) {
            cout << "Libro no encontrado." << endl;
        }
    }

    // Función para mostrar el menú y procesar la selección del usuario
    void mostrarMenu() {
        char opcion;
        do {
            cout << "\n----- MENU -----" << endl;
            cout << "1. Agregar libro" << endl;
            cout << "2. Buscar libros" << endl;
            cout << "3. Prestar libro" << endl;
            cout << "4. Devolver libro" << endl;
            cout << "5. Salir" << endl;
            cout << "Ingrese su opcion: ";
            cin >> opcion;
            cin.ignore();  // Limpiar el buffer de entrada

            switch (opcion) {
                case '1':
                    agregarLibro();
                    break;
                case '2':
                    buscarLibros();
                    break;
                case '3':
                    prestarLibro();
                    break;
                case '4':
                    devolverLibro();
                    break;
                case '5':
                    cout << "Saliendo del programa..." << endl;
                    break;
                default:
                    cout << "Opcion invalida. Inténtelo de nuevo." << endl;
            }
        } while (opcion != '5');
    }
};

// Función principal
int main() {
    int numLibros;

    cout << "Bienvenido al sistema de gestion de biblioteca." << endl;
    cout << "Ingrese el numero maximo de libros que puede contener la biblioteca: ";
    cin >> numLibros;
    cin.ignore();  // Limpiar el buffer de entrada

    Biblioteca biblioteca;

    // Mostrar el menú de opciones
    biblioteca.mostrarMenu();

    return 0;
}

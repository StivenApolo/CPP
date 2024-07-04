/*
Desarrolle un sistema simple con programación modular para gestionar los libros en una biblioteca.
El sistema debe manejar un vector de libros y permitir agregar libros, buscar libros, 
listar todos los libros y eliminar libros. Para ello cree la 
estructura Libro con los siguientes campos: 
id (entero), 
titulo (cadena de caracteres), 
autor (cadena de caracteres) 
y año (entero). 
Cree un menú que permita seleccionar las siguientes opciones: 

Agregar Libro: Permitir al usuario agregar un nuevo libro a la biblioteca.
Buscar Libro: Permitir al usuario buscar un libro por su ID.
Listar Libros: Mostrar todos los libros disponibles en la biblioteca.
Eliminar Libro: Permitir al usuario eliminar un libro por su ID.
*/

#include <iostream>

using namespace std;

struct Libro{
    int id;
    string titulo;
    string autor;
    int anio;
};

void agregarLibro(Libro[], int&);
void buscarLibro(Libro[], int);
void listarLibros(Libro[], int);
void eliminarLibro(Libro[], int&);

int main(){
    int opcion;
    int n = 0;
    int cantidadLibros = 0;
    cout << "Ingrese la cantidad de libros que puede almacenar la biblioteca: ";
    cin >> cantidadLibros;
    Libro libros[cantidadLibros];

    do{
        cout << "\nMENU: \n";
        cout << "1. Agregar Libro\n";
        cout << "2. Buscar Libro\n";
        cout << "3. Listar Libros\n";
        cout << "4. Eliminar Libro\n";
        cout << "5. Salir\n";
        cout << "Opcion: ";
        cin >> opcion;

        switch(opcion){
            case 1: 
                    if(n == cantidadLibros){ // Si la cantidad de libros es igual a la cantidad de libros que puede almacenar la biblioteca
                        cout << "No hay espacio para mas libros\n";
                        break;
                    }
                    cout << "Agregar Libro\n";
                    agregarLibro(libros, n);
                    break;
            case 2: 
                    if(n == 0){ // Si no hay libros
                        cout << "No hay libros para buscar\n";
                        break;
                    }
                    cout << "Buscar Libro\n";
                    buscarLibro(libros, n);
                    break;
            case 3: 
                    if(n == 0){  // Si no hay libros
                        cout << "No hay libros para listar\n";
                        break;
                    }
                    cout << "Listar Libros\n";
                    listarLibros(libros, n);
                    break;
            case 4: 
                    if(n == 0){ // Si no hay libros
                        cout << "No hay libros para eliminar\n";
                        break;
                    }
                    eliminarLibro(libros, n);
                    break;
            case 5: break;
            default: cout << "Opcion no valida\n";
        }
        //Borrar Pantalla
        system("pause");
        cout << "\nPresione Enter para continuar...";
        system("cls"); 
    }while(opcion != 5);
    return 0;
}

void agregarLibro(Libro libros[], int &n){
    cout << "Ingrese el ID del libro: ";
    cin >> libros[n].id;  // .id es un miembro de la estructura Libro y se accede con el operador punto
    cin.ignore(); // Limpiar el buffer para que la siguiente entrada no sea ignorada
    cout << "Ingrese el titulo del libro: ";
    getline(cin, libros[n].titulo); // getline para leer cadenas de caracteres y cin para leer enteros
    cout << "Ingrese el autor del libro: ";
    getline(cin, libros[n].autor); // getline para leer cadenas de caracteres  y cin para leer enteros
    cout << "Ingrese el anio del libro: ";
    cin >> libros[n].anio; // .anio es un miembro de la estructura Libro y se accede con el operador punto no se usa getline porque es un entero
    n++;  // Incrementar el contador de libros
}

void buscarLibro(Libro libros[], int n){
    int id;
    cout << "Ingrese el ID del libro a buscar: ";
    cin >> id;

    for(int i = 0; i < n; i++){
        if(libros[i].id == id){
            cout << "ID: " << libros[i].id << endl;
            cout << "Titulo: " << libros[i].titulo << endl;
            cout << "Autor: " << libros[i].autor << endl;
            cout << "Anio: " << libros[i].anio << endl;
            return;
        }
    }

    cout << "Libro no encontrado\n";
}   

void listarLibros(Libro libros[], int n){
    for(int i = 0; i < n; i++){
        cout << "ID: " << libros[i].id << endl;
        cout << "Titulo: " << libros[i].titulo << endl;
        cout << "Autor: " << libros[i].autor << endl;
        cout << "Anio: " << libros[i].anio << endl;
        cout << endl;
    }
}

void eliminarLibro(Libro libros[], int &n){
    int id;
    cout << "Ingrese el ID del libro a eliminar: ";
    cin >> id;

    for(int i = 0; i < n; i++){
        if(libros[i].id == id){
            for(int j = i; j < n-1; j++){
                libros[j] = libros[j+1];
            }
            n--;
            cout << "Libro eliminado\n";
            return;
        }
    }

    cout << "Libro no encontrado\n";
}


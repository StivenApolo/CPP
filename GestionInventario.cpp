/*Desarrolle un sistema de gestión de inventario para una tienda. El sistema debe 
permitir agregar, modificar, buscar, listar y eliminar productos. Además, debe ser 
capaz de guardar y cargar el inventario desde un fichero.*/

#include <iostream>

using namespace std;

// Estructura de un producto
struct Producto {
    string nombre;
    int cantidad;
    float precio;
};

// Prototipos de funciones
void agregarProducto(Producto productos[], int &n);
void modificarProducto(Producto productos[], int n);
void buscarProducto(Producto productos[], int n);
void listarProductos(Producto productos[], int n);
void eliminarProducto(Producto productos[], int &n);
void guardarInventario(Producto productos[], int n);
void cargarInventario(Producto productos[], int &n);

int main() {
    Producto productos[100]; // Inventario de productos
    int n = 0; // Cantidad de productos en el inventario
    int opcion;

    do {
        cout << "\n1. Agregar producto" << endl;
        cout << "2. Modificar producto" << endl;
        cout << "3. Buscar producto" << endl;
        cout << "4. Listar productos" << endl;
        cout << "5. Eliminar producto" << endl;
        cout << "6. Guardar inventario" << endl;
        cout << "7. Cargar inventario" << endl;
        cout << "8. Salir" << endl;
        cout << "Opcion: ";
        cin >> opcion;

        switch(opcion) {
            case 1:
                agregarProducto(productos, n);
                system("pause");
                system("cls");
                break;
            case 2:
                modificarProducto(productos, n);
                system("pause");
                system("cls");
                break;
            case 3:
                buscarProducto(productos, n);
                system("pause");
                system("cls");
                break;
            case 4:
                listarProductos(productos, n);
                system("pause");
                system("cls");
                break;
            case 5:
                eliminarProducto(productos, n);
                system("pause");
                system("cls");
                break;
            case 6:
                guardarInventario(productos, n);
                system("pause");
                system("cls");
                break;
            case 7:
                cargarInventario(productos, n);
                system("pause");
                system("cls");
                break;
            case 8:
                cout << "Saliendo..." << endl;
                break;
            default:
                cout << "Opción inválida" << endl;
                system("pause");
                system("cls");
        }
    } while(opcion != 8);

    return 0;
}

// Agregar un producto al inventario
void agregarProducto(Producto productos[], int &n) {
    cout << "\nNombre: ";
    cin >> productos[n].nombre;
    cout << "Cantidad: ";
    cin >> productos[n].cantidad;
    cout << "Precio: ";
    cin >> productos[n].precio;
    n++;// n++ == n=n+1
}

// Modificar un producto del inventario
void modificarProducto(Producto productos[], int n) {
    string nombre;
    cout << "\nNombre del producto a modificar: ";
    cin >> nombre;

    for(int i = 0; i < n; i++) {
        if(productos[i].nombre == nombre) {
            cout << "Nuevo nombre: ";
            cin >> productos[i].nombre;
            cout << "Nueva cantidad: ";
            cin >> productos[i].cantidad;
            cout << "Nuevo precio: ";
            cin >> productos[i].precio;
            return;
        }
    }

    cout << "Producto no encontrado" << endl;
}

// Buscar un producto en el inventario
void buscarProducto(Producto productos[], int n) {
    string nombre;
    cout << "\nNombre del producto a buscar: ";
    cin >> nombre;

    for(int i = 0; i < n; i++) {
        if(productos[i].nombre == nombre) {
            cout << "Cantidad: " << productos[i].cantidad << endl;
            cout << "Precio: " << productos[i].precio << endl;
            return;
        }
    }

    cout << "Producto no encontrado" << endl;
}
// Listar todos los productos del inventario
void listarProductos(Producto productos[], int n) {
    cout << endl;
    for(int i = 0; i < n; i++) {
        cout << "Nombre: " << productos[i].nombre << endl;
        cout << "Cantidad: " << productos[i].cantidad << endl;
        cout << "Precio: " << productos[i].precio << endl;
        cout << endl;
    }
}

// Eliminar un producto del inventario
void eliminarProducto(Producto productos[], int &n) {
    string nombre;
    cout << "\nNombre del producto a eliminar: ";
    cin >> nombre;

    for(int i = 0; i < n; i++) {
        if(productos[i].nombre == nombre) {
            for(int j = i; j < n - 1; j++) {
                productos[j] = productos[j + 1];
            }
            n--;
            cout << "Producto eliminado" << endl;
            return;
        }
    }

    cout << "Producto no encontrado" << endl;
}

// Guardar el inventario en un fichero
void guardarInventario(Producto productos[], int n) {
    FILE *archivo = fopen("inventario.txt", "w");

    for(int i = 0; i < n; i++) {
        fprintf(archivo, "%s %d %f\n", productos[i].nombre.c_str(), productos[i].cantidad, productos[i].precio);
    }

    fclose(archivo);
}

// Cargar el inventario desde un fichero
void cargarInventario(Producto productos[], int &n) {
    FILE *archivo = fopen("inventario.txt", "r");

    while(!feof(archivo)) { // Mientras no sea el final del archivo
    //  feof que hace? = verifica si el puntero al archivo ha llegado al final del archivo
        fscanf(archivo, "%s %d %f\n", productos[n].nombre.c_str(), &productos[n].cantidad, &productos[n].precio); // c_str() convierte un string a un array de caracteres
        n++;
    }
    fclose(archivo);

}

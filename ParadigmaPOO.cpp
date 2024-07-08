/* Paradigma Orientado a Objetos
que es: 
El paradigma orientado a objetos es un paradigma de programación que trata de resolver los problemas utilizando objetos.
En este paradigma, los objetos son ciudadanos de primera clase, es decir, pueden ser asignados a variables, pasados como argumentos y retornados como valores.
En el paradigma orientado a objetos, los objetos son instancias de clases, es decir, son variables que contienen atributos y métodos.
En el paradigma orientado a objetos, se utilizan clases para definir los objetos y los métodos para definir las operaciones que pueden realizar los objetos.
En el paradigma orientado a objetos, se utilizan atributos para definir las propiedades de los objetos y los métodos para definir el comportamiento de los objetos.
En el paradigma orientado a objetos, se utilizan constructores para inicializar los objetos y destructores para liberar los recursos de los objetos.
En el paradigma orientado a objetos, se utilizan herencia, polimorfismo y encapsulamiento para reutilizar el código y para organizar los objetos en jerarquías.

como se define una clase
Una clase se define utilizando la palabra clave class seguida del nombre de la clase y de las llaves { y } que delimitan el cuerpo de la clase.
Una clase puede contener atributos, métodos, constructores y destructores. 
Los atributos se definen utilizando la palabra clave public seguida del tipo de dato y del nombre del atributo.

como se define un objeto
Un objeto se define utilizando la palabra clave new seguida del nombre de la clase y de los paréntesis ( y ) que delimitan los argumentos del constructor de la clase.
Un objeto es una instancia de una clase, es decir, es una variable que contiene atributos y métodos.
Un objeto se puede asignar a una variable, se puede pasar como argumento y se puede retornar como valor.

*/
// PROGRAMA PARA ENTENDEER LA PROGRAMACION ORIENTADA A OBJETOS PARA GESTIONAR A UNA PERSONA QUE TRABAJA EN UNA TIENDA O COMPRA EN UNA TIENDA

#include <iostream>

using namespace std;

class Persona{
    public:
        string nombre;
        int edad;
        string direccion;
        string telefono;
        string email;
        void mostrarDatos();
};

void Persona::mostrarDatos(){
    cout << "Nombre: " << nombre << endl;
    cout << "Edad: " << edad << endl;
    cout << "Direccion: " << direccion << endl;
    cout << "Telefono: " << telefono << endl;
    cout << "Email: " << email << endl;
}

class Empleado : public Persona{
    public:
        string puesto;
        float salario;
        void mostrarDatos();
};

void Empleado::mostrarDatos(){
    cout << "Nombre: " << nombre << endl;
    cout << "Edad: " << edad << endl;
    cout << "Direccion: " << direccion << endl;
    cout << "Telefono: " << telefono << endl;
    cout << "Email: " << email << endl;
    cout << "Puesto: " << puesto << endl;
    cout << "Salario: " << salario << endl;
}

class Cliente : public Persona{
    public:
        string tarjetaCredito;
        float saldo;
        void mostrarDatos();
};

void Cliente::mostrarDatos(){
    cout << "Nombre: " << nombre << endl;
    cout << "Edad: " << edad << endl;
    cout << "Direccion: " << direccion << endl;
    cout << "Telefono: " << telefono << endl;
    cout << "Email: " << email << endl;
    cout << "Tarjeta de Credito: " << tarjetaCredito << endl;
    cout << "Saldo: " << saldo << endl;
}

//S e deben ingresar varios empleados y clientes, y generar un menu para mostrar los datos de los empleados y clientes segun el usuario lo eliga

int main (){
    int nEmpleados;
    int nClientes;
    cout << "Ingrese el numero de empleados: ";
    cin >> nEmpleados;
    cout << "Ingrese el numero de clientes: ";
    cin >> nClientes;
    Empleado empleados[nEmpleados];
    Cliente clientes[nClientes];
    for(int i = 0; i < nEmpleados; i++){
        cout << "Ingrese los datos del empleado " << i+1 << endl;
        cout << "Nombre: ";
        cin >> empleados[i].nombre;
        cout << "Edad: ";
        cin >> empleados[i].edad;
        cout << "Direccion: ";
        cin >> empleados[i].direccion;
        cout << "Telefono: ";
        cin >> empleados[i].telefono;
        cout << "Email: ";
        cin >> empleados[i].email;
        cout << "Puesto: ";
        cin >> empleados[i].puesto;
        cout << "Salario: ";
        cin >> empleados[i].salario;
    }
    for(int i = 0; i < nClientes; i++){
        cout << "Ingrese los datos del cliente " << i+1 << endl;
        cout << "Nombre: ";
        cin >> clientes[i].nombre;
        cout << "Edad: ";
        cin >> clientes[i].edad;
        cout << "Direccion: ";
        cin >> clientes[i].direccion;
        cout << "Telefono: ";
        cin >> clientes[i].telefono;
        cout << "Email: ";
        cin >> clientes[i].email;
        cout << "Tarjeta de Credito: ";
        cin >> clientes[i].tarjetaCredito;
        cout << "Saldo: ";
        cin >> clientes[i].saldo;
    }
    int opcion;
    do{
        cout << "Menu" << endl;
        cout << "1. Mostrar datos de empleados" << endl;
        cout << "2. Mostrar datos de clientes" << endl;
        cout << "3. Salir" << endl;
        cout << "Ingrese una opcion: ";
        cin >> opcion;
        switch(opcion){
            case 1:
                for(int i = 0; i < nEmpleados; i++){
                    cout << "Datos del empleado " << i+1 << endl;
                    empleados[i].mostrarDatos();
                }
                break;
            case 2:
                for(int i = 0; i < nClientes; i++){
                    cout << "Datos del cliente " << i+1 << endl;
                    clientes[i].mostrarDatos();
                }
                break;
            case 3:
                cout << "Saliendo..." << endl;
                break;
            default:
                cout << "Opcion no valida" << endl;
                break;
        }while(opcion != 3);
    } while (opcion != 3);
    return 0;
}
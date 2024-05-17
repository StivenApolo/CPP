 //Stiven Apolo 7243 
 //17/02/2024
 
 /*
    DEFINICION DE PROBLEMA: Se nececita buscar un dato en un vector de tamaño 50
    REQUERIMEINTOS:  Debe usar el Metodo de Busqueda Binaria 
    Datos de Entrada: 
                    - Dato a buscar
                    - Vector de tamaño 50
    Datos de Salida :  
                    - Dato encontrado
 */

#include <iostream>

//Definicion de prototipos de funciones y procedimientos
int BusquedaBinaria(int v[], int Buscar , int tamano);
int LlenarVector(int v[], int tamano);
void MostrarVector(int v[], int tamano);

using namespace std;

int main() {
    int Vector [10]; // Se define el el vector con el tamaño requerido
    int DatoBuscado; // Definciion del Dato a buscar en el Vector

    cout << "Llene el Vector" << endl;  // Se indica que el usuario debe ingresar los datos en el vector
    LlenarVector(Vector, 10); // Se llama a la funcion para que el vector sea llenado, se le pasa el vector vacio, y un numero, no una variable  por que el tamño esta espefificado
    
    cout << endl << "Vector" << endl ; // Se hace saltos de Linea para mostrar el vector de una mejor manera
    MostrarVector(Vector,10); // Se llama al procedimiento para mostrar el Vector antes ingresado 
    
    cout << " Ingrese el Valor a Buscar: "; // Mnesaje para que el usuario sepa que ya debe ingresar el dato que quiere buscar 
    cin >> DatoBuscado;  // Se ingresa el dato a busacr

    cout << "Dato :  "<<BusquedaBinaria(Vector, DatoBuscado ,10); // Se llama a la funcion para buscar el numero y que nos lo devuelva para poder utilizarlo de ser necesario
     
    return 0;
}

int LlenarVector(int v[], int tamano){
    for (int i = 0; i < tamano; i++)
    {
        cout << "Ingrese el Dato[" << i << "] :  " ;
        cin >> v[i];
    }
    return v[tamano];
}

void MostrarVector(int v[], int tamano){
    for (int i = 0; i < tamano; i++)
    {
        cout << "["<< i << "] :: "<< v[i] << endl;
    }
}

int BusquedaBinaria(int v[], int Buscar , int tamano){
    int aux=0;
    for (int i = 0; i < tamano/2; i++)
    {
        if (Buscar== v[i])
        {
            return v[i];
            break;
        }
        if (Buscar == v[tamano-aux] )
        {
            return v[tamano-aux];
            break;
        }
        aux=aux-1;
    }
    
}

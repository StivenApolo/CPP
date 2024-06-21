// Multiplicar Dos matrices de tamaño Filas*Columnas 

#include <iostream>

using namespace std;

int main(){

    int Filas1, Columnas1;
    int Filas2, Columnas2;

    cout << "Ingrese el numero de Filas de la Matriz 1: ";
    cin >> Filas1;
    cout << "Ingrese el numero de Columnas de la Matriz 1: ";
    cin >> Columnas1;

    cout << "Ingrese el numero de Filas de la Matriz 2: ";
    cin >> Filas2;
    cout << "Ingrese el numero de Columnas de la Matriz 2: ";
    cin >> Columnas2;

    while (Columnas1 != Filas2)
    {
        cout << endl <<"No se pueden multiplicar las matrices " << endl;
        cout << "El tamanio de las FILAS de la MATRZ 2 debe ser igual al tamanio de las COLUMNA de la MATRIZ 1"<< endl;
        cout << "Ingrese el numero de Filas de la Matriz 2: ";
        cin >> Filas2;
    }


    int Matriz1[Filas1][Columnas1];
    int Matriz2[Filas2][Columnas2];
    int VectorResultado[Filas1*Columnas2];
    
    system("cls");
    
    cout << "Ingrese los elementos de la Matriz 1: " << endl;
    for (int i = 0; i < Filas1; i++){
        for (int j = 0; j < Columnas1; j++){
            cout << "Ingrese el elemento [" << i << "][" << j << "]: ";
            cin >> Matriz1[i][j];
        }
    }

    cout << "Ingrese los elementos de la Matriz 2: " << endl;
    for (int i = 0; i < Filas2; i++){
        for (int j = 0; j < Columnas2; j++){
            cout << "Ingrese el elemento [" << i << "][" << j << "]: ";
            cin >> Matriz2[i][j];
        }
    }

    
    for (int i = 0; i < Filas1; i++){
        for (int j = 0; j < Columnas2; j++){
            VectorResultado[i*Columnas2 + j] = 0;   // Inicializar el vector resultado en 0 
            for (int k = 0; k < Columnas1; k++){
                VectorResultado[i*Columnas2 + j] += Matriz1[i][k] * Matriz2[k][j];
            }
        }
    }

    cout << "El resultado de la multiplicacion es el vector : " << endl;
    for (int i = 0; i < (Filas1*Columnas2); i++)
    {
        cout << VectorResultado[i] << " ";
    }
    

}
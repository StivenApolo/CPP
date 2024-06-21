/*Ordenar una matriz n*m y ordenarla*/

/*
    Stiven Apolo
    7243
    14/06/2024
*/
#include <iostream>

using namespace std;

int main (){

    int filas;
    int columnas;

    

    cout << "Ingrese el numero de filas: ";
    cin >> filas;

    cout << "Ingrese el numero de columnas: ";
    cin >> columnas;

    int matriz[filas][columnas];  // Declaracion de la matriz segun las filas y columnas ingresadas
    int vector[filas*columnas];  // Declaracion del vector de filas*columnas para poder guardar todos los datos de la matriz

    system("cls"); // Limpiar pantalla

    cout << "Ingrese los elementos de la matriz: " << endl;

    for (int i = 0; i < filas; i++){            // Ciclo que recorre las filas de la matriz
        for (int j = 0; j < columnas; j++){     // Ciclo que recorre las columnas de la matriz
            cout << "Ingrese el elemento [" << i << "][" << j << "]: "; // Ingreso de datos en la matriz
            cin >> matriz[i][j]; // Guardar el dato en la matriz 
        }
    }
    //O(n^2) por que usa dos ciclos anidados para recorrer la matriz

    system("cls"); // Limpiar pantalla

    cout << "Matriz original: " << endl;
    for (int i = 0; i < filas; i++){             //ciclo que recorre las filas de la matriz
        for (int j = 0; j < columnas; j++){    //ciclo que recorre las columnas de la matriz
            cout << matriz[i][j] << " ";    //imprimir los datos de la matriz
        }
        cout << endl;
    }
    //O(n^2) por que usa dos ciclos anidados para recorrer la matriz

    //pasar los datos de la matriz al vector
    int k = 0;
    for (int i = 0; i < filas; i++){            //ciclo que recorre las filas de la matriz
        for (int j = 0; j < columnas; j++){   //ciclo que recorre las columnas de la matriz
            vector[k] = matriz[i][j];      //guardar los datos de la matriz en el vector segun la posicion k
            k++;                  //aumentar el valor de k
        }
    }
    //O(n^2) por que usa dos ciclos anidados para recorrer la matriz


    //Ordenar el vector por METODO BURBUJA
    /*
    Uso el metodo burbuja para ordenar el vector ya que para el ingreso,impresion y para pasar los datos de 
    la matriz al vector y viceversa ya se usan dos ciclos anidados y por ende la compljidad temporal es O(n^2)
    y el metodo burbuja tiene una complejidad temporal de O(n^2) por lo que no presentaria un ventaja implementar 
    un metodo de ordenamiento mas eficiente
    */
    for (int i = 0; i < filas*columnas; i++){   
        for (int j = 0; j < filas*columnas; j++){
            if (vector[j] > vector[j+1]){
                int aux = vector[j];
                vector[j] = vector[j+1];
                vector[j+1] = aux;
            }
        }
    }
    //O(n^2) por que usa dos ciclos anidados para recorrer el vector


    //Pasar los datos del vector a la matriz
    k = 0;
    for (int i = 0; i < filas; i++){           // ciclo que recorre las filas de la matriz 
        for (int j = 0; j < columnas; j++){   // ciclo que recorre las columnas de la matriz
            matriz[i][j] = vector[k];     // guardar los datos del vector en la matriz segun la posicion k
            k++;                // aumentar el valor de k
        }
    }
    //O(n^2) por que usa dos ciclos anidados para recorrer la matriz



    cout << "Matriz ordenada: " << endl;
    for (int i = 0; i < filas; i++){         //ciclo que recorre las filas de la matriz     
        for (int j = 0; j < columnas; j++){     //ciclo que recorre las columnas de la matriz
            cout << matriz[i][j] << " ";    //imprimir los datos de la matriz
        }
        cout << endl;        //salto de linea
    }
    //O(n^2) por que usa dos ciclos anidados para recorrer la matriz

    // Complejidad Temporaral:  O(n^2) + O(n^2) + O(n^2) + O(n^2)  = O(n^2)


}


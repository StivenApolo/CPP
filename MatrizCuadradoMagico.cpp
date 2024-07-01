/*
Trabajo en Parejas
Integrantes: 
    -Stiven Apolo 7243
    -Alvaro Silva 7464
*/

#include <iostream>
#include <cstdlib> 
#include <ctime>

//Ingresar una matriz n*n ingresada al azar sin usar la fucion ramdom
//Verificar si es un cuadrado magico 
//Calcular la complejisdad big O

using namespace std;

int main (){
    int n;
    cout << "Ingrese el tamanio de la matriz: ";
    cin >> n;

    int matriz[n][n];

    // Inicializa la semilla del generador de números aleatorios
    srand(time(0));

    //Ingreso al azar de datos de la matriz
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            matriz[i][j] = rand() % 100; // Genera un número aleatorio entre 0 y 99
        }
    }
    //Complejiad O(n^2) ya que se recorre la matriz n*n veces


    //Mostrar la matriz
    cout << "Matriz generada: " << endl;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cout << matriz[i][j] << " ";
        }
        cout << endl;
    }
    //Complejiad O(n^2) ya que se recorre la matriz n*n veces


    //Verificar si es un cuadrado magico
    bool esCuadradoMagico = true;
    int sumaActual=0;
    int sumaAnterior=0;


    //Suma filas
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; i < n; i++)
        {
            sumaActual += matriz[i][j];
        }
        if (i == 0)
        {
            sumaAnterior = sumaActual;
        }
        else
        {
            if (sumaAnterior != sumaActual)
            {
                esCuadradoMagico = false;
                cout << "No es un cuadrado magico" << endl;
                return 0;
            }
        }
        sumaActual = 0;
    }
    //Complejiad O(n^2) ya que se recorre la matriz n*n veces


    //Suma columnas
    if (esCuadradoMagico==true)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; i < n; i++)
            {
                sumaActual += matriz[j][i];
            }
            if (sumaAnterior != sumaActual)
            {
                esCuadradoMagico = false;
                cout << "No es un cuadrado magico" << endl;
                return 0;
            }
            sumaActual = 0;
        }
    }
    //Complejiad O(n^2) ya que se recorre la matriz n*n veces


    //Suma diagonal principal
    if (esCuadradoMagico==true)
    {
        for (int i = 0; i < n; i++)
        {
            sumaActual += matriz[i][i];
        }
        if (sumaAnterior != sumaActual)
        {
            esCuadradoMagico = false;
            cout << "No es un cuadrado magico" << endl;
            return 0;
        }
    }
    //Complejiad O(n) ya que se recorre la matriz n veces


    //Suma diagonal secundaria
    if (esCuadradoMagico==true)
    {
        for (int i = 0; i < n; i++)
        {
            sumaActual += matriz[i][n-i-1];
        }
        if (sumaAnterior != sumaActual)
        {
            esCuadradoMagico = false;
            cout << "No es un cuadrado magico" << endl;
            return 0;
        }
    }
    //Complejiad O(n) ya que se recorre la matriz n veces
    

    //Complejidad total O(n^2) + O(n^2) + O(n^2) + O(n) + O(n) = O(n^2)


}
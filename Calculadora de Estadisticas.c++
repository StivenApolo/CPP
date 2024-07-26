/*
Por: Stiven Alexander  Codigo: 7243
Fecha: 28/04/2024
*/

#include <iostream>
#include <cmath>    // Para funciones matemáticas como sqrt()
#include <algorithm> // Para  la funcion sort

using namespace std ;

void IngresoDeArreglo(int v[], int tamano);
float PromedioDelArreglo(int v[], int tamano);
float CalcularMediana(int v[], int tamano);
float CalcularDesviacionEstandar(int v[], int tamano);

int main(){
    int n; 
    cout << " Ingrese cuantos numeros desea ingresar: " ;
    cin >>  n ;
    int v[n];
    IngresoDeArreglo(v, n);
    cout << " Promedio: " << PromedioDelArreglo(v,n) << endl;
    cout << " Mediana: " << CalcularMediana(v, n) << endl;
    cout << " Desviacion estandar: " << CalcularDesviacionEstandar(v, n) << endl;
    
}

float CalcularDesviacionEstandar(int v[], int tamano) {
    float media = PromedioDelArreglo(v, tamano);
    float suma_cuadrados_diferencia = 0.0;

    // Calcular la suma de los cuadrados de las diferencias entre cada valor y la media
    for (int i = 0; i < tamano; i++) {
        float diferencia = v[i] - media;
        suma_cuadrados_diferencia += diferencia * diferencia;
    }

    // Calcular la varianza como el promedio de los cuadrados de las diferencias
    float varianza = suma_cuadrados_diferencia / tamano;

    // Calcular la desviación estándar como la raíz cuadrada de la varianza
    float desviacion_estandar = sqrt(varianza);
    // sqrt() es una función de la biblioteca cmath que calcula la raíz cuadrada

    return desviacion_estandar;
}


float CalcularMediana(int v[], int tamano) {
    // Ordenar el arreglo para calcular la mediana
    sort(v, v + tamano);

    // Si el tamaño del arreglo es impar, devolver el valor en la posición central
    if (tamano % 2 != 0) {
        return v[tamano / 2];
    } 
    // Si el tamaño del arreglo es par, calcular el promedio de los dos valores centrales
    else {
        float mediana = (v[tamano / 2 - 1] + v[tamano / 2]) / 2.0;
        return mediana;
    }
}

float PromedioDelArreglo(int v[], int tamano){
    float promedio;
    for (int i = 0; i < tamano; i++)
    {
        promedio= promedio + v[i];
    }
    return promedio/tamano;
}

void IngresoDeArreglo(int v[], int tamano){
    for (int i = 0; i < tamano; i++)
    {
        cout  << " Ingrese la posicion |"<< i << "|: " ;
        cin >> v[i];
    }
}
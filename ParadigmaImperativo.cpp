// Paradirma: Imperativo
/*
¿ Que es ?
El paradigma imperativo es un paradigma de programación que trata de resolver los problemas utilizando instrucciones que modifican el estado de las variables.
En este paradigma, las variables son ciudadanos de primera clase, es decir, pueden ser asignadas a otras variables, pasadas como argumentos y retornadas como valores.
En el paradigma imperativo, las instrucciones son imperativas, es decir, indican al ordenador cómo realizar una tarea.
En el paradigma imperativo, se utilizan ciclos para resolver los problemas.
En el paradigma imperativo, se utilizan variables mutables, es decir, variables cuyo valor puede cambiar a lo largo del tiempo.
En el paradigma imperativo, se utilizan asignaciones, es decir, la modificación del valor de una variable.
En el paradigma imperativo, se utilizan estructuras de control, es decir, instrucciones como if, else, switch, etc.
*/
//Programa imperativo simple QUE SUMA VECTORES MODULARMENTE 

#include <iostream>

using namespace std;

int IngresoVector(int Vector[],int n);
void SumaVectores(int Vector1[],int Vector2[],int n);
void ImprimirVector(int Vector[],int n);

int main(){
    int n;
    cout << "Ingrese el tamaño de los vectores: ";
    cin >> n;
    int Vector1[n];
    int Vector2[n];
    cout << "Ingrese los elementos del primer vector: " << endl;
    IngresoVector(Vector1,n);
    cout << "Ingrese los elementos del segundo vector: " << endl;
    IngresoVector(Vector2,n);
    cout << "La suma de los vectores es: " << endl;
    SumaVectores(Vector1,Vector2,n);
    return 0;
}

int IngresoVector(int Vector[],int n){
    for(int i = 0; i < n; i++){
        cout << "Ingrese el elemento " << i+1 << ": ";
        cin >> Vector[i];
    }
}

void SumaVectores(int Vector1[],int Vector2[],int n){
    int VectorSuma[n];
    for(int i = 0; i < n; i++){
        VectorSuma[i] = Vector1[i] + Vector2[i];
    }
    ImprimirVector(VectorSuma,n);
}


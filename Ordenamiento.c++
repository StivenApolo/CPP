#include <iostream>

using namespace std;

int IngresoVector(int vector[], int numero);
void MostrarVector(int vector[], int numero);

int main (){

    int n;
    cout << "Ingrreser el tamano del vector: " ;
    cin >> n;
    int v[n];

    IngresoVector(v,n);
    MostrarVector(v,n);
    
}

int OrdenaQuickSort( int vector[], int low,  int higt){ // low y higt haces referencia a la primera u ultima posicion 

}

int IngresoVector(int vector[], int numero){
    for (int i = 0; i < numero; i++)
    {
        cout << "Ingrese el valor de la posicion (" << i << ") :  " ;
        cin >> vector[i];
    }
    return vector[numero];
}

void MostrarVector(int vector[], int numero){
    for (int i = 0; i < numero; i++)
    {
        cout << i <<  "  =  "<< vector[i]<< endl;
    }
}
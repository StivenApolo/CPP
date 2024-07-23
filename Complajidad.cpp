//Ordenamiento Burbuja Recursivo

#include <iostream>

using namespace std;

void burbuja(int a[], int n){ // n es el tamaño del arreglo, a es el arreglo a ordenar
    if(n==1){
        return;
    }
    for(int i=0; i<n-1; i++){
        if(a[i]>a[i+1]){
            int aux = a[i];
            a[i] = a[i+1];
            a[i+1] = aux;
        }
    }
    burbuja(a, n-1);
}
//Ordenamiento Burbuja sin ciclos

void BurbujaRecursivo(int a[], int n , int i, int j){
    if(i==n-1){
        return;
    }
    if(j==n-1){
        BurbujaRecursivo(a, n, i+1, 0);
        return;
    }
    if(a[j]>a[j+1]){
        int aux = a[j];
        a[j] = a[j+1];
        a[j+1] = aux;
    }
    BurbujaRecursivo(a, n, i, j+1);
}
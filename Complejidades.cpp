#include <iostream>
#include <vector>

using namespace std;

// Función recursiva para generar todos los subconjuntos de un conjunto dado
void generarSubconjuntos(const vector<int>& conjunto, vector<int>& subconjunto, int indice) {
    if (indice == conjunto.size()) {
        // Imprimir el subconjunto generado
        cout << "Subconjunto: ";
        for (int elemento : subconjunto) {
            cout << elemento << " ";
        }
        cout << endl;
        return;
    }

    // No incluir el elemento en el subconjunto
    generarSubconjuntos(conjunto, subconjunto, indice + 1);

    // Incluir el elemento en el subconjunto
    subconjunto.push_back(conjunto[indice]);
    generarSubconjuntos(conjunto, subconjunto, indice + 1);

    // Eliminar el elemento agregado para probar diferentes combinaciones
    subconjunto.pop_back();
}

int main() {
    vector<int> conjunto = {1, 2, 3};
    vector<int> subconjunto;

    cout << "Generando todos los subconjuntos del conjunto {1, 2, 3}:" << endl;
    generarSubconjuntos(conjunto, subconjunto, 0);

    return 0;
}

/*
int main() {
    int n;
    cout << "Ingrese el tamaño del vector: ";
    cin >> n;
    int V[n];
    int suma = 0;

    for (int i = 0; i < n; i++) {
        cout << "Ingrese el numero de la posicion [" << i << "] : ";
        cin >> V[i];
        suma += V[i]; // Calcula la suma de los elementos del vector
    }

    cout << "Vector multiplicado por la suma de sus elementos:" << endl;
    for (int i = 0; i < n; i++) {
        cout << " > " << V[i] * suma << endl; // Multiplica cada elemento por la suma total
    }
    
    return 0;
}



int main() {
    int n;
    cout << "Ingrese el tamaño del vector: ";
    cin >> n;
    int V[n];
    for (int i = 0; i < n; i++) {
        cout << "Ingrese el numero de la posicion [" << i << "] : ";
        cin >> V[i];
    }

    // Ordenar el vector utilizando el método de la burbuja
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (V[j] > V[j + 1]) {
                int temp = V[j];
                V[j] = V[j + 1];
                V[j + 1] = temp;
            }
        }
    }

    cout << "Vector ordenado:" << endl;
    for (int i = 0; i < n; i++) {
        cout << " > " << V[i] << endl;
    }
    return 0;
}




void quickSort(int arr[], int left, int right) {
    int i = left, j = right;
    int pivot = arr[(left + right) / 2];
    
    // Particionamiento
    while (i <= j) {
        while (arr[i] < pivot) i++;
        while (arr[j] > pivot) j--;
        if (i <= j) {
            swap(arr[i], arr[j]);
            i++;
            j--;
        }
    }
    
    // Recursión
    if (left < j) quickSort(arr, left, j);
    if (i < right) quickSort(arr, i, right);
}

int main () {
    int n;
    cout << "Ingrese el tamaño del vector: ";
    cin >> n;
    int V[n];
    for (int i = 0; i < n; i++) {
        cout << "Ingrese el numero de la posicion [" << i << "] : ";
        cin >> V[i];
    }

    // Ordenar el vector utilizando Quicksort
    quickSort(V, 0, n - 1);

    cout << "Vector ordenado:" << endl;
    for (int i = 0; i < n; i++) {
        cout << " > " << V[i] << endl;
    }
    return 0;
}


int main () {
    int n;
    cout << "Ingrese el tamaño del vector: ";
    cin >> n;
    int V[n];
    for (int i = 0; i < n; i++) {
        cout << "Ingrese el numero de la posicion [" << i << "] : ";
        cin >> V[i];
    }
    cout << "Vector:" << endl;
    for (int i = 0; i < n; i++) {
        cout << " > " << V[i] << endl;
    }
    return 0;
}

int busquedaBinaria(int arr[], int n, int x) {
    int inicio = 0;
    int fin = n - 1;
    while (inicio <= fin) {
        int medio = inicio + (fin - inicio) / 2;
        if (arr[medio] == x) {
            return medio;
        }
        if (arr[medio] < x) {
            inicio = medio + 1;
        } else {
            fin = medio - 1;
        }
    }
    return -1;
}

int main() {
    int arr[] = {2, 3, 4, 10, 40};
    int n = sizeof(arr) / sizeof(arr[0]);
    int x = 10; // Elemento a buscar

    cout << "Elemento a buscar: " << x << endl;

    int resultado = busquedaBinaria(arr, n, x);

    if (resultado == -1) {
        cout << "Elemento no encontrado en el arreglo." << endl;
    } else {
        cout << "Elemento encontrado en la posición " << resultado << " del arreglo." << endl;
    }

    return 0;
}


int main() {
    int n = 10;
    int m = 20;
    int suma = n + m;
    cout << "La suma de " << n << " y " << m << " es: " << suma << endl;
    return 0;
}
*/
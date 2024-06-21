// Stiven A lexander Apolo Parra 
// Codigo : 7243
// Fecha: 14/06/2024
/*
Definicion del Problema
Se nesecita poder buscar un elemento en un vector desordenado, para ello se debe ordenar el vector y luego realizar la busqueda binaria.

Analisis de la Complejidad 
Para el ordenamiento se utilizo el metodo de la burbuja, el cual tiene una complejidad de O(n^2), luego se realiza la busqueda binaria que tiene una complejidad de O(log n), por lo que la complejidad total del algoritmo es de O(n^2 + log n) = O(n^2)

Diseño del Algoritmo
1. Se crea un vector de tamaño n
2. Se llena el vector con numeros aleatorios
3. Se ordena el vector con el metodo de la burbuja
4. Se busca un numero aleatorio en el vector con la busqueda binaria
5. Se imprime el resultado de la busqueda
*/

// Desarrollo del Codigo

#include <iostream>
#include <vector>

using namespace std;

void IngresoVector(vector<int>& vec){  
    for (int i = 0; i < vec.size(); i++)            // Se recorre el vector/ vec.size() es el tamaño del vector
    {
        cout << "Ingrese el valor de la posicion (" << i << ") :  " ;
        float temp;                         // Se declara una variable temporal de tipo float
        cin >> temp;                        // Se ingresa el valor
        vec[i] = static_cast<int>(temp);   // Se trunca el valor ingresado
    }
}

void MostrarVector(const vector<int>& vec){         // Se recorre el vector
    for (int i = 0; i < vec.size(); i++)        // Se recorre el vector / vec.size() es el tamaño del vector
    {
        cout << i <<  "  =  "<< vec[i]<< endl; // Se imprime el valor de la posicion i
    }
}


/* Se comento una ves que se implemento el metodo de Quick Sort para mejorar la eficiencia
void OrdenarPorBurbuja(int vector[], int numero){ // Se ordena el vector
    int aux;                            // Se declara una variable auxiliar
    for (int i = 0; i < numero; i++)    // Se recorre el vector
    {
        for (int j = 0; j < numero-1; j++)      // Se recorre el vector
        {
            if (vector[j] > vector[j+1])        // Si el valor de la posicion j es mayor al valor de la posicion j+1
            {
                aux = vector[j];            // Se guarda el valor de la posicion j en aux
                vector[j] = vector[j+1];        // Se asigna el valor de la posicion j+1 a la posicion j
                vector[j+1] = aux;        // Se asigna el valor de aux a la posicion j+1
            }
        }
    }
}

*/

void swap(int &a,int &b){       // Se intercambian los valores de a y b
    int aux = a;                // Se guarda el valor de a en una variable auxiliar
    a = b;                      // Se asigna el valor de b a a
    b = aux;                    // Se asigna el valor de aux a b
}

int particion(vector<int>&array,int inicio, int fin){ // Se particiona el vector
    int pivote = array[inicio];     // Se toma el primer elemento como pivote
    int i = inicio + 1;        // Se inicializa i en inicio + 1
    for(int j = i; j <= fin; j++){      // Se recorre el vector desde i hasta fin
        if(array[j] < pivote){          // Si el valor de la posicion j es menor al pivote
            swap(array[i],array[j]);       // Se intercambian los valores de las posiciones i y j
            i++;                        // Se incrementa i
        }
    }
    swap(array[inicio],array[i-1]);     // Se intercambian los valores de las posiciones inicio y i-1
    return i-1;                         // Se retorna i-1
}

void quickSort(vector<int>&arreglo, int inicio, int fin){ // Se ordena el vector
    if(inicio < fin){                                       // Si inicio es menor a fin
        int pivote = particion(arreglo,inicio,fin);     // Se particiona el vector
        quickSort(arreglo,inicio,pivote-1);        // Se ordena la primera parte del vector
        quickSort(arreglo,pivote+1,fin);            // Se ordena la segunda parte del vector
    }
}

int BusquedaBinaria(const vector<int>& vec, int dato){ // const vector<int>& vec es un vector constante de enteros, int dato es el dato a buscar
    int inicio = 0;                                         // Se inicializa inicio en 0
    int fin = vec.size()-1;                     // Se inicializa fin en el tamaño del vector - 1
    int centro;                             // Se declara la variable centro
    while (inicio <= fin)           // Mientras inicio sea menor o igual a fin
    {
        centro = (inicio + fin) / 2;        // Se calcula el centro
        if (vec[centro] == dato)        // Si el valor de la posicion centro es igual al dato
        {
            return centro;              // Se retorna centro
        }
        else if (vec[centro] < dato)        // Si el valor de la posicion centro es menor al dato
        {
            inicio = centro + 1;        // Se asigna centro + 1 a inicio
        }
        else
        {
            fin = centro - 1;               // Se asigna centro - 1 a fin
        }
    }
    return -1;                      // Se retorna -1
}

int main (){
    int n;                  // Se declara la variable n
    cout << "Ingrese el tamano del vector: " ;        // Se imprime un mensaje
    cin >> n;        // Se ingresa el valor de n
    vector<int> v(n);    // Se crea un vector de tamaño n
    IngresoVector(v);       // Se llena el vector
    cout << endl;           // Se imprime un salto de linea
    cout << "Vector Ordenado " << endl;     // Se imprime un mensaje
    //OrdenarPorBurbuja(v.data(),n);      // Se ordena el vector
    // Se comenta este ordenamiento y se utiliza el metodo de Quick Sort para mejorar la eficiencia
    quickSort(v,0,n-1);     // Se ordena el vector
    MostrarVector(v);       // Se muestra el vector
    cout << "Ingrese el dato a buscar: ";       // Se imprime un mensaje
    int dato;                       // Se declara la variable dato
    cin >> dato;                    // Se ingresa el valor de dato
    int pos = BusquedaBinaria(v,dato);    // Se busca el dato en el vector
    if (pos != -1)      // Si pos es diferente de -1
    {
        cout << "El dato se encuentra en la posicion: " << pos << endl;     // Se imprime la posicion del dato
    }
    else
    {
        cout << "El dato no se encuentra en el vector" << endl;     // Se imprime un mensaje
    }
    return 0;           // Se retorna 0
}


/*
Pruebas
caso 1:
Ingrresar el tamano del vector: 5
Ingrese el valor de la posicion (0) :  5
Ingrese el valor de la posicion (1) :  4
Ingrese el valor de la posicion (2) :  3
Ingrese el valor de la posicion (3) :  2
Ingrese el valor de la posicion (4) :  1

Vector Ordenado 
0  =  1
1  =  2
2  =  3
3  =  4
4  =  5
Ingrese el dato a buscar: 3
El dato se encuentra en la posicion: 2

caso 2:
Ingrresar el tamano del vector: 5
Ingrese el valor de la posicion (0) :  5.2
Ingrese el valor de la posicion (1) :  4.3
Ingrese el valor de la posicion (2) :  3.1
Ingrese el valor de la posicion (3) :  2.5
Ingrese el valor de la posicion (4) :  1.7

-- los valores se truncan Por ser definidos como enteros

Vector Ordenado
0  =  1
1  =  2
2  =  3
3  =  4
4  =  5
Ingrese el dato a buscar: 3
El dato se encuentra en la posicion: 2
*/

//Optimizacion  
// Se puede optimizar el algoritmo de ordenamiento, Utilizando el metodo de Quick Sort, el cual tiene una complejidad de O(n log n) en el peor de los casos, y O(n^2) en el peor de los casos, por lo que la complejidad total del algoritmo seria de O(n log n) + O(log n) = O(n log n)
/*
Por eso  incluimos la libreria <vector> y cambiamos(Comentamos) el metodo de ordenamiento de burbuja por el metodo de Quick Sort
*/

//Documentacion
/*
    - Se comento la mayoria de lineas de codigo, para mejorar el entendimiento de este, y asi se peuda entender el funcionamiento y el proposito 
    - El codigo se lo realizo de forma modularizada, para que sea mas facil de entender y de mantener
    - Se utilizo el metodo de Quick Sort para mejorar la eficiencia del algoritmo
    - Se realizaron pruebas para verificar el correcto funcionamiento del algoritmo
    - Se documentaron las pruebas realizadas
*/



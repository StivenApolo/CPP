//Progrma basico para entender el paradigma funcional en C++

/*
Que es el paradigma funcional?
El paradigma funcional es un paradigma de programación que trata de resolver los problemas utilizando funciones matemáticas.
En este paradigma, las funciones son ciudadanos de primera clase, es decir, pueden ser asignadas a variables, pasadas como argumentos y retornadas como valores.
En el paradigma funcional, las funciones son puras, es decir, no tienen efectos secundarios, no modifican el estado de las variables, no realizan operaciones de entrada/salida, etc.
En el paradigma funcional, se evita el uso de ciclos y se utilizan recursiones para resolver los problemas.
En el paradigma funcional, se evita el uso de variables mutables, es decir, variables cuyo valor puede cambiar a lo largo del tiempo.
En el paradigma funcional, se evita el uso de asignaciones, es decir, de la modificación del valor de una variable.
En el paradigma funcional, se evita el uso de estructuras de control, es decir, de instrucciones como if, else, switch, etc.
En el paradigma funcional, se evita el uso de excepciones, es decir, de la interrupción del flujo normal de ejecución de un programa.
En el paradigma funcional, se evita el uso de bucles, es decir, de instrucciones como for, while, do-while, etc.


Funciones puras e impuras
Una función pura es una función que no tiene efectos secundarios, es decir, que no modifica el estado de las variables, no realiza operaciones de entrada/salida, etc.
Una función impura es una función que tiene efectos secundarios, es decir, que modifica el estado de las variables, realiza operaciones de entrada/salida, etc.
En el paradigma funcional, se prefieren las funciones puras a las funciones impuras, ya que las funciones puras son más fáciles de razonar, de probar y de depurar.
En el paradigma funcional, se recomienda que la mayoría de las funciones sean puras y que sólo unas pocas funciones sean impuras.

cuando se utiliza el paradigma funcional?
El paradigma funcional se utiliza cuando se desea resolver problemas de forma declarativa, es decir, especificando qué se quiere hacer en lugar de cómo se quiere hacer.
El paradigma funcional se utiliza cuando se desea resolver problemas de forma recursiva, es decir, dividiendo un problema en subproblemas más pequeños y resolviendo cada subproblema de forma recursiva.
El paradigma funcional se utiliza cuando se desea resolver problemas de forma inmutable, es decir, sin modificar el estado de las variables, sin realizar operaciones de entrada/salida, etc.
El paradigma funcional se utiliza cuando se desea resolver problemas de forma matemática, es decir, utilizando funciones matemáticas para representar los datos y las operaciones.
El paradigma funcional se utiliza cuando se desea resolver problemas de forma paralela, es decir, utilizando múltiples hilos de ejecución para resolver un problema de forma concurrente.

*/


#include <iostream>

using namespace std;

int suma(int a, int b){ // Funcion pura
    return a + b; // Funcion pura porque no modifica el estado de las variables
}

// Funcion impura

void imprimir(int a, int b){ // Funcion impura
    cout << "La suma de " << a << " + " << b << " es: " << suma(a,b) << endl;  // Funcion pura porque no modifica el estado de las variables
}


int main(){
    int a = 5;
    int b = 10;
    cout << "La suma de " << a << " + " << b << " es: " << suma(a,b) << endl;
    imprimir(a,b); // Funcion impura porque modifica el estado de las variables
    return 0;
}
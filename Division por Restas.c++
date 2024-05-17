// Stiven Apolo 7243

#include <iostream>

using namespace std ;
int DivisionPorRestasSucesivas(int *Dividendo, int Divisor, int i );
int MultiplicacionPorSuma(int numero );
void ResiduoDivision(int Dividendo, int Divisor, int n );

int main(){
    int dividendo ;
    int divisor;
    int n;

    cout << "Ingrese el dividendo: ";
    cin >>  dividendo;
    cout << "Ingrese el divisor: ";
    cin >> divisor;
    cout << "Ingrese los decimales que desea: ";
    cin >> n;

    int aux=0;
    cout << "Resultado: "<< DivisionPorRestasSucesivas(&dividendo,divisor, aux)<< endl;
    cout << "Residuo: "<< dividendo << endl;
    cout << "decimal: " ; 
    ResiduoDivision(dividendo, divisor, n);
}

void ResiduoDivision(int Dividendo, int Divisor, int n ){
    int aux=0;
    for (int i = 0; i < n; i++)
    {
        if (Dividendo != 0)
        {
            Dividendo= MultiplicacionPorSuma(Dividendo);
            aux=0;
            cout << DivisionPorRestasSucesivas(&Dividendo,Divisor, aux);
        }
    }
}

int MultiplicacionPorSuma(int numero ){
    int aux=0;
    for (int i = 0; i < 10; i++)
    {
        aux=aux+numero;
    }
    return aux;
}


// Modifica el valor del Dividendo, el cual lo podre ocupar el main luego 
int DivisionPorRestasSucesivas(int *Dividendo, int Divisor, int i ){//Funcion Recursiva
    if (*Dividendo>=Divisor)
    {
        *Dividendo=*Dividendo-Divisor;
        return DivisionPorRestasSucesivas(Dividendo,Divisor, i+1);
    }
    return i;
}


/*
int DivisionPorRestasSucesivas(int Dividendo, int Divisor, int i ){//Funcion Recursiva
    if (Dividendo>=Divisor)
    {
        //Dividendo= Dividendo - Divisor;
        //i=i+1;
        //return DivisionPorRestasSucesivas(Dividendo,Divisor, i);
        return DivisionPorRestasSucesivas(Dividendo-Divisor,Divisor, i+1);
    }
    //cout << "i: "<<i; 
    return i;
}
*/
    /*
    while (dividendo>= divisor)
    {
        dividendo=  dividendo- divisor;
        aux=aux+1;
    }

    cout << "Aux: "<< aux ;
    */
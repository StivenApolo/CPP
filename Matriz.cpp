/*
Un supermercado cuenta con 5 cajeros que laboran seis días a la semana (de lunes a sábado).
De cada cajero se registra en una matriz el total de ventas que ha realizado en cada día.
Determinar:
a) Total de ventas de los 5 cajeros en cada día de la semana.
b) El día de la semana con menor venta en el supermercado.
c) Cajero con la mayor venta en la semana.
d) Día de la semana con menor venta para el cuarto cajero.
*/
#include <iostream>

using namespace std;

int main() {
    int ventas [5][6] ;
    int totalVentas[6];


    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 6; j++)
        {
            cout << "Ingrese las ventas del cajero " << i+1 << " en el dia " << j+1 << ": ";
            cin >> ventas[i][j];
        }
    }
    cout << "----------------------- "<<endl    ;
// a) Total de ventas de los 5 cajeros en cada día de la semana.
    for (int i = 0; i < 6; i++)
    {
        totalVentas[i] = 0;
        for (int j = 0; j < 5; j++)
        {
            totalVentas[i] += ventas[j][i];
        }
    }
// Impresion de los totales de ventas
    for (int i = 0; i < 6; i++)
    {
        cout << "Total de ventas en el dia " << i+1 << ": " << totalVentas[i] << endl;
    }
    cout << "----------------------- "<<endl    ;
// b) El día de la semana con menor venta en el supermercado.
    int menorVenta = totalVentas[0];
    int diaMenorVenta = 1;
    for (int i = 1; i < 6; i++)
    {
        if (totalVentas[i] < menorVenta)
        {
            menorVenta = totalVentas[i];
            diaMenorVenta = i+1;
        }
    }
    cout << "El dia de la semana con menor venta es el dia " << diaMenorVenta << " con " << menorVenta << " ventas." << endl; 
    cout << "----------------------- "<<endl    ;

// c) Cajero con la mayor venta en la semana.
    int mayorVenta = 0;
    int cajeroMayorVenta = 1;
    for (int i = 0; i < 5; i++)
    {
        int totalVentasCajero = 0;
        for (int j = 0; j < 6; j++)
        {
            totalVentasCajero += ventas[i][j];
        }
        if (totalVentasCajero > mayorVenta)
        {
            mayorVenta = totalVentasCajero;
            cajeroMayorVenta = i+1;
        }
    }
    cout << "El cajero con la mayor venta en la semana es el cajero " << cajeroMayorVenta << " con " << mayorVenta << " ventas." << endl;
    cout << "----------------------- "<<endl    ;

// d) Día de la semana con menor venta para el cuarto cajero.

    menorVenta = ventas[3][0];
    diaMenorVenta = 1;
    for (int i = 1; i < 6; i++)
    {
        if (ventas[3][i] < menorVenta)
        {
            menorVenta = ventas[3][i];
            diaMenorVenta = i+1;
        }
    }
    cout << "El dia de la semana con menor venta para el cuarto cajero es el dia " << diaMenorVenta << " con " << menorVenta << " ventas." << endl;
    cout << "----------------------- "<<endl    ;
}
    

#include <iostream>
using namespace std;
int main()
{
    int v[20];
for (int i=0; i<20; i++) //ingreso de valores al vector
{       
    cout << "Introduce los valores "<<i+1<<endl;
    cin >> v[i];
}
int buscar;
cout  << "Ingrese un dato a buscar: " ;
cin >>  buscar;
int aux=0;
for (int i = 0; i < 20; i++)
{
    if ( buscar== v[i])
    {
        cout  << "Valor encontrado, en la pocisicion: [" << i+1 << "]" ;
        aux=1;
    }
}
if ( aux!=1)
{
    cout << "Valor no encontrado " ;
}

}
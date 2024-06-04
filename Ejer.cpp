#include <iostream>

using namespace std;

int main() {
    int contador = 0;
    int n=6;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            for (int k = 1; k <= j; k++)
            {
                //cout << " i: "<< i << " j: "<< j << " k: "<< k << " " << endl; 
                contador++;
            }
            // cout << "----------------------- "<<endl    ;
        }
        // cout << "----------------------- "<<endl    ;
        //cout << endl    ;
    }
    cout << "Contador: "<<contador << endl;
}
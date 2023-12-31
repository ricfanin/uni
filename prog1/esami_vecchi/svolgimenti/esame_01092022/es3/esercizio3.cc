#include <iostream>
#include <string.h> // definisce la funzione "int strlen (const char * array);"
#include <math.h>   // definisce la funzione "int pow (base, esponente);"
#include "pila.h"   // fare riferimento al file "pila.h" per le funzioni esposte

using namespace std;

int decodificaNumero(char numeroCodificato []);

int main() { 
    int dimensioneMassima = 9;
    char numeroCodificato [dimensioneMassima];
    cout << "Inserisci l'array: ";
    cin >> numeroCodificato;
    int decodifica = decodificaNumero(numeroCodificato);
    cout << "Decodifica: " << decodifica << endl;
}

int decodificaNumero(char numeroCodificato []) {
    // Scrivere il codice qui
    init();
    int total = 0;
    int n = strlen(numeroCodificato);
    for (int i = 0; i <= strlen(numeroCodificato); i++)
    {
        push(i+1);
        if(i == n || numeroCodificato[i] == 'I')
        {
            while(!vuota())
            {
                int first;
                top(first);
                total += pow(10, n) * first;
                n--;
                pop();
            }

        }
    }

    deinit();
    return total;    
    // Potete assumere che l'array rispetti le assunzioni
    // dell'esercizio (non serve fare controlli sull'input)
}

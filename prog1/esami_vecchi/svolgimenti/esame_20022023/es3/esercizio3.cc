#include <iostream>
#include <cstdlib>
#include "coda.h"

using namespace std;

int trovaIlVincitore(int n, int k);

int main(int argc, char * argv[]) {

    if (argc != 3) {
        cerr << "Usage: a./out <numeroDiAmici> <numeroDiSalti>" << endl;
        exit(0);
    }

    cout << "Il vincitore e' l'amico numero " << trovaIlVincitore(atoi(argv[1]), atoi(argv[2])) << endl;
}


// Implementare la funzione sottostante come da consegna:
// - 'numeroDiAmici' è il numero di amici, o anche chiamato 'n'
// - 'numeroDiSalti' è il numero di salti, o anche chiamato 'k' 
int trovaIlVincitore(int numeroDiAmici, int numeroDiSalti) {
    init();
    int amici_vivi = numeroDiAmici;

    for (int i = 1; i <= numeroDiAmici; i++)
    {
        enqueue(i);
    }

    while(amici_vivi > 0)
    {
        print();
        cout << "--" << endl;
        for (int i = 0; i < numeroDiSalti ; i++)
        {
            int f;
            first(f);
            enqueue(f);
            dequeue();       
        }

        dequeue();
        amici_vivi--;
    }    

    int winner;
    first(winner);
    return winner;
}



// inserisci n amici
// scorri fino a k%n+1 e rimuovi il primo elemento ogni volta e lo aggiungi in fondo
// quando arrivi a k%n+1 rimuovi  e basta
// ricomincia
#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

// lettura file con nome da cli

int main(int argc, char* argv[])
{
    // controllo se sono stati inseriti i corretti parametri da riga di comando
    if(argc != 3) 
    {
        cout << "Usage: exercise1.out <input> <order>" << endl;
        return -1;
    }

    ifstream input, order;
    input.open(argv[1]);
    order.open(argv[2]);

    // Controllo che gli stream siano stati aperti correttamente
    if (input.fail() || order.fail()) {
        cout << "Errore nell'apertura degli stream!" << endl;
    }

    //inserisci codice qui
    char stringa[255];
    input >> stringa;
    int n_stringhe = atoi(stringa);
    char stringhe_input[n_stringhe][255];


    int counter = 0;
    while(input >> stringa)
    {
        strcpy(stringhe_input[counter], stringa);
        cout << stringhe_input[counter] << endl;
        counter++;
    }

    while(order >> stringa)
    {
        int index = atoi(stringa);
        if(index > 0 && index < n_stringhe)
        {
            cout << stringhe_input[index] << " ";
        }
        else
        {
            cout << "MISSING" << " ";
        }
    }
    cout << endl;

    // chiudo le stream dei file
    input.close();
}
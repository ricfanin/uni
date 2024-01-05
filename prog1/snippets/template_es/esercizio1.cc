#include <iostream>
#include <fstream>
using namespace std;

// lettura file con nome da cli

int main(int argc, char* argv[])
{
    // controllo se sono stati inseriti i corretti parametri da riga di comando
    if(argc != n_param) 
    {
        cout << "Usage: exercise1.out <input>" << endl;
        return -1;
    }

    fstream input;
    input.open(argv[1], ios::in);

    // Controllo che gli stream siano stati aperti correttamente
    if (input.fail()) {
        cout << "Errore nell'apertura degli stream!" << endl;
    }

    //inserisci codice qui


    // scorrimento file parola per parola
    char current_word[255];
    while(input >> current_word)
    {
        
    }

    // chiudo le stream dei file
    input.close();
}
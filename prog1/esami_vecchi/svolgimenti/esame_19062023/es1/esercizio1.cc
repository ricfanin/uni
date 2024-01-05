#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

char* shifting(char* word, int shift);

int main(int argc, char* argv[])
{
    // controllo se sono stati inseriti i corretti parametri da riga di comando
    if(argc != 2) 
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

    int shift = 0;
    char word_selected[255];
    cin >> shift; 
    cin >> word_selected;

    for (int i = 0; i < strlen(word_selected); i++)
    {
        word_selected[i] = tolower(word_selected[i]);
    }
    char* string_to_find = shifting(word_selected, shift);

    char current_word[255];
    int counter_occ = 0;
    while(input >> current_word)
    {
        int j = 0;
        for (int i = 0; i < strlen(current_word); i++)
        {   
            while(current_word[i] == string_to_find[j])
            {
                j++;
                i++;
            }
        }        

        if(j == strlen(string_to_find))
        {
            counter_occ++;
        }
    }

    cout << counter_occ << endl;
    // chiudo le stream dei file
    input.close();
}

char* shifting(char* word, int shift)
{
    int size = strlen(word) - 1;
    char last = word[0];

    if(shift == 0)
    {
        return word;
    }

    for (int i = strlen(word) - 1; i > 0; i--)
    {
        word[(i+shift)%strlen(word)] = word[i];
    }    
    word[1] = last;
    
    return word;
}


// abc -> cbc -> 
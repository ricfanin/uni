#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

char* cut_word(char word[]);
void shift_word(char word[], int shift, char* word_shifted);

int main(int argc, char* argv[])
{
    ifstream input;
    ofstream output;

    input.open(argv[1]);
    output.open(argv[2]);

    int shift = 0;
    while(shift == 0)
    {
        cout << "inserisci shift: " << endl;
        cin >> shift;
    }


    char current_word[255];
    while(input >> current_word)
    {
        char blabla[255] = {0};
        shift_word(current_word, shift, blabla);
        cout << blabla << " ";
    }


    return 0;
}

// char* cut(char word[])
// {
//     char word_cutted[255];

//     for (int i = 0; i < strlen(word); i++)
//     {
//         if(word[i] < 97 && word[i] > 122 && strlen(word_cutted) == 0)
//         {
//             continue;
//         }
//         else
//         {
//             cout << word;
//         }
//     }

//     return word_cutted;
// }


void shift_word(char word[], int shift, char* word_shifted)
{
    char alphabet[26] = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
    bool is_first_letter = false;
    for(int i = 0; i < strlen(word); i++)
    {
        if(find(alphabet, alphabet[25], tolower(word[i])))
        {
            word_shifted[i] = word[(i+shift)%strlen(word)];
        }
        //cout << word_shifted[i] << endl;
    }
}
// 1 - rimuovo coda e testa
// 2 - capisco come shiftare la parola --> (posizione lettera + shift)%lunghezza parola
// 3 - to lower case tutto 

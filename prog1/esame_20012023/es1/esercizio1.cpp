#include <iostream>
#include <fstream>
#include <cmath>
#include <cstring>

using namespace std;

int codifica(string parola)
{
    int parola_codificata = 0;

    for (int i = 0; i < parola.length(); i++)
    {
        if(parola[i] >= '0' && parola[i] <= '9')
        {
            parola_codificata += (parola[i] - 48) * pow(36, (parola.length() - 1) - i);
        }
        
        if(parola[i] >= 'a' && parola[i] <= 'z')
        {
            parola_codificata += ((parola[i] - 97) + 10) * pow(36, (parola.length() - 1) - i);
        }             
    }

    return parola_codificata;
}

string decodifica(int parola_codificata)
{
    //char carattere = (parola_codificata - (parola_codificata%36))/36;
    string parola_reversed;
    int resto = parola_codificata%36;
    while (resto > 0)
    {
        if (resto >= 0 && resto < 10)
        {
            parola_reversed += resto + 48;
            parola_codificata = (parola_codificata - (resto))/36;
            resto = parola_codificata%36;
        }
        
        if (resto >= 10 && resto <= 36)
        {
            parola_reversed += (resto - 10) + 97;
            parola_codificata = (parola_codificata - (resto))/36;
            resto = parola_codificata%36;
        }
    }
    

    string parola;
    for (int i = parola_reversed.length() - 1; i >= 0; i--)
    {
        parola += parola_reversed[i];
    }
    
    return parola;    
}

int main(int argc, char* argv[])
{
    ifstream input;
    ofstream output;

    input.open(argv[1]);
    output.open(argv[2]);

    char chiave[8] = "";

    while (strlen(chiave) > 7 || strlen(chiave) == 0)
    {
        cout << "Inserisci un numero massimo fino a 7 come chiave di criptazione: " << endl;
        cin >> chiave;
    }   

    int offset = atoi(chiave);
    string buffer;

    while (input >> buffer)
    {
        
        buffer[4] = '\0';
        cout << buffer << endl;

        int buffer_encoded = codifica(buffer) + offset;

        cout << "Codifica: " << buffer_encoded << endl;

        string buffer_decoded = decodifica(buffer_encoded);

        cout << "decodifica: " << buffer_decoded << endl;        

        output << buffer_decoded << " ";
    }


}



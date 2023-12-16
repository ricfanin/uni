#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

int main(int argc, char* argv[])
{
    ifstream input;
    input.open(argv[1]);

    char* parola_scelta = argv[2];

    char parola_corrente[31];
    while(input >> parola_corrente)
    {
        char* is_contenuta = strstr(parola_corrente, parola_scelta);
        if (is_contenuta != NULL)
        {
            cout << "parola trovata" << endl;
            return 0;
        }
        
    }

    cout << "parola non trovata" << endl;
    return 0;
}
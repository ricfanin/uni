#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

int main(int argc, char* argv[])
{
    ifstream input;
    input.open(argv[1]);

    char char_to_find[255];
    cout << "inserisci caratteri da cercare" << endl;
    cin.getline(char_to_find, sizeof(char_to_find));

    char current_char;

    while(input.get(current_char))
    {
        for (int i = 0; i < strlen(char_to_find); i++)
        {
            if(tolower(current_char) == tolower(char_to_find[i]))
            {
                cout << current_char;
            }
        }        
        
    }

    return 0;
}
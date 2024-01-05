#include <iostream>
#include <fstream>
using namespace std;

// lettura file con nome da cli

int main(int argc, char* argv[])
{
    // controllo se sono stati inseriti i corretti parametri da riga di comando
    if(argc != 3) 
    {
        cout << "Usage: exercise1.out <input> <output>" << endl;
        return -1;
    }

    fstream input, output;
    input.open(argv[1]);
    output.open(argv[2]);

    // Controllo che gli stream siano stati aperti correttamente
    if (input.fail() || output.fail()) {
        cout << "Errore nell'apertura degli stream!" << endl;
        return -1;
    }



    // scorrimento file parola per parola
    char longest_line[255];
    char current_line[255];
    int lenght = 0;


    while(input.getline(current_line, sizeof(current_line)))
    {
        int i = 0;
        while(current_line[i] != '\0')
        {
            i++;
        }

        if(i > lenght)
        {
            for (int j = 0; j < i; j++)
            {
                longest_line[j] = current_line[j];
            }
            
            lenght = i;            
        }
    
        output << i << endl;    
          
    }
   
    output << longest_line;  
    
    // chiudo le stream dei file
    input.close();
    output.close();
}
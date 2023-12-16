#include <iostream>
#include <fstream>

using namespace std;

int main(int argc, char* argv[])
{
    ifstream input;
    input.open(argv[1]);

    string parola;
    int counter = 0;

    while(counter <= 4)
    {
        while(input >> parola)
        {
            if(parola.length() == 4)
            {
                if(stoi(parola) <= 9999)
                {
                    cout << parola << endl;
                    counter++;
                }
            }
        }
    }
     
    cout << "Le stringe trovate sono: " <<  counter/4 << endl;
}
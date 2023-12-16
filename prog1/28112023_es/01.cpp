#include <iostream>
#include "pila.h"
#include <fstream>
#include <cstring>
using namespace std;

int main()
{
    ifstream input("interi.txt");
    ofstream output("output.txt");
    if(!input.is_open()) return 1;

    char line[16];
    pila_init();

    while(!input.eof() && !input.fail())
    {
        input.getline(line, '\n');
        int number = atoi(line);
        pila_push(number);
    }
    
    pila_print();

    int tmp;
    while(pila_top(tmp))
    {   
        output << tmp << endl;
        pila_pop();
    }
    
    input.close();

    return 0;
}
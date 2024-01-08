// Creare un programma che

#include <iostream>
#include <string>
#include <cmath>

using namespace std;

// Inizio dichiarazione delle funzioni
int binToDec(string n, int base);

// Fine dichiarazione delle funzioni

int main(int argc, char *argv[])
{

    // Controlli

    // Fine Controlli

    string num1 = "ADC";
    string num2 = "1010";
    string num3 = "A54";
    string num4 = "AFZ19";

    // Richiamo funzioni
    cout << "Numero in binario: " << num1 << " -- Numero in Decimale: " << formAnyBaseToDec(num1, 16) << endl;
    cout << "Numero in binario: " << num2 << " -- Numero in Decimale: " << formAnyBaseToDec(num2, 2) << endl;
    cout << "Numero in binario: " << num3 << " -- Numero in Decimale: " << formAnyBaseToDec(num3, 16) << endl;
    cout << "Numero in binario: " << num4 << " -- Numero in Decimale: " << formAnyBaseToDec(num4, 36) << endl;

    return 0;
}

// Inizio implementazione delle funzioni
int formAnyBaseToDec(string n, int base)
{

    int nDec = 0;
    int tmp = 0;
    char * arrBase = new char[base];
    int * arrConversione = new int[base];

    for (int i = 0; i < base; i++)
    {
        arrConversione[i] = i;
        if (i < 10)
        {
            arrBase[i] = '0' + i;
        }
        else
        {
            tmp = i - 10;
            arrBase[i] = 'A' + tmp;
        }
    }

    for (int i = 0; i < n.length(); i++)
    {
        for (int j = 0; j < base; j++)
        {
            if (n[i] == arrBase[j])
            {
                tmp = arrConversione[j] * pow(base, n.length()-i-1);

                // cout << arrConversione[j] << " - ";
                // cout << arrBase[j] << " - ";
                // cout << tmp << endl;
                nDec += tmp;
            }
        }
    }

    delete[] arrBase;
    delete[] arrConversione;
    return nDec;
}
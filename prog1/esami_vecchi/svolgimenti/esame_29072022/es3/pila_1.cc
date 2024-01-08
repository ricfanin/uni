#include "pila_1.h"
#include <iostream>

using namespace std;

static int len;
static int* pila;
static int index_P1;
static int index_P2;

// inizializza P1 e P2 con un'array o una lista 
// doppiamente concatenata con dimensione massima 
// 'dim'. Di conseguenza, la somma del numero di 
// elementi in P1 e P2 può essere al massimo uguale 
// a 'dim';
void init(int dim)
{
    pila = new int[dim];
    len = dim;
    index_P2 = dim;
    index_P1 = -1;
}

// inserisci l'elemento 'valore' in P1
bool pushP1(int valore)
{
    if(index_P1 + 1  != index_P2)
    {
        index_P1++;
        pila[index_P1] = valore;
        return true;
    }
    else
    {
        cout << "memoria condivisa full" << endl;
        return false;
    }
}

// inserisci l'elemento 'valore' in P2
bool pushP2(int valore)
{
    if(index_P2 - 1 != index_P1)
    {
        index_P2--;
        pila[index_P2] = valore;
        return true;
    }
    else
    {
        cout << "memoria condivisa full" << endl;
        return false;
    }
}

// assegna al parametro il valore del primo 
// elemento di P1, se presente
bool topP1(int& top)
{
    if(pila[index_P1] != 0)
    {
        top = pila[index_P1];
        return true;
    }
    else return false;
}

// assegna al parametro il valore del primo 
// elemento di P2, se presente
bool topP2(int& top)
{
    if(pila[index_P2] != 0)
    {
        top = pila[index_P2];
        return true;
    }
    else return false;
}

// rimuovi il primo elemento di P1, se presente
bool popP1()
{
    if(pila[index_P1] != 0)
    {   
        index_P1--;
        return true;
    }
    else
    {
        return false;
    }
}

// rimuovi il primo elemento di P2, se presente
bool popP2()
{
    if(pila[index_P2] != 0)
    {   
        index_P2++;
        return true;
    }
    else
    {
        return false;
    }    
}

// de-inizializza la pila e dealloca la memoria dinamica
void deinit()
{
    delete pila;
}

// stampa a video gli elementi di P1 e P2
void print()
{
    cout << "P1: ";
    for (int i = 0; i <= index_P1; i++)
    {
        cout << pila[i] << " ";
    }

    cout << "P2: ";
    for (int i = len - 1; i >= index_P2; i--)
    {
        cout << pila[i] << " ";
    }
    

    cout << endl;
}
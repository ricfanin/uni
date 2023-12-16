//Scrivere un programma che, dato in input un file con un intero per 
//riga, crea una lista concatenata con i numeri contenuti nel file

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cstring>

using namespace std;

struct nodo;
typedef nodo* list;


struct nodo{
    int val;
    list nextNode;
};

void print_list(list node)
{
    while(node != nullptr)
    {
        cout << node->val << endl;
        node = node->nextNode;
    }
}

void delete_list(list node)
{
    while(node != nullptr)
    {
        list tmp = node;
        node = node->nextNode;
        delete tmp;
    }
}

void print_reversed_list(list curr)
{
    list next;
    list prev;
    while(curr != nullptr)
    {     
        next = curr->nextNode;
        curr->nextNode = prev;
        prev = curr;
        curr = next;
    }

    print_list(prev);
}

bool check_if_prime(int n)
{
    if(n <= 1)
    {
        return false;
    }

    for(int i = 2; i <= n/2; i++)
    {
        if(n % i == 0)
        {
            return false;
        }
    }

    return true;
}

int main()
{
    ifstream inputFile("testo.txt");
    if (!inputFile.is_open())
    {
        return 1;
    }

    list head = new nodo;
    list currentNode = new nodo;

    char line[2];
    while (!inputFile.eof() && !inputFile.fail()){
        if(head->nextNode == nullptr)
        {
            inputFile.getline(line, '\n');
            if(check_if_prime(atoi(line))){
                head->val = atoi(line);
                head->nextNode = currentNode;    
            }
        }
        else
        {
            inputFile.getline(line, '\n');
            if(check_if_prime(atoi(line))){
                currentNode->val = atoi(line);
                currentNode->nextNode = new nodo;
                currentNode = currentNode->nextNode; 
            }
            
        }
    }    

    inputFile.close();

    //delete_list(head);
    
    print_reversed_list(head);

    return 0;
}
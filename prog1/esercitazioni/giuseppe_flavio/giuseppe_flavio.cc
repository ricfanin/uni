//#include "lista_circolare.h"
#include <iostream>

using namespace std;

struct nodo{
    int val;
    nodo* next;
};

nodo* head;
nodo* tail;

void circolare_init()
{
    head = NULL;
}

void circolare_deinit()
{
    while(head != tail)
    {
        nodo* tmp = head;
        head = head->next;
        delete tmp;        
    }

    delete head;
}

void circolare_add_end(int value)
{
    if(head == NULL)
    {
        head = new nodo;
        head->val = value;
        head->next = head;
        tail = head;
    }
    else
    {
        nodo* tmp = new nodo;
        tmp->val = value;
        tmp->next = head;
        tail->next = tmp;
        tail = tmp;
    }
}

void circolare_add_start(int value)
{
    if(head == NULL)
    {
        head = new nodo;
        head->val = value;
        head->next = head;
        tail = head;
    }
    else
    {
        nodo* tmp = new nodo;
        tmp->val = value;
        tmp->next = head;
        tail->next = tmp;
        head = tmp;
    }
}

void circolare_remove(int index)
{   
    nodo* tmp = head;
    for(int i = 0; i < index; i++)
    {
        tmp = tmp->next;
    }

    nodo* nodo_rimuovere = tmp->next;
    tmp->next = nodo_rimuovere->next;
    delete(nodo_rimuovere);
}

void circolare_remove_last()
{   
    nodo* nodo_rimuovere = tail;
    nodo* tmp = head;
    while(tmp->next != tail)
    {
        tmp = tmp->next;
    }
    delete(nodo_rimuovere);
    tail = tmp;
}

void circolare_print()
{
    nodo* tmp = head;
    while (tmp != tail)
    {
        cout << tmp->val << " ";
        tmp = tmp->next;
    }
    
    cout << tmp->val << endl;
}

void circolare_remove_node(nodo* remove)
{
    nodo* tmp = head;
    while(tmp->next != remove)
    {
        tmp = tmp->next;
    }
    
    nodo* rimozione = tmp->next;
    tmp->next = rimozione->next;
    delete rimozione;
}


//////////////////////////////////////////////////

int trova(int n_persone, int salti)
{
    circolare_init();
    int persone_rimaste = n_persone;
    int leader;

    for (int i = 1; i <= n_persone; i++)
    {
        circolare_add_end(i);
    }
    

    nodo* current_node = head;
    while(persone_rimaste > 0)
    {         
        leader = current_node->val;
        cout << current_node->val << endl;
        cout << "---------" << endl;   
        for (int i = 0; i < salti; i++)
        {
            current_node = current_node->next;
        }


        // rimuovere current node
        cout << current_node->val << endl;
        nodo* tmp = current_node->next;
        circolare_remove_node(current_node);
        current_node = tmp;
        persone_rimaste--;


    
    }

    //cout << "SUCA" << *current_node->val << endl;


    //circolare_deinit();
    return leader;
}

int main(int argc, char* argv[])
{
    if(argc < 3)
    {
        cout << "inserire due parametri dopo ./a.out" << endl;
    }

    int n_persone = atoi(argv[1]);
    int salti = atoi(argv[2]);

    cout << "Leader: " << trova(n_persone, salti) << endl; 

    return 0;
}
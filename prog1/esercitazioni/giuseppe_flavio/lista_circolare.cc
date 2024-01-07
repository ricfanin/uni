#include "lista_circolare.h"
#include <iostream>

using namespace std;

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








#ifndef CIRCOLARE_H
#define CIRCOLARE_H

struct nodo{
    int val;
    nodo* next;
};

void circolare_add_end(int);
void circolare_add_start(int);

void circolare_remove();

void circolare_print();


void circolare_init();
void circolare_deinit();

#endif
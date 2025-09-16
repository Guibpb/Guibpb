/**
*   Nome:Guilherme Borges de Pádua Barbosa
*   Nº USP: 15653045
*/

#include <string>
#include "pessoa.h"
using namespace std;

#ifndef LISTA_H
#define LISTA_H

typedef Pessoa ListEntry;

class List{ 
public:
    List();
    ~List();
    void insert(int p, ListEntry x);
    void remove(int p, ListEntry &x);
    void retrieve(int p, ListEntry &x);
    bool empty();
    bool full();
    void clear();
    int size();
    int search(long int x);
    void print();

private:
    struct ListNode; 
    typedef ListNode * ListPointer;
    struct ListNode{ 
        ListEntry entry; 
        ListPointer nextNode;
    };

    ListPointer head;
    int count;
    void setPosition(int p, ListPointer &current);
};

#endif
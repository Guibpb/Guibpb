#include <iostream>
#include "lista_ordenada.h"

using namespace std;

OrderedList::OrderedList(){
    sentinel = new ListNode;
    head = sentinel;
    count = 0;
}

OrderedList::~OrderedList(){
    clear();
    delete sentinel;
}

bool OrderedList::empty(){
    return (head == sentinel);
}

bool OrderedList::full(){
    return false;
}

void OrderedList::insert(ListEntry x){ 
    ListPointer p, q;
    sentinel->entry = x;
    p = head;
    while(p->entry.expoente > x.expoente)
        p = p->nextNode;

    q = new ListNode;
    if(q == NULL){ 
        cout << "Memória insuficiente";
        abort();
    }

    if(p == sentinel){
        p->nextNode = q;
        sentinel = q;
    }
    else{ 
        *q = *p;
        p->entry = x;
        p->nextNode = q;
    }
    count++;
}

void OrderedList::clear()
{ 
    ListPointer q;

    while (head != sentinel){ 
        q = head;
        head = head->nextNode;
        delete q;
    }
    count = 0;
}

ListEntry OrderedList::getHead(){
    return head->entry;
}

void OrderedList::print(){
    ListPointer q, _head, _sentinel;
    _head = head;
    _sentinel = sentinel;

    while(_head != _sentinel){
        q = _head;
        _head = _head ->nextNode;
        ListEntry entry = q->entry;

        cout << entry.coeficiente << "*x^" << entry.expoente << " + ";
    }
}

OrderedList OrderedList::sum(OrderedList b, int indice){
    OrderedList sum;
    ListPointer p, q;
    ListEntry entryP, entryQ;
    int _sum;

    while(head != sentinel && b.head != b.sentinel){
        p = head;
        entryP = p->entry;
        q = b.head;
        entryQ = q->entry;


        if(entryP.expoente == entryQ.expoente){
            _sum = entryP.coeficiente + indice*entryQ.coeficiente;
            ListEntry tempEntry;
            tempEntry.expoente = entryP.expoente;
            tempEntry.coeficiente = _sum;
            sum.insert(tempEntry);
            head = head->nextNode;
            b.head = b.head->nextNode;
        }

        if(entryP.expoente > entryQ.expoente)
            head = head->nextNode;
        else
            b.head = b.head->nextNode;
    }
    
    return sum;
}
    
/**
*   Nome:Guilherme Borges de Pádua Barbosa
*   Nº USP: 15653045
*/

#include <iostream>
#include "lista.h"
using namespace std;

List::List(){
    head = NULL;
    count = 0;
}

List::~List(){
    clear();
}

bool List::empty(){
    return (head == NULL);
}

bool List::full(){
    return false;
}

void List::setPosition(int p, ListPointer &current){
    int i;
    current = head;
    for(i = 2; i <= p; i++)
        current = current->nextNode;
}

void List::insert(int p, ListEntry x){ 
    ListPointer newNode, current;

    if (p < 1 || p > count+1){ 
        cout << "Posição Inválida.";
        abort();
    }

    newNode = new ListNode;
    newNode->entry = x;

    if(p == 1){ 
        newNode->nextNode = head;
        head = newNode;
    }
    else{ 
        setPosition(p-1,current);
        newNode->nextNode = current->nextNode;
        current->nextNode = newNode;
    }

    count++;
}

void List::remove(int p, ListEntry &x){ 
    ListPointer node, current;
    if (p < 1 || p > count){ 
        cout << "Posição inválida";
        abort();
    }
    
    if(p == 1){ 
        node = head;
        head = node->nextNode;
    }
    else{ 
        setPosition(p-1,current);
        node = current->nextNode;
        current->nextNode = node->nextNode;
    }

    x = node->entry;
    delete node;
    count--;
}

void List::retrieve(int p, ListEntry &x){
    ListPointer q;

    if(p < 1 || p > count)
        abort();

    setPosition(p,q);
    x = q->entry;
}

void List::clear(){
    ListPointer q;
    while (head != NULL){ 
        q = head;
        head = head->nextNode;
        delete q;
    }
}

int List::size(){
    return count;
}

int List::search(long int x){
    int p = 1;
    ListPointer q = head;

    while(q != NULL && q->entry.matricula != x){
        q = q->nextNode;
        p++;
    }

    return (q == NULL ? 0 : p);
}   

void List::print(){
    ListPointer q = head;
    cout << "[Nome: " << q->entry.nome << " - Idade: " << q->entry.idade << " - Matrícula: " << q->entry.matricula;
    q = q->nextNode;

    while(q != NULL){
        cout << ", Nome: " << q->entry.nome << " - Idade: " << q->entry.idade << " - Matrícula: " << q->entry.matricula;
        q = q->nextNode;
    }

    cout << "]." << endl;
}

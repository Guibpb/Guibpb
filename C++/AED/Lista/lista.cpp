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

void List::insert(int p, int x){ 
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

void List::remove(int p, int &x){ 
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


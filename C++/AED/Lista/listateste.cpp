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

void List::clear(){
    ListPointer q;

    while(head != NULL){
        q = head;
        head = head->nextNode;
        delete q;
    }
}

void List::setPosition(int p, ListPointer &current){
    current = head;
    for(int i = 2; i < p; i++){
        current = current->nextNode;
    }
}

void List::insert(int p, ListEntry x){
    ListPointer newNode, current;
    newNode = new ListNode;

    if(p < 1 || p > count -1){
        cout << "Posição Inválida" << endl;
        abort();
    }

    newNode->entry = x;

    if(p == 1){
        newNode->nextNode = head;
        head = newNode;
    }
    else{
        setPosition(p, current);
        newNode->nextNode = current->nextNode;
        current->nextNode = newNode;
    }

    count++;
}

void List::remove(int p, ListEntry &x){
    ListPointer node, current;
    node = new ListNode;

    if(p < 1 || p > count - 1){
        cout << "Posição Inválida" << endl;
        abort();
    }

    if(p == 1){
        node = head;
        head = head->nextNode;
    }
    else{
        setPosition(p, current);
        node = current->nextNode;
        current->nextNode = node->nextNode;
    }
    x = node->entry;
    delete node;
    count--;
}
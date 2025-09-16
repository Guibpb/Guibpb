#include <iostream>
#include "lista_dup.h"
using namespace std;

List::List(){
    head = tail = NULL;
    count = 0;
}

List::~List(){ 
    ListPointer q;
    while (head != NULL){ 
        q = head;
        head = head->nextNode;
        delete q;
    }
}

void List::insertStart(ListEntry x){
    ListPointer newNode = new ListNode;
    newNode->entry = x;
    newNode->prevNode = nullptr;
    newNode->nextNode = head;

    if (head != nullptr) {
        head->prevNode = newNode;
    } else {
        tail = newNode;
    }

    head = newNode;
    count++;
}


void List::insertEnd(ListEntry x){
    ListPointer newNode = new ListNode;
    newNode->entry = x;
    newNode->nextNode = nullptr;
    newNode->prevNode = tail;

    if (tail != nullptr) {
        tail->nextNode = newNode;
    } else {
        head = newNode;
    }

    tail = newNode;
    count++;
}

bool List::empty(){
    return count == 0;
}

void List::print(){
    ListPointer q;
    q = head;

    cout << "Lista na ordem direta: " << endl;
    while(q != NULL){
        cout << q->entry << " ";
        q = q->nextNode;
    }
    cout << "\n\n";

    q = tail;

    cout << "Lista na ordem inversa: " << endl;
    while(q != NULL){
        cout << q->entry << " ";
        q = q->prevNode;
    }
    cout << "\n\n";
}


#include <iostream>
#include "fila.h"
using namespace std;

Queue::Queue(){
    tail = head = NULL;
    count = 0;
}

Queue::~Queue(){
    QueuePointer p;

    while(head != NULL){
        p = head;
        head = head->nextNode;
        delete p;
    }
}

void Queue::append(QueueEntry x){
    QueuePointer p;
    p = new QueueNode;
    if(p == NULL){
        abort();
    }
    count++;

    p->entry = x;
    if(empty())
        head = tail = p;
    else{
        tail->nextNode = p;
        tail = p;
    }

    p->nextNode = NULL;
}

void Queue::serve(QueueEntry &x){
    if(empty())
        abort();

    count--;

    x = head->entry;

    QueuePointer p;
    p = head;
    head = head->nextNode;
    delete p;

    if(head == NULL)
        tail = NULL;
}

bool Queue::empty(){
    return (head == NULL);
}

bool Queue::full(){
    return false;
}

void Queue::clear(){
    QueueEntry x;

    while(!empty()){
        serve(x);
    }
}

int Queue::size(){
    return count;
}

void Queue::getFront(QueueEntry &x){
    if(empty()){
        abort();
    }
    x = head->entry;
}

void Queue::getRear(QueueEntry &x){
    if(empty()){
        abort();
    }

    x = tail->entry;
}

void Queue::print(){
    if(empty()){
        cout << "Vazia" << endl;
        abort();
    }

    int _count = count;
    QueueEntry temp;

    cout << "Fila: ";
    for(int i = 0; i < _count; i++){
        serve(temp);
        cout << temp << " ";
        append(temp);
    }
    cout << endl;
}
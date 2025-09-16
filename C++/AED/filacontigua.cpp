#include <iostream>
#include "filacontigua.h"
using namespace std;

Queue::Queue(){
    count = 0;
    head = 1;
    tail = MaxQueue;
}

Queue::~Queue(){
    clear();
}

void Queue::append(QueueEntry x){
    if(full()){
        abort();
    }

    count++;
    tail = (tail%MaxQueue) + 1;
    entry[tail] = x;
}

void Queue::serve(QueueEntry &x){
    if(empty())
        abort();

    count--;
    x = entry[head];
    head = (head % MaxQueue) + 1;
}

bool Queue::empty(){
    return (count == 0);
}

bool Queue::full(){
    return (count == MaxQueue);
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
    if(empty())
        abort();

    x = entry[head];
}

void Queue::getRear(QueueEntry &x){
    if(empty())
        abort();

    x = entry[tail];
}

void Queue::print(){
    if(empty()){
        cout << "Dia Vazio" << endl;
        abort();
    }

    cout << "Nome das pessoas cadastradas em tal slot: " << endl;
    QueueEntry x;
    for(int i = 0; i < count; i++){
        serve(x);
        append(x);
        cout << x.nome << endl;
    }
}
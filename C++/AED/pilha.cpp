//Nome: Guilherme Borges de Pádua Barbosa
//Nº USP: 15653045

#include <iostream>
#include "pilha.h"
using namespace std;

Stack::Stack(){
    top = NULL;
    count = 0;
}

Stack::~Stack(){
    clear();
}

bool Stack::empty(){
    return (top == NULL);
}

void Stack::isEmpty(){
    if(empty()){
        cout << "Pilha Vazia" << endl;
        abort();
    }
}

bool Stack::full(){
    return false;
}

void Stack::push(StackEntry x){
    StackPointer p;
    count++;

    p = new StackNode;
    if(p == NULL){
        cout << "Memória Insuficiente" << endl;
        abort();
    }

    p->entry = x;
    p->nextNode = top;
    top = p;
}

void Stack::pop(StackEntry &x){
    isEmpty();
    count--;
    x = top->entry;

    StackPointer p;
    p = top;
    top = top->nextNode;
    delete p;
}

void Stack::clear(){
    StackEntry temp;

    while(!empty()){
        pop(temp);
    }

    count = 0;
}

int Stack::size(){
    return count;
}

void Stack::getTop(StackEntry &x){
    isEmpty();

    pop(x);
    push(x);
}

void Stack::print(){
    isEmpty();

    int _count = count;
    StackEntry temp[_count];

    cout << "Pilha: ";
    
    for(int i = 0; i < _count; i++){
        pop(temp[i]);
        cout << temp[i] << " ";
    }
    
    for(int i = _count; i > 0; i--){
        push(temp[i-1]);
    }

    cout << endl;
}

void Stack::get(StackEntry &x, int n){
    isEmpty();
    int _count = count;
    StackEntry temp[_count];

    for(int i = 0; i < n; i++){
        pop(temp[i]);
    }

    for(int i = n; i > 0; i--){
        push(temp[i-1]);
    }

    x = temp[n-1];
}

void Stack::change(StackEntry x, int n){
    isEmpty();
    int _count = count;
    StackEntry temp[_count];

    for(int i = 0; i < n; i++){
        pop(temp[i]);
    }

    temp[n-1] = x;

    for(int i = n; i > 0; i--){
        push(temp[i-1]);
    }
}

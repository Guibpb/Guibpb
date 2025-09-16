#include <iostream>
#include "lista.h"

List L;

class Pilha{
public:
    void push(ListEntry x){
        L.insert(1,x);
    }
    void pop(ListEntry &x){
        L.remove(1,x);
    }
};

class Fila{
public:
    void append(ListEntry x){
        L.insert(1,x);    
    }
    void serve(ListEntry &x){
        L.remove(L.size()-1, x);
    } 
};
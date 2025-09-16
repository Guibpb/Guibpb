//Nome: Guilherme Borges de Pádua Barbosa
//Nº USP: 15653045

using namespace std;

#ifndef PILHA_H
#define PILHA_H

typedef char StackEntry;

class Stack {
public:
    Stack();
    ~Stack();
    void push(StackEntry x);
    void pop(StackEntry &x);
    bool empty();
    bool full();
    void clear();
    int size();
    void getTop(StackEntry &x);
    void print();
    void isEmpty();
    void get(StackEntry &x, int n);
    void change(StackEntry x, int n);

private:
    struct StackNode;

    typedef StackNode (* StackPointer);

    struct StackNode{
        StackEntry entry;
        StackPointer nextNode;
    };

    StackPointer top;

    int count;
};

#endif
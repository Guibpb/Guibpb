#include <iostream>
#include "pilha.h"
#include "fila.h"
using namespace std;

void stackToQueue(Stack &S, Queue &Q){
    StackEntry temp;

    while(!S.empty()){
        S.pop(temp);
        Q.append(temp);
    }
}

void queueToStack(Stack &S, Queue &Q){
    QueueEntry temp;

    while(!Q.empty()){
        Q.serve(temp);
        S.push(temp);
    }
}

void StackToStackInverse(Stack &S1, Stack &S2){
    StackEntry temp;

    while(!S1.empty()){
        S1.pop(temp);
        S2.push(temp);
    }
}

void StackToStack(Stack &S1, Stack &S2){
    Stack tempS;
    StackEntry temp;

    while(!S1.empty()){
        S1.pop(temp);
        tempS.push(temp);
    }

    while(!tempS.empty()){
        tempS.pop(temp);
        S2.push(temp);
    }
}

int main(){
    Stack S, S2;
    Queue Q;
    S.push('a');
    S.push('b');
    S.push('c');
    S.push('d');
    S.print();
    StackToStackInverse(S,S2);
    S2.print();
    StackToStack(S2,S);
    S.print();
    return 0;
}
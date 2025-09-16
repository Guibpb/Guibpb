using namespace std;
#include <string>

#ifndef FILA_H
#define FILA_H

struct Pessoa {
    string nome;
    string endereço;
    string cpf;
    unsigned int idade;
};

typedef Pessoa QueueEntry;

class Queue{
public:
    Queue();
    ~Queue();
    bool empty();
    bool full();
    void append(QueueEntry x);
    void serve(QueueEntry &x);
    void print();
    void clear();
    int size();
    void getFront(QueueEntry &x);
    void getRear(QueueEntry &x);

private:
    static const int MaxQueue = 100;
    int head;
    int tail;
    int count;
    QueueEntry entry[MaxQueue + 1];
};

#endif
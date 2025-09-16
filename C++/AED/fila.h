using namespace std;

#ifndef FILA_H
#define FILA_H

typedef char QueueEntry;

class Queue{
public:
    Queue();
    ~Queue();
    bool empty();
    bool full();
    void append(QueueEntry x);
    void serve(QueueEntry &x);
    void clear();
    int size();
    void getFront(QueueEntry &x);
    void getRear(QueueEntry &x);
    void print();

private:
    struct QueueNode;
    typedef QueueNode (* QueuePointer);

    struct QueueNode{
        QueueEntry entry;
        QueuePointer nextNode;
    };

    QueuePointer head, tail;
    int count;
};

#endif
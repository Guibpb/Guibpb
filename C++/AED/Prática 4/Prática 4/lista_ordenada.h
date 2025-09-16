using namespace std;

#ifndef LISTA_ORDENADA_H
#define LISTA_ORDENADA_H

struct Nó{
    int coeficiente;
    int expoente;
};

typedef Nó ListEntry;

class OrderedList{
public:
    OrderedList();
    ~OrderedList();
    void insert(ListEntry x);
    bool empty();
    bool full();
    void clear();
    ListEntry getHead();
    void print();
    OrderedList sum(OrderedList b, int indice);
private:
    struct ListNode; 
    typedef ListNode * ListPointer;
    struct ListNode{
        ListEntry entry; 
        ListPointer nextNode; 
    };

    ListPointer head, sentinel;
    int count;
}; 

#endif
using namespace std;

#ifndef LISTA_DUP_H
#define LISTA_DUP_H

typedef int ListEntry;

class List{ 
public:
    List();
    ~List();
    void insertStart(ListEntry x);
    void insertEnd(ListEntry x);
    void print();
    bool empty();

private:   
    struct ListNode; 
    typedef ListNode * ListPointer;

    struct ListNode{ 
        ListEntry entry; 
        ListPointer nextNode, prevNode;
    };
    
    ListPointer head, tail; 
    int count; 
};


#endif
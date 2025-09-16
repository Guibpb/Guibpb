#ifndef LISTA_H
#define LISTA_H

typedef int ListEntry;

class List{ 
public:
    List();
    ~List();
    void insert(int p, int x);
    void remove(int p, int &x);
    bool empty();
    bool full();
    void clear();
    int size();
private:
    struct ListNode; 
    typedef ListNode * ListPointer;
    struct ListNode{ 
        ListEntry entry; 
        ListPointer nextNode;
    };

    ListPointer head;
    int count;
    void setPosition(int p, ListPointer &current);
};

#endif
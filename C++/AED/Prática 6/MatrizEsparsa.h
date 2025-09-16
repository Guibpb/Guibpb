//Nome: Guilherme Borges de Pádua Barbosa
//Nº USP: 15653045

#ifndef MATRIZESPARSA_H
#define MATRIZESPARSA_H

typedef int ListEntry;

class Matrix{
public:
    Matrix();
    ~Matrix();
    void insert(int c, int r, ListEntry x);
    void print();
    bool full();
    bool empty();
    void clear();

private:
    struct ListNode;
    typedef ListNode * ListPointer;

    struct ListNode{
        ListEntry entry;
        int rValue, cValue;
        ListPointer rNext, cNext;
    };

    ListPointer R[10], C[10];
};

#endif
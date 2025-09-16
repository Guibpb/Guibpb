/**
*   Nome:Guilherme Borges de Pádua Barbosa
*   Nº USP: 15653045
*/
#include <string>
#include "pessoa.h"
using namespace std;

#ifndef AVL_H
#define AVL_H

typedef Pessoa TreeEntry;

class AVLTree {
public:
    AVLTree();
    ~AVLTree();
    void searchInsert(TreeEntry x);
    bool remove(TreeEntry x);
    bool search(TreeEntry x);
    void clear();
    void print();

private:
    struct TreeNode;
    typedef TreeNode * TreePointer;

    struct TreeNode{
        TreeEntry entry;
        int count;
        int bal;
        TreePointer leftNode, rightNode;
    };

    TreePointer root;

    void clear(TreePointer &t);
    void searchInsert(TreeEntry x, TreePointer &pA, bool &h);
    bool remove(TreeEntry x, TreePointer &p, bool &h);
    void removeMin(TreePointer &q, TreePointer &r, bool &h);
    void balanceR(TreePointer &pA, bool &h);
    void balanceL(TreePointer &pA, bool &h);
    void print(TreePointer &t, int s);
    bool rSearch(TreeEntry x, TreePointer &t); 
};


#endif

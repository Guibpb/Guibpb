/**
*Nome:Guilherme Borges de Pádua Barbosa
*Nº USP: 15653045
*/

#ifndef ARVOREALEATORIA_H
#define ARVOREALEATORIA_H

typedef int TreeEntry;

class BinaryTree{
public:
    BinaryTree();
    ~BinaryTree();
    bool empty();
    bool full();
    void clear();
    void preOrder();
    void postOrder();
    void inOrder();
    int height();
    void print();
    void insert(TreeEntry x);

private:
    struct TreeNode;
    typedef TreeNode *TreePointer;

    struct TreeNode{
        TreeEntry entry;
        TreePointer leftNode, rightNode;
    };

    TreePointer root;
    void clear(TreePointer &t);
    void preOrder(TreePointer &t);
    void postOrder(TreePointer &t);
    void inOrder(TreePointer &t);
    void process(TreeEntry x);
    int height(TreePointer &t);
    void insert(TreeEntry x, TreePointer &t);
    void print(TreePointer &t, int s);
};

#endif
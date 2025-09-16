/**
*Nome:Guilherme Borges de Pádua Barbosa
*Nº USP: 15653045
*/

#include <iostream>
#include <cstdlib>
#include <iomanip>
#include "ArvoreAleatoria.h"
using namespace std;

BinaryTree::BinaryTree(){
    root = NULL;
}

BinaryTree::~BinaryTree(){
    clear();
}

bool BinaryTree::empty(){
    return (root == NULL);
}

bool BinaryTree::full(){
    return false;
}

void BinaryTree::clear(){
    clear(root);
    root = NULL;
}

void BinaryTree::clear(TreePointer &t){
    if(t != NULL){
        clear(t->leftNode);
        clear(t->rightNode);
        delete t;
    }
}

void BinaryTree::preOrder(){
    preOrder(root);
}

void BinaryTree::preOrder(TreePointer &t){
    if(t != NULL){
        process(t->entry);
        preOrder(t->leftNode);
        preOrder(t->rightNode);
    }
}

void BinaryTree::inOrder(){
    inOrder(root);
}

void BinaryTree::inOrder(TreePointer &t){
    if(t != NULL){
        inOrder(t->leftNode);
        process(t->entry);
        inOrder(t->rightNode);
    }
}

void BinaryTree::postOrder(){
    postOrder(root);
}

void BinaryTree::postOrder(TreePointer &t){
    if(t != NULL){
        postOrder(t->leftNode);
        postOrder(t->rightNode);
        process(t->entry);
    }
}

void BinaryTree::process(TreeEntry x){
    cout << " "; // espaços
    cout << setw(6) << x << endl; // escreve a raiz
}

int BinaryTree::height(){
    return height(root);
}

int BinaryTree::height(TreePointer &t){
    if(t == NULL)
        return -1;
    else{
        int L, R;
        L = height(t->leftNode);
        R = height(t->rightNode);
        if(L > R)
            return L+1;
        else
            return R+1;
    }
}

void BinaryTree::insert(TreeEntry x){
    insert(x, root);
}

void BinaryTree::print(){ 
    print(root,0);
}

void BinaryTree::print(TreePointer &t, int s){ 
    int i;
    if(t != NULL){ 
        print(t->rightNode, s+3); // escreve subárvore direita
        for(i=1; i<=s; i++)
        cout << " "; // espaços
        cout << setw(6) << t->entry << endl; // escreve a raiz
        print(t->leftNode, s+3); // escreve subárvore esquerda
    }
}

void BinaryTree::insert(TreeEntry x, TreePointer &t){
    TreePointer newNode = new TreeNode;
    newNode->entry = x;

    if(t == NULL){
        newNode->rightNode = NULL;
        newNode->leftNode = NULL;
        t = newNode;
        return;
    }
    else{
        int random = rand()%2;

        switch(random){
            case 0:
                insert(x, t->rightNode);
                break;
            case 1:
                insert(x, t->leftNode);
                break;
        }
    }
}
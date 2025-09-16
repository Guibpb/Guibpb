/**
*   Nome:Guilherme Borges de Pádua Barbosa
*   Nº USP: 15653045
*/

#include <iostream>
#include <iomanip>
#include "AVL.h"
#include <string>

using namespace std;

AVLTree::AVLTree(){
    root = NULL;
}

AVLTree::~AVLTree(){
    clear();
}

void AVLTree::clear(){
    clear(root);
}

void AVLTree::clear(TreePointer &t){
    if(t != NULL){
        clear(t->leftNode);
        clear(t->rightNode);
        delete t;
        t = nullptr;
    }
}

void AVLTree::searchInsert(TreeEntry x){
    bool h = false;
    searchInsert(x, root, h);
}

void AVLTree::searchInsert(TreeEntry x, TreePointer &pA, bool &h){
    TreePointer pB, pC;

    if(pA == NULL){
        pA = new TreeNode;
        h = true;
        pA->entry = x;
        pA->count = 1;
        pA->leftNode = pA->rightNode = NULL;
        pA->bal = 0;
    }

    else
        if(x.nome < pA->entry.nome){
            searchInsert(x, pA->leftNode, h); 
            if(h){
                switch(pA->bal){
                    case -1: pA->bal = 0; h = false; break;
                    case 0: pA->bal = 1; break;
                    case 1: 
                            pB = pA->leftNode;
                            if(pB->bal == 1){ //LL
                                pA->leftNode = pB->rightNode;
                                pB->rightNode = pA;
                                pA->bal = 0;
                                pA = pB;
                            }
                            else{ //LR
                                pC = pB->rightNode;
                                pB->rightNode = pC->leftNode;
                                pC->leftNode = pB;
                                pA->leftNode = pC->rightNode;
                                pC->rightNode = pA;
                                if(pC->bal == 1) pA->bal = -1; else pA->bal = 0;
                                if(pC->bal == -1) pA->bal = 1; else pB->bal = 0;
                                pA = pC;
                            }
                            pA->bal = 0; h = false;
                }
            }
        }
        else
            if(x.nome > pA->entry.nome){ 
                searchInsert(x, pA->rightNode, h);
                if(h){ // subárvore direita cresceu 
                    switch (pA->bal){ 
                        case +1: pA->bal = 0; h = false; break;
                        case 0: pA->bal = -1; break;

                        case -1: pB = pA->rightNode;
                        if(pB->bal == -1){ // rotação RR
                            pA->rightNode = pB->leftNode; pB->leftNode = pA;
                            pA->bal = 0; pA = pB;
                        }
                        else{ // rotação RL
                            pC = pB->leftNode; pB->leftNode = pC->rightNode;
                            pC->rightNode = pB; pA->rightNode = pC->leftNode;
                            pC->leftNode = pA;
                            if(pC->bal == -1) pA->bal = +1; else pA->bal = 0;
                            if(pC->bal == +1) pB->bal = -1; else pB->bal = 0;
                            pA = pC;
                        }
                        pA->bal = 0; h = false;
                    } // switch
                }
            } 
            else pA->count++;
}

bool AVLTree::remove(TreeEntry x){
    bool h=false;
    return remove(x,root,h);
}

//-------------------------------
bool AVLTree::remove(TreeEntry x, TreePointer &p, bool &h){ 
    TreePointer q;
    bool removeu;

    if(p == NULL) // x não encontrado
        return false;

    if(x.nome < p->entry.nome){   
        removeu = remove(x,p->leftNode,h);
        if(h)
        balanceL(p,h);
        return removeu;
    }
    else
        if(x.nome > p->entry.nome){ 
            removeu = remove(x,p->rightNode,h);
            if(h)
            balanceR(p,h);
            return removeu;
        }
        else{ // remover p->
            q = p;
            if(q->rightNode == NULL){
                p = q->leftNode;
                h = true;
            }
            else
                if(q->leftNode == NULL){
                    p = q->rightNode;
                    h = true;
                }
                else{
                    removeMin(q,q->rightNode,h);
                    if(h)
                    balanceR(p,h);
                }

            delete q;
            delete p;
            p = NULL;
            return true; // x removido
        }
}

void AVLTree::removeMin(TreePointer &q, TreePointer &r, bool &h){
    if(r->leftNode != NULL){
        removeMin(q, r->leftNode, h);
        if(h)
        balanceL(r,h);
    }
    else{
        q->entry = r->entry;
        q->count = r->count;
        q = r;
        r = r->rightNode;
        h = true;
    }
}

void AVLTree::balanceL(TreePointer &pA, bool &h)
{
    TreePointer pB, pC;
    int balB, balC;

    // subárvore esquerda encolheu
    switch (pA->bal)
    {
        case +1:
            pA->bal = 0;
            break;

        case 0:
            pA->bal = -1;
            h = false;
            break;

        case -1:
            pB = pA->rightNode;
            balB = pB->bal;

            if (balB <= 0) // rotação RR
            {
                pA->rightNode = pB->leftNode;
                pB->leftNode = pA;

                if (balB == 0)
                {
                    pA->bal = -1;
                    pB->bal = +1;
                    h = false;
                }
                else
                {
                    pA->bal = 0;
                    pB->bal = 0;
                }

                pA = pB;
            }
            else // rotação RL
            {
                pC = pB->leftNode;
                balC = pC->bal;

                pB->leftNode = pC->rightNode;
                pC->rightNode = pB;

                pA->rightNode = pC->leftNode;
                pC->leftNode = pA;

                if (balC == -1)
                    pA->bal = +1;
                else
                    pA->bal = 0;

                if (balC == +1)
                    pB->bal = -1;
                else
                    pB->bal = 0;

                pA = pC;
                pC->bal = 0;
            }
            break;
    }
}


void AVLTree::balanceR(TreePointer &pA, bool &h){
    TreePointer pB, pC;
    int balB, balC;

    // subárvore direita encolheu
    switch (pA->bal)
    {
        case -1:
            pA->bal = 0;
            break;

        case 0:
            pA->bal = +1;
            h = false;
            break;

        case +1:
            pB = pA->leftNode;
            balB = pB->bal;

            if (balB >= 0) // rotação LL
            {
                pA->leftNode = pB->rightNode;
                pB->rightNode = pA;

                if (balB == 0)
                {
                    pA->bal = +1;
                    pB->bal = -1;
                    h = false;
                }
                else
                {
                    pA->bal = 0;
                    pB->bal = 0;
                }

                pA = pB;
            }
            else // rotação LR
            {
                pC = pB->rightNode;
                balC = pC->bal;

                pB->rightNode = pC->leftNode;
                pC->leftNode = pB;

                pA->leftNode = pC->rightNode;
                pC->rightNode = pA;

                if (balC == +1)
                    pA->bal = -1;
                else
                    pA->bal = 0;

                if (balC == -1)
                    pB->bal = +1;
                else
                    pB->bal = 0;

                pA = pC;
                pC->bal = 0;
            }
            break;
    }
}

bool AVLTree::search(TreeEntry x){
    return rSearch(x, root);
}

//--------------------------------------------------------------------------
bool AVLTree::rSearch(TreeEntry x, TreePointer &t){
    if (t == NULL)
        return false; // x não encontrado

    if (x.nome < t->entry.nome)
        return rSearch(x, t->leftNode);
    else if (x.nome > t->entry.nome)
        return rSearch(x, t->rightNode);
    else
        return true; // x.nome == t->entry.nome
}

void AVLTree::print(){ 
    print(root,0);
}

void AVLTree::print(TreePointer &t, int s){ 
    int i;
    if(t != NULL){ 
        print(t->rightNode, s+3); // escreve subárvore direita
        for(i=1; i<=s; i++)
        cout << " "; // espaços
        cout << setw(6) << t->entry.nome << endl; // escreve a raiz
        print(t->leftNode, s+3); // escreve subárvore esquerda
    }
}

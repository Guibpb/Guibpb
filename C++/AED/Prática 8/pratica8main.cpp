/**
*Nome:Guilherme Borges de Pádua Barbosa
*Nº USP: 15653045
*/

#include <iostream>
#include "ArvoreAleatoria.h"
#include <iomanip>

using namespace std;

int main(){
    BinaryTree T;
    /*for(int i = 0; i < 10; i++){
        T.insert(i);
    }*/ 

    //T.postOrder();
    //T.preOrder();
    //T.inOrder();
    //T.print();
    //cout << T.height() << endl;

    if(T.empty()){
        cout << "Árvore está vazia." << endl;
    }
    else{
        cout << "Árvore não está vazia." << endl;
    }
    
    if(T.full()){
        cout << "Árvore está cheia." << endl;
    }
    else{
        cout << "Árvore não está cheia." << endl;
    }


    return 0;
}
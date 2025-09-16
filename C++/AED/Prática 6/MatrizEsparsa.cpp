//Nome: Guilherme Borges de Pádua Barbosa
//Nº USP: 15653045

#include <iostream>
#include "MatrizEsparsa.h"
using namespace std;

void Matrix::print(){
    ListEntry matrix[10][10];

    for(int i = 0; i < 10; i++){
        for(int j = 0; j < 10; j++)
            matrix[i][j] = 0;
    }
    int i = 0;

    for(int i = 0; i < 10; i++){
        ListPointer q = R[i];

        while(q != NULL){
            matrix[i][q->cValue] = q->entry;
            q = q->cNext;
        }
    }

    for(int i = 0; i < 10; i++){
        for(int j = 0; j < 10; j++){
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}
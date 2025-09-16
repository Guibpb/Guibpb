//Nome: Guilherme Borges de Pádua Barbosa
//Nº USP: 15653045

#include <iostream>
#include "lista_dup.h"
using namespace std;

int main(){
    List lista;
    bool run = true;
    int entry;

    cout << "Insira os números para serem inseridos no final da lista(0 para terminar): " << endl;
    while(run){
        cin >> entry;
        if(entry == 0){
            lista.print();
            return 0;
        }
        //lista.insertStart(entry);
        lista.insertEnd(entry);
    } 


    return 0;
}
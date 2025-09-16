//Nome: Guilherme Borges de Pádua Barbosa
//Nº USP: 15653045

#include <iostream>
#include "pilha.h"
using namespace std;
#include <string>

int main(){
    Stack pilha;
    string palavra;
    cout << "Insira a frase para inverter: ";
    getline(cin,palavra);

    for(char letra : palavra){
        pilha.push(letra);
    }

    char letra;
    cout << "Frase invertida: " << endl;

    while(!pilha.empty()){
        pilha.pop(letra);
        cout << letra;
    }

    cout << endl;

    return 0;
}

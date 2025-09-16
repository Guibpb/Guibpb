/**
*   Nome:Guilherme Borges de Pádua Barbosa
*   Nº USP: 15653045
*/

#include <iostream>
#include <iomanip>
#include "AVL.h"
#include "Hash.h"
#include "lista.h"
#include <string>
using namespace std;

void menuHash(HashTable &h){
    cout << "\nMenu - Tabela Hash:" << "\n1 - Inserir" << "\n2 - Remover" << "\n3 - Buscar" << "\n4 - Imprimir" << "\n5 - Sair" << endl;
    int op, resultado;
    Pessoa p;
    cin >> op;

    switch(op){
        case 1: 
            cout << "\nInsira seu nome: " << endl;
            cin.ignore();
            getline(cin, p.nome);

            cout << "\nInsira sua idade: " << endl;
            cin >> p.idade;

            cout << "\nInsira sua matrícula: " << endl;
            cin >> p.matricula;

            h.insert(p);
            menuHash(h);
            break;

        case 2: 
            cout << "\nInsira a pessoa para remover." << endl;

            cout << "Nome: ";
            cin.ignore();
            getline(cin, p.nome);;

            cout << "Idade: ";
            cin >> p.idade;

            cout << "Matrícula: ";
            cin >> p.matricula;

            h.remove(p);

            cout << endl;
            menuHash(h);
            break;

        case 3: 
            cout << "\nInsira a pessoa para buscar" << endl;

            cout << "Nome: ";
            cin.ignore();
            getline(cin, p.nome);

            cout << "Idade: ";
            cin >> p.idade;

            cout << "Matrícula: ";
            cin >> p.matricula;

            resultado = h.search(p);

            cout << endl;

            if(resultado != 0)
                cout << "Esse nome está na tabela, e sua posição na lista é: " << resultado << ".\n\n";
            else
                cout << "Esse nome não está na tabela.\n\n";
            menuHash(h);
            break;

        case 4:
            h.print();
            menuHash(h);
            break;

        case 5: 
            break;

        default: 
            cout << "Entrada Inválida" << endl;
            abort();
    }
}

void menuArvore(AVLTree &t){
    cout << "\nMenu - AVL:" << "\n1 - Inserir" << "\n2 - Remover" << "\n3 - Buscar" << "\n4 - Imprimir" << "\n5 - Sair" << endl;
    int op;
    string nome;
    Pessoa p;
    cin >> op;

    switch(op){
        case 1: 
            cout << "\nInsira seu nome: ";
            cin.ignore();
            getline(cin, p.nome);

            cout << "Insira sua idade: ";
            cin >> p.idade;

            cout << "Insira sua matrícula: ";
            cin >> p.matricula;

            t.searchInsert(p);
            menuArvore(t);
            break;

        case 2: 
            cout << "\nInsira a pessoa para remover." << endl;

            cout << "Nome: ";
            cin.ignore();
            getline(cin, p.nome);

            cout << "Idade: ";
            cin >> p.idade;

            cout << "Matrícula: ";
            cin >> p.matricula;

            if(t.remove(p))
                cout << "Usuário removido com sucesso!" << endl;
            else
                cout << "Não foi possível remover o usuário." << endl;

            menuArvore(t);
            break;

        case 3: 
            cout << "\nInsira a pessoa para busacr." << endl;

            cout << "Nome: ";
            cin.ignore();
            getline(cin, p.nome);

            cout << "Idade: ";
            cin >> p.idade;

            cout << "Matrícula: ";
            cin >> p.matricula;

            if(t.search(p))
                cout << "Esse nome está na árvore.\n" << endl;
            else
                cout << "Esse nome não está na árvore.\n" << endl;
            menuArvore(t);
            break;

        case 4:
            t.print();
            menuArvore(t);
            break;

        case 5: 
            break;

        default: 
            cout << "Entrada Inválida" << endl;
            abort();
    }
}

int main(){
    AVLTree Tree;
    menuArvore(Tree);

    HashTable tabela;
    //menuHash(tabela);
    return 0;
}
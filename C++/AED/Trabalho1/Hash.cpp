/**
*   Nome:Guilherme Borges de Pádua Barbosa
*   Nº USP: 15653045
*/

#include <iostream>
#include <string>
#include "Hash.h"
#include "lista.h"

HashTable::HashTable(){
    tabela = new List[TAMANHO]; //cria um array de listas com o tamanho definido
}

HashTable::~HashTable(){
    clear();
}

void HashTable::clear(){
    for(int i = 0; i < TAMANHO; i++){
        tabela[i].clear(); //usa o método de lista 'clear' para a tabela inteira
    }
}

HashKey HashTable::transform(string nome){
    HashKey chave = 0;

    for(int i = 0; i < size(nome); i++){
        chave = (chave*128 + nome[i])%TAMANHO; //função hash
    }
    return chave;
}

void HashTable::insert(HashEntry pessoa){
    HashKey chave = transform(pessoa.nome);
    tabela[chave].insert(1, pessoa);//Insere no começo da lista de posição chave
}

int HashTable::search(HashEntry &pessoa){
    HashKey chave = transform(pessoa.nome); //Descobre a chave Hash
    int resultado = tabela[chave].search(pessoa.matricula); //Encontra usando o método da lista, e modifica o x

    return(resultado == 0 ? 0 : resultado); //Retorna 0 se não for encontrado ou a posição na lista se for
}

void HashTable::remove(HashEntry &pessoa){
    HashKey chave = transform(pessoa.nome);
    int posicao = tabela[chave].search(pessoa.matricula); //encontra a posicao do item com base na matrícula, na lista de indice 'chave'

    if(posicao != 0){
        tabela[chave].remove(posicao, pessoa); //remove o item, se encontrado
        cout << "Pessoa removida com sucesso." << endl;
    }
    else
        cout << "Pessoa não encontrada." << endl;
}

void HashTable::print(){
    if(empty()){
        cout << "Tabela está vazia." << endl;
        return;
    }

    for(int i = 0; i < TAMANHO; i++){
        if(!tabela[i].empty()){
            tabela[i].print();
        }
    }
}

bool HashTable::empty(){
    bool resultado = true;

    for(int i = 0; i < TAMANHO; i++){
        if(!tabela[i].empty())
            resultado = false; //Se alguma das listas não estiver vazia, a tabela também não estará
    }

    return resultado;
}
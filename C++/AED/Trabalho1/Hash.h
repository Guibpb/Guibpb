/**
*   Nome:Guilherme Borges de Pádua Barbosa
*   Nº USP: 15653045
*/

#include <string>
#include "lista.h"
using namespace std;

#ifndef HASH_H
#define HASH_H

typedef Pessoa HashEntry;
typedef int HashKey;

class HashTable {
public:
    HashTable();
    ~HashTable();
    HashKey transform(string x);
    void insert(HashEntry x);
    int search(HashEntry &x);
    void remove(HashEntry &x);
    void clear();
    void print();
    bool empty();

private:
    const int TAMANHO = 701; //Tamanho da tabela
    List *tabela; //cria um array de listas
};

#endif
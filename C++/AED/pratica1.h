//Aluno: Guilherme Borges de Pádua Barbosa
//Nº USP: 15653045

using namespace std;

#ifndef PRATICA1_H
#define PRATICA1_H

class DataN{
public:
    void cadastra(int Dia, int Mes, int Ano);
    void imprimeDataFormato1();
    void imprimeDataFormato2();
    void adicionaDias(int dias);
    bool bissexto();

private:
    int dia;
    int mes;
    int ano;
    bool ano_bissexto;
    const int dias_mes[12] = {31,28,31,30,31,30,31,31,30,31,30,31};
};

#endif
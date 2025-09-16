//Aluno: Guilherme Borges de Pádua Barbosa
//Nº USP: 15653045

#include <iostream>
#include "pratica1.h"

int main(){
    DataN calendario;

    int dia1, mes1, ano1;
    cout << "Insira a data desejada: ";
    cin >> dia1 >> mes1 >> ano1;

    calendario.cadastra(dia1, mes1, ano1);
    calendario.imprimeDataFormato1();
    calendario.imprimeDataFormato2();

    if(calendario.bissexto())
        cout << "Esse ano é bissexto!" << endl;
    else
        cout << "Esse ano não é bissexto." << endl;

    int dias_soma;

    cout << "Insira quantos dias você quer somar (máx 7): ";
    cin >> dias_soma;

    calendario.adicionaDias(dias_soma);
    cout << "Nova data: " << endl;
    calendario.imprimeDataFormato1();
    calendario.imprimeDataFormato2();

    return 0;
}
//Aluno: Guilherme Borges de Pádua Barbosa
//Nº USP: 15653045

#include <iostream>
#include "pratica1.h"
using namespace std;
#include <string>

bool DataN::bissexto(){
    return ano_bissexto;
}

void DataN::imprimeDataFormato1(){
    cout << dia << "/" << mes << "/" << ano << endl;
}

void DataN::imprimeDataFormato2(){
    string meses[] = {"Janeiro", "Fevereiro", "Março", "Abril", "Maio", "Junho", "Julho", "Agosto", "Setembro", "Outubro", "Novembro", "Dezembro"};
    cout << dia << " de " << meses[mes-1] << " de " << ano << endl;
}

void DataN::adicionaDias(int dias){
    if(dias > 7){
        cout << "Dias demais!" << endl;
        abort();
    }
        
    int sum = dia + dias;

    if(ano_bissexto && mes == 2){
        if(sum > 29){
            mes++;
            dia = sum - 29;
        }

        return;
    }

    if(sum > dias_mes[mes-1]){
        dia = sum - dias_mes[mes-1];

        if(mes == 12){
            ano++;
            mes = 1;
            return;
        }
        mes++;    
        
        return;
    }

    dia = sum;
    return;
}

void DataN::cadastra(int Dia, int Mes, int Ano){
    if(Dia <= 0 || Dia >= 32 || Mes <= 0 || Mes >= 13 || Ano <= 0){
        cout << "Data Inválida" << endl;
        abort();
    }

    if(Ano % 4 == 0){
        if(Ano % 100 == 0 && Ano % 400 == 0){
            ano_bissexto = true;
        }
        else if(Ano % 100 == 0 && Ano % 400 != 0){
            ano_bissexto = false;
        }
        else{
            ano_bissexto = true;
        }
    }

    if(!(ano_bissexto && Mes == 2) && Dia > dias_mes[Mes-1]){
        cout << "Data Inválida" << endl;
        abort();
    }

    if(ano_bissexto && Dia >= 30 && Mes == 2){
        cout << "Data Inválida" << endl;
        abort();
    }

    dia = Dia;
    mes = Mes;
    ano = Ano;
};
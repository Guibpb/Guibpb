#include <iostream>
#include "filacontigua.h"
using namespace std;
#include <string>

struct Slot{
    string dia[5] = {"Segunda",  "Terça", "Quarta", "Quinta", "Sexta"};
    string periodo[2] = {"Manhã, Tarde"};
    Queue fila[10];    
};

static Slot slot;

void cadastra(){
    Pessoa pessoa;
    string buff;

    cout << "Insira seus dados (nome/endereço/cpf/idade): ";
    getline(cin, buff);
    getline(cin,pessoa.nome);
    getline(cin,pessoa.endereço);
    getline(cin, pessoa.cpf);
    cin >> pessoa.idade;

    if(pessoa.idade < 5){
        abort();
    }

    //cout << pessoa.nome << endl << pessoa.endereço << endl << pessoa.cpf << endl << pessoa.idade << endl;

    system("clear || cls");
    cout << "Horários Disponíveis:" << endl;

    for(int i = 0; i < 10; i++){
        if(!slot.fila[i].full()){
            cout << "Horário - " << i + 1 << endl;
            cout << "Dia: " << slot.dia[i/2] << "\nPeríodo: ";

            if(i%2 == 0)
                cout << "Manhã\n" << endl;
            else
                cout << "Tarde\n" << endl;
        }
    }

    cout << "Escolha, dentre os horários disponíveis, o número de 1 a 10: " << endl;
    int horario;
    cin >> horario;

    if(horario < 1 || horario > 10 || slot.fila[horario-1].full()){
        cout << "Horário Inválido" << endl;
        abort();
    }
    cout << "Cadastro efetuado com sucesso" << endl;
    slot.fila[horario-1].append(pessoa);

    cin.ignore();
    cin.get();
}

int escolha_slot(){
    cout << "Escolha o slot de 1 a 10" << endl;

    for(int i = 0; i < 10; i++){
        cout << "Horário - " << i + 1 << endl;
        cout << "Dia: " << slot.dia[i/2] << "\nPeríodo: ";

        if(i%2 == 0)
            cout << "Manhã\n" << endl;
        else
            cout << "Tarde\n" << endl;
    }

    int escolha;
    cin >> escolha;
    return escolha;
}

void imprime(){
    system("clear || cls");
    int escolha = escolha_slot();

    slot.fila[escolha-1].print();
    cin.ignore();
    cin.get();
}

void remove(){
    int escolha = escolha_slot();

    Pessoa pessoa;
    slot.fila[escolha-1].serve(pessoa);

    system("clear || cls");
    cout << "Pessoa Vacinada -\nNome: " << pessoa.nome << "\nEndereço: " << 
    pessoa.endereço << "\nCPF: " << pessoa.cpf << "\nIdade: " << pessoa.idade;
    cin.ignore();
    cin.get();
}

int main(){
    bool sair = true;

    while(sair){
        system("clear || cls");
        cout << "1- Cadastro\n2- Mostrar\n3- Remover\n4-Sair" << endl;

        int escolha;
        cin >> escolha;

        switch (escolha){
            case 1:
                cadastra();
                break;

            case 2:
                imprime();
                break;

            case 3:
                remove();
                break;

            case 4:
                sair = false;
                break;

            default:
                cout << "Entrada Inválida" << endl;
                break;
        }
    }

    return 0;
}

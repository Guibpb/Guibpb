#include <iostream>
#include "lista_ordenada.h"
using namespace std;

OrderedList P, Q;

void modificar(OrderedList &polinomio){
    ListEntry nó;
    polinomio.clear();
    bool opcao = true;

    while(opcao){
        cout << "Entre o coeficiente de um dos termos(entre 0 para terminar): ";
        cin >> nó.coeficiente;
        if(nó.coeficiente == 0)
            break;
        cout << "Entre o expoente desse coeficiente: ";
        cin >> nó.expoente;
        polinomio.insert(nó);
    }
}

void graus(){
    cout << "Grau de P é: " << P.getHead().expoente << endl;
    cout << "Graud de Q é: " << Q.getHead().expoente << endl;
}

void imprimir(){
    cout << "Impressão do Polinomio P: ";
    P.print();
    cout << "\nImpressão do Polinomio Q: ";
    Q.print();
}

void soma(){
    OrderedList soma = P.sum(Q, 1);
    soma.print();
}

void subtracao(){
    OrderedList sub = P.sum(Q, -1);
    sub.print();
}

void menu(){
    int opcao;
    while (true) {
        cout << "\n====== MENU ======\n"
             << "1. Modificar o P(x)\n"
             << "2. Modificar o Q(x)\n"
             << "3. Retornar os graus\n"
             << "4. Imprimir\n"
             << "5. Imprimir P(x) + Q(x)\n"
             << "6. Imprimir P(x) - Q(x)\n"
             << "7. Sair\n"
             << "Escolha uma opcao: ";
             
        cin >> opcao;

        // Tratamento das opções
        switch (opcao) {
            case 1:
                modificar(P);
                break;
            case 2:
                modificar(Q);
                break;
            case 3:
                graus();
                break;
            case 4:
                imprimir();
                break;
            case 5:
                soma();
                break;
            case 6:
                subtracao();
                break;
            case 7:
                return;
            default:
                cout << "Opção inválida. Tente novamente.\n";
        }
    }
}

int main(){
    menu();
    return 0;
}
#include <iostream>
#include <string>
#include <cstring>

using namespace std;

struct Domicilio{ //struct com os dados
    float rendaMedia;
    int ocupantes;
    string endereço;
};

void addDados(int &i, Domicilio domicilio[]){ 
    i++; //aumenta o indice global de domicilios

    system("clear || cls");
    cout << "Domicilio " << i+1 << endl;

    cout << "Insira a renda media: ";
    cin >> domicilio[i].rendaMedia;

    cout << "Insira o numero de ocupantes: ";
    cin >> domicilio[i].ocupantes;

    cout << "Insira o endereço: ";
    cin.ignore();
    getline(cin,domicilio[i].endereço);
}

int findDados(int i, Domicilio domicilio[]){
    system("clear || cls");

    string endereço;
    cout << "Insira o endereço do domicilio: ";
    
    cin.ignore();
    getline(cin,endereço);

    domicilio[i+1].endereço = endereço; //sentinela no valor depois do ultimo

    int j = 0;

    while(domicilio[j].endereço.compare(endereço) != 0)
        j++;   

    if(j != i+1)
        return j;

    else
        return -1;
}


int main(){
    int N, indexOfUltimo = -1, opcao, i;
    cout << "Numeros de domicilios: ";
    cin >> N;
    Domicilio domicilio[N+1];

    while(true){
        system("clear || cls");
        cout << "Menu: " << endl;
        cout << "Insira a opção: " << endl;
        cout << "1 - Adicionar os dados de um domicilio" << endl;
        cout << "2 - Procurar os dados de um domicilio" << endl;
        cout << "0 - Sair" << endl;

        cin >> opcao;

        switch(opcao){
            case 0:
                return 0;

            case 1:
                if(indexOfUltimo == N-1){
                    cout << "Número de domicílios máximo atingido.";
                    break;
                }
                addDados(indexOfUltimo, domicilio);
                break;

            case 2:
                i = findDados(indexOfUltimo, domicilio);

                if(i < 0){
                    cout << "Endereço nao encontrado" << endl;
                    cin.ignore();
                    system("pause");
                }     

                else{
                    cout << "Domicilio de índice: " << i+1 << endl;
                    cout << "Renda media: " << domicilio[i].rendaMedia << endl;
                    cout << "Ocupantes: " << domicilio[i].ocupantes <<endl;
                    cin.ignore();
                    system("pause");
                }

                break;

            default:
                cout << "Numero invalido" << endl;
                break;
        }
    }
    return 0;
}

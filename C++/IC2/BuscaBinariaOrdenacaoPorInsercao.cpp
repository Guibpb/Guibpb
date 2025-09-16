#include <iostream>
#include <string>
#include <cstring>
#include <math.h>

using namespace std;

struct Domicilio{
   float rendaMedia;
   int ocupantes;
   int ocupantesEmIdadeEscolar;
   string endereço;
};

void ordenarDados(int N, Domicilio domicilio[]){
   for(int i = 2; i < N; i++){
      Domicilio domicilioAtual = domicilio[i];
      domicilio[0] = domicilioAtual;
      int j = i;

      while(domicilioAtual.endereço < domicilio[j-1].endereço){
          domicilio[j] = domicilio[j-1];
          j--;
      }
      domicilio[j] = domicilioAtual;
  }
}

void addDados(int &i, Domicilio domicilio[]){
    i++;

    system("clear || cls");
    cout << "Domicilio " << i << endl;

    cout << "Insira a renda media: ";
    cin >> domicilio[i].rendaMedia;

    cout << "Insira o numero de ocupantes: ";
    cin >> domicilio[i].ocupantes;

    cout << "Insira o numero de ocupantes em idade escolar: ";
    cin >> domicilio[i].ocupantesEmIdadeEscolar;

    cout << "Insira o endereço: ";
    cin.ignore();
    getline(cin,domicilio[i].endereço);
}

int findDados(int N, Domicilio domicilio[]){
    system("clear || cls");

    for(int i = 1; i < N; i++){
        cout << "Domicilio de índice: " << i << endl;
        cout << "Endereço: " << domicilio[i].endereço << endl;
        cout << "\n\n";
    }

    string endereço;
    cout << "Insira o endereço do domicilio desejado: ";

    cin.ignore();
    getline(cin,endereço);

    int left = 1, right = N;

    while(left < right){
        int middle = floor((right+left)/2);

        if(domicilio[middle].endereço < endereço)
            left = middle + 1;
        else
            right = middle;
    }

    if(domicilio[right].endereço == endereço)
        return right;
    
    else
        return -1;
}

int main(){
    int N, indexOfUltimo = 0,opcao, i;
    cout << "Numeros de domicilios: ";
    cin >> N;
    Domicilio domicilio[N+1];
    string buff;

    while(true){
        system("clear || cls");
        cout << "Menu " << endl;
        cout << "Insira a opção: " << endl;
        cout << "1 - Adicionar os dados de um domicilio" << endl;
        cout << "2 - Procurar os dados de um domicilio" << endl;
        cout << "0 - Sair" << endl;

        cin >> opcao;

        switch(opcao){
            case 0:
                return 0;

            case 1:
                if(indexOfUltimo == N){
                    system("clear || cls");
                    cout << "Numero maximo inserido" << endl;
                    cin.ignore();
                    cin.ignore();
                    system("pause");
                    break;
                }
                addDados(indexOfUltimo, domicilio);
                break;

            case 2:
                ordenarDados(indexOfUltimo+1, domicilio);
                i = findDados(indexOfUltimo+1, domicilio);
                
                if(i < 0){
                    cout << "Endereço nao encontrado" << endl;
                    cin.ignore();
                    system("pause");
                }
                    
                else{
                    cout << "Domicilio de índice: " << i << endl;
                    cout << "Renda media: " << domicilio[i].rendaMedia << endl;
                    cout << "Ocupantes: " << domicilio[i].ocupantes <<endl;
                    cout << "Ocupantes em idade escolar: " << domicilio[i].ocupantesEmIdadeEscolar << endl;
                    cin.ignore();
                    system("pause");
                }

                break;

            default:
                system("clear || cls");
                cout << "Numero invalido" << endl;
                cin.ignore();
                cin.ignore();
                system("pause");
                break;
        }
    }
    return 0;
}
#include <iostream>

using namespace std;

int contComp = 0, contReg = 0, contRec = 1;

struct Pessoa{
    string nome;
    int idade;
};

void quickSort(Pessoa a[], int L, int R){
    int i = L, j = R, w;
    int x = a[(L+R)/2].idade;

    do{
        contComp++;
        while(a[i].idade < x){
            i++;
            contComp++;
        }

        contComp++;
        while(x < a[j].idade){
            j--;
            contComp++;
        }

        if(i <= j){
            w = a[i].idade;
            string temp = a[i].nome;
            a[i] = a[j];
            a[j].idade = w;
            a[j].nome = temp;
            i++;
            j--;
            contReg++;
        }
    }while(i <= j);

    if(L < j){
        quickSort(a, L, j);
        contRec++;
    }
        

    if(i < R){
        quickSort(a, i, R);
        contRec++;
    }
}
        

void print(Pessoa pessoa[], int N){
    /*cout << "Lista de Pessoas Ordenada:" << endl;
    system("clear || cls");
    for(int i = 1; i <= N; i++){
        cout << i << "-\nNome: " << pessoa[i].nome << "\nIdade: " << pessoa[i].idade << "\n\n";
    }*/

    cout << "Número de Comparações: " << contComp << "\nNúmero de Movimentações: " << contReg << "\nNúmero de chamadas da função recursiva: " << contRec << endl;
}

int main(){
    cout << "Insira o número de pessoas: ";
    int numeroDePessoas;
    cin >> numeroDePessoas;

    Pessoa pessoa[numeroDePessoas + 1];

    for(int i = 1; i <= numeroDePessoas; i++){
        cout << "\n\n" << i << "ª Pessoa -";
        cout << "Insira o nome: ";
        cin >> pessoa[i].nome;
        cout << "Insira a idade: ";
        cin >> pessoa[i].idade;
    }

    quickSort(pessoa, 1, numeroDePessoas);
    print(pessoa, numeroDePessoas);

    return 0;
}

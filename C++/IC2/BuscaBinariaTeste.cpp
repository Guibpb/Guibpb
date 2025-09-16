#include <iostream>
#include <math.h>

using namespace std;

struct Domicilio{
    string endereço;
};

int findDados(int N, Domicilio domicilio[]){
    system("clear || cls");

    for(int i = 1; i < N; i++){
        cout << "Domicilio de índice: " << i << endl;
        cout << "Endereço: " << domicilio[i].endereço << endl;
        cout << "\n\n";
    }

    string endereço;
    cout << "Insira o endereço do domicilio desejado: ";
    getline(cin,endereço);
    cout << endereço << endl;

    int left = 1, right = N;
    int debug = 1;

    while(left < right){
        int middle = (right+left)/2;
        cout << debug << " middle: " << middle << "\n domicilio[middle]: " << domicilio[middle].endereço << endl;
        cout << " left: " << left << " right: " << right << endl;

        if(domicilio[middle].endereço < endereço)
            left = middle + 1;
        else
            right = middle;

        debug++;
    }

    if(domicilio[right].endereço == endereço)
        return right;

    else
        return -1;
}

int main(){
    Domicilio domicilio [6];

    domicilio[1].endereço = "a";
    domicilio[2].endereço = "b";
    domicilio[3].endereço = "c";
    domicilio[4].endereço = "d";
    domicilio[5].endereço = "e";

    cout << findDados(5, domicilio) << endl;


    return 0;
}
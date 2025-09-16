#include <iostream>

using namespace std;

float fatorial (int x){
    float fact = 1;

    for(int i = 2; i <= x; i++)
        fact *= i;

    return fact;
}

float combinação(int m, int n){

    return (fatorial(n))/((fatorial(m))*(fatorial(n - m)));
}


int main(){
    int m, n;

    cout << "insira n e m: ";
    cin >> n >> m;

    if(n < 0 || m < 0 || m > n){
        cout << "Valor impróprio" << endl;
        return 0;
    }

    cout << "Combinação: " << combinação(m,n) << endl;


    return 0;
}
#include <iostream>
#include <vector>

using namespace std;

void bubblesort(vector <int> &vet, int N){ //peguei isso aq de IC2 ano passado
    bool sorted;
    int j = 1;
    do{
        sorted = true;

        for(int i = 0; i < N-j; i++){
            if(vet[i] > vet[i+1]){
                swap(vet[i],vet[i+1]);
                sorted = false;
            }
        }
        j++;

    }while(!sorted);
}

int main(){
    int array[14] = {21, 2, 43, 76, 87, 52, 11, 99, 5, 78, 41, 77, 62, 93};
    vector <int> bucket[10];
    vector <int> arrayordenado;

    for(int x : array){
        int i = x;
        do{
            i /= 10;
        }while(i > 10);

        bucket[i].push_back(x);
    }

    for(vector <int> &x : bucket){
        bubblesort(x, x.size());
    }

    for(vector <int> x: bucket){
        for(int y : x){
            arrayordenado.push_back(y);
        }
    }

    for(int x : arrayordenado)
        cout << x << " ";
}
#include <iostream>
#include <stdio.h>


using namespace std;


int calcularSegundaOcorrencia(int v[], int x, int n, int &op){
   int count = 0;
   op += 2;//count e i = 0


   for(int i = 0; i < n; i++){
       op += 3; // i < n e i++
       
       if(v[i] == x){
           count++;
           op++;//count++
       }
       op += 2;//v[i] == x


       if(count == 2){
           op++;//count == 2
           return i;
       }
       op++;//count == 2
   }


   return -1;
}

int main(){
   int n, x, op = 0;
   cout << "Coloque o tamanho do vetor: ";
   cin >> n;
   cout << "Coloque o valor de x: ";
   cin >> x;


   int *v;
   v = new int(n);


   cout << "Insira " << n << " valores para o vetor: ";
   for(int i = 0; i < n; i++)
       cin >> v[i];


   cout << "Indíce da segunda ocorrência: " << calcularSegundaOcorrencia(v, x, n, op) << endl;
   cout << "Numero de operações: " << op << endl;


   delete []v;


   return 0;
}
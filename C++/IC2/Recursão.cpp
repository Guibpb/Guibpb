#include <iostream>
#include <ctime>

using namespace std;

int count = 0;

int hanoi(int n, string a, string c, string b){
   count += 4;

   if(n>0){
       hanoi(n-1, a, b, c);
       hanoi(n-1, b, c, a);
   }
}

int main(){
   int n;
   string a = "da esquerda";
   string b = "central";
   string c = "da direita";

   cout << "Insira o número de discos: ";
   cin >> n;

   clock_t t1, t2;
   double ttotal;
   t1 = clock();

   hanoi(n, a, b, c);
   t2 = clock();
   ttotal = difftime(t2,t1)/CLOCKS_PER_SEC;

   cout << "O número de variáveis criadas na recursão é: " << count << endl;
   cout << "O tempo total é: " << ttotal << " segundos." << endl;

   return 0;
}
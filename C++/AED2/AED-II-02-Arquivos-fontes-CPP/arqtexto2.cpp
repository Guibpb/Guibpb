#include <iostream>
#include <fstream>
#include <cstdlib>
#include <iomanip>
#include <string>
using namespace std;
int main()
{ int numero;
  string nome;
  ifstream inFile;  // inFile é o arquivo de leitura dos dados

  inFile.open("saida.txt", ios::in);	// abre o arquivo para leitura
  if (! inFile)
  {  cout << "Arquivo saida.txt nao pode ser aberto" << endl;
     abort();
  }

  cout << setiosflags(ios::left) 
       << setw(10) << "Numero"
       << setw(50) << "Nome" << endl;
  while(inFile >> numero >> nome)
    cout << setiosflags(ios::left) 
         << setw(10) << numero 
         << setw(50) << nome << endl;
   
  inFile.close(); // se o programador omitir a chamada ao método close
  return 0;      // o destrutor se encarrega de fechar o arquivo
}

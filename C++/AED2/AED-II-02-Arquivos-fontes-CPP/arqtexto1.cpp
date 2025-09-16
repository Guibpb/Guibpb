#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
using namespace std;

int main()
{
	int numero, t;
	string nome;
	ofstream outFile; // outFile � o arquivo onde a sa�da ser� escrita

	outFile.open("saida.txt", ios::out); // abre o arquivo para escrita
	if (!outFile)
	{
		cout << "Arquivo saida.txt nao pode ser aberto" << endl;
		abort();
	}

	outFile << "teste";

	cout << "Entre com o numero e nome do funcion�rio\n"
		 << "Fim de arquivo (0) termina a entrada de dados\n\n? ";

	do
	{
		cin >> t;
		outFile << numero << " " << nome << "\n";
		cout << "? ";
	}while(t == 0);
	outFile.close(); // se o programador omitir a chamada ao m�todo close
	return 0;		 // o finalizador se encarrega de fechar o arquivo
}

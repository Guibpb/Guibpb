#include <iostream>
#include <fstream>
#include <cstdlib>
#include <iomanip>
#include <string>
using namespace std;
struct funcionario // estrutura do registro de funcion�rio
{
	int matricula;
	string nome;
	string cargo;
	int escolaridade;
	char sexo;
	string local;
	char ecivil; // estado civil
	float salario;
};

int main()
{
	funcionario f;
	char sexo;
	ifstream funcFile("func.dat");

	if (!funcFile)
	{
		cout << "Arquivo func.dat nao pode ser aberto" << endl;
		abort();
	}

	cout << "\n\nSexo dos funcionarios a serem listados (M ou F) Ctrl-Z termina? ";
	while (cin >> sexo)
	{
		cout << "Consulta funcionario com sexo = " << sexo << endl;
		cout << setiosflags(ios::left)
			 << setw(10) << "Matricula"
			 << setw(10) << "Nome"
			 << setw(15) << "Cargo"
			 << setw(5) << "Esc."
			 << setw(5) << "Sexo"
			 << setw(10) << "Local"
			 << setw(5) << "E.C."
			 << setw(10) << "Salario" << endl;

		funcFile.clear();																							  // limpa "eof = final de arquivo" para proximo uso
		funcFile.seekg(0);																							  // posiciona no inicio do arquivo
		funcFile >> f.matricula >> f.nome >> f.cargo >> f.escolaridade >> f.sexo >> f.local >> f.ecivil >> f.salario; // ler primeiro registro
		while (!funcFile.eof())
		{
			if (f.sexo == sexo) // o registro atende a condi��o de consulta?
				cout << setiosflags(ios::left)
					 << setw(10) << f.matricula
					 << setw(10) << f.nome
					 << setw(15) << f.cargo
					 << setw(5) << f.escolaridade
					 << setw(5) << f.sexo
					 << setw(10) << f.local
					 << setw(5) << f.ecivil
					 << setw(10) << f.salario << endl;
			funcFile >> f.matricula >> f.nome >> f.cargo >> f.escolaridade >> f.sexo >> f.local >> f.ecivil >> f.salario; // ler pr�ximo registro
		}
		cout << "\n\nSexo dos funcionarios a serem listados (M ou F) Ctrl-Z termina? ";
	}
	return 0;
}

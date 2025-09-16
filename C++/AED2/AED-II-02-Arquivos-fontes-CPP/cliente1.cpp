// cliente1.cpp
#include <iostream>
#include <fstream>
#include <cstdlib>
using namespace std;
#include "cliente.h"

int main()
{
	int i;
	cliente clienteVazio = {0, "", 0.0};
	ofstream outCredito("credito.dat", ios::out);

	if (!outCredito)
	{
		cerr << "Arquivo credito.dat nao pode ser aberto." << endl;
		exit(1);
	}
	for (i = 0; i < 100; i++)
		outCredito.write((const char *)(&clienteVazio), sizeof(cliente));
	return 0;
}

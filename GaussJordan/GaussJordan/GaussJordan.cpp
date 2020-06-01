// GaussJordan.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <iomanip>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <stdio.h>
#include <time.h>
#include <math.h>

using namespace std;

int op;
double jordan[6][6], aux, x[6];
char tecla[256];

void CapturaDatos(int matriz)
{
	system("cls");
	for (int i = 1; i <= matriz; i++)
	{
		cout << "ECUACION No. " << i << "\n\n";
		for (int j = 1; j <= (matriz + 1); j++)
		{
			cout << "Digite el " << j << " coeficiente: ";
			cin >> jordan[i][j];
		}
		cout << "\n";
	}
}
void Matriz(int tamanio)
{
	system("cls");
	CapturaDatos(tamanio);
	//PROCESO
	for (int j = 1; j <= tamanio; j++) {
		for (int i = 1; i <= tamanio; i++) {
			if (i != j) {
				aux = jordan[i][j] / jordan[j][j];
				for (int k = 1; k <= (tamanio + 1); k++) {
					jordan[i][k] = jordan[i][k] - aux * jordan[j][k];
				}
			}
		}
	}
	//IMPRESION
	for (int i = 1; i <= tamanio; i++)
	{
		for (int j = 0; j <= (tamanio + 1); j++)
		{
			cout << jordan[i][j] << "\t";
		}
		cout << "\n";
	}
	cout << "\nLa solucion es:\n";
	for (int i = 1; i <= tamanio; i++) {
		x[i] = jordan[i][tamanio + 1] / jordan[i][i];
		cout << "x" << i << "=" << x[i] << "\t";
	}
	cout << "\nDigite una Tecla y Oprima ENTER para Continuar: ";
	cin >> tecla;
}
void Menu()
{
	system("cls");
	cout << "\t\tMETODO DE GAUSS JORDAN\n\n";
	cout << "1. Ecuacion con 2 Incognitas.\n";
	cout << "2. Ecuacion con 3 Incognitas.\n";
	cout << "3. Ecuacion con 4 Incognitas.\n";
	cout << "4. Salir.\n\n";
	cout << "Digite el Numero de La Opcion que Desea Ejecutar y Oprima ENTER: ";
	cin >> op;
	if (op == 4)
	{
		system("cls");
		cout << "ALUMNO: Aldo Fernando Vilardy Roa.\n\n";
		cout << "CODIGO: 20510278.\n\n";
		cout << "MATERIA: Estructura de Datos.\n\n";
		cout << "CURSO: Ingenieria de Sistemas 4 Semestre (Jornada Diurna).\n\n";
		cout << "GRACIAS POR USAR ESTE PROGRAMA.\n";
		cout << "Oprima Cualquier Tecla.\n\n";
		system("pause");
		exit(0);
	}
	else if (op >= 1 && op <= 3)
	{
		Matriz(op + 1);
	}
	else
	{
		system("cls");
		cout << "El Numero de Opcion Digitado NO Existe.";
		cout << "Oprima Cualquier Tecla.\n\n";
		cout << "\n\nDigite una Tecla y Oprima ENTER para Continuar: ";
		cin >> tecla;
		Menu();
	}
}
void main()
{
	Menu();
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file

// Matrix.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <fstream>
#include <vector>
using namespace std;


int main()
{
	ifstream fin("input.txt");
	ofstream fout("output.txt");
	int n;
	fin >> n;
	int mas = (n*n + n) / 2;
	vector <int> vect(n, 0), rez(n, 0), matrix(mas, 0);
	for (int i = 0; i < n; i++)
		fin >> vect[i];
	for (int i = 0; i < mas; i++)
		fin >> matrix[i];
	for (int i = 0; i < n; i++)
	{
		for (int k = 0; k < i; k++)
			rez[i] += matrix[i + n*k - (k + 1)*k / 2] * vect[i];
		for (int k = (2 * n - i + 1)*i / 2; k < (2 * n - i)*(i + 1) / 2; k++)
			rez[i] += matrix[k] * vect[i];
	}
	for (int i = 0; i < n; i++)
		fout << rez[i] << endl;
	fin.close();
	fout.close();
	return 0;
}

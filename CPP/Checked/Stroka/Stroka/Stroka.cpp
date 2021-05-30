// Stroka.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <fstream>
#include <cstring>
using namespace std;
bool ln(char s)
{
	return (((s < 91) && (s > 64)) || ((s < 123) && (s > 96)) || ((s < 58) && (s > 47))) ? true : false;
}
int main()
{
	char str[300], mod[300];
	FILE * ptrFile = fopen("Ввод.txt", "r");
	fgets(str, 300, ptrFile);
	fclose(ptrFile);
	int i, j = -1;
	for (i = 0; str[i] != 0; i++)
		if (ln(str[i]))
		{
			j++;
			int l;
			char temp[300];
			for (l = 0; str[i] != 0, ln(str[i]); i++, l++)
				temp[l] = str[i];
			if ((l < 5) && (atoi(temp)))
				for (int p = 5 - l; p > 0; p--, j++)
					mod[j] = '0';
			for (int p = 0; p < l; p++, j++)
				mod[j] = temp[p];
			mod[j] = ' ';
			i--;
		}
	ofstream fout("Вывод.txt");
	for (int p = 0; p < j; p++)
		fout << mod[p];
	fout.close();
	system("pause");
    return 0;
}


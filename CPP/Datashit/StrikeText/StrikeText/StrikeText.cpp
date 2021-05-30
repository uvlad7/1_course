// StrikeText.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <Windows.h>
#include <string>
#include <iostream>
using namespace std;


int CopyBoard(string str)
{
	HGLOBAL hglb;
	char *s;
	int ll = str.length() + 1;

	if (!(hglb = GlobalAlloc(GHND, ll))) {
		return 1;
	}
	if (!(s = (char *)GlobalLock(hglb))) {
		return 1;
	}
	strcpy(s, str.c_str());
	GlobalUnlock(hglb);
	if (!OpenClipboard(NULL) || !EmptyClipboard()) {
		GlobalFree(hglb);
		return 1;
	}
	SetClipboardData(CF_TEXT, hglb);
	CloseClipboard();
	return 0;
}

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	string text, striked;
	while (true)
	{
		getline(cin, text);
		striked = "&#0822;";
		for (unsigned int i = 0; i < text.length(); i++)
			striked = striked + text[i] + "&#0822;";
		CopyBoard(striked);
		system("cls");
	}
    return 0;
}


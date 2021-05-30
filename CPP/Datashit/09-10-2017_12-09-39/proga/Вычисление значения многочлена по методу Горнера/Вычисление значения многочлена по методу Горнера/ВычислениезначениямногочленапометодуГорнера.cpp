// ВычислениезначениямногочленапометодуГорнера.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
using namespace std;

int main()
{
	int n, x, a, rezult;
	cout << "Vvedite starshuju stepen' mnogochlena:" << endl;
	cin >> n;
	int *ptr = new int[n + 1];
	for (int i = 0; i < n + 1; i++)
	{
		cout << "Vvedite koefficient pri " << n - i << " stepeni:" << endl;
		cin >> ptr[i];
	}
	cout << "Vvedite znachenie peremennoj x:" << endl;
	cin >> x;
	rezult = ptr[0];
	for (int i = 1; i < n + 1; i++)
	{
		rezult = rezult*x + ptr[i];
	}
	cout << "Znachenie mnogochlena = " << rezult << endl;
	return 0;
}

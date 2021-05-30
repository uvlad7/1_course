// GroundControl.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;
struct rootstate
{
	int instack = 0;
	int fT = 1;
	int fF = 0;
};

int main()
{
	vector <vector <int>> vTable;
	int n;
	ifstream fin("input.txt");
	fin >> n;
	for (int i = 0; i < n; i++)
	{
		int k;
		fin >> k;
		vector<int> vLine(k);
		for (int j = 0; j < k; j++)
			fin >> vLine[j];
		vTable.push_back(vLine);
	}
	vector<rootstate> vState(n);
	stack<int> sDeep;
	sDeep.push(1);
	vState[0].instack = 1;
	while (!sDeep.empty())
	{
		int temp = sDeep.top() - 1;
		int i = 0;
		int k = 0;
		vState[0].instack = 1;
		for(i = 0; i < vTable[temp].size(); i++)
		{
			if (vState[vTable[temp][i] - 1].instack == 0)
			{
				sDeep.push(vTable[temp][i]);
				vState[vTable[temp][i] - 1].instack = 1;
				break;
			}
			if (vState[vTable[temp][i] - 1].instack == 2)
				k = 1;
		}
		if (i == vTable[temp].size())
		{
			if (k == 1)
			{
				int f = 0, t = 1;
				for (int j = 0; j < vTable[temp].size(); j++)
				{
					if (vState[vTable[temp][j] - 1].instack == 2)
					{
						f += vState[vTable[temp][j] - 1].fT;
						t += min(vState[vTable[temp][j] - 1].fT, vState[vTable[temp][j] - 1].fF);
					}
				}
				vState[temp].fF = f;
				vState[temp].fT = t;
			}
			else
			{
				vState[temp].fF = 0;
				vState[temp].fT = 1;
			}
			vState[temp].instack = 2;
			sDeep.pop();
		}
	}
	cout << min(vState[0].fF, vState[0].fT) << endl;
	system("pause");
    return 0;
}


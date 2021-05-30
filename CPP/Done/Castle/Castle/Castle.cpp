// Castle.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <fstream>
#include <iostream>
#include <map>
#include <vector>
#include <iterator>
#include <Windows.h>
using namespace std;

struct point
{
	int walls;
	int iiId;
};
struct ID
{
	int id = 0;
	int square = 1;
};
enum Direction {
	Left = 0, Up, Right, Down
};
bool isWall(point P, Direction D)
{
	return (((1 << D) & P.walls) == 0);
}
class comp
{
public:
	bool operator()(const int &a, const int &b)
	{
		return (a > b);
	}
};

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	vector <ID> vId;
	vector <int> ivId;
	int m, n;
	ifstream fin("input.txt");
	fin >> m >> n;
	vector <vector<point>> castle(m, vector<point>(n));
	for (int i = 0; i < m; i++)
		for (int j = 0; j < n;j++)
			fin >> castle[i][j].walls;
	ID tId;
	tId.id = 1;
	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++)
		{
			if ((!isWall(castle[i][j], Left)) && (!isWall(castle[i][j], Up)))
			{
				vId.push_back(tId);
				tId.id++;
				ivId.push_back(vId.size() - 1);
				castle[i][j].iiId = ivId.size() - 1;
			}
			else
			{
				if ((isWall(castle[i][j], Left)) && (isWall(castle[i][j], Up)))
				{
					if (ivId[castle[i][j - 1].iiId] != ivId[castle[i - 1][j].iiId])
					{
						vId[ivId[castle[i - 1][j].iiId]].square += vId[ivId[castle[i][j - 1].iiId]].square + 1;
						ivId[castle[i][j - 1].iiId] = ivId[castle[i - 1][j].iiId];
					}
					else
						vId[ivId[castle[i - 1][j].iiId]].square ++;
					castle[i][j].iiId = castle[i - 1][j].iiId;
				}
				else
				{
					if (isWall(castle[i][j], Left))
					{
						castle[i][j].iiId = castle[i][j - 1].iiId;
						vId[ivId[castle[i][j - 1].iiId]].square++;
					}
					if (isWall(castle[i][j], Up))
					{
						castle[i][j].iiId = castle[i - 1][j].iiId;
						vId[ivId[castle[i - 1][j].iiId]].square++;
					}
				}
			}
		}
	map <int, int> mRoom; //id, square
	for (unsigned int i = 0; i < ivId.size(); i++)
		mRoom.insert(make_pair(vId[ivId[i]].id, vId[ivId[i]].square));
	cout << "Количество комнат: " << mRoom.size() << endl;
	map <int, int>::iterator itr, max = mRoom.begin();
	multimap <int, int, comp> mmRoom; //square, id
	for (itr = mRoom.begin(); itr != mRoom.end(); advance(itr, 1))
		mmRoom.insert(make_pair(itr->second, itr->first));
	cout << "Максимальная площадь: " << mmRoom.begin()->first << endl;
	if (mmRoom.size() > 1)
	{
		multimap <int, int, comp>::iterator it, jt;
		pair <int, int> p1, p2; //x, y
		int s = 0;
		for (it = mmRoom.begin(); it != mmRoom.end(); advance(it, 1))
		{
			jt = it;
			advance(jt, 1);
			if (s >= it->first + jt->first)
				break;
			for (jt = it, advance(jt, 1); jt != mmRoom.end(); advance(jt, 1))
				for (int i = 0; i < m; i++)
					for (int j = 0; j < n; j++)
						if (vId[ivId[castle[i][j].iiId]].square == it->first)
						{
							if ((i != 0) && (vId[ivId[castle[i - 1][j].iiId]].square == jt->first) && !(isWall(castle[i][j], Up)) && (s < it->first + jt->first))
							{
								p1 = make_pair(i, j);
								p2 = make_pair(i - 1, j);
								s = it->first + jt->first;
								goto next;
							}
							if ((j != 0) && (vId[ivId[castle[i][j - 1].iiId]].square == jt->first) && !(isWall(castle[i][j], Left)) && (s < it->first + jt->first))
							{
								p1 = make_pair(i, j);
								p2 = make_pair(i, j - 1);
								s = it->first + jt->first;
								goto next;
							}
							if ((i != m - 1) && (vId[ivId[castle[i + 1][j].iiId]].square == jt->first) && !(isWall(castle[i][j], Down)) && (s < it->first + jt->first))
							{
								p1 = make_pair(i, j);
								p2 = make_pair(i + 1, j);
								s = it->first + jt->first;
								goto next;
							}
							if ((j != n - 1) && (vId[ivId[castle[i][j + 1].iiId]].square == jt->first) && !(isWall(castle[i][j], Right)) && (s < it->first + jt->first))
							{
								p1 = make_pair(i, j);
								p2 = make_pair(i, j + 1);
								s = it->first + jt->first;
								goto next;
							}
						}
		next:;
		}
		cout << "Разрушить стену между клетками (" << p1.first + 1 << ", " << p1.second + 1 << ") и (" << p2.first + 1 << ", " << p2.second + 1 << ")" << endl;
		cout << "Площадь новой комнаты: " << s << endl;
	}
	else
	{
		cout << "Разрушить стену между клетками (1, 1) и (0, 1)" << endl;
		cout << "Площадь новой комнаты: дофига" << endl;
	}
	system("pause");
    return 0;
}
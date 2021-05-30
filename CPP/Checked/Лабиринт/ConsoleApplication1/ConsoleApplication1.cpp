// ConsoleApplication1.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <vector>
#include <queue>
#include <stack>
#include <fstream>
using namespace std;

ifstream fin("maze.in");
ofstream fout("maze.out");

struct adres
{
	int x, y;
};

struct point
{
	bool enabled = 0;
	bool visited = 0;
	int dist = 1000001;
};

int main()/**сверху, справа, снизу, слева**/
{
	int M, N;
	adres s_adr, f_adr, t_adr, t1_adr;
	fin >> M >> N;
	fin >> s_adr.x >> s_adr.y;
	fin >> f_adr.x >> f_adr.y;
	vector < vector <point> > a(M + 2, vector <point>(N + 2));
	for (int i = 1; i <= M; i++)
		for (int j = 1; j <= N; j++)
			fin >> a[i][j].enabled;
	queue <adres> q;
	a[s_adr.x][s_adr.y].visited = 1;
	a[s_adr.x][s_adr.y].dist = 0;
	q.push(s_adr);
	while (!q.empty())
	{
		t_adr = q.front();
		q.pop();
		t1_adr.x = t_adr.x - 1;
		t1_adr.y = t_adr.y;
		if ((t1_adr.x>0) && (a[t1_adr.x][t1_adr.y].enabled) && (a[t1_adr.x][t1_adr.y].dist > a[t_adr.x][t_adr.y].dist + 1))
		{
			a[t1_adr.x][t1_adr.y].visited = 1;
			a[t1_adr.x][t1_adr.y].dist = a[t_adr.x][t_adr.y].dist + 1;
			q.push(t1_adr);
		}
		t1_adr.x = t_adr.x;
		t1_adr.y = t_adr.y + 1;
		if ((t1_adr.y <= N) && (a[t1_adr.x][t1_adr.y].enabled) && (a[t1_adr.x][t1_adr.y].dist > a[t_adr.x][t_adr.y].dist + 1))
		{
			a[t1_adr.x][t1_adr.y].visited = 1;
			a[t1_adr.x][t1_adr.y].dist = a[t_adr.x][t_adr.y].dist + 1;
			q.push(t1_adr);
		}
		t1_adr.x = t_adr.x + 1;
		t1_adr.y = t_adr.y;
		if ((t1_adr.x <= M) && (a[t1_adr.x][t1_adr.y].enabled) && (a[t1_adr.x][t1_adr.y].dist > a[t_adr.x][t_adr.y].dist + 1))
		{
			a[t1_adr.x][t1_adr.y].visited = 1;
			a[t1_adr.x][t1_adr.y].dist = a[t_adr.x][t_adr.y].dist + 1;
			q.push(t1_adr);
		}
		t1_adr.x = t_adr.x;
		t1_adr.y = t_adr.y - 1;
		if ((t1_adr.y>0) && (a[t1_adr.x][t1_adr.y].enabled) && (a[t1_adr.x][t1_adr.y].dist > a[t_adr.x][t_adr.y].dist + 1))
		{
			a[t1_adr.x][t1_adr.y].visited = 1;
			a[t1_adr.x][t1_adr.y].dist = a[t_adr.x][t_adr.y].dist + 1;
			q.push(t1_adr);
		}
	}
	if (a[f_adr.x][f_adr.y].visited)
	{
		fout << a[f_adr.x][f_adr.y].dist << endl;
		stack <adres> s;
		s.push(f_adr);
		t_adr = f_adr;
		while ((t_adr.x != s_adr.x) || (t_adr.y != s_adr.y))
		{
			if (a[t_adr.x - 1][t_adr.y].dist + 1 == a[t_adr.x][t_adr.y].dist)
			{
				t1_adr.x = t_adr.x - 1;
				t1_adr.y = t_adr.y;
			}
			if (a[t_adr.x][t_adr.y + 1].dist + 1 == a[t_adr.x][t_adr.y].dist)
			{
				t1_adr.x = t_adr.x;
				t1_adr.y = t_adr.y + 1;
			}
			if (a[t_adr.x + 1][t_adr.y].dist + 1 == a[t_adr.x][t_adr.y].dist)
			{
				t1_adr.x = t_adr.x + 1;
				t1_adr.y = t_adr.y;
			}
			if (a[t_adr.x][t_adr.y - 1].dist + 1 == a[t_adr.x][t_adr.y].dist)
			{
				t1_adr.x = t_adr.x;
				t1_adr.y = t_adr.y - 1;
			}
			t_adr = t1_adr;
			s.push(t_adr);
		}
		while (!s.empty())
		{
			fout << s.top().x << " " << s.top().y << endl;
			s.pop();
		}
	}
	else
		fout << "-1";
	return 0;
}

// disabled.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <string>
#include <iostream>
#include <fstream>
#include <deque>
#include <algorithm>

using namespace std;

struct CMan {
	string name;
	bool facility;
	CMan (string _name, bool _facility)
	{
		name = _name;
		facility = _facility;
	}
	CMan() 
	{
		name = "";
		facility = false;
	}
	CMan (CMan *man) 
	{
		name = man -> name ;
		facility = man->facility;
	}
	friend ostream & operator << (ostream &OS, CMan man);
	friend istream & operator >> (istream &IS, CMan& man);
};

ostream & operator << (ostream &OS, CMan man)
{
	OS << man.name << (man.facility ? "1" : "0");
	return OS;
}
istream & operator >> (istream &IS, CMan& man)
{
	IS>> man.name;
	IS>> man.facility;
	return IS;
}

bool U (CMan man)
{
		if (man.facility == false)
			return true;
}
int main()
{
	ifstream ifile ("ifile.txt");
	CMan man;
	deque <CMan> manDeque;
	deque <CMan> :: iterator i;
	deque <CMan> :: iterator it = std::find_if (manDeque.begin(), manDeque.end(), U);
	while (!ifile.eof()) {
		ifile >> man;
		if (man.facility == false)
			manDeque.push_back(man);
		else 
		{
		/*	for ( i = manDeque.begin() ; i!= manDeque.end(); i++)
				if (i->facility == false)
				{
					manDeque.insert(i, &man);
					break;
				}*/
			manDeque.insert(it, &man);
		}
	}
	while (!manDeque.empty())
	{
		cout << manDeque.front() << "\n";
		manDeque.pop_front();
	}
	ifile.close();
	system("pause");
	return 0;
}


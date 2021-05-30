// Ochered.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h" 
#include <string> 
#include <iostream> 
#include <fstream> 
#include <queue>
#include <deque>
#include <iterator>

using namespace std;

class CMan {
public:
	string name;
	bool facility;
	CMan(string name, bool facility)
	{
		this->name = name;
		this->facility = facility;
	}
	CMan() {
		name = "";
		facility = false;
	}
	CMan(CMan *man)
	{
		name = man->name;
		facility = man->facility;
	}
	friend ostream & operator << (ostream &OS, const CMan &man);
	friend istream & operator>> (istream &IS, CMan &man);
};

ostream & operator << (ostream &OS, const CMan &man)
{
	OS << man.name << " " << (man.facility ? "has facility" : "has no facility");
	return OS;
}

istream & operator >> (istream & IS, CMan & man)
{
	IS >> man.name >> man.facility;
	return IS;
}

class CManN : public CMan
{
public:
	int num;
	CManN() {
		name = "";
		facility = false;
		num = 0;
	}
	CManN(CMan &m, int n) : CMan(m) { num = n; }
	friend ostream & operator << (ostream &OS, const CMan &man);
};


ostream & operator << (ostream &OS, const CManN &man)
{
	OS << man.name << " " << (man.facility ? "has facility" : "has no facility");
	return OS;
}

class mycomp
{
public:
	bool operator()(const CManN &a, const CManN &b)
	{
		return (!a.facility && b.facility) || (!(a.facility && !b.facility) && (a.num > b.num));
	}
};

int main()
{
	ifstream ifile("in.txt");
	CMan man;
	int i = 0;
	priority_queue <CManN, vector<CManN>, mycomp> manQueue;
	while (!ifile.eof())
	{
		i++;
		ifile >> man;
		CManN mann(man, i);
		manQueue.push(mann);
	}
	ifile.close();
	while (!manQueue.empty())
	{
		cout << manQueue.top() << endl;
		manQueue.pop();
	}
	system("pause");
	return 0;
}

//int main()
//{
//	ifstream ifile("in.txt");
//	CMan man;
//	deque <CMan> manDeque;
//	deque <CMan> ::iterator i;
//	while (!ifile.eof())
//	{
//		ifile >> man;
//		if (man.facility == false)
//			manDeque.push_back(&man);
//		else
//		{
//			i = manDeque.begin();
//			while (i != manDeque.end() && i->facility)
//				advance(i, 1);
//			manDeque.insert(i, &man);
//		}
//	}
//	ifile.close();
//	while (!manDeque.empty())
//	{
//		cout << manDeque.front() << "\n";
//		manDeque.pop_front();
//	}
//	system("pause");
//	return 0;
//}


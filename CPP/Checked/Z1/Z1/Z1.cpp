// Z1.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
using namespace std;

class man
{
private:
	char gender;
public:
	man(const char g) { gender = g; }
	void setGender(const char g) { gender = g; }
	const char getGender() const { return gender; }
	virtual void print(ostream&) const = 0;
	virtual bool prnt() const = 0;
};

class parent : public man
{
private:
	char *name;
	int ID;
public:
	parent(const char g, const char *nm, int id) : man(g), ID(id) { name = new char[strlen(nm) + 1];strcpy(name, nm); }
	void setName(const char *nm) { name = new char[strlen(nm) + 1];strcpy(name, nm); }
	void setID(int id) { ID = id; }
	const char * getName() { return name; }
	int getID() { return ID; }
	virtual void print(ostream&) const;
	virtual bool prnt() const { return true; }
	~parent() { delete[] name; }
};
void parent::print(ostream &out) const
{
	out << "parent " << getGender() << " " << name << " " << ID;
}

class child : public man
{
private:
	int mum;
	int dad;
public:
	child(const char g, int m, int d) : man(g), mum(m), dad(d) {};
	void setMum(int m) { mum = m; }
	void setDad(int d) { dad = d; }
	const int  getMum() { return mum; }
	const int  getDad() { return dad; }
	virtual void print(ostream&) const;
	virtual bool prnt() const { return false; }
};
void child::print(ostream &out) const
{
	out << "child " << getGender() << " mum: " << mum << " dad: " << dad;
}


int main()
{
	setlocale(LC_ALL, "Russian");
	parent d1('M', "Afsdg", 222);
	parent d2('M', "Bob", 456);
	parent m1('F', "Cilla", 123);
	parent m2('F', "Diana", 243);
	man **visitors = new man*[12];
	visitors[0] = new child('F', 123, 222);
	visitors[1] = new child('M', 123, 222);
	visitors[2] = new child('M', 243, 456);
	visitors[3] = &d1;
	visitors[4] = &d2;
	visitors[5] = &m1;
	visitors[6] = &m2;
	cout << "With two parents:" << endl;
	for (int i = 0; i < 7; i++)
	{
		if (!visitors[i]->prnt())
		{
			child *c = (child*)visitors[i];
			if ((c->getMum() != 0) && (c->getDad() != 0))
			{
				c->print(cout);
				cout << endl;
			}
		}
	}
 	
	man **max = new man*[7];
	int M = 0, col = 0;
	for (int i = 0; i < 7; i++)
		if (visitors[i]->prnt())
		{
			parent *p = (parent*)visitors[i];
			int tM = 0;
			if (visitors[i]->getGender() == 'F')
			{
				for (int j = 0; j < 7; j++)
				{
					if (!visitors[j]->prnt())
					{
						child *c = (child*)visitors[j];
						if (c->getMum() == p->getID())
							tM++;
					}
				}
			}
			else
			{
				for (int j = 0; j < 7; j++)
				{
					if (!visitors[j]->prnt())
					{
						child *c = (child*)visitors[j];
						if (c->getDad() == p->getID())
							tM++;
					}
				}
			}
			if (tM == M)
			{
				max[col] = visitors[i];
				col++;
			}
			if (tM > M)
			{
				col = 1;
				delete[] max;
				max = new man*[7];
				max[0] = visitors[i];
				M = tM;
			}
		}
	cout << "Parents_max_childs:" << endl;
	for (int i = 0; i < col; i++)
	{
		max[i]->print(cout);
		cout << endl;
	}
	system("pause");
    return 0;
}

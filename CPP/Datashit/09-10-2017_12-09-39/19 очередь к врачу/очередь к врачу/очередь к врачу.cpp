// очередь к врачу.cpp: определяет точку входа для консольного приложения.
//



#include "stdafx.h"
#include "Queue.h"

ifstream in("input.txt");


int main()
{
	int first_list=0;//следующая фамилия из списка
	string list[100];//все фамилии из файла
	int p = 0;//количество фамилий в списке
	string famil;
	Queue s1;
	int n = 0;
	int i = 0;
	
	
	
	while (!in.eof())
	{
		in >> famil;
		if (famil != "")
			s1.push(famil);
	}
	
	while (i != 3)
	{
		cout << "Enter the command: " << endl;	
		cin >> i;
		switch (i)
		{
		case 1: cout << "Enter the patient name "; cin >> famil; s1.push(famil); break; 
		case 2: s1.pop(); break;
		case 3: 
			{
				cout << "Doctor went home." << endl;
				in.close();
				ofstream out("input.txt");
				if (s1.empty()){
					cout << "Queue is empty. " << endl;
				}
				while (!s1.empty()){
					cout << s1.watch() << endl;
					out << s1.show();
					if (!s1.empty())
						out << endl;
				}
				break;
			}
		default:
			cout << "Incorrect data" << endl;
			cin >> i;
			break;
		}
	}
	return 0;
}


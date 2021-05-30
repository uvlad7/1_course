//работа со стеками
#include <iostream>
#include <math.h>
using namespace std;

void push(int *&end)
{
	int temp;
	cout<<"Введите элемент стека ";
	cin>>temp;
	*end=temp;
	end++;
}

void pop(int *&end)
{	
		end--;
		cout<<"Последний элемент стека "<<*end<<"\n\n";
}

void main()
{
	setlocale(0,"");
	bool b=0;
	int *end,data[1000],temp;
	end=&data[0];
	while(b==0)
	{
		cout<<"Введите 1 для добавления элемента, 2 для извлечения и 0 для завершения работы\n";
		cin>>temp;
		switch(temp)
		{
			case 1: push(end);
				break;
			case 2: 
				{
					if(end==&data[0])
						cout<<"Стек пуст\n\n";
					else
						pop(end);
				}
				break;
			case 0: b=1;
				break;
		}
	}
	cout<<"\nThe end\n\n";
	system("PAUSE");

}
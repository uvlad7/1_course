//������ �� �������
#include <iostream>
#include <math.h>
using namespace std;

void push(int *&end)
{
	int temp;
	cout<<"������� ������� ����� ";
	cin>>temp;
	*end=temp;
	end++;
}

void pop(int *&end)
{	
		end--;
		cout<<"��������� ������� ����� "<<*end<<"\n\n";
}

void main()
{
	setlocale(0,"");
	bool b=0;
	int *end,data[1000],temp;
	end=&data[0];
	while(b==0)
	{
		cout<<"������� 1 ��� ���������� ��������, 2 ��� ���������� � 0 ��� ���������� ������\n";
		cin>>temp;
		switch(temp)
		{
			case 1: push(end);
				break;
			case 2: 
				{
					if(end==&data[0])
						cout<<"���� ����\n\n";
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
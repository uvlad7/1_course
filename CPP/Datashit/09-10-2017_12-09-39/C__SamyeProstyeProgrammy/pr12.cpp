// Нахождение трёх наибольших элементов массива за один просмотр
#include <iostream>
#include <math.h>
using namespace std;

void main()
{
	setlocale(LC_ALL,".1251");
	int n;
	cout<<"Нахождение трёх максимальных элементов массива.\n";
	cout<<endl<<"Введите количество элементов массива (>3) ";
	cin>>n;
	int *a,i;
	a=new int[n];
	cout<<"Введите массив"<<endl;
	for(i=0;i<n;i++)
		cin>>a[i];
	int m1,m2,m3,t;
	bool temp=0;
	if(a[0]<a[1]&&a[0]<a[2])
	{
		m1=a[0];
		if(a[1]<a[2])
		{m2=a[1]; m3=a[2];}
		else
		{m2=a[2]; m3=a[1];}
	}
	else
		if(a[1]<a[2]&&a[1]<a[0])
		{
			m1=a[1];
			if(a[0]<a[2])
				{m2=a[0]; m3=a[2];}
			else
				{m2=a[2]; m3=a[0];}
		}
		else
		{
			m1=a[2];
			if(a[0]<a[1])
				{m2=a[0]; m3=a[1];}
			else
				{m2=a[1]; m3=a[0];}
		}
	for(i=3;i<n;i++)
	{
		if(a[i]>m3)
		{
			m1=m2;
			m2=m3;
			m3=a[i];
		}
		else
			if(a[i]>m2)
			{
				m1=m2;
				m2=a[i];
			}
			else
				if(a[i]>m1)
					m1=a[i];
	}
	cout<<endl<<"Максимальные элементы: ";
	cout<<m1<<", ";
	cout<<m2<<", ";
	cout<<m3<<endl<<"\n";
	delete []a;
	system("PAUSE");
}
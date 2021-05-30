//Умножение матрицы на вектор + чтение данных из файла и динамическая матрица
#include <iostream>
#include <math.h>
#include <fstream>
using namespace std;

void main()
{
	setlocale(0,"");
	int **a,*b,*c,n,m,i,j;
	cout<<"Умножение матрицы на вектор"<<endl<<endl;
	ifstream f("data.txt");
	f>>n;
	f>>m;
	a=new int*[n];
	for(i=0;i<n;i++)
		a[i]=new int[m];
	b=new int[m];
	cout<<"Матрица:"<<endl;
	for(i=0;i<n;i++)
	{
		for(j=0;j<m;j++)
		{
			f>>a[i][j];
			cout<<a[i][j]<<" ";
		}
		cout<<endl;
	}
	cout<<"\nВектор:"<<endl;
	for(i=0;i<m;i++)
	{
		f>>b[i];
		cout<<b[i]<<" ";
	}
	c=new int[n];
	for(i=0;i<n;i++)
		c[i]=0;
	for(i=0;i<n;i++)
		for(j=0;j<m;j++)
			c[i]+=a[i][j]*b[j];
	cout<<endl<<"\nОтвет: ";
	for(i=0;i<n;i++)
		cout<<c[i]<<" ";
	cout<<endl<<endl;
	for(i=0;i<n;i++)
		delete []a[i];
	delete []a;
	system("PAUSE");
}
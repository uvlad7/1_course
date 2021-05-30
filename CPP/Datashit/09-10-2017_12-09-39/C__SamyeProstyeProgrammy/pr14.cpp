//создание матрицы в динамической пам€ти
#include <iostream>
#include <math.h>
using namespace std;

void main()
{
	setlocale(LC_ALL,".1251");
	int n,m,i,j,**a;
	cout<<"—оздание в динамической пам€ти матрицы"<<endl<<endl;
	cout<<"¬ведите количество строк ";
	cin>>n;
	cout<<"¬ведите количество столбцов ";
	cin>>m;
	a=new int*[n];
	for(i=0;i<n;i++)
		a[i]=new int[m];
	for(i=0;i<n;i++)
		for(j=0;j<m;j++)
			a[i][j]=i*m+j+1;
	cout<<endl<<endl;
	for(i=0;i<n;i++)
	{
		for(j=0;j<m;j++)
			cout<<a[i][j]<<" ";
		cout<<endl;
	}
	cout<<endl;
	for(i=0;i<n;i++)
		delete[]a[i];
	delete[]a;
	system("PAUSE");
}


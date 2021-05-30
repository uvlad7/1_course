// Составление упорядоченного массива из двух упорядоченных массивов
#include <iostream>
#include <math.h>
using namespace std;

void main()
{
	setlocale(LC_ALL,".1251");
	cout<<"Составление упорядоченного массива из двух упорядоченных массивов"<<endl<<endl;
	int n,m;
	cout<<"Количество элементов первого массива ";
	cin>>n;
	cout<<endl<<"Количество элементов второго массива ";
	cin>>m;
	int *a,*b,*c,k=m+n,i,j;
	a=new int[n];
	b=new int[m];
	c=new int[k];
	cout<<endl<<"Введите первый упорядоченный массив"<<endl;
	for(i=0;i<n;i++)
		cin>>a[i];
	cout<<endl<<"Введите второй упорядоченный массив"<<endl;
	for(i=0;i<m;i++)
		cin>>b[i];
	//вы атакованы, азаза)))00
	i=0; j=0; k=0;
	while(i<n&&j<m)
		if(a[i]<b[j])
		{
			c[k]=a[i];
			k++; i++;
		}
		else
		{
			c[k]=b[j];
			k++; j++;
		}
	while(j<m)
	{
		c[k]=b[j];
		k++; j++;
	}
	while(i<n)
	{
		c[k]=a[i];
		k++; i++;
	}
	cout<<"/nОтвет:"<<endl;
	for(i=0;i<k;i++)
		cout<<c[i]<<" ";
	cout<<endl;
	delete []a;
	delete []b;
	delete []c;
	system("PAUSE");
}
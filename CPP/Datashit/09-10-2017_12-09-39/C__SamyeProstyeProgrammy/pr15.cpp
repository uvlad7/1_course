//Треугольник Паскаля
#include <iostream>
using namespace std;

void main()
{
	setlocale(0,"");
	int **a,n,i,k;
	cout<<"Треугольник Паскаля\n\nВведите степень ";
	cin>>n;
	n+=1;
	a=new int*[n];
	for(i=1;i<=n;i++)
		a[i-1]=new int[i];
	for(i=0;i<n;i++)
		a[i][0]=1;
	i=1;
	while(i<n)
	{
		a[i][i]=1;
		i++;
	}
	for(k=2;k<n;k++)
		for(i=1;i<k;i++)
			a[k][i]=a[k-1][i-1]+a[k-1][i];
	for(k=0;k<n;k++)
	{
		for(i=0;i<=k;i++)
			cout<<a[k][i]<<" ";
		cout<<endl;
	}
	for(i=0;i<n;i++)
		delete[]a[i];
	delete[]a;
	cout<<endl;
	system("PAUSE");
}

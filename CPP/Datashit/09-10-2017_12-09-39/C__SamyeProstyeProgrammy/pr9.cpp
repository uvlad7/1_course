// Решето Эратосфена
#include <iostream>
#include <math.h>
using namespace std;

void main()
{
	setlocale(LC_ALL,".1251");
	cout<<"Решето Эратосфена"<<endl<<endl;
	int n;
	cout<<"Число до которого будем искать ";
	cin>>n;
	int *a,i,j;
	a=new int[n];
	for(i=1;i<=n;i++)
		a[i-1]=i;
	for(i=1;i<n;i++)
		if(a[i]!=0)
			for(j=i+a[i];j<n;j+=a[i])
				a[j]=0;
	cout<<endl<<"Ответ:"<<endl;
	for(i=0;i<n;i++)
		if(a[i]!=0)
			cout<<a[i]<<" ";
	cout<<endl<<endl;
	delete []a;
	system("PAUSE");
}

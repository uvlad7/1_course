//Спираль Улама
#include <iostream>
using namespace std;

void main()
{
	setlocale(LC_ALL,".1251");
	int i,j,n,k=1,p=1,**a,count=1,t;
	cout<<"Спираль Улама.\nВведите размер спирали ";
	cin>>n;
	a=new int*[n];
	for(i=0;i<n;i++)
		a[i]=new int[n];
	if(n%2==0)
	{
		i=n/2-1;
		j=n/2-1;
	}
	else
	{
		i=n/2;
		j=n/2;
	}
	while(count<2*n)
	{
		t=0;
		switch(count%4)
		{
		case 1: do {a[i][j]=k;k++;t++;j++;} while(t<p);
			break;
		case 2: { do {a[i][j]=k;k++;t++;i++;} while(t<p); p++; }
			break;
		case 3: do {a[i][j]=k;k++;t++;j--;} while(t<p);
			break;
		case 0: { do {a[i][j]=k;k++;t++;i--;} while(t<p); p++; }
			break;
		}
		count++;
	}
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
			if(a[i][j]<10)
				cout<<" "<<a[i][j]<<" ";
			else
				cout<<a[i][j]<<" ";
		cout<<endl;
	}
	for(i=0;i<n;i++)
		delete[]a[i];
	delete[]a;
	system("PAUSE");
}
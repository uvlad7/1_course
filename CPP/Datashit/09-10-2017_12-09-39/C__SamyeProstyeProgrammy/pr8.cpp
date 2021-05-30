//поиск простых чисел по уже найденым (по массиву простых чисел)
#include <iostream>
#include <math.h>
#include <conio.h>
using namespace std;

int main()
{
	int n,i=0,k=3,temp=1;
	int *a;
	bool c=0;
	cout<<"input maximum = ";
	cin>>n;
	a=new int [n];
	a[0]=2;
	while(k<=n)
	{
		while(i<temp&&a[i]<int(sqrt(double(n))))
		{
			if (k%a[i]==0)
			{
				c=1;
				break;
			}
			i++;
		}
		if (c==0)
		{ 
			i=temp+1;
			a[i]=k; 
			cout<<k<<" "; 
			k++; 
			temp++;
			i=0;
		}
		else 
		{
			k++;
			c=0;
			i=0;
		}
	}
	cout<<endl;
	system("PAUSE");
}

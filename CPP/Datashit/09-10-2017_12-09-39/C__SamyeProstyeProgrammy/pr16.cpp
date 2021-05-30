//Поиск простых чисел (делителями)
#include <iostream>
#include <math.h>
using namespace std;

void main()
{
	setlocale(LC_ALL,".1251");
	int n,i,j;
	bool temp;
	cout<<"Поиск простых чисел"<<endl<<endl;
	cout<<"Введите число до которого нужно искать ";
	cin>>n;
	for(i=3;i<n;i++)
	{
		temp=0;	
		int k =(int)sqrt((double)i)+1; 
		for(j=2;j<k;j++)
		{
			if(i%j==0)
			{
				temp=1;
				break;
			}
		}
		if(temp==0 && k>2)
			cout<<i<<" ";
	}
	cout<<endl<<endl;
	system("PAUSE");


}
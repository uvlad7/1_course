// ���������� ���������
#include <iostream>
#include <math.h>
using namespace std;

void main()
{
	setlocale(LC_ALL,".1251");
	int n;
	cout<<"���������� ���������"<<endl<<endl;
	cout<<"������� ������ ������� ";
	cin>>n;
	int *a,i,temp,j;
	a=new int[n];
	cout<<"������� ������"<<endl;
	for(i=0;i<n;i++)
		cin>>a[i];
	for(j=0;j<n-1;j++)
		for(i=0;i<n-j-1;i++)
			if(a[i]>a[i+1])
			{
				temp=a[i];
				a[i]=a[i+1];
				a[i+1]=temp;
			}
			cout<<endl<<"�����:"<<endl;
	for(i=0;i<n;i++)
		cout<<a[i]<<" ";
	cout<<endl<<endl;
	system("PAUSE");
}
// ����������� �������������� ������� �� ���� ������������� ��������
#include <iostream>
#include <math.h>
using namespace std;

void main()
{
	setlocale(LC_ALL,".1251");
	cout<<"����������� �������������� ������� �� ���� ������������� ��������"<<endl<<endl;
	int n,m;
	cout<<"���������� ��������� ������� ������� ";
	cin>>n;
	cout<<endl<<"���������� ��������� ������� ������� ";
	cin>>m;
	int *a,*b,*c,k=m+n,i,j;
	a=new int[n];
	b=new int[m];
	c=new int[k];
	cout<<endl<<"������� ������ ������������� ������"<<endl;
	for(i=0;i<n;i++)
		cin>>a[i];
	cout<<endl<<"������� ������ ������������� ������"<<endl;
	for(i=0;i<m;i++)
		cin>>b[i];
	//�� ���������, �����)))00
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
	cout<<"/n�����:"<<endl;
	for(i=0;i<k;i++)
		cout<<c[i]<<" ";
	cout<<endl;
	delete []a;
	delete []b;
	delete []c;
	system("PAUSE");
}
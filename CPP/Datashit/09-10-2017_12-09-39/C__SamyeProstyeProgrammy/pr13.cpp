//��������� ������� �� ������
#include <iostream>
#include <math.h>
using namespace std;

void main()
{
	setlocale(LC_ALL,".1251");
	int **a,*b,*c,n,m,i,j;
	cout<<"��������� ������� �� ������"<<endl<<endl;
	cout<<"������� ���������� ����� ";
	cin>>n;
	cout<<endl<<"������� ���������� �������� ";
	cin>>m;
	a=new int*[n];
	for(i=0;i<n;i++)
		a[i]=new int[m];
	b=new int[m];
	cout<<endl<<"������� �������"<<endl;
	for(i=0;i<n;i++)
		for(j=0;j<m;j++)
			cin>>a[i][j];
	cout<<endl<<endl<<"������� ������ ������ "<<m<<endl;
	for(i=0;i<m;i++)
		cin>>b[i];
	c=new int[n];
	for(i=0;i<n;i++)
		c[i]=0;
	for(i=0;i<n;i++)
		for(j=0;j<m;j++)
			c[i]+=a[i][j]*b[j];
	cout<<endl<<"�����: ";
	for(i=0;i<n;i++)
		cout<<c[i]<<" ";
	cout<<endl<<endl;
	for(i=0;i<n;i++)
		delete []a[i];
	delete []a;

	system("PAUSE");
}
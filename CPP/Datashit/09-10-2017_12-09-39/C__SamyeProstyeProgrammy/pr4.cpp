//���������� ��������� ��������� � ������� (������ 1)
#include <iostream>
using namespace std;

void main()
{
	setlocale(0,"");
	int n,i,*a,count=1,j,ras=1;
	cout<<"���������� ��������� ��������� ������� (������ 1)"<<endl;
	cout<<"\n������� ���������� ��������� ������� ";
	cin>>n;
	a=new int[n];
	cout<<"������� ������: ";
	for(i=0;i<n;i++)
		cin>>a[i];
	for(i=1;i<n;i++)
		if(a[i]==a[0])
			count++;
	cout<<endl<<endl<<a[0]<<" - "<<count<<" ��."<<endl;
	count=1;
	for(i=1;i<n;i++)
	{
		if(a[i]!=a[0])
			for(j=i+1;j<n;j++)
				if(a[j]==a[i])
				{
					count++;
					a[j]=a[0];
				}
		if(count!=1||a[i]!=a[0])
		{
			cout<<a[i]<<" - "<<count<<" ��."<<endl;
			ras++;
		}
		count=1;
	}
	cout<<"\n\n����� ��������� ���������: "<<ras<<" ��.\n\n";
	delete[]a;
	system("PAUSE");
}
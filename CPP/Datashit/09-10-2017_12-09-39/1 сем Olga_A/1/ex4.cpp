#include <iostream>
using namespace std;
int main()
{
	int n;
	cin>>n;
	int m[3];
	int *a=new int[n];
	for(int i=0;i<n;i++)
		cin>>a[i];
	m[0]=a[1];
	for(int i=0;i<n;i++)
		if (a[i]<m[0])
			m[0]=a[i];
	m[2]=m[1]=m[0];
	for (int i=0;i<n;i++)
		if (a[i]>m[0])
		{
			m[2]=m[1];
			m[1]=m[0];
			m[0]=a[i];
		}
		else
			if (a[i]>m[1])
			{
				m[2]=m[1];
				m[1]=a[i];
			}
			else if (a[i]>m[2])
				m[2]=a[i];

 cout<<m[0]<<" "<<m[1]<<" "<<m[2];
 cin>>n;
return 0;
}
#include <iostream>
using namespace std;
int main()
{
	int n,m=0,k,l,s;
	cin>>n;
	int *vek =  new int[n];
	for (int i=0;i<n;i++)
		cin>>vek[i];
	int *res= new int [n];
	for(int i=1;i<=n;i++)
		m=m+n-i+1;
	int *mat= new int[m];
	for (int i=0;i<m;i++)
		mat[i]=i+1;
	for (int i=0;i<n;i++)
	{
		s=0;
		res[i]=mat[i]*vek[s++];

		k=n-1;
		l=i;
		for (int j=0;j<i;j++)
		{
			l+=k;
			res[i]+=mat[l]*vek[s++];
			k--;
		}
		l++;
		for(int j=0;j<n-i-1;j++)
			res[i]+=mat[l++]*vek[s++];
	}
	for (int i=0;i<n;i++)
		cout<<res[i]<<" ";
	return 0;

}
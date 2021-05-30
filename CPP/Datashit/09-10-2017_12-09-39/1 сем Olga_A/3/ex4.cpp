#include <iostream>
#include <iomanip>
using namespace std;
int main()
{
	int n,m,min,maxmin,max,minmax,i,j;
	cin>>n>>m;
	int **mas=new int *[n];
	for (i=0; i<n; i++)
		mas[i]=new int[n];
	for (i=0;i<n;i++)
		for (j=0;j<m;j++)
			cin>>mas[i][j];
	max=min=mas[0][0];
	for ( i=1; i<m; i++)
	{	if (mas[0][i]<min)
			min=mas[0][i];
     	if (mas[i][0]>max)
			max=mas[i][0];}
	maxmin=min;
	minmax=max;
	for( i=1;i<n;i++)
	{	min=mas[i][0];
		for ( j=1;j<m;j++)
		{	if (mas[i][j]<min)
				min=mas[i][j];
		    if (mas[j][i]>max)
				max=mas[j][i];
		}
		if (min>maxmin)
				maxmin=min;
		if (max<minmax)
				minmax=max;
	}
	if (maxmin==minmax)
		cout<<"sedlivaya tochka "<<maxmin;
	else
		cout<<"net sedlovoy tochki";
	cin>>n;

return 0;
}
#include <iostream>
using namespace std;
int main()
{
int n,m;
cin>>n>>m;
int * mas1 = new int[n];
int * mas2 = new int[m];

cout<<"vvedite massiv 1: ";
int i=0,j=0,k=0;
for (i ;i<n; i++)
cin>>mas1[i];
cout<<"vvedite massiv 2: ";
for (j ;j<m;j++)
cin>>mas2[j];
i=0;
j=0;
k=0;
int * mas = new int[n+m];
while((i<n)&&(j<m))
 if (mas1[i]<=mas2[j])
 	 mas[k++]=mas1[i++];
 else
	 mas[k++]=mas2[j++];
 while(i<n)
  	 mas[k++]=mas1[i++];
 while(j<m)
  	 mas[k++]=mas2[j++];
for (i= 0; i<n+m; i++)
cout<<mas[i]<<" ";

cout<<endl;
cin>>n;
return 0;
}

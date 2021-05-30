#include <iostream>
#include <math.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int * mas = new int[n];
   for (int i=0;i<n-1;i++)
   { mas[i]=i+2;}
   int k=0;
   while (k<n-1)
   {if (mas[k]!=0) 
     for (int j=k+k+2;j<n-1;j=j+k+2)
		 mas[j]=0;
   k++;
   }
   for (int i=0;i<n-1;i++)
	    if (mas[i]!=0)
			cout<<mas[i]<<" ";
   //cout<<endl<<(int) 'A';
   cin>>n;
return 0;
}
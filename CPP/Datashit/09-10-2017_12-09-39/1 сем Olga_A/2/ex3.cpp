#include <iostream>
#include <iomanip>
using namespace std;
int main()
{
     int n,m,k;
     cin>>n;
	 m=n+1;
 int mas[6][6];
     for(int i=1;i<m;i++)
          for(int j=1;j<m;j++)
               mas[i][j]=0;
	 int i,j=n/2+1;
	 i=n/2;
	 k=2;
	 mas[i][j]=1;
	 while (k<n*n+1)
	 {
		i--;
		if (i<1)
	        i=n;
		j++;
	     if (j>n)
		     j=1;
		 while (mas[i][j]!=0)
		 {i--;
		 if (i<1)i=n;
		 j--;
		 if(j<1) j=n;}
		 
		 mas[i][j]=k;
		 k++;
	 }
		    

     for(int i=1;i<m;i++)
     {
          for(int j=1;j<m;j++)
          {
               cout<<setw(4)<<mas[i][j];
          }
          cout<<endl;
     }

cin>>n;
return 0;
}
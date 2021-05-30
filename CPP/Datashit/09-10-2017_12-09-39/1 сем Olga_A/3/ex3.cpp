#include <iostream>
#include <iomanip>
using namespace std;
int main()
{
     int n,m,j,k;
     cin>>n;
int **mas = new int *[n];
 for (int i = 0 ;i<n; i++)
mas[i] = new int[n];

     for(int i=0;i<n;i++)
          for(j=0;j<n;j++)
                 mas[i][j]=0;
     if (n%2==1)
	 {m=n/2;
	 j=n/2;}
	 else {
	 m=n/2-1;
	 j=n/2-1;
	 }
     mas[m][j]=1;
     k=2;
    int x=1;
   while (k<=n*n)
  {
          for (int s=1;((s<=x));s++)
          mas[m][++j]=k++;
          for (int s=1;((s<=x&&k<=n*n));s++)
               mas[++m][j]=k++;
          x++;
          for (int s=1;((s<=x&&k<=n*n));s++)
               mas[m][--j]=k++;
          for (int s=1;((s<=x&&k<=n*n));s++)
               mas[--m][j]=k++;
          x++;
     }

     for(int i=0;i<n;i++)
     {
          for(int j=0;j<n;j++)
          {
               cout<<setw(4)<<mas[i][j];
          }
          cout<<endl;
     }

cin>>n;
return 0;
}
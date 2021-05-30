#include <iostream>
#include <iomanip>
using namespace std;
int main()
{
	int n;
	cin>>n;
	n=n+1;
	int **mas=new int*[n];
	for (int i = 0 ;i<n; i++)
		mas[i] = new int[n];
	for (int i=0;i<n;i++)
		for (int j=0;j<n;j++)
			mas[i][j]=0;
	for (int i=0;i<n;i++)
		mas[i][0]=mas[i][i]=1;
	for (int i=2;i<n;i++)
		for (int j=1;j<i;j++)
			mas[i][j]=mas[i-1][j]+mas[i-1][j-1];
	
	for(int i=0;i<n;i++)
     {
          for(int j=0;j<=i;j++)
          {
               cout<<setw(7)<<mas[i][j];
          }
          cout<<endl;
     }

cin>>n;
return 0;

}
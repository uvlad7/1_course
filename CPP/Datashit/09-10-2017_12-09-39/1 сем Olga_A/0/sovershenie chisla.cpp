# include <iostream>
using namespace std;
void main()
{
    int n1,n2,s;
	cout<<"vvedite granici";
	cin>>n1>>n2;
	for(int j=n1; j<=n2;j++)
	{s=0;
	 for( int i=1; i<=j/2;i++)
	  {if (j%i==0) s=s+i;
      }
	 if (s==j)
	 cout<<j<<" ";

 }
	cin>>n1;
return;
}
#include <iostream>
using namespace std;
extern "C" int __fastcall Sum(int,int,int&,int);
int main()
{const int m=3;
int a[]={1,2,3},s=0,c,b;
 /*cout<<"vvedite massiv:"<<endl;
 for(int i=0;i<m;i++)
	 cin>>a[i];*/
 cout<<"vvedite c i b, c<b:"<<endl;
	 cin>>c>>b;

	
	cout<<"summa= "<<Sum(c,b,a,m)<<endl;
return 0;
}
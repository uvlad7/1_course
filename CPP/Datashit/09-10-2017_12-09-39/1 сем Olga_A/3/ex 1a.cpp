#include <iostream>
using namespace std;
void sw(int x,int y)
{
	x=x+y;
	y=x-y;
	x=x-y;
}
int main()
{
 int a,b;
cin>>a>>b;
sw(a,b);
cout<<a<<" "<<b;
cin>>b;
return 0;
}
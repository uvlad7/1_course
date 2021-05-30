# include <iostream>
using namespace std;
void main()
{
int n,n1,s;
cout<<"vvedite chislo";
cin>>n;
_asm
{
	mov al,n
}
s=0;
n1=n;
while( n>0)
{s=s*10+n%10;
 n=n/10;
}
if (n1==s)
 cout<<"palindrom";
else cout<<"net";
cin>>n;
return;
}
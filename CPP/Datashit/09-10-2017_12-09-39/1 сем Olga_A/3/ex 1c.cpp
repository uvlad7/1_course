#include <iostream>
using namespace std;

void change(int * a, int * b)
{
int t = *a;
*a = *b;
*b = t;
}

int main()
{
int a,b;
cin>>a>>b;
change(&a, &b);
cout<<a<<" "<<b<<endl;
cin>>b;
return 0;
}

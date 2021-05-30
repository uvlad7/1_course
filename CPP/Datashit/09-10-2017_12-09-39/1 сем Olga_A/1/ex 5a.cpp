#include <iostream>
using namespace std;
int main()
{
int n,m;
cin>>n>>m;
int * mas1 = new int[n];
int * mas2 = new int[m];

cout<<"vvedite massiv 1: ";
for (int i = 0 ;i<n; i++)
cin>>mas1[i];
cout<<"vvedite massiv 2: ";
for (int j = 0 ;j<m;j++)
cin>>mas2[j];

int * mas = new int[n+m];
for (int p = 0, q = 0, k = 0; p<n||q<m;k++ )
{
if(p<n&&q<m)
{
if(mas1[p]>mas2[q])
{
mas[k] = mas2[q];
q++;
}
else
{
mas[k] = mas1[p];
p++;
}
}
else
{
if(p<n)
{
mas[k] = mas1[p];
p++;
}
else if(q<m)
{
mas[k] = mas2[q];
q++;
}

}
}

for (int a = 0; a<n+m; a++)
cout<<mas[a]<<" ";

cout<<endl;
cin>>n;
return 0;
}

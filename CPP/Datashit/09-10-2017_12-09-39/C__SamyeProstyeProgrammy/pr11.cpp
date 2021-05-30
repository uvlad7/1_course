// Вывод на экран рисунка из звёздочек
#include <iostream>
using namespace std;

int main()
{
     int n,j,i;
     cout<<"input n=";
     cin>>n;
     cout<<endl;
     for(j=0;j<n;j++)
      {
       for(i=0;i<n-j;i++)
         cout<<"*";
       for(i=0;i<2*j;i++)
         cout<<" ";
       for(i=0;i<n-j;i++)
         cout<<"*";
       cout<<endl;
      }
       for(j=n;j>0;j--)
      {
       for(i=0;i<n-j+1;i++)
         cout<<"*";
       for(i=0;i<2*j-2;i++)
         cout<<" ";
       for(i=0;i<n-j+1;i++)
         cout<<"*";
       cout<<endl;
      }
     cout<<endl;
     system("PAUSE");
}  

// заполнение нечетного магического квадрата

#include <iostream>
#include <stdio.h>
#include <conio.h>
#include <math.h>
using namespace std;

int main()
{
    setlocale(LC_CTYPE,"Russian");
    cout<<"Заполнение нечетного магического квадрата"<<endl<<endl;
    int i,j,num,n;
    bool temp=0,t=0;;
    cout<<"input n=";
    cin>>n;
    cout<<endl;
    int a[n][n];
    for(i=0;i<n;i++)
     for(j=0;j<n;j++)
      a[i][j]=0;
    i=n/2-1;
    j=n/2;
    a[i][j]=1;
    for(num=2;num<=n*n;num++)
       {  
         if(t==0)
          {
            i--; 
            j++;
          }
         t=0;
         while(temp==0)
          {
               if(i<0)
                i=n-1;
               if(j<0&&i>=0&&i<n)
                j=n-1;
               if(j>=n&&i>=0&&i<n)
                j=0;  
               if(i>=0&&i<n&&j>=0&&j<n)
                temp=1;
          }
         temp=0;
         if(a[i][j]==0)
                a[i][j]=num;
         else
            {
                t=1;
                i--;
                j--;
                num--;
            }          
       }
       
    for(i=0;i<n;i++)
      {
        for(j=0;j<n;j++)
          if(a[i][j]<10)
              cout<<" "<<a[i][j]<<"  ";
          else
              cout<<a[i][j]<<"  ";
           cout<<endl;
      }
    cout<<endl<<"The end";       
    while(!kbhit()) {}                        
}

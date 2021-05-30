// Решение квадратных уравнений
#include <iostream>
#include <stdio.h>
#include <conio.h>
#include <math.h>
using namespace std;

int main()
{
     double a,b,c,x1,x2,d;
     cout<<"input a=";
     cin>>a;
     cout<<"input b=";
     cin>>b;
     cout<<"input c=";
     cin>>c;
     if(a==0)
       {
          x1=(0-c)/b;
          cout<<"x="<<x1<<endl;
       }
     else
       {
           d=b*b-4*a*c;
           if(d<0)
           cout<<"no answer"<<endl;
           if(d==0)
            {
               x1=(0-b)/(2*a);
               cout<<"x="<<x1<<endl;
            }
           if(d>0)
            {
               x1=(0-b-sqrt(d))/(2*a);
               x2=(0-b+sqrt(d))/(2*a);
               cout<<"x1="<<x1<<endl;
               cout<<"x2="<<x2<<endl;
            }
       }
      _getch() ;   
}

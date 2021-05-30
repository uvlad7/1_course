// Нахождение седловой точки матрицы
#include <iostream>
#include <math.h>
#include <conio.h>
using namespace std;

int main()
{
    setlocale(LC_ALL,".1251");
    int n,m,i,j;
    cout<<"Седловая точка матрицы"<<endl<<endl;
    cout<<"Введите размер матрицы n= ";
    cin>>n;
    cout<<"Введите размер матрицы m= ";
    cin>>m;
    cout<<endl;
    int a[n][m],min1,max1,min2,max2;
    for(i=0;i<n;i++)
      for(j=0;j<m;j++)
        cin>>a[i][j];
        
      min1=a[0][0];
      i=0;
      for(j=1;j<m;j++)
        {min1=(a[i][j]<min1)?a[i][j]:min1; cout<<"min1="<<min1<<endl;}
      max1=min1;
      
      for(i=1;i<n;i++)
        {
        min1=a[i][0];              
        for(j=1;j<m;j++)
           {min1=(a[i][j]<min1)?a[i][j]:min1; cout<<"min1="<<min1<<endl;}
        {max1=(max1<min1)?min1:max1; cout<<"max1="<<max1<<endl;}
        }

      max2=a[0][0];
      j=0;
      for(i=1;i<n;i++)
        {max2=(a[i][j]>max2)?a[i][j]:max2; cout<<"max2="<<max2<<endl;}
      {min2=max2; cout<<"min2="<<min2<<endl;} 
            
      for(j=1;j<m;j++)
        {
        min1=a[0][j];              
        for(i=1;i<n;i++)
           max2=(a[i][j]>max2)?a[i][j]:max2;
        min2=(max2<min2)?max2:min2;
        }  
     cout<<endl<<max1<<endl;
     cout<<min2<<endl;                        
    system("PAUSE");
}

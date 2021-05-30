//Нахождение максимальной длины последовательности возрастающих элементов

#include <iostream>
#include <math.h>
using namespace std;

int main()
{
    int count=1,n,maxi=1;
    setlocale(0,"");
    cout<<"Нахождение максимальной длины последовательности возрастающих элементов"<<endl<<endl;
    cout<<"input n= ";
    cin>>n;
    int *a,i,*b,max=0,imax=0;
	a=new int[n];
	b=new int[n];
    for(i=0;i<n;i++)
      cin>>a[i];
	b[0]=1;
    for(i=1;i<n;i++)
      {
      if(a[i]>a[i-1])
        b[i]=b[i-1]+1;
      else
		b[i]=1; 
      } 
	for(i=0;i<n;i++)
		if(b[i]>maxi)
		{
			maxi=b[i];
			imax=i;
		}
    cout<<"Максимальная длина элементов равна "<<maxi<<endl;
	for(i=imax-maxi+1;i<=imax;i++)
		cout<<a[i]<<" ";
    cout<<endl<<"The end"<<endl<<endl;
	delete[]a;
	delete[]b;
    system("PAUSE");             
}

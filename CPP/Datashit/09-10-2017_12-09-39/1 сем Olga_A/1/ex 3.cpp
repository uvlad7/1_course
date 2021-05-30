#include <iostream>// работает нормально при и начальном равном 112. при меньших не работает
using namespace std;
int main()
{  int s,n,k,p,h,l;
   cin>>n;
   int * m = new int[n];
   for (int i=111;i<=n;i++)
   {
	   l=-1;
	   k=i;
	   while (k>0) 
	   {   m[++l]=k%10;
     	   k=k/10;
	   }
	  s=0;
	   h=1;
	  while(s<i)
	   { s=0;
	   	     for (int a=0;a<=l;a++)
		 {   p=1;
			 for(int j=1;j<=h;j++) 
				p=p*m[a];
			 s=s+p;
		 }
		 h++;
	   }
	if (i==s)
		   cout<<i<<" ";
   } cin>>n;
return 0;
}
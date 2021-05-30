#include <iostream>
#include<math.h>
using namespace std;
float func(float a){
	return a*a;
}


void integral(int a,int b,double eps)
{
	int n=1;
	double x,step;
	double Int_Old,Int_New;
	Int_Old=0;
	Int_New=(func(a)+func(b))*(b-a)/2;
	
	
	while(eps<fabs(Int_New-Int_Old))
	{
		Int_Old=Int_New;
		n=n*2;
		Int_New=(func(a)+func(b))/2;
		step=(b-a)/n;
		x=a+step;
		while(x<b)
		{
			Int_New=Int_New+func(x);
			x+=step;
		}
		Int_New=Int_New*(b-a)/n;
	}

}
int main()
{
	int k,p;
	double q;
	cin>>k>>p>>q;
	integral(k,p,q);
}

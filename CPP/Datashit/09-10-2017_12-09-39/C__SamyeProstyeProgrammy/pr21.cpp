// Вычисление синуса с точностью Е
#include <iostream>
using namespace std;

void main()
{
	setlocale(LC_ALL,".1251");
	int i=2;
	double x,x1,e,d,ans;
	cout<<"Нахождение синуса с определенной точностью.\nВведите х(в градусах) = ";
	cin>>x;
	cout<<"\nВведите точность с которой необходимо посчитать ";
	cin>>e;
	x1=x*3.14159/180;
	d=x1;
	ans=d;
	do
	{
		d*=((-1)*x1*x1)/(i*(i+1));
		ans+=d;
		i+=2;
	}
	while(d>e ||d<(-e));
	if(ans>0)
		ans=int((ans+(0.5*e))/e)*e;
	if(ans<0)
		ans=int((ans-(0.5*e))/e)*e;
	cout<<"\nsin("<<x<<") = "<<ans<<endl;
	system("PAUSE");
}
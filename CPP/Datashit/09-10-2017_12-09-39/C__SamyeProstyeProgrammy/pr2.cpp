#include <iostream>
#include <math.h>
using namespace std;

// Работа с полиномом
void main()
{
	setlocale(LC_ALL,".1251");
	int n;
	cout<<"Введите старшую степень полинома ";
	cin>>n;
	int *a,i,x,znat;
	a=new int[n+1];
	for(i=n;i>=0;i--)
	{
		cout<<endl<<"Введите коофициент при x^"<<i<<" ";
		cin>>a[i];
	}
	cout<<endl<<"Получился полином:"<<endl;
	for(i=n;i>1;i--)
		cout<<"("<<a[i]<<"x^"<<i<<")+";
	cout<<"("<<a[i]<<"x"<<")+";
	cout<<a[0]<<endl;
//Нахождение значения полинома в заданой точке
	cout<<endl<<"Введите точку в которой необходимо найти значение полинома "<<endl;
	cout<<"x= ";
	cin>>x;
	znat=a[n];
	for(i=n;i>0;i--)
		znat=znat*x+a[i-1];
	cout<<endl<<"Значение полинома равно "<<znat<<endl<<endl;
//Перемножение полиномов
	int *b,m;
	cout<<"Введите старшую степень второго полинома ";
	cin>>m;
	b=new int[m+1];
	for(i=m;i>=0;i--)
	{
		cout<<endl<<"Введите коофициент при x^"<<i<<" ";
		cin>>b[i];
	}
	cout<<endl<<"Получился полином:"<<endl;
	for(i=m;i>1;i--)
		cout<<"("<<b[i]<<"x^"<<i<<")+";
	cout<<"("<<b[i]<<"x"<<")+";
	cout<<a[0]<<endl;

	int *c,k=m+n,j;
	c=new int[k+1];
	for(i=0;i<=k;i++)
		c[i]=0;
	for(i=0;i<=n;i++)
		for(j=0;j<=m;j++)
			c[i+j]+=a[i]*b[j];

	cout<<endl<<"Получился полином в результате перемножения:"<<endl;
	for(i=k;i>1;i--)
		cout<<"("<<c[i]<<"x^"<<i<<")+";
	cout<<"("<<c[i]<<"x"<<")+";
	cout<<a[0]<<endl;
	delete []b;
	delete []c;
//Нахождение производной
	for(i=1;i<=n;i++)
		a[i-1]=a[i]*i;
	cout<<endl<<"Производная от первого полинома:"<<endl;
	for(i=n-1;i>1;i--)
		cout<<"("<<a[i]<<"x^"<<i<<")+";
	cout<<"("<<a[i]<<"x"<<")+";
	cout<<a[0]<<endl;
	
	cout<<endl<<"The end."<<endl<<endl;
	delete []a;
	system("PAUSE");
}

#include <iostream>
#include <cmath>
#include "windows.h"
#include <iomanip>
using namespace std;

void sqrt_x(double x)
{
    if (x<0)
    cout<<setw(8)<<"не опр.";
    else
    cout<<setw(8)<<fixed << setprecision(3)<<sqrt(x);
}

void x_umn_x(double x)
{
    cout<<setw(12)<< x*x;
}

void sin_x(double x)
{
    cout<<setw(8)<<fixed << setprecision(3)<< sin(x);
}

void log_e_x(double x)
{
    if (x<=0)
    cout<<setw(8)<<"не опр.";
    else
    cout<<setw(8)<<fixed << setprecision(3)<<log(x);

}

void arc_sinx(double x)
{
    if ((x>=-1) && (x<=1))
    cout<<setw(8)<<fixed << setprecision(3)<<asin(x);
    else cout<<setw(8)<<"не опр.";
}

void exp_x(double x)
{
    cout<<setw(18)<<fixed << setprecision(3)<<exp(x);
}

void tablica(double x1, double x2, int kolvrazb, void (*f1)(double), void (*f2)(double),
      void (*f3)(double), void (*f4)(double), void (*f5)(double), void (*f6)(double))
{
    double zn=0;
    if(kolvrazb<=0)kolvrazb=1;
    cout<<"_______________________________________________________________________________"<<endl;
    cout<<" знач. х  /"<<setw(8)<<"sqrt(x)"<<"/"<<setw(12)<<"x*x"<<"/"<<setw(8)<<"ln(x)"<<"/"<<setw(8)<<"sin(x)"<<"/"<<setw(8)<<"asin(x)"<<"/"<<setw(18)<<"exp^x"<<"/"<<endl;
    cout<<"_______________________________________________________________________________"<<endl;
   for (int i=0;i<=kolvrazb;i++)
    {
    zn=x1+(x2-x1)*i/kolvrazb;
    cout<<fixed << setprecision(3)<<"x="<<setw(8)<<zn;
    cout<<"/";f1(zn);cout<<"/";f2(zn);cout<<"/";f3(zn);cout<<"/";f4(zn);cout<<"/";f5(zn);cout<<"/";f6(zn);cout<<"/"<<endl;
    }
    cout<<"_______________________________________________________________________________"<<endl;
}

int main()
{
    setlocale(LC_ALL, "Russian");
    int kolvr;
    double a,b;
    cout<<"Введите отрезок, на котором Вы хотите получить значения функций"<<endl;
    cin>>a>>b;
    if(a>b)
    {
        a=a+b;
        b=a-b;
        a=a-b;
    }
    cout<<"Введите количество разбиений рассматриваемого отрезка"<<endl;
    cin>>kolvr;
    tablica(a,b,kolvr,&sqrt_x,&x_umn_x,&log_e_x,&sin_x,&arc_sinx,&exp_x);
   return 0;
}





































#include <iostream>
#include <cmath>
#include "windows.h"
using namespace std;

double funkc(double x)
{
    if (x<0)
    return 0;
    else
    return 2*sqrt(3*x);
}

double integral(double x1, double x2,int kolvrazb, double (*f)(double))
{
  double S=0,ch=0;
  for (int i=1;i<kolvrazb+1;i++)
  {
  S=S+((f(x1+(x2-x1)*(i-1)/kolvrazb)+f(x1+(x2-x1)*i/kolvrazb))/2)*(x2-x1)/kolvrazb;
  }
  return S;
}

int main ()
{
    setlocale(LC_ALL, "Russian");
    int kolvr;
    double I,a,b;
    cout<<"Введите пределы интегрирования"<<endl;
    cin>>a>>b;
    if(a>b)
    {
        a=a+b;
        b=a-b;
        a=a-b;
    }
    cout<<"Введите количество разбиений рассматриваемого отрезка"<<endl;
    cin>>kolvr;
    I = integral(a,b,kolvr,&funkc);
    cout<<I<<endl;
   return 0;
}




#include <iostream>
#include <math.h>
#include <conio.h>
using namespace std;

// ����� ����������� n ��� ������� ����� ������������� ���������� S=1+4+7+... > 1000
void ex1()
{
     int n=0,k=0,t=1;
     while(n<1000)
     {
      n+=t;
      t+=3;
      k++;
     } 
     cout<<"�����: ����� "<<t<<", ��� ����� "<<k<<endl; 
}

// ����� ����� ���� ��������� �����
void ex2()
{
    int a,sum=0,temp;
    cout<<"������� ����� ";
    cin>>a;
    while(a>0)
    {
     temp=a%10;
     sum+=temp;
     a=a/10;
    }
    cout<<"����� ����� "<<sum<<endl;
} 
 
// ������������ �����
void ex3()
{
    int a,sum=0,temp;
    cout<<"������� ����� ";
    cin>>a;
    while(a>0)
    {
     temp=a%10;
     sum=sum*10+temp;
     a=a/10;
    }
    cout<<"����� ����� "<<sum<<endl;
}           
                     
int main()
{
    setlocale(LC_CTYPE,"Russian");//���� �� ��������, �� �������� �� setlocale(LC_ALL, "1251")
    cout<<"1. ����� �������������� ���������� ������ 1000"<<endl;
    cout<<"2. ����� ����� ���� �����"<<endl;
    cout<<"3. ������������� �����"<<endl;
    cout<<"0. �����"<<endl;
    int n;
    n=-1;
    while(n!=0)
    {                
       cout<<endl;
       cout<<"������� ����� ������"<<endl;
       cout<<"� ";
       cin>>n;
       cout<<endl;
       switch(n)
        {
        case 1:ex1();
           break;  
        case 2:ex2();
           break;
        case 3:ex3();
           break;
        case 0: cout<<"Good bye!"; 
             break;    
        default:cout<<"Incorrect"<<endl;
           break;        
        }
    }  
    system("PAUSE");
}

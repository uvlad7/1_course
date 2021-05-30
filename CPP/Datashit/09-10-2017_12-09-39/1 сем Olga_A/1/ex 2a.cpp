#include <iostream>
#include <math.h>
using namespace std;
int main()
{
    int n;
    double x;
	cin>>n;
    int * mas = new int[n];
    mas[0] = 2;
    int size = 1;
    bool flag = true;
    cout<<2<<" ";
    for (int i = 3 ;i<=n; i++)
    {
        flag  = true;
		j=0;
		x=sqrt(i);
		while ((mas[j]<=x)&&(flag))
        {
            if(i%mas[j]==0)
			{ flag = false;
			break}
			j++;

        }
        if(flag)
        {
            cout<< i<<" ";
            mas[size] = i;
            size++;
        }
    }cin>>n;
return 0;
}
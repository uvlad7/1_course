// ѕеревод числа из арабской в римскую (до 3000)
#include <iostream>
#include <math.h>
using namespace std;

void main()
{
	setlocale(0,"");
	int n,k,i,d;
	char c[4][2];
	c[0][0]='M'; c[0][1]=' ';
	c[1][0]='C'; c[1][1]='D';
	c[2][0]='X'; c[2][1]='L';
	c[3][0]='I'; c[3][1]='V';
	cout<<"ѕеревод числа из арабской в римскую системы\n\n";
	cout<<"¬ведите число (<4000) ";
	cin>>n;
	k=n;
	i=0;
	for(int j=1000;j>0;j/=10)
	{
		d=k/j;
		if(k==0)
			continue;
		else
		{
			/*switch(d)
			{
			case 9: cout<<c[i][0]<<c[i+1][0];
				break;
			case 8: cout<<c[i][1]<<c[i][0]<<c[i][0]<<c[i][0];
				break;
			case 7: cout<<c[i][1]<<c[i][0]<<c[i][0];
				break;
			case 5: cout<<c[i][1];
				break;
			case 4: cout<<c[i][0]<<c[i][1];
				break;
			case 3: cout<<c[i][0]<<c[i][0]<<c[i][0];
				break;
			case 2: cout<<c[i][0]<<c[i][0];
				break;
			case 1: cout<<c[i][0];
				break;
			}
			*/
			if(d==9)
				cout<<c[i][0]<<c[i+1][0];
			if(d>4&&d<9) 
				{
				cout<<c[i][1];
				for(int z=0;z<d-5;z++)
					cout<<c[i][0];
				}
			if(d==4)
				cout<<c[i][0]<<c[i][1];
			if(d<4)
			{
				for(int z=0;z<d;z++)
					cout<<c[i][0];
			}
			i++;
			k%=j;
		}
	}
	cout<<endl<<endl;
	system("PAUSE");
}
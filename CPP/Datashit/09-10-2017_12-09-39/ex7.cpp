#include <iostream>
#include <string>
#include <fstream>
using namespace std;

int main()
{
	string a[100];
	int fl=0,ll=0,f=50,l=50;
	ifstream in("in.txt");
	ofstream out("out.txt");
	string str;
	int r=1;
	while(getline(in,str)&&r!=0)
	{
		if (str[0]=='1')
		{str.erase(0,2);
		a[l++]=str;}

		if (str[0]=='4')
		{str.erase(0,2);
		a[ll++]=str;}
		if (str[0]=='2')
			if (fl<ll)
				fl++;
			else 
				f++;
		if (str[0]=='3')
		{for (int i=fl;i<ll;i++)
		out<<a[i]<<endl;
		for (int i=f;i<l;i++)
			out<<a[i]<<endl;
r=0;
		}

	}
}
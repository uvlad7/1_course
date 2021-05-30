#include <iostream>
using namespace std;
int main()
{
    int n;
    cin>>n;
    char * m = new char[n];
	int m2[256];
	for (int i=1;i<256;i++)
		m2[i]=0;
	for (int i=0;i<n;i++)
	{
		cin>>m[i];
		m2[(int)m[i]]++;
	}
	for (int i=1;i<256;i++)
		if (m2[i]!=0)
		cout<<"simvol "<<(char)i<<" vstretilsya "<<m2[i]<<" raz"<<endl;
	   //cout<<endl<<(int) 'A';
   cin>>n;
return 0;
}
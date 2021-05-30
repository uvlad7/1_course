#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

struct Dot {
	double x;
	Dot(double _x=0.):x(_x) {};
	friend ostream& operator<<( ostream& os, const Dot& a);
};
ostream& operator<<( ostream& os, const Dot& a) {
	os.precision(5);
	os<<"X: "<<fixed<<a.x;
	return os;
};

struct Circle: public Dot {
	double r;
	Circle(double _x=0.,double _r=0.):Dot(_x),r(_r){};
	Circle(const Dot& a):Dot(a){r=0;};
	friend ostream& operator<<( ostream& os, Circle &a);
};
ostream& operator<<( ostream& os, Circle &a) {
	os.precision(5);
	os<<"X: "<<fixed<<a.x<<" R: "<<a.r;
	return os;
}


Circle operator+(const Dot&a, const Dot&b)  {
	return Circle(a.x,b.x);					
}
Circle operator+(const Circle&a, const Circle&b) {
	double R = max(a.x+a.r,b.x+b.r);
	double L = min(a.x-a.r,b.x-b.r);
	return Circle((L+R)/2.,fabs(L-R)/2.);
}
Circle operator+(const Dot&a, const Circle&b){
	return b+Circle(a);	
}
Circle operator+(const Circle&a, const Dot&b){
	return a+Circle(b);	
}


Circle arr_sum(Circle *a, int col) {
	Circle ans(*a);	
	for (int i=1; i<col ; i++)
		ans = ans+a[i];
	return ans;
}

bool cmp(const Dot* a,const Dot* b) {
	return a->x < b->x;
}


int main(){
	Dot a(10),b(4);
	cout<<a<<endl<<b<<endl<<a+b<<endl;
	
	Circle c(14,2);
	cout<<endl<<c<<endl<<a<<endl<<c+a<<endl;
	
	Circle x(0,2),y(2,2);
	cout<<endl<<x<<endl<<y<<endl<<x+y<<endl;

	Circle p = Dot(0)+Dot(2)+Circle(4,2);
	cout<<endl<<p<<endl;

	c=x=y;
	cout<<endl<<c<<endl;

	cout<<endl;
	Circle A[5]; 
	for (int i=0; i<5; i++) {
		A[i].x=i;
		A[i].r=fabs(i-1.);
		cout<<A[i]<<endl;
	}
	Circle s=arr_sum(A,5);
	cout<<s<<endl;


	Dot *Q[5];
	for (int i=0; i<5; i++)
		Q[i] = &A[i];
	Q[0]=&c; Q[1]=&y;
	sort(Q,Q+5,cmp);
	cout<<endl;
	for (int i=0; i<5; i++)
		cout<<*Q[i]<<endl;

	return 0;
}
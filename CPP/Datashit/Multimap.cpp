#include <map>
typedef pair <int, string> pp; //цена, магазин
multimap <string, pp> A;
ifstream in;
int main()
{
	ifstream in("input.txt");
	string map, pr;
	int cost;
	while(in>>mag>>pr>>cost)
		A.insert(make_pair(pr, make_pair(cost, mag)));
	cout<<getw(is)<<"Магазин"...
	for вывод всех элем.
}
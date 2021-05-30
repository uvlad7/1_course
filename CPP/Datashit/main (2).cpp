#include <iostream>
#include <fstream>
#include <windows.h>
#include <vector>
#include <algorithm>
#include <iterator>
#include <map>
using namespace std;

bool SortByRouteNum(const pair< pair <int, string>, pair <int, string> > &p1, const pair <pair <int, string>,pair <int, string> > &p2)
{
    return p1.first.first < p2.first.first;
}

bool SortByBusNum(const pair< pair <int, string>, pair <int, string> > &p1, const pair <pair <int, string>,pair <int, string> > &p2)
{
    return p1.second.first < p2.second.first;
}

void DifferentRoutes(map <string, pair < pair < int, string > , int > > m)
{
    cout<<"��������� ��������"<<endl;
    int mas[m.size()],count=0,num=0;
   map <string, pair < pair < int, string > , int > > :: iterator it;
for( it = m.begin(); it != m.end(); ++it)
  {
      for (int i=0; i<m.size(); i++)
      if (it->second.second==mas[i]) count++;
      if (count==0)
      {
          cout<<it->second.second<<endl;
          mas[num]=it->second.second;
          num++;
      }
      count=0;
  }
}

void DifferentBusNames(map <string, pair < pair < int, string > , int > > m)
{
    cout<<"���-�� ��������� �����"<<endl;
    string mas[m.size()];
    int count=0,num=0;
    for (int i=0; i<m.size(); i++)
        mas[i]=" ";
   map <string, pair < pair < int, string > , int > > :: iterator it;
for( it = m.begin(); it != m.end(); ++it)
  {
      for (int i=0; i<m.size(); i++)
      if (it->second.first.second==mas[i]) count++;
      if (count==0)
      {
          mas[num]=it->second.first.second;
          num++;
      }
      count=0;
  }
        cout<<num<<endl;
}
/*
//� �����, ��� ���� ������ ������� ������� �������� � �������� �������� ������, �.�. ���� �������� ������
bool ChangeDriver(map <string, pair < pair < int, string > , int > > m, string NameOfDriver, string NewNameOfDriver)
{
    map <string, pair < pair < int, string > , int > > :: iterator it;
for( it = m.begin(); it != m.end(); ++it)
  {
      if (it->first==NameOfDriver) {
    it->first=NewNameOfDriver;
    cout<<"����� ��� "<<it->first<<endl;
      }
  }
}*/

void SameNameOfFactory(map <string, pair < pair < int, string > , int > > m, string NameOfFactory)
{
    int count=0;
    cout<<"�������� ����� �����"<<endl;
   map <string, pair < pair < int, string > , int > > :: iterator it;
for( it = m.begin(); it != m.end(); ++it)
  {
      if (it->second.first.second==NameOfFactory) {
      cout << it->first<< endl;
      count++;}
  }
  if (count==0)
    cout<<"�� �������"<<endl;
}

void show_vector( vector < pair < pair <int, string>, pair <int, string> > > a)
{
    for (int i=0; i<a.size(); i++)
    cout<<a.at(i).first.first<<" "<<a.at(i).first.second<<" "<<a.at(i).second.first<<" "<<a.at(i).second.second<<endl;
}

int main()
{

    vector < pair< pair <int, string>, pair <int, string> > > v;
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    int  routenum, busnum, n;
    string driver, busname;
    ifstream in;
    in.open("input.txt");
    while (!in.eof())
    {
    in>>routenum>>driver>>busnum>>busname;
    cout<<"����� �������� "<<routenum<<" �������� "<<driver <<" ����� �������� "<<busnum <<" ����� �������� "<< busname<<endl;
    v.push_back(make_pair(make_pair(routenum,driver),make_pair(busnum,busname)));
    }
    in.close();
    cout<<"��������������� ������ �� ������ ��������"<<endl;
    sort(v.begin(), v.end(), SortByRouteNum);
    show_vector(v);
    cout<<"��������������� ������ �� ������ ��������"<<endl;
    sort(v.begin(), v.end(), SortByBusNum);
    show_vector(v);
    map <string, pair < pair < int, string > , int > > ListOfDrivers;
  for (int i=0; i<v.size(); i++)
    ListOfDrivers.insert (make_pair (v.at(i).first.second, make_pair ( make_pair (v.at(i).second.first,v.at(i).second.second) , v.at(i).first.first  ) ));
   cout<<"������� ����� ��������"<<endl;
   string NameOfFactory;
   cin>>NameOfFactory;
   SameNameOfFactory(ListOfDrivers,NameOfFactory);
   DifferentRoutes(ListOfDrivers);
   DifferentBusNames(ListOfDrivers);
  // string Name, NewName;
   //cout<<"������� ���, ������� �� ������ ��������"<<endl;
   //cin>> Name;
  // cout<<"������� ����� ���"<<endl;
  // cin>> NewName;
   //ChangeDriver(ListOfDrivers,Name,NewName);
    return 0;
}

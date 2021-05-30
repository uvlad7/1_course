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
    cout<<"Различные маршруты"<<endl;
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
    cout<<"Кол-во различных марок"<<endl;
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
//Я понял, что надо просто удалить старого водителя и добавить водителя заново, т.к. ключ поменять нельзя
bool ChangeDriver(map <string, pair < pair < int, string > , int > > m, string NameOfDriver, string NewNameOfDriver)
{
    map <string, pair < pair < int, string > , int > > :: iterator it;
for( it = m.begin(); it != m.end(); ++it)
  {
      if (it->first==NameOfDriver) {
    it->first=NewNameOfDriver;
    cout<<"Новое имя "<<it->first<<endl;
      }
  }
}*/

void SameNameOfFactory(map <string, pair < pair < int, string > , int > > m, string NameOfFactory)
{
    int count=0;
    cout<<"Водители вашей марки"<<endl;
   map <string, pair < pair < int, string > , int > > :: iterator it;
for( it = m.begin(); it != m.end(); ++it)
  {
      if (it->second.first.second==NameOfFactory) {
      cout << it->first<< endl;
      count++;}
  }
  if (count==0)
    cout<<"Не найдены"<<endl;
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
    cout<<"Номер маршрута "<<routenum<<" Водитель "<<driver <<" Номер автобуса "<<busnum <<" Марка автобуса "<< busname<<endl;
    v.push_back(make_pair(make_pair(routenum,driver),make_pair(busnum,busname)));
    }
    in.close();
    cout<<"Отсортированный вектор по номеру маршрута"<<endl;
    sort(v.begin(), v.end(), SortByRouteNum);
    show_vector(v);
    cout<<"Отсортированный вектор по номеру автобуса"<<endl;
    sort(v.begin(), v.end(), SortByBusNum);
    show_vector(v);
    map <string, pair < pair < int, string > , int > > ListOfDrivers;
  for (int i=0; i<v.size(); i++)
    ListOfDrivers.insert (make_pair (v.at(i).first.second, make_pair ( make_pair (v.at(i).second.first,v.at(i).second.second) , v.at(i).first.first  ) ));
   cout<<"Введите марку автобуса"<<endl;
   string NameOfFactory;
   cin>>NameOfFactory;
   SameNameOfFactory(ListOfDrivers,NameOfFactory);
   DifferentRoutes(ListOfDrivers);
   DifferentBusNames(ListOfDrivers);
  // string Name, NewName;
   //cout<<"Введите имя, которое вы хотите поменять"<<endl;
   //cin>> Name;
  // cout<<"Введите новое имя"<<endl;
  // cin>> NewName;
   //ChangeDriver(ListOfDrivers,Name,NewName);
    return 0;
}

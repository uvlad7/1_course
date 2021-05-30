#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class IPerson
{
public:
	virtual void PrintStatus( void ) = 0;
};

class CMale: public IPerson
{
public:
	CMale( string name, int age = 0 )
	{
		m_age = age;
		m_name	= name;
	}
	virtual void PrintStatus( void )
	{
		cout<<"Male: "<<m_name<<"("<<m_age<<").\n";
	}
protected:
	int m_age;
	string m_name;
};

class CHusband: public IPerson
{
public:
	CHusband( string wifesName, int wifesAge )
	{
		m_wifesName = wifesName;
		m_wifesAge = wifesAge;
	}
	virtual void PrintStatus( void )
	{
		cout<<"Wife: "<<m_wifesName<<"("<<m_wifesAge<<").\n";
	}
protected:
	int m_wifesAge;
	string m_wifesName;
};

class CDaddy: public IPerson
{
public:
	CDaddy(
		int childrenCount,
		string childName[]
	)
	{
		m_childrenCount = childrenCount;
		m_childName = new string[m_childrenCount];
		for ( int i=0; i<m_childrenCount; i++ )
			m_childName[i] = childName[i];
	}
	virtual void PrintStatus( void )
	{
		cout<<"Children:\n";
		for ( int i=0; i<m_childrenCount; i++ )
			cout<<m_childName[i]<<endl;
	}
	virtual ~CDaddy( void )
	{
		delete[] m_childName;
	}
protected:
	int m_childrenCount;
	string* m_childName;
};

class CSocietyUnit: public CMale, public CHusband, public CDaddy
{
public:
	CSocietyUnit(
		string name,
		int age,
		string wifesName,
		int wifesAge, 
		int childrenCount,
		string childName[],
		string accupation
	):	CMale( name, age ),
		CHusband( wifesName, wifesAge ),
		CDaddy( childrenCount, childName )
	{
		m_accupation = accupation;
	}
	virtual void PrintStatus( void )
	{
		CMale::PrintStatus();
		CHusband::PrintStatus();
		CDaddy::PrintStatus();
		cout<<"Accupation: "<<m_accupation<<endl;
	}
private:
	string m_accupation;
};

int main()
{
	string children1[2] = {"Bib","Kate"};
	string children2[2] = { "Kate", "Monica" };
	CMale* male = new CMale( "CMale instance", 35 );
	CHusband* husband = new CHusband("CHusband instance", 25 );
	CDaddy* daddy = new CDaddy( 2, children1 );
	CSocietyUnit* unit = new CSocietyUnit( "CSocietyUnit instance", 33, "Ellison", 27, 2, children2, "laiborer" );

	IPerson** people = new IPerson* [5];
	people[0] = male;
	people[1] = husband;
	people[2] = daddy;
	people[3] = (CDaddy*)unit;
	people[4] = NULL;
	IPerson** iterator = people;
	while ( *iterator ){
		(*iterator)->PrintStatus();
		iterator++;
	}


}
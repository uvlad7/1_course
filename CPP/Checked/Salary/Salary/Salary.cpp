// Salary.cpp: определ€ет точку входа дл€ консольного приложени€.
//

#include "stdafx.h"
#include <iostream>
#include <cstring>
#include <fstream>
using namespace std;

class Employee
{
public:
	Employee(const char *, const char *);
	~Employee();
	const char *getFirstName() const;
	const char *getLastName() const;
	virtual float earnings() const = 0;
	virtual void print() const = 0;
private:
	char *firstName;
	char *lastName;
};
Employee::Employee(const char *first, const char *last)
{
	firstName = new char[strlen(first) + 1];
	strcpy(firstName, first);
	lastName = new char[strlen(last) + 1];
	strcpy(lastName, last);
}
Employee::~Employee()
{
	delete[] firstName;
	delete[] lastName;
}
const char * Employee::getFirstName() const
{
	return firstName;
}
const char * Employee::getLastName() const
{
	return lastName;
}

class Boss: public Employee
{
public:
	Boss(const char * first, const char * last, float salary = 0.0) : Employee(first, last), weeklySalary(salary) {};
	void setWeeklySalary(float);
	virtual float earnings() const;
	virtual void print() const;
private:
	float weeklySalary;
};
void Boss::setWeeklySalary(float salary)
{
	weeklySalary = salary;
}
float Boss::earnings() const
{
	return weeklySalary;
}
void Boss::print() const
{
	cout << "Boss " << getFirstName() << " " << getLastName() << " " << earnings() << endl;
}

class CommissionWorker: public Employee
{
public:
	CommissionWorker(const char * first, const char *last, float base = 0.0, float com = 0.0, unsigned quant = 0) : Employee(first, last), salary(base), commission(com), quantity(quant) {};
	void setSalary(float);
	void setCommission(float);
	void setQuantity(unsigned);
	virtual float earnings() const;
	virtual void print() const;
private:
	float salary;
	float commission;
	unsigned quantity;
};
void CommissionWorker::setSalary(float base)
{
	salary = base;
}
void CommissionWorker::setCommission(float com)
{
	commission = com;
}
void CommissionWorker::setQuantity(unsigned quant)
{
	quantity = quant;
}
float CommissionWorker::earnings() const
{
	return salary + commission * quantity;
}
void CommissionWorker::print() const
{
	cout << "Comission Worker " << getFirstName() << " " << getLastName() << " " << earnings() << endl;
}

class PieceWorker: public Employee
{
public:
	PieceWorker(const char * first, const char *last, float wage = 0.0, unsigned quant = 0) : Employee(first, last), wagePerPiece(wage), quantity(quant) {};
	void setWage(float);
	void setQuantity(unsigned);
	virtual float earnings() const;
	virtual void print() const;
private:
	float wagePerPiece;
	unsigned quantity;
};
void PieceWorker::setWage(float wage)
{
	wagePerPiece = wage;
}
void PieceWorker::setQuantity(unsigned quant)
{
	quantity = quant;
}
float PieceWorker::earnings() const
{
	return wagePerPiece * quantity;
}
void PieceWorker::print() const
{
	cout << "Piece Worker " << getFirstName() << " " << getLastName() << " " << earnings() << endl;
}

class HourlyWorker : public Employee
{
public:
	HourlyWorker(const char * first, const char *last, float wage = 0.0, float overwage = 0.0, float quant = 0.0, float nrm = 0.0) : Employee(first, last), wagePerHour(wage), wagePerOverHour(overwage), quantity(quant), norm(nrm) {};
	void setWage(float);
	void setOvertimeWage(float);
	void setQuantity(float);
	void setNorm(float);
	virtual float earnings() const;
	virtual void print() const;
private:
	float wagePerHour;
	float wagePerOverHour;
	float norm;
	float quantity;
};
void HourlyWorker::setWage(float wage)
{
	wagePerHour = wage;
}
void HourlyWorker::setOvertimeWage(float overwage)
{
	wagePerOverHour = overwage;
}
void HourlyWorker::setQuantity(float quant)
{
	quantity = quant;
}
void HourlyWorker::setNorm(float nrm)
{
	norm = nrm;
}
float HourlyWorker::earnings() const
{
	if (quantity < norm)
		return wagePerHour * quantity;
	else return wagePerHour * norm + wagePerOverHour * (quantity - norm);
}
void HourlyWorker::print() const
{
	cout << "Hourly Worker " << getFirstName() << " " << getLastName() << " " << earnings() << endl;
}

istream& operator >> (istream &in, Employee** empl)
{
	char type;
	char first[50], last[50];
	in >> type >> first >> last;
	switch (type)
	{
	case 'B':
	{
		float sal;
		in >> sal;
		Boss *temp = new Boss(first, last, sal);
		*empl = temp;
		break;
	}
	case 'C':
	{
		float sal, com;
		unsigned quant;
		in >> sal >> com >> quant;
		CommissionWorker *temp = new CommissionWorker(first, last, sal, com, quant);
		*empl = temp;
		break;
	}
	case 'P':
	{
		float wag;
		unsigned quant;
		in >> wag >> quant;
		PieceWorker *temp = new PieceWorker(first, last, wag, quant);
		*empl = temp;
		break;
	}
	case 'H':
	{
		float wag, owag, quant, nrm;
		in >> wag >> owag >> quant >> nrm;
		HourlyWorker *temp = new HourlyWorker(first, last, wag, owag, quant, nrm);
		*empl = temp;
		break;
	}
	default:
		break;
	}
	return in;
}

int main()
{
	Employee **employers = new Employee *[11];
	employers[10] = NULL;
	ifstream fin("¬вод.txt");
	for (int i = 0; i < 10; i++)
		fin >> &(employers[i]);
	fin.close();
	Employee** iterator = employers;
	while (*iterator)
	{
		(*iterator)->print();
		iterator++;
	}
	system("pause");
    return 0;
}
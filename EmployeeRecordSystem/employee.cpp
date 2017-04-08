//employee.cpp

#include <iostream>
#include "employee.h"

namespace EmployeeRecords
{
Employee::Employee()
	:mFirstName("")
	,mLastName("")
	,mEmployeeNumber(-1)
	,mSalary(kDefaultStartingSalary)
	,mHired(false)
{

}

Employee::~Employee()
{

}

void Employee::promote(int raiseAmount)
{
	setSalary(getSalary() + raiseAmount);
}

void Employee::demot(int demeritAmount)
{
	setSalary(getSalary() - demeritAmount);
}

void Employee::hire()
{
	mHired = true;
}

void Employee::fire()
{
	mHired = false;
}

void Employee::display() const
{
	using namespace std;
	cout << "Employee: " << getLastName() << ", " << getFirstName() << endl;
	cout << "Employee Number: " << getEmployeeNumber() << endl;
	cout << "Salary: $" << getSalary() << endl;
	cout << endl;
}

void Employee::setFirstName(const std::string& firstName)
{
	mFirstName = firstName;
}

const std::string& Employee::getFirstName() const
{
	return mFirstName;
}

void Employee::setLastName(const std::string& lastName)
{
	mLastName = lastName;
}

const std::string& Employee::getLastName() const
{
	return mLastName;
}

void Employee::setEmployeeNumber(int employeeNumber)
{
	mEmployeeNumber = employeeNumber;
}

int Employee::getEmployeeNumber() const
{
	return mEmployeeNumber;
}

void Employee::setSalary(int newSalary)
{
	mSalary = newSalary;
}

int Employee::getSalary() const
{
	return mSalary;
}

bool Employee::getIsHired() const
{
	return mHired;
}
}
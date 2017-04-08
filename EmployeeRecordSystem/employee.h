//employee.h

#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#pragma once
#include <string>

namespace EmployeeRecords
{
const int kDefaultStartingSalary = 30000;

class Employee
{
public:
	Employee();
	~Employee();
	void promote(int raiseAmount = 1000);
	void demot(int demeritAmount = 1000);
	void hire();
	void fire();
	void display() const;

	void setFirstName(const std::string& firstName);
	const std::string& getFirstName() const;

	void setLastName(const std::string& lastName);
	const std::string& getLastName() const;

	void setEmployeeNumber(int employeeNumber);
	int getEmployeeNumber() const;

	void setSalary(int newSalary);
	int getSalary() const;

	bool getIsHired() const;

private:
	std::string mFirstName;
	std::string mLastName;
	int mEmployeeNumber;
	int mSalary;
	bool mHired;
};

}

#endif //EMPLOYEE_H
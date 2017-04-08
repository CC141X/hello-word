#include <iostream>
#include <stdexcept>
#include "database.h"

namespace EmployeeRecords
{
Database::Database() : mNextEmployeeNumber(kFirstEmployeeNumber)
{
}

Employee& Database::addEmployee(const std::string& firstName,
                                const std::string& lastName)
{
    Employee theEmployee;
    theEmployee.setFirstName(firstName);
    theEmployee.setLastName(lastName);
    theEmployee.setEmployeeNumber(mNextEmployeeNumber);
    theEmployee.hire();
    mEmployees.push_back(theEmployee);
    return mEmployees[mEmployees.size() - 1];
}

Employee& Database::getEmployee(int employeeNumber)
{
    for(auto& employee : mEmployees)
    {
        if(employee.getEmployeeNumber() == employeeNumber){
            return employee;
        }
    }
    throw std::runtime_error("No employee found.");
}

Employee& Database::getEmployee(const std::string& firstName,
                                const std::string& lastName)
{
    for(auto& employee : mEmployees)
    {
        if((employee.getFirstName() == firstName)
           && (employee.getLastName() == lastName)){
            return employee;
           }
    }
    throw std::runtime_error("No employee found.");
}

void Database::displayAll() const
{
    for(const auto& employee : mEmployees){
        employee.display();
    }
}

void Database::displayCurrent() const
{
    for(const auto& employee : mEmployees)
    {
        if(employee.getIsHired()){
            employee.display();
        }
    }
}

void Database::displayFormer() const
{
    for(const auto& employee : mEmployees)
    {
		if (!employee.getIsHired()){
			employee.display();
        }
    }
}

}

#include <iostream>
#include <stdexcept>
#include <exception>
#include "database.h"
#include "common/definelog.h"
#include "common/definelog.c"

using namespace EmployeeRecords;

int displayMenu();
void doHire(Database& db);
void doFire(Database& db);
void doPromote(Database& db);
//void doDemote(Database& db);

int main(int argc, char* argv[])
{
	DEF_LOG_INFO("start");
    Database employeeDB;
    bool done = false;
    while(!done)
    {
        int selection = displayMenu();
        switch(selection)
        {
        case 1:
            doHire(employeeDB);
            break;
        case 2:
            doFire(employeeDB);
            break;
        case 3:
            doPromote(employeeDB);
            break;
        case 4:
            employeeDB.displayAll();
            break;
        case 5:
            employeeDB.displayCurrent();
            break;
        case 6:
            employeeDB.displayFormer();
            break;
        case 0:
            done = true;
            break;
        default:
            std::cerr << "Unknown command." << std::endl;
            break;
        }
    }
    return 0;
}

int displayMenu()
{
	using std::cout;
	using std::endl;
	int selection;
	cout << "1) Hire" << endl;
	cout << "2) Fire" << endl;
	cout << "3) Promote" << endl;
	cout << "4) List all" << endl;
	cout << "5) List all current" << endl;
	cout << "6) List all former" << endl;
	cout << "0) Quit" << endl;
	std::cin >> selection;
	return selection;
}

void doHire(Database& db)
{
	std::string firstName;
	std::string lastName;
	std::cout << "First name:";
	std::cin >> firstName;
	std::cout << "Last name:";
	std::cin >> lastName;
	try{
		db.addEmployee(firstName, lastName);
	}
	catch (const std::exception& exception){
		std::cerr << "Unable to add new employee: " << exception.what() << std::endl;
	}
}

void doFire(Database& db)
{
	int employeeNumber;
	std::cout << "Employee number: ";
	std::cin >> employeeNumber;
	try{
		Employee& emp = db.getEmployee(employeeNumber);
		emp.fire();
		std::cout << "Employee " << employeeNumber << " terminated." << std::endl;
	}
	catch (const std::exception& exception){
		std::cerr << "Unable to terminate employee: " << exception.what() << std::endl;
	}
}

void doPromote(Database& db)
{
	int employeeNumber;
	int raiseAmout;
	std::cout << "Employee number: ";
	std::cin >> employeeNumber;
	std::cout << "Raise: ";
	std::cin >> raiseAmout;
	try{
		Employee& emp = db.getEmployee(employeeNumber);
		emp.promote(raiseAmout);
	}
	catch (const std::exception& exception){
		std::cerr << "Unable to promote employee: " << exception.what() << std::endl;
	}
}
//void doDemote(Database& db);
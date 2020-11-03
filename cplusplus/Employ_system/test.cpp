//test.cpp

#include <iostream>
/*
 * #include "Employee.hpp"

using namespace std;
using namespace Records;

int main()
{
	cout << "just a test the Employee class." <<endl;
	
	Employee emp;
	emp.setFirstName("wfh");
	emp.setLastName("hahh");
	emp.setEmployeeNumber(23);
	emp.setSalary(900000);
	emp.promote(700);
	emp.promote();
	emp.hire();
	emp.fire();
	emp.display();
	return 0;
}
*/
/*
#include "Database.hpp"


using namespace std;
using namespace Records;

int main()
{
	Database myDB;
	Employee& emp1 = myDB.addEployee("Greg", "Wallis");
	emp1.fire();

	Employee& emp2 = myDB.addEployee("Marc", "White");
	emp2.setSalary(10000);



	Employee& emp3 = myDB.addEployee("John", "Doe");
	emp3.setSalary(1);
	emp3.promote();

	cout << "all employees:" << endl << endl;
	myDB.displayAll();


	cout << "all Current employees:" << endl << endl;
	myDB.displayCurrent();
	cout << "all Former employees:" << endl << endl;
	myDB.displayFormer();

}*/


//test.cpp

#include <iostream>
#include "Database.hpp"
#include <stdexcept>
#include <exception>

using namespace std;
using namespace Records;

int displayMenu();
void doHire(Database& db);
void doFire(Database& db);
void doPromote(Database& db);
void doDemote(Database& db);


int main()
{
	Database employeeDB;
	bool done = false;

	while(!done){
		int selection = displayMenu();
		switch (selection){
		case 0:
			done = true;
			break;
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
			doDemote(employeeDB);
			break;
		case 5:
			employeeDB.displayAll();
			break;
		case 6:
			employeeDB.displayCurrent();
			break;

		case 7:
			employeeDB.displayFormer();
			break;

		default:
			cerr << "Unknow command." <<endl;
			break;
		}
	}
	return 0;
}



int displayMenu()
{	
	int selection;
	cout << endl ;
	cout << "Employee Database" << endl;
	cout << "--------------------------" <<endl;
	cout << "1)Hire a new employee" << endl;
	cout << "2)Fire an employee" << endl;
	cout << "3)Promote an employee" << endl;
	cout << "4)Demote an employees" << endl;
	cout << "5)List all employees" << endl;
	cout << "6)List all current employees" << endl;
	cout << "7)List all former employees" << endl;
	cout << endl ;
	cout << "---->";
	cin >>selection;
	return selection;
}


void doHire(Database& db)
{
	string firstName;
	string lastName;
	
	cout << "First Name?";
	cin >> firstName;
	cout << "Last Name?";
	cin >> lastName;

	db.addEployee(firstName, lastName);
}


void doFire(Database& db)
{
	int employeeNumber;

	cout << "Employee numbers?";
	cin >> employeeNumber;

	try {
		Employee& emp = db.getEployee(employeeNumber);
		emp.fire();
		cout << "Employee " << employeeNumber << "terminated." <<endl;
	} catch (const std::logic_error& exception) {
		cerr << "Unable to terminate employee: " << exception.what() <<endl;
	}
}


void doPromote(Database& db)
{
	int employeeNumber;
	int raiseAmount;
	cout << "Employee numbers?";
        cin >> employeeNumber;

	cout << "How much raise? ";
	cin >> raiseAmount;

	try {
		Employee& emp = db.getEployee(employeeNumber);
		emp.promote(raiseAmount);	
	} catch (const std::logic_error& exception) {
		cerr << "Unable to promote the employee: " << exception.what() <<endl;
	}
}




void doDemote(Database& db)
{
	int employeeNumber;
	int demeritAmount;
	cout << "Employee numbers?";
        cin >> employeeNumber;

	cout << "How much decrise? ";
	cin >> demeritAmount;

	try {
		Employee& emp = db.getEployee(employeeNumber);
		emp.demote(demeritAmount);	
	} catch (const std::logic_error& exception) {
		cerr << "Unable to demote the employee: " << exception.what() <<endl;
	}
}

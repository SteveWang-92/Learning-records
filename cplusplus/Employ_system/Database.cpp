//Database.cpp

#include "Database.hpp"
#include <stdexcept>

namespace Records{

	Employee& Database::addEployee(const std::string& firstname,
			const std::string& lastName)
	{
		Employee theEmployee(firstname, lastName);
		theEmployee.setEmployeeNumber(mNextEmployeeNumber++);
		theEmployee.hire();
		mEmployees.push_back(theEmployee);
		return mEmployees[mEmployees.size() - 1];
	}

	Employee& Database::getEployee(const std::string& firstname,
			const std::string& lastName)
	{	
		for (auto& employee : mEmployees){
			if (employee.getFirstName() == firstname && 
					employee.getLastName() == lastName)
			{
				return employee;
			}
		}
		throw std::logic_error("No employee found.");
	}


	Employee& Database::getEployee(int employeeNumber)
	{	
		for (auto& employee : mEmployees){
			if (employee.getEmployeeNumber() == employeeNumber)
			{
				return employee;
			}
		}
		throw std::logic_error("No employee found.");
	}


	void Database::displayAll() const
	{
		for(const auto& employee : mEmployees)
		{
			employee.display();
		}
	}



	void Database::displayCurrent() const
	{
		for(const auto& employee : mEmployees)
		{
			if (employee.isHired())
			employee.display();
		}
	}


	void Database::displayFormer() const
	{
		for(const auto& employee : mEmployees)
		{
			if (!employee.isHired())
			employee.display();
		}
	}




}

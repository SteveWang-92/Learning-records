//Database.hpp
//
#pragma once
#include <iostream>
#include <vector>
#include "Employee.hpp"

namespace Records{
	const int kFirstEmployeeNumber = 1000;

	class Database
	{
		public:
			Employee& addEployee(const std::string& firstname, 
					const std::string& lastName);

			Employee& getEployee(const std::string& firstname, 
					const std::string& lastName);


			Employee& getEployee(int employeeNumber);

			void displayAll() const;

			void displayCurrent() const;
			void displayFormer() const;
		private:
			std::vector<Employee> mEmployees;
			int mNextEmployeeNumber = kFirstEmployeeNumber;
	};

}

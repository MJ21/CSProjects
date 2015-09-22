//Michael Flath
//CS165 Assignment 15.1
//This is the implementation file salariedemployee.cpp

#include <iostream>
#include <string>
#include "salariedemployee.hpp"
using std::string;
using std::cout;
using std::endl;

namespace MJFEmployees
{
	SalariedEmployee::SalariedEmployee() : name("No name yet"), ssn("No number yet"), netPay(0)
	{
		//deliberately empty
	}
	
	SalariedEmployee::SalariedEmployee(const string& theName, const string& theNumber, double theWeeklyPay) : name(theName), ssn(theNumber), netPay(0)
	{
		//deliberately empty
	}
	
	string SalariedEmployee::getName() const
	{
		return name;
	}
	
	string SalariedEmployee::getSsn() const
	{
		return ssn;
	}
	
	double SalariedEmployee::getNetPay() const
	{
		return netPay;
	}	
	double SalariedEmployee::getSalary() const
	{
		return salary;
	}
	
	void SalariedEmployee::setName(const string& newName)
	{
		name = newName;
	}
	
	void SalariedEmployee::setSsn(const string& newSsn)
	{
		ssn = newSsn;
	}

	void SalariedEmployee::setNetPay(double newNetPay)
	{
		netPay = newNetPay;
	}

	void SalariedEmployee::setSalary(double newSalary)
	{
		salary = newSalary;
	}
	
	void SalariedEmployee::printCheck()
	{
		setNetPay(salary);
		cout << "\n_________________________________________\n";
		cout << "Pay to the order of " << getName() << endl;
		cout << "The sum of " << getNetPay() << " Dollars\n";
		cout << "__________________________________________\n";
		cout << "Check Stub Not NEGOTIABLE \n";
		cout << "Employee Number: " << getSsn() << endl;
		cout << "Salaried Employee. Regular Pay: " << salary << endl;
		cout << "__________________________________________\n";
	
	}	
}


//Michael Flath
//CS165 ASsignment 15.1
//This is the header file salariedemployee.hpp
#ifndef SALARIEDEMPLOYEE_HPP
#define SALARIEDEMPLOYEE_HPP

#include <string>

using std::string;

namespace MJFEmployees
{
	class SalariedEmployee
	{
	public:
		SalariedEmployee();	
		SalariedEmployee(const string& theName, const string& theSsn, double theWeeklySalary);
		string getName() const;		
		string getSsn() const;
		double getNetPay() const;
		double getSalary() const;
		void setName(const string& newName);
		void setSsn(const string& newSsn);
		void setNetPay(double newNetPay);
		void setSalary(double newSalary);	
		void printCheck();
	protected:
	string name;
	string ssn;
	double netPay;	
	double salary; //weekly
	};
}

#endif //SALARIEDEMPLOYEE_HPP


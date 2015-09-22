//Michael Flath
//cs165 Assignment 15.1
//This is the implementation file administrator.cpp
//This is a derived class from salariedemployee.hpp
#include <iostream>
#include <string>
#include "administrator.hpp"
using std::string;
using std::cout;
using std::cin;
using std::endl;

namespace MJFEmployees
{
	Administrator::Administrator() : SalariedEmployee(), salary(0)
	{
		//deliberately empty
	}
	
	Administrator::Administrator(const string& theName, const string& theNumber, double theWeeklyPay, string title, string job, string svisor)
	{
		//deliberately empty
	}
	
	void Administrator::setTitle(const string& newTitle)
	{
		title = newTitle;
	}

	void Administrator::setJob(const string& newJob)
	{	
		job = newJob;
	}
	
	void Administrator::setSvisor(const string& newSvisor)
	{
		svisor = newSvisor;
	}
	string Administrator::getTitle() const
	{
		return title;
	}	
	
	string Administrator::getJob() const
	{
		return job;
	}

	string Administrator::getSvisor() const
	{
		return svisor;
	}
	
	void Administrator::adminInput()//string& newTitle, string& newJob, string& newSvisor)
	{
		cout << "You may now enter administrator's data. " << endl;
		cout << "Please enter the administrator's title: " << endl;
		getline(cin, title);
		cout << "Please enter the administrator's responsibility: " <<endl;
		getline(cin, job);
		cout << "Please enter the administrator's supervisor: " << endl;
		getline(cin, svisor);
		cout << "Thank you! " << endl;
	}
	
	void Administrator::print()
	{
		cout << "Administrator's data: " << endl;
		cout << "Title: " << getTitle() << endl;
		cout << "Responsibility: " << getJob() << endl;
		cout << "Supervisor: " << getSvisor() << endl;
		cout << "Salary: " << salary << endl;
	}
}


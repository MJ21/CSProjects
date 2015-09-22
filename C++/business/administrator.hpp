//Michael Flath
//CS154 Assignment 15.1
//This is the header file administrator.hpp
//This is the derived class from the file salariedemployee.hpp
#ifndef ADMINISTRATOR_H
#define ADMINISTRATOR_H

#include <string>
#include "salariedemployee.hpp"

using std::string;

namespace MJFEmployees
{
	class Administrator : public SalariedEmployee
	{	
		public:
			Administrator();
			Administrator(const string& theName, const string& theSsn, double theWeeklySalary, string title, string job, string svisor);
			void setTitle(const string& newTitle);			
			void setJob(const string& newJob);
			void setSvisor(const string& newSvisor);
			string getTitle() const;
			string getJob() const;
			string getSvisor() const;
			void adminInput();//string& newTitle, string& newJob, string& newSvisor);
			void print();
		protected:
			string title;
			string job;
			string svisor;
			double salary; //weekly
	};
}

#endif //ADMINISTRATOR_H

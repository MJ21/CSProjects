//Michael Flath
//cs165 Assignment 15.1
//This is the main file for administrator.hpp and administrator.cpp
#include <iostream>
#include "administrator.hpp"
using std::cout;
using std::cin;
using std::endl;
using MJFEmployees::Administrator;

int main()
{
	Administrator Mike;
	Mike.setName("Mighty Mike");
	Mike.setSsn("123-45_6789");
	Mike.setTitle("Professor");
	Mike.setJob("English");
	Mike.setSvisor("Jess");
	Mike.adminInput();
	Mike.print();

	return 0;


}

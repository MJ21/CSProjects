//Michael Flath
//CS165 Assignment 13.1
//This program will use a vector to store names of people who are in a building.
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

void enterName();
void removeName();
void print();

class Building
{
	public:
		string id;
		vector<string> name;
		void enterName();
		void removeName();
		void print();
};

int main()
{
	Building office;
	int choice;
	char ans;
	//Menu: Enter, delete, or print name(s).
	do
	{
		cout << "Choose a selection:" << endl;
		cout << " 1. Enter a name.\n 2. Delete a name.\n 3. Print name list." << endl;
		cin >> choice;
		switch(choice)
		{
			case 1:
				office.enterName();
				break;
			case 2: 
				office.removeName();
				break;
			case 3:
				office.print();
				break;
		}
		cin.clear();
		cin.ignore(1000, '\n');
		
		cout << "Would you like to select another function: (Y/N) " << endl;
		cin >> ans;
	}while(ans == 'Y' || ans == 'y');
	
	return 0;
}
//This function uses a vector to receive and store names.
void Building::enterName()
{
	char ans;
	do
	{
		cout << "Enter a name: " << endl;
		cin >> id;
		name.push_back(id);
		
		cout << "Would you like to enter another name? (Y/N)" << endl;
		cin >> ans;

	}while(ans == 'Y' || ans == 'y');

}
//This function removes name from vector.
void Building::removeName()
{
	string erase_name;
	char cont;
	do
	{
		cout << "Enter a name you wish to remove: " << endl;
		cin >> erase_name;
		name.erase(remove(name.begin(), name.end(), erase_name), name.end());
		cout << "Delete another name? (Y/N) " << endl;
		cin >> cont;
	
	}while(cont == 'Y' || cont == 'y');		
}
//This function prints the current name list.
void Building::print()
{	
	for(int i = 0; i < name.size(); i++)
	{
		cout << name.at(i) << ", ";
		
	}
	cout << endl;
}

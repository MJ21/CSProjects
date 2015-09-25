/******************************************
 * Name:Michael Flath
 * 
 *Input: This program will receive an item's: name, age, color, asking price, and paid price. Then the items information will be placed in an inventory.
 *
 *Output: This program will output information (name, age, color, asking price, and paid price) regarding an item.
 *
 *Overview: This program receives information regarding multiple items and stores the information as an inventory.
 *
 * *****************************************/
#include <iostream>
#include <cstring>
#include "Inventory.hpp"

using std::cout;
using std::cin;
using std::endl;
using std::string;

int main(int argc, char **argv)
{
	Item object1("vase", 1, "red", 200.00, 175.00);
	Item object2("glass", "blue", 1000, 1000); 
	Item object3;
	
	cout << object1.get_name() << endl;
	cout << object2.get_name() << endl;
	cout << object3.get_name() << endl;

	return 0;

}


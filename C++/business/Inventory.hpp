//Michael Flath
//This is the header file Inventory.hpp.
#include <iostream>
#include <cstring>
using std::string;

class Item
{
	public:
		Item(string new_name, int new_age, string new_color, double new_ask_price, double new_paid_price);
	
		Item(string new_name, string new_color, double new_ask_price, double new_paid_price);
	
		Item(string new_name, double new_ask_price, double new_paid_price);
	
		Item(string new_name, double new_ask_price);

		Item();
		//Initialize default constructor.
		void set_name(string new_name);
		void set_age(int new_age);
		void set_color(string new_color);
		void set_askPrice(double new_ask_price);
		void set_paidPrice(double new_paid_price);
		void output();
		string get_name();
		int get_age();
		string get_color();
		double get_askPrice();
		double get_paidPrice();	
	
	private:
		string name;
		int age;
		string color;
		double ask_price;
		double paid_price;		
};

//Michael Flath
//This is the implementation file Inventory.cpp.
#include <iostream>
#include "Inventory.hpp"
#include <cstring> 
using std::string;

Item::Item(string new_name, int new_age, string new_color, double new_ask_price, double new_paid_price)
{
	name = new_name;
	age = new_age;
	color = new_color;
	ask_price = new_ask_price;
	paid_price = new_paid_price;

}

Item::Item(string new_name, string new_color, double new_ask_price, double new_paid_price)
{
	name = new_name;
	color = new_color;
	ask_price = new_ask_price;
	paid_price = new_paid_price;
}
Item::Item(string new_name, double new_ask_price, double new_paid_price)
{
	name = new_name;
	ask_price = new_ask_price;
	paid_price = new_paid_price;
}
Item::Item(string new_name, double new_ask_price)
{	
	name = new_name;
	ask_price = new_ask_price;
}

Item::Item(): name("Name"), ask_price(0.00){	
}

void Item::set_name(string new_name)
{
	name = new_name;
}

void Item::set_age(int new_age)
{
	age = new_age;
}

void Item:: set_color(string new_color)
{
	color = new_color;
}

void Item::set_askPrice(double new_ask_price)
{
	ask_price = new_ask_price;
}

void Item::set_paidPrice(double new_paid_price)
{
	paid_price = new_paid_price;
}

string Item::get_name() 
{
	return name;
}

int Item::get_age()
{
	return age;
}

string Item::get_color()
{
	return color;
}

double Item::get_askPrice()
{
	return ask_price;
}

double Item::get_paidPrice()
{
	return paid_price;
}

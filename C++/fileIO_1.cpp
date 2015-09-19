/**********************************************
 *Name: Michael Flath
 *Updated: 5/23/14
 *CS165 Assignment 12.2
 *
 *Input: This program will receive data to be stored in another file.
 *
 *Output: This program will calculate the median and output it.
 *
 *Overview: Using file i/o this program will open another file and calculate the median. Then it will received data, store it in the same file, calculate the median, and finally close the file.
 *
 ******************************************/
#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;
using std::string;

int main()
{
	ifstream ifs, if1, if2;
	
	vector<int> v;	
	int num,num1, mid;
	int plus = 0; //Count input
	//Quartiles
	int q1, q2, q3, q4;
	

	//Open file and store numbers in a vector.
	ifs.open("data1.txt");
	if(ifs.is_open())
	{
		while(ifs >> num)
		{
			v.push_back(num);
			plus++; //Counts how many numbers have been collected.
		}	
		ifs.close();
	}
	//locate middle element.
	mid = plus / 2;
	//Re-open the file and calculate median.
	if1.open("data1.txt");
	if(if1.is_open())
	{
		for(int i =0; i < mid; i++)
		{
			if1 >> num1;
			cout << num1 << " ";	
		}	
		if(plus % 2 == 0)
		{
			int medianNum; 
			medianNum = ((v[mid-1] + v[mid]) / 2);
			cout << "The median is: " << medianNum << endl;
		}
		else 
		{
			cout << "Median: " << v[mid-1] << endl;
		}
		if1.close();
	}
	//Output quartiles
	q1 = plus / 4;
	q2 = mid;
	q3 = ((plus * 3) / 4);
	q4 = plus;
	//Open file, input quartiles and ouput them.
	if2.open("data1.txt");
	if(if2.is_open())
	{
		cout << "Quartile 1: " << endl;
		for(int i = 0; i < q1; i++) 
		{
			if2 >> num;
			cout << num << ", ";
		}
		cout << endl;
		cout << "Quartile 2: " << endl;
		for(int i = q1; i < q2; i++) 
		{
			if2 >> num;
			cout << num << ", ";
		}
		cout << endl;
		cout << "Quartile 3: " << endl;
		for(int i = q2; i < q3; i++) 
		{
			if2 >> num;
			cout << num << ", ";
		}
		cout << endl;
		cout << "Quartile 4: " << endl;
		for(int i = q3; i < q4; i++) 
		{
			if2 >> num;
			cout << num << ", ";
		}
		cout << endl;
		if2.close();
	}
	return 0;

	
}

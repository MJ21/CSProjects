/*
Michael Flath
CS325
Assignment 2
*/

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <iomanip>

using namespace std;

long BC1(int newN, int newR);
long BC2(int newN, int newR);

int main(int argc, char *argv[]) {
	clock_t start, end;
	float time;
	int numN, numR;
	long total_BC1, total_BC2;
	if(argc != 3)
		cout << "Error: please add 2 numbers to calculate the combination. ex(command 3 5)" << endl;
		
	numN = atoi(argv[1]);
	numR = atoi(argv[2]);
	
	start = clock();
	total_BC1 = BC1(numN, numR);
	end = clock() - start;
	time = (float)end/CLOCKS_PER_SEC;
	
	start = clock();
	total_BC2 = BC2(numN, numR);
	end = clock() - start;
	time = (float)end/CLOCKS_PER_SEC;
	
	cout << "Total for BC1: " << total_BC1 << endl;
	cout << "BC1: Time in seconds: " << setprecision(6) << time << endl;
	cout << "Total for BC2: " << total_BC2 << endl;
	cout << "BC2: Time in seconds: " << setprecision(6) << time << endl;
	return 0;
}

long BC1(int newN, int newR) {
	if(newR == 0 || newR == newN)
		return 1;
	else
		return BC1(newN - 1, newR) + BC1(newN - 1, newR - 1);
}

long BC2(int newN, int newR) {
	if(newR == 0)
		return 1;
	else
		return BC2(newN - 1, newR - 1) * newN/newR;
}
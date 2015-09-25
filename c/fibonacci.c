/*
Michael Flath
CS325
Assignment 1
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

long fib_Recursion(int newNuma);
long fib_Iterative(int newNumb);

int main(int argc, char *argv[]) {

	clock_t start, end;
	double total;
	int a, b;
	if(argc != 2) 
		printf("Error: Please enter the number of fibonacci numbers to test!");
	
	int number = atoi(argv[1]);
	start = clock();
	a = fib_Recursion(number);
	end = clock();
	total = (double)(end - start)/CLOCKS_PER_SEC;
	printf("Recursion time: %.3f\n", total);
	
	start = clock();
	b = fib_Iterative(number);
	end = clock();
	total = (double)(end - start)/CLOCKS_PER_SEC;
	printf("Iterative time: %.3f\n", total);
	
	printf("Recursive: %d Iterative %d\n", a, b);
	
	return 0;
}

long fib_Recursion(int newNuma) {
	if(newNuma == 0) {
		return 0;
	}
	if (newNuma == 1) {
		return 1;
	}
	return fib_Recursion(newNuma - 1) + fib_Recursion(newNuma - 2);
}

long fib_Iterative(int newNumb) {
	long fib = 0;
	long a = 1;
	long b = 0;
	long i = 0;
	for(i = 0; i < newNumb; i++) {
		b = fib + a;
		a = fib;
		fib = b;
	}
	return fib;
}
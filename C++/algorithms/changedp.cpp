/*******************************************
Michael Flath
Project 2
This file is changedp.cpp

Summary: This algorithm will use dynamic programming to calculate the least amount of 
coins for any given amount, num.

*******************************************/

#include <iostream>
#include <climits>
using namespace std;

struct Coins {
	int size_den;
	int minCoins;
	int C[5000];
};

Coins min_change(int Den[], int numDen, int newAmount) {
	Coins change;
	change.size_den = numDen;
	int index[numDen];
	int T[newAmount];	//Holds minimum amount of coins
	//change.C[numDen];	//Holds the amount of each coin used
	int i, j, coin, min;
	
	T[0] = 0;
	
	for(i = 1; i <= newAmount; i++) {
		min = INT_MAX;
		for(j = 0; j < numDen; j++) {
			index[j] = 0;
			if(Den[j] <= i) {
				if((1 + T[i - Den[j]]) < min) {
					min = (1 + T[i - Den[j]]);
					coin = j;
				}
			}
		}
		T[i] = min;
		change.C[i] = coin;		
	}
	
	

	cout << endl;
	int num = newAmount;
	cout << "T[newAmount]: " << T[newAmount] << endl;
	
	//Outputs the coins used to produce the minimum amount of change to add up to the amount.
	while(num > 0) {
		index[change.C[num]] += 1;
		//cout << Den[change.C[num]] << endl;
		num = num - Den[change.C[num]];	
	}
	cout << endl;
	//Outputs the number of times each coin is used
	int x;
	for(x = 0; x < numDen; x++)
		cout << index[x] << " ";
	
	cout << endl;
	
	return change;
}

int main(int argc, char *argv[]) {
	Coins resultA, resultB, resultC, resultD;
	int test1[4] = {1,2,4,8};
	int amountA = 15;
	
	int test2[4] = {1,3,7,12};
	int amountB = 29;
	
	int test3[4] = {1,3,7,12};
	int amountC = 31;
	
	int test4[5] = {1, 5, 10, 25, 50};
	int amountD = 2015;
	
	resultD = min_change(test4, 5, amountD);
	
	//resultA = min_change(test1, 4, amountA);	
	
	//resultB = min_change(test2, 4, amountB);
	
	//resultC = min_change(test3, 4, amountC);
	
	return 0;
}
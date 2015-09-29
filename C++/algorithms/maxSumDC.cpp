/*
Michael Flath
Divide and Conquer 
Find Max sum within a list of integers.

*/

#include <iostream>
#include <fstream>
#include <cstdlib>

using namespace std;

int max(int a, int b) { 
	if (a > b)
		return a;
	else 
		return b;
}

int crossingSum(int arr[], int newlo, int newmid, int newhi) {
	
	int MaxLeft, MaxRight;
	int maxCross;
	int sum = 0;
	
	//Left side Max
	MaxLeft = 0;	
	for (int i = newmid; i >= 0; i--) {
		sum += arr[i];
		if (sum > MaxLeft)
			MaxLeft = sum;
	}
	
	//Right side Max
	sum = 0;
	MaxRight = 0;
	for (int i = newmid + 1; i <= newhi; i++) {
		sum += arr[i];
		if (sum > MaxRight)
			MaxRight = sum;
	}
	
	
	maxCross = MaxRight + MaxLeft;
	
	return  maxCross; 
}

int algorithm3(int newArr[], int lo, int hi)
{	
	int mid;
	int leftMax = 0;
	int rightMax = 0;
	
	//base case, only 1 element in array
	if (lo == hi) { 
		return newArr[lo];
	}
	
	mid = (lo + hi)/2;
	
	return max(max(algorithm3(newArr, lo, mid), algorithm3(newArr, mid+1, hi)), crossingSum(newArr, lo, mid, hi));
}

int main(int argc, char *argv[]) {
	int maxSumA, maxSumB, maxSumC, maxSumD, maxSumE, maxSumF, maxSumG, maxSumH;
	
	int testarrA[16] = {1, 4, -9, 8, 1, 3, 3, 1, -1, -4, -6, 2, 8, 19, -10, -11};
	int testarrB[15] = {2, 9, 8, 6, 5, -11, 9, -11, 7, 5, -1, -8, -3, 7, -2}; //no comma between 7 and -2
	int testarrC[12] = {10, -11, -1, -9, 33, -45, 23, 24, -1, -7, -8, 19};  //no comma between 7 and -8
	int testarrD[10] = {31,-41, 59, 26, -53, 58, 97, -93, -23, 84};
	int testarrE[9] = {3, 2, 1, 1, -8, 1, 1, 2, 3};
	int testarrF[10] = {12, 99, 99, -99, -27, 0, 0, 0, -3, 10};
	int testarrG[9] = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
	int testarrH[3] = {-1, -3, -5};
	
	
	cout << "Test A: " << endl;
	maxSumA = algorithm3(testarrA, 0, 15);
	cout << "Max sum: " << maxSumA << endl;
	
	cout << "Test B: " << endl;
	maxSumB = algorithm3(testarrB, 0, 14);
	cout << "Max sum: " << maxSumB << endl;
	
	cout << "Test C: " << endl;
	maxSumC = algorithm3(testarrC, 0, 11);
	cout << "Max sum: " << maxSumC << endl;
	
	cout << "Test D: " << endl;
	maxSumD = algorithm3(testarrD, 0, 9);
	cout << "Max sum: " << maxSumD << endl;
	
	cout << "Test E: " << endl;
	maxSumE = algorithm3(testarrE, 0, 8);
	cout << "Max sum: " << maxSumE << endl;
	
	cout << "Test F: " << endl;
	maxSumF = algorithm3(testarrF, 0, 9);
	cout << "Max sum: " << maxSumF << endl;
	
	cout << "Test G: " << endl;
	maxSumG = algorithm3(testarrG, 0, 8);
	cout << "Max sum: " << maxSumG << endl;
	
	cout << "Test H: " << endl;
	maxSumH = algorithm3(testarrH, 0, 2);
	cout << "Max sum: " << maxSumH << endl;
	
	return 0;
}
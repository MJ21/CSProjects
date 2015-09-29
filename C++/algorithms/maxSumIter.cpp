/*
Michael Flath
Find Max sum: Iterative approach
*/
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cctype>
#include <vector>
#include <string.h>
#include <cstdlib>

using namespace std;

int algorithm2(int newArr[], int newSize) {
	//ofstream fout;
	int max = 0;
	int sum = 0;
	int lo_index;
	int hi_index;
	
	for(int i = 0; i < newSize; i++) {
		sum = 0;
		for(int j = i; j < newSize; j++) {
			sum += newArr[j];
			
			if(sum > max) {
				lo_index = i;
				hi_index = j;
				max = sum;
			}
		}
	}
	
	cout << "Subarray: ";
	for(int x = lo_index; x <= hi_index; x++) {
		cout << newArr[x] << ", ";
	}
	
	cout << "Max sum: " << max << endl;

	cout << endl;
	
	return max;
}


int main(int argc, char *argv[]) {
	
	ifstream fin;
	int size = 0;
	int next = 0;
	int result, x;
	char line[256];

	int array[100];
	char tmp[5];
	
	fin.open("MSS_Problems.txt");
	if(!fin) {
		cout << "Error! File input would not open!" << endl;
		return 1;
	}
	
	
	if(fin.is_open())
	{
		while(!fin.eof())
		{	
					
			fin.getline(line, 256);
			
			//Parse line
			int i = 0; 
			int k = 0;
			for(int j = 0; j < strlen(line); j++) {
				
				if(line[j] == ' ') {
				
				}
				else if(line[j] == ',') {
					array[k] = atoi(tmp);
					k++;
					if(k == 1) {
						//cout << "Tmp: " << endl;
					}
					//print out each array by element
					size++;
					next++;
					memset(tmp, 0, sizeof(tmp));
				}
				else if(line[j] == '[' || line[j] == ']') {
				
				}
				else {
					if(next == 1) {
						next = 0;
						i = 0;
					}
					tmp[i] = line[j];
					i++;
				}
			}
			
			//add final number
			array[k] = atoi(tmp);
			size++;
			cout << endl;
			
			result = algorithm2(array, size);
			
			size = 0;
			memset(line, 0, sizeof(line));
			memset(array, 0, 100);
			
		}
		
		
	}
	fin.close();
	
	cout << "Done!" << endl;

	int newMaxA, newMaxB, newMaxC, newMaxD, newMaxE, newMaxF, newMaxG, newMaxH;
	int testarrA[16] = {1, 4, -9, 8, 1, 3, 3, 1, -1, -4, -6, 2, 8, 19, -10, -11};
	int testarrB[15] = {2, 9, 8, 6, 5, -11, 9, -11, 7, 5, -1, -8, -3, 7, -2}; //no comma between 7 and -2
	int testarrC[12] = {10, -11, -1, -9, 33, -45, 23, 24, -1, -7, -8, 19};  //no comma between 7 and -8
	int testarrD[10] = {31,-41, 59, 26, -53, 58, 97, -93, -23, 84};
	int testarrE[9] = {3, 2, 1, 1, -8, 1, 1, 2, 3};
	int testarrF[10] = {12, 99, 99, -99, -27, 0, 0, 0, -3, 10};
	int testarrG[9] = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
	int testarrH[3] = {-1, -3, -5};
	
	
	cout << "Test A: " << endl;
	newMaxA = algorithm2(testarrA, 16);
	cout << "Test B: " << endl;
	newMaxB = algorithm2(testarrB, 15);
	cout << "Test C: " << endl;
	newMaxC = algorithm2(testarrC, 12);
	cout << "Test D: " << endl;
	newMaxD = algorithm2(testarrD, 10);
	cout << "Test E: " << endl;
	newMaxE = algorithm2(testarrE, 9);
	cout << "Test F: " << endl;
	newMaxF = algorithm2(testarrF, 10);
	cout << "Test G: " << endl;
	newMaxG = algorithm2(testarrG, 9);
	cout << "Test H: " << endl;
	newMaxH = algorithm2(testarrH, 3);
	
  return 0;
}


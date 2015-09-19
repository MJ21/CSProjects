/****************************************
 * Michael Flath
 * CS165 Project: Game of life
 * 
 * Input: User will choose 3 locations on the grid to beget live cells.
 *
 * Ouput: The grid's  mutatation depends on the number of live cells inputed into the grid and to the rules of the game.
 *
 * Overview: This program is written according to Conway's Game of Life.
 *****************************************/
#include <iostream>
#include <string>

using namespace std;

void copy(char arrA[22][80], char arrB[22][80]);
void generation(char newArr[22][80]);
void print(char arr[22][80]);


int main(int argc, char *argv[])
{
	
	char world[22][80];
	char newgrid[22][80];
	int pos1, pos2;
	char ans; // To enter another living cell.

	cout << "The Game of Life " << endl;
	cout << "RULES: " << endl;
	cout << "Choose the locations of any amount of living cells anywhere in the grid. \n Enter any number between 0 and 22 for the row and 0 and 80 for the column (row, column).\n If an occupied cell has 0 or 1 neighboring cell(s), the cell will die of loneliness.\n If the cell has more than 3 neighboring cells, the cell will die of overcrowding.\n If an empy cell has 3 neighboring cells, the cell is born." << endl; 
	//Enter any amount of living cells within the grid.
	do 
	{
		cout << "Enter a living cell: ";
		cin >> pos1 >> pos2;
		world[pos1-1][pos2-1] = '*';
		cout << "Enter another living cell? (Y/N)" << endl;
		cin >> ans;
		
	}while(ans == 'Y' || ans == 'y');

	copy(world, newgrid);
	cout << "**********FIRST GENERATION**********" << endl;
	print(newgrid);
	generation(newgrid);

	return 0;
}
//Copy's the new generation of cells
void copy(char arrA[22][80], char arrB[22][80])
{
	for(int i = 0; i < 22; i++)
	{
		for(int j = 0; j < 80; j++)
		{
			arrB[i][j] = arrA[i][j];
		}
	}
}
//Uses a loop to check the eight cells around each cell.
void generation(char newArr[22][80])
{
	char oldarr[22][80];
	char temp[22][80];
	char ans;
	copy(newArr, oldarr);
	copy(oldarr, temp);
	int match = 0;
	int x = 22;
	int y = 80;
	//Loop through each cell. Adds up the total living cells around cell target.
	do
	{
		for(int i = 0; i < 22; i++)
		{	
	
			for(int j = 0; j < 80; j++)
			{
				int total = 0;
				int a = 0;
				int b = 0;
				int c = 0;
				int d = 0;
				int e = 0;
				int f = 0;
				int g = 0;
				int h = 0;
				//Check the eight cells around the cell target.
				if(newArr[(i-1+x)%x][(j-1+y)%y] == '*')
					a += 1;	
				if(newArr[(i-1+x)%x][j] == '*')
					b += 1;	
				if(newArr[(i-1+x)%x][(j+1)%y] == '*')
					c += 1;
				if(newArr[i][(j-1+y)%y] == '*')
					d += 1;
				if(newArr[i][(j+1)%y] == '*')
					e += 1;
				if(newArr[(i+1)%x][(j-1+y)%y] == '*')
					f += 1;
				if(newArr[(i+1)%x][j] == '*')
					g += 1;
				if(newArr[(i+1)%x][(j+1)%y] == '*')
					h += 1;
				total = a + b + c + d + e + f + g + h; 
				//Check * total to produce a live cell, or allow cell to remain, or terminate cell.
				//cout << "total: " << i << " " << j << " = " << total << endl;
									
				//0 or 1 neighbor or more than 3 neighbors results in cell death.
				if(total < 2 || total > 3)
				{
					temp[i][j] = ' ';
			
				}
				if(total == 2) //Cell remains
				{
					temp[i][j] = newArr[i][j];
				}
				if(total == 3)//Cell birth
				{
					temp[i][j] = '*';
				}
			}	
		}
		copy(temp, newArr);
		print(newArr);
		cout << "Continue Simulation?" << endl;
		cin >> ans;
	}while(ans == 'Y' || ans == 'y');
}
//Print generation
void print(char arr[22][80])
{
	cout << "---------------------------------------------------------------------------------" << endl;
	for(int i = 0; i < 22; i++)
	{
		for(int j = 0; j < 80; j++)
		{
			if(arr[i][j] == '*')
			{
				cout << '*';
			}
			else
				cout << ' ';
		}
		cout << endl;
	}
	cout << "--------------------------------------------------------------------------------" << endl;
}

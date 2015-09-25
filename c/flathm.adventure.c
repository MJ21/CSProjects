/*
Name: Michael Flath
Maze game.
 */
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <time.h>

//This function removes the newline character from the standard input via fgets()
void removeNewline( char *str, int size) {
	int i;
	for (i = 0; i < size; ++i) {
		if( str[i] == '\n') {
			str[i] = '\0';
			return;
		}
	}
}

int main() {
	//Get process id
	int pid = getpid();
	time_t t;
	
	//Initialize random number generator
	srand((unsigned) time(&t));
	
	//Char array of room names
	char *roomNames[] = {"Black", "White", "Silver", "Purple", "Orange", "Yellow", "Blue", "Green", "Brown", "Red"};
	int *roomNum[7];
	char *win[8];
	char dirname[50];
	
	//Create directory for room files
	sprintf(dirname, "flathm.rooms.%d", pid);
	int retval;
	retval = mkdir(dirname, 0777);
	if(retval != -1)
		//printf("Directory created!\n");
	
	//Create 7 rooms in directory, open each file and write contents: Assign random name, type, and connections
	FILE *fin, *fout;
	int i, rnum1, rnum2, rnum3, rnum4;
	char fname[50];
	
	//Generate contents of each file- name, connections, room_type
	for(i=0;i<7;i++) {
	
		sprintf(fname, "flathm.rooms.%d/Rm%d", pid, i);
		fin = fopen(fname, "w");
		if(!fin)
			printf("%s could not open", fname);
		
		if(i == 0) {
			// Generate Random Start room and 3 connections
			int j = 0;
			while (j != 1) {
				rnum1 = rand() % 10;
				rnum2 = rand() % 10;
				rnum3 = rand() % 10;
				rnum4 = rand() % 10;
				
				//Make sure each random room selection is different
				if(rnum1 == rnum2 || rnum1 == rnum3 || rnum1 == rnum4)
					j = 0;
				else if(rnum2 == rnum3 || rnum2 == rnum4)
					j = 0;
				else if(rnum3 == rnum4)
					j = 0;
				else 
					j = 1;
			}
			//Keep track of which files equal to which room names and their index numbers in roomNames array
			roomNum[i] = rnum1;
			win[i] = roomNames[rnum1];
			
			//**********Display the first file's room name
			//printf("\n%s is Room %d\n", roomNames[rnum1], i);
			
			//Write room name, connections, and room_type into file
			fprintf(fin, "ROOM NAME: %s\n", roomNames[rnum1]);
			fprintf(fin, "CONNECTION 1: %s\n", roomNames[rnum2]);
			fprintf(fin, "CONNECTION 2: %s\n", roomNames[rnum3]);
			fprintf(fin, "CONNECTION 3: %s\n", roomNames[rnum4]);
			fprintf(fin, "ROOM TYPE: %s\n", "START_ROOM");
				
		}
		//Randomly generate contents for files 2-6
		else if(i > 0 && i < 6) {
			int x;
			//Randomly choose a connection from one room to the next room
			x = (rand() % 3) + 1;
			if(x == 1)
				rnum1 = rnum2;
			else if(x == 2)
				rnum1 = rnum3;
			else if(x == 3)
				rnum1 = rnum4;
			else printf("Error! No connection to room 2 from room 1."); 
			
			int j = 0;
			while (j != 1) {
				
				rnum2 = rand() % 10;
				rnum3 = rand() % 10;
				rnum4 = rand() % 10;
				
				//Make sure each random room selection is different
				if(rnum1 == rnum2 || rnum1 == rnum3 || rnum1 == rnum4)
					j = 0;
				else if(rnum2 == rnum3 || rnum2 == rnum4)
					j = 0;
				else if(rnum3 == rnum4)
					j = 0;
				else 
					j = 1;
			}
			
			//Check if random selection is used already
			int m, numtaken;			
			for(m=0; m<=i; m++) {
				if(rnum1 == roomNum[m]) {
					numtaken = 1;
				}				
			}
			
			//If randomly selected room name has been used, then find and select unused room name
			if(numtaken == 1) {
				int y, z, unused;
				int index = 0;
				for(y=0; y<10; y++) {
					for(z=0;z<=i;z++) {
						if(roomNum[z] == y) {
								index++;
						}
						else {
							unused = y;
						}
					}
					if(index == 0) {
							rnum1 = unused;
					}
					index = 0;
				}
			}
				
			roomNum[i] = rnum1;
			win[i] = roomNames[rnum1];
			
			//**********Display which room/file equals which room name
			//printf("%s is Room %d\n", roomNames[rnum1], i);
			
			//Write randomly generated contents into files
			fprintf(fin, "ROOM NAME: %s\n", roomNames[rnum1]);
			fprintf(fin, "CONNECTION 1: %s\n", roomNames[rnum2]);
			fprintf(fin, "CONNECTION 2: %s\n", roomNames[rnum3]);
			fprintf(fin, "CONNECTION 3: %s\n", roomNames[rnum4]);
			if(roomNum[i-1] != rnum2 && roomNum[i-1] != rnum3 && roomNum[i-1] != rnum4)
				fprintf(fin, "CONNECTION 4: %s\n", win[i-1]);			//Connection back to previous room
			fprintf(fin, "ROOM TYPE: %s\n", "MID_ROOM");
			
		}
		//Generate random content for room/file 7
		else {
			int x;
			
			//Randomly choose a connection from room 6 to connect to room 7
			x = (rand() % 3) + 1;
			if(x == 1)
				rnum1 = rnum2;
			else if(x == 2)
				rnum1 = rnum3;
			else if(x == 3)
				rnum1 = rnum4;
			else printf("Error! No connection to room 6 from room 7.");
			
			//Generate random END_ROOM and 3 connections
			int j = 0;
			while (j != 1) {
				rnum2 = rand() % 10;
				rnum3 = rand() % 10;
				rnum4 = rand() % 10;
				
				//Make sure each random room selection is different
				if(rnum1 == rnum2 || rnum1 == rnum3 || rnum1 == rnum4)
					j = 0;
				else if(rnum2 == rnum3 || rnum2 == rnum4)
					j = 0;
				else if(rnum3 == rnum4)
					j = 0;
				else 
					j = 1;
			}
			
			//Check if random selection is used already
			int m, numtaken;			
			for(m=0; m<=i; m++) {
				if(rnum1 == roomNum[m]) {
					numtaken = 1;
				}				
			}
			
			//If randomly selected room name has been used, then find and select unused room name
			if(numtaken == 1) {
				int y, z, unused;
				int index = 0;
				for(y=0; y<10; y++) {
					for(z=0;z<=i;z++) {
						if(roomNum[z] == y) {
								index++;
						}
						else {
							unused = y;
						}
					}
					if(index == 0) {
							rnum1 = unused;
					}
					index = 0;
				}
			}
			
			roomNum[i] = rnum1;
			win[i] = roomNames[rnum1];
			
			//***********Display file 7's room name
			//printf("%s is Room %d\n", roomNames[rnum1], i);
			
			//Write randomly generated contents to file 7
			fprintf(fin, "ROOM NAME: %s\n", roomNames[rnum1]);
			fprintf(fin, "CONNECTION 1: %s\n", roomNames[rnum2]);
			fprintf(fin, "CONNECTION 2: %s\n", roomNames[rnum3]);
			fprintf(fin, "CONNECTION 3: %s\n", roomNames[rnum4]);
			if(roomNum[i-1] != rnum2 && roomNum[i-1] != rnum3 && roomNum[i-1] != rnum4)
				fprintf(fin, "CONNECTION 4: %s\n", win[i-1]);			//If there is none, write connection back to previous room
			fprintf(fin, "ROOM TYPE: %s\n", "END_ROOM");
			
		}
		
		fclose(fin);
	}
	
	/**********************************Start Game************************************/
	char *final[20];
	char Readfile[50];
	int n = 0;
	int steps = 0;
	char a[10], b[10], c[10];
	char name[10], con1[10], con2[10], con3[10], con4[10], con5[10];
	
	//Open START_ROOM 
	sprintf(Readfile, "flathm.rooms.%d/Rm0", pid);
	fout = fopen(Readfile, "r");
	
	//Open file, START_ROOM, and read contents - name, connection 1, 2, 3 into variables a, b, c
	if(fout != NULL) {
	
		while(fscanf(fout, "%s %s %s", &a, &b, &c) == 3) {
			
			if(n == 0)
				sprintf(name, "%s", c);
			else if(n == 1)
				sprintf(con1, "%s", c);
			else if(n == 2)
				sprintf(con2, "%s", c);
			else if(n == 3)
				sprintf(con3, "%s", c);
			else if(n == 4)
				sprintf(con4, "%s", c);
			else 
				sprintf(con5, "%s", c);
				
			n++;
		}
		rewind(fout);
		fclose(fout);
	}
	
	//Receive standard input for next room and check for correct input, otherwise report error.
	int correct = 0;
	char answer[10];
	
	while(correct != 1) {
		//Check number of connections and print accordingly
		if(n == 5) {
			printf("\n");
			printf("CURRENT LOCATION: %s\n", name);
			printf("POSSIBLE CONNECTIONS: %s, %s, %s.\n", con1, con2, con3);
			printf("WHERE TO? >");
		}
		else {
			printf("\n");
			printf("CURRENT LOCATION: %s\n", name);
			printf("POSSIBLE CONNECTIONS: %s, %s, %s, %s.\n", con1, con2, con3, con4);
			printf("WHERE TO? >");
		}
		
		//Get standard input
		fgets(answer, 10, stdin);
		removeNewline(answer, 10);
		
		//Check answer selection- answer must be of the three choices and include exact spelling.
		if(strcmp(answer, con1) == 0) {
			correct = 1;
		}
		else if(strcmp(answer, con2) == 0) {
			correct = 1;
		}
		else if(strcmp(answer, con3) == 0) {
			correct = 1;
			
		}
		else if (strcmp(answer, con4) == 0) {
			correct = 1;
		}
		else {
			printf("\n");
			printf("\nHUH? I DON'T UNDERSTAND THAT ROOM. TRY AGAIN.\n");
			printf("\n");
			
		}
		
	}
	
	int exit = 0;
	char openroom[50];
	char name2[10], connect1[10], connect2[10], connect3[10], connect4[10], connect5[10];
	
	//If the END_ROOM is located with first guess, do not enter into while loop.
	if(strcmp(answer, win[6]) == 0) {
		exit = 1;
	}
	//Run game until the END_ROOM is reached
	while(exit != 1) {
				
		int number, rm, k;
		
		//Search for file name that is equal to standard input- user's room selection.
		for(i = 0; i < 10; i++) {
			if(strcmp(answer, roomNames[i]) == 0) {
				number = i;
				final[steps] = roomNames[i];
				steps++;
				for(k = 0; k < 7; k++) {
					if(number == roomNum[k]) 
						rm = k;
				}
			}
		}
		
		//Open file/room selection
		sprintf(openroom, "flathm.rooms.%d/Rm%d", pid, rm);
		fout = fopen(openroom, "r");
	
		//Read contents of each room that has been selected- name, connection 1, 2, 3, and/or 4 into char variables
		if(fout != NULL) {
	
			k = 0;
			while(fscanf(fout, "%s %s %s", &a, &b, &c) == 3) {
				if(k == 0)
					sprintf(name2, "%s", c);
				else if(k == 1)
					sprintf(connect1, "%s", c);
				else if(k == 2)
					sprintf(connect2, "%s", c);
				else if(k == 3)
					sprintf(connect3, "%s", c);
				else if(k == 4)
					sprintf(connect4, "%s", c);
				else 
					sprintf(connect5, "%s", c);
					
				k++;
			}
			rewind(fout);
			fclose(fout);
		}
		
		int close1 = 0;
		
		//Print contents of selected file, ask for another selection/standard input, check for correct input.
		while(close1 != 1) {
			
			if(k == 5) {
				printf("\n");
				printf("CURRENT LOCATION: %s\n", name2);
				printf("POSSIBLE CONNECTIONS: %s, %s, %s.\n", connect1, connect2, connect3);
				printf("WHERE TO? >");
			}
			else {
				printf("\n");
				printf("CURRENT LOCATION: %s\n", name2);
				printf("POSSIBLE CONNECTIONS: %s, %s, %s, %s.\n", connect1, connect2, connect3, connect4);
				printf("WHERE TO? >");
			}
			
			//Receive standard input
			fgets(answer, 10, stdin);
			removeNewline(answer, 10);
			
			//Check for correct input. Input must match previous list of connections
			if(strcmp(answer, connect1) == 0) {
				close1 = 1;
			}
			else if(strcmp(answer, connect2) == 0) {
				close1 = 1;
			}
			else if(strcmp(answer, connect3) == 0) {
				close1 = 1;
			}
			else if(strcmp(answer, connect4) == 0) {
				close1 = 1;
			}
			else {
				printf("\n");
				printf("\nHUH? I DON'T UNDERSTAND THAT ROOM. TRY AGAIN.\n");
				printf("\n");
				
			}
		} 
		//If answer = end room, exit game
		if(strcmp(answer, win[6]) == 0) {
			exit = 1;
		}
		
	}
	
	//Display results of Game if the user found the end room.
	steps++;
	printf("\n");
	printf("YOU HAVE FOUND THE END ROOM. CONGRATULATIONS!\n");
	printf("YOU TOOK %d STEPS. YOUR PATH TO VICTORY WAS:\n", steps);
	int h;
	for(h = 0; h < steps - 1; h++) {
		printf("%s\n", final[h]);
	} 
	printf("%s\n", answer);
	
	return 0;
}

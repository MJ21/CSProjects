/*************************************************************************************************************
Name: Michael Flath

Description: 
	This program is a Unix shell written in C. It will process both foreground and background commands. 
	There are 3 built in commands: exit, cd, and status. This shell will allow comment lines beginning with '#'. 
 **************************************************************************************************************/
 
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>
#include <signal.h>
#include <fcntl.h>

struct Status {
	char *type;
	int statusNum;
};

void removeNewline( char *str, int size);
int parseArgs(char* newLine, char** newCommand);
int execute_builtin(char** Newargs, int newSize, struct Status *newStatus);
int execute_command(char** command, int newSize, struct Status *newStatus);
void outputcommand(char** Newargs, struct Status *newStatus, int arraynum, int Size);
void inputcommand(char** Newargs, struct Status *newStatus, int arraynum, int Size);
void checkstatus(struct Status *newStatus);

int main(int argc, char **argv[])
{
	while(1)
	{
		
		struct Status exitstatus, *pstatus;
		pstatus = &exitstatus;
		char *arg[520];
		char line[520];
		int numArgs;
		int exitnum;
		pid_t pid;
		int backstatus, i;
		
		pid = waitpid(-1, &backstatus, WNOHANG); 
		if(pid > 0)
		{
			printf("background pid %d is done: ", pid);
			if (WIFEXITED(backstatus))
			{
				exitstatus.type = "exit";
				exitstatus.statusNum = backstatus;
				printf("Exit value %d\n", backstatus);
			}
			else if (WIFSIGNALED(backstatus))
			{
				exitstatus.type = "signal";
				exitstatus.statusNum = backstatus;
				printf("terminated by signal %d\n", backstatus);
			} 
		}	
		
		//Command prompt for new commands
		printf(": ");
		fflush(stdout);
		
		//Receive commands from the standard input
		fgets(line, 520, stdin);
		
		if(feof(stdin))
		{
			exit(1);
		}
		removeNewline(line, 520);
		
		//*****Call Parsing function to parse commands into an array of strings****
		numArgs = parseArgs(line, arg);
		
		if(arg[0] == NULL)
		{
			continue;
		}
		
		exitnum = execute_builtin(arg, numArgs, pstatus);

		memset(arg, 0, 520);
		
	}
	return EXIT_SUCCESS;
}

void removeNewline( char *str, int size) 
{
	int i;
	for (i = 0; i < size; ++i) {
		if( str[i] == '\n' || str[i] == EOF) {
			str[i] = '\0';
			return;
		}
	}
}

int parseArgs(char* newLine, char** newCommand) 
{
	char *token;
	int size = 0; 
	// Use spaces " " as a delimeter.
	token = strtok(newLine, " ");
	while (token != NULL)
	{
		newCommand[size] = token;
		token = strtok(NULL, " ");
		size++;
	}
	return size;
} 

void checkstatus(struct Status *newStatus)
{
	if (strcmp(newStatus->type, "exit") == 0)
	{
		printf("Exit value %d\n", newStatus->statusNum);
	}
	else if (strcmp(newStatus->type, "signal") == 0)
	{
		printf("terminated by signal %d\n", newStatus->statusNum);
	}
} 

int execute_builtin(char** Newargs, int newSize, struct Status *newStatus)
{
	char dir[100];
	int i, exitval;
	
	//Check arguments for I/O redirection symbols. Execute I/O redirection function if symbols are found.
	for(i = 0; i < newSize; i++)
	{
		if (strcmp(Newargs[i], ">") == 0)
		{
			//call function output
			outputcommand(Newargs, newStatus, i, newSize);
			return 0;
		}
		else if (strcmp(Newargs[i], "<") == 0)
		{
			//call function input
			inputcommand(Newargs, newStatus, i, newSize);
			return 0;
		}
	}
	
	//Check and execute built in commands: cd, exit, status. Check for comments: "#"
	if(strcmp(Newargs[0], "cd") == 0)
	{
		if(Newargs[1] == NULL)
		{
			chdir(getenv("HOME"));
		}
		else
		{
			getcwd(dir, sizeof(dir)); 
			strcat(dir, "/");			
			strcat(dir, Newargs[1]);	
			if(chdir(dir) == -1)	
			{
				perror("smallsh");
				return 1;
			}
		}
		return 0;
	}
	//Exit smallsh if exit command is entered (exit or Exit).
	else if(strcmp(Newargs[0], "exit") == 0 || strcmp(Newargs[0], "Exit") == 0)
	{
		 exit(EXIT_SUCCESS);
	}
	//Check and print exit status or terminating signal
	else if(strcmp(Newargs[0], "status") == 0)
	{
		checkstatus(newStatus);
		return 0;
	}
	//Return if the line is a comment "#".
	else if(strcmp(Newargs[0], "#") == 0)
	{
		return 0;
	}
	//Execute commands by starting and running a new process via fork() and execvp().
	else exitval = execute_command(Newargs, newSize, newStatus);
	
	return exitval;	
}

int execute_command(char** command, int newSize, struct Status *newStatus)
{
	pid_t pid, wpid;
	int status;
	int background = 0;
	
	pid = fork();
	//Check for background process command "&"
	if(strcmp(command[newSize-1], "&") == 0)
	{
		command[newSize-1] = NULL;
		background = 1;
	}
	if (pid == 0) //Fork() returns 0 if in child process
	{
		if(execvp(command[0], command) == -1) 
		{
			perror("smallsh");
			exit(EXIT_FAILURE);
		}		
	}
	else if (pid < 0) //Fork returns -1 if an Error has occurred.
	{
		perror("smallsh");
		return 1;
	}
	else 
	{	

		if(background != 1)
		{

			if(signal(SIGINT, SIG_IGN))
			{
				kill(pid, SIGINT);
			}
			do
			{
				wpid = waitpid(pid, &status, WUNTRACED); 
			}while(!WIFEXITED(status) && !WIFSIGNALED(status));
		}
		else
		{
			signal(SIGINT, SIG_IGN); 
			printf("background pid is %d\n", pid);	
			
			return 0;
		}
	}

	if (WIFEXITED(status))
	{
		newStatus->type = "exit";
		if(status == 256)
			status = 1;
		newStatus->statusNum = status;
	}
	else if (WIFSIGNALED(status))
	{
		newStatus->type = "signal";
		newStatus->statusNum = status;
	}
	
	return status;
}

void outputcommand(char** Newargs, struct Status *newStatus, int arraynum, int Size)
{
	int background = 0;
	int fdin, fdin2, fd1, fd2;
	int status;
	
	if(strcmp(Newargs[Size-1], "&") == 0)
	{
		background = 1;
		Newargs[Size-1] = NULL;
	}
	Newargs[arraynum] = NULL; 
	
	pid_t pid, wpid;
	pid = fork();
	if(pid == 0) 
	{
		
		if(Newargs[arraynum-1] == NULL)
		{
			fdin = open("/dev/null", O_RDONLY);
			if (fdin == -1)
			{
				perror("open");
			}
			fcntl(fdin, F_SETFD, 1); 
			fdin2 = dup2(fdin, 0); 
			if (fdin2 == -1)
			{
				
				exit(EXIT_FAILURE);
			}
		}
		
		fd1 = open(Newargs[arraynum+1], O_WRONLY | O_CREAT | O_TRUNC, S_IRWXU | S_IRGRP | S_IROTH);
		if (fd1 == -1)
		{
			perror("open");
		}
		fcntl(fd1, F_SETFD, 1); //close on exec
		fd2 = dup2(fd1, 1); //Redirect stdout to new output file.
		if (fd2 == -1)
		{
			//perror("dup2");
			exit(EXIT_FAILURE);
		}
		if(execvp(Newargs[0], Newargs) == -1)
		{
			perror("smallsh");
			exit(EXIT_FAILURE);
		}
		close(fd1);
	
	}
	else if (pid < 0) //perror: fork failed
	{
			perror("smallsh");
	}
	else // Parent process
	{

		if (background != 1)
		{
			
			if (signal(SIGINT, SIG_IGN))	
			{
				kill(pid, SIGINT);
			}
			do
			{
				wpid = waitpid(pid, &status, WUNTRACED | WCONTINUED);
			}while (!WIFEXITED(status) && !WIFSIGNALED(status)); 
		}
		else
		{
			signal(SIGINT, SIG_IGN); 
			printf("background pid is %d\n", pid);
	
			return;
		}
	}	

	if (WIFEXITED(status))
	{
		newStatus->type = "exit";
		newStatus->statusNum = status;
	}
	else if (WIFSIGNALED(status))
	{
		newStatus->type = "signal";
		newStatus->statusNum = status;
	}		
}

void inputcommand(char** Newargs, struct Status *newStatus, int arraynum, int Size)
{
	int background = 0;
	int fd1, fd2;
	int status;

	if(strcmp(Newargs[Size-1], "&") == 0)
	{
		background = 1;
		Newargs[Size-1] = NULL;
	}
	Newargs[arraynum] = NULL;
	
	pid_t pid, wpid;
	pid = fork();
	if(pid == 0) 
	{
		
		fd1 = open(Newargs[arraynum+1], O_RDONLY, S_IRWXU | S_IRGRP | S_IROTH);
		if (fd1 == -1)
		{
			perror("open");
		}
		fcntl(fd1, F_SETFD, 1); 
		fd2 = dup2(fd1, 0);		
		if (fd2 == -1)
		{
		
			exit(EXIT_FAILURE);
		}
		if(execvp(Newargs[0], Newargs) == -1)
		{
			perror("smallsh");
			exit(EXIT_FAILURE);
		}
		close(fd1);
	}
	else if (pid < 0) //fork failed
	{
			perror("smallsh");
	}
	else 
	{
		if (background != 1)
		{
	
			if (signal(SIGINT, SIG_IGN))
			{
				kill(pid, SIGINT);
			}
			do
			{
				wpid = waitpid(pid, &status, WUNTRACED | WCONTINUED);
			}while (!WIFEXITED(status) && !WIFSIGNALED(status));
		}
		else
		{
			signal(SIGINT, SIG_IGN); 
			printf("background pid is %d\n", pid);
			return;
		}
	}	
	
	if (WIFEXITED(status))
	{
		newStatus->type = "exit";
		newStatus->statusNum = status;
	}
	else if (WIFSIGNALED(status))
	{
		newStatus->type = "signal";
		newStatus->statusNum = status;
	}
}
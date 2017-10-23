#include <stdio.h> // standard I/O
#include <stdlib.h> // exit function
#include <string.h> // control C string data type
#include <unistd.h> // pipe
#include <sys/types.h> // fork
#include <sys/wait.h>

#define MAX_ARG 8
#define MAX_LENGTH 32
#define MAX_LINE 256 /* maximum number of letters in a single line */
#define END_CMD "goodbye"
#define PROMPT "allen-prompt>"
#define IS_WHITE_SPACE(x) ((x) == ' ' || (x) == '\t')
#define IS_EOS(x) ((x) == '\0')
#define PREFIX "/bin/"
#define SEPARATOR " "

int main(int argc, char **argv)
{
	int i, arg_num;
	char inputLine[MAX_LINE];
	char parse[MAX_ARG][MAX_LENGTH];
	char *arg[MAX_ARG];
	char *token = NULL;
	
	pid_t pid;
	int status;
	
	while (1) {
		/* print prompt & enter command */
		printf("%s", PROMPT);
		fgets(inputLine, MAX_LINE, stdin);
		inputLine[strlen(inputLine)-1] = '\0';

		/* condition: exit program */
		if (strcmp(inputLine, END_CMD) == 0) { 
			printf("Bye Seongmin!\n");
			break;
		}
		
		/* parsing command */
		token = strtok(inputLine, SEPARATOR);
		for(i = 0; (token != NULL && i < MAX_ARG); ++i) {
			strcpy(parse[i], token);
			token = strtok(NULL, SEPARATOR);
		}
		arg_num = i;
		
		/* execute command */
		if (pid = fork()) { /* parent */
			waitpid(pid, &status, 0);
			// printf("Program is normally completed.\n");
		}
		else { /* child */
			char cmd[MAX_LENGTH+4] = PREFIX;

			for (i = 0; i < arg_num; ++i)
				arg[i] = parse[i];
			arg[i] = (char*)0;
		
			strcat(cmd, arg[0]);
			// printf("Child's cmd: %s\n", cmd);
			execl(cmd, arg[0], arg[1], arg[2], arg[3], arg[4], arg[5], arg[6], arg[7]);
		}
	}

	exit(0);
}


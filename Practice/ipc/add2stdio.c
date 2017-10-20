#include "ourhdr.h"

int main()
{
	int n, int1, int2;
	char line[MAXLINE];

	while (fgets(line, MAXLINE, stdin) != NULL) {
		if (sscanf(line, "%d%d", &int1, &int2) == 2) {
			printf(line, "%d\n", int1 + int2);
		}
		else {
			if (printf("invalid args\n") == EOF)
				err_sys("printf error");
		}
	}

	exit(0);
}

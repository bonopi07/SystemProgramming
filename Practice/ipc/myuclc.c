#include <ctype.h>
#include "ourhdr.h"
#include <unistd.h>
#include <fcntl.h>

int main()
{
	int c;
	
	while ((c = getchar()) != EOF) {
		if (isupper(c))
			c = tolower(c);
		if (putchar(c) == EOF)
			write(STDOUT_FILENO, "EOF entered", 12);
		if (c == '\n')
			fflush(stdout);
	}

	exit(0);
}

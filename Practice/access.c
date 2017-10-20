#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void main()
{
	char *filename = "afile";

	if (access(filename, R_OK) == -1) {
		fprintf(stderr, "User cannot read file %s\n", filename);
		exit(1);
	}

	printf("%s is readable, proceeding\n", filename);
}

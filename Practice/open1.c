#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>

char* workfile = "junk";

int main()
{
	int fileDes;

	if ((fileDes = open(workfile, O_WRONLY|O_CREAT, 0644)) == -1) {
		printf("new file created!\n");
	}
	else {
		printf("Open Successful!\n");
	}

	exit(0);
}

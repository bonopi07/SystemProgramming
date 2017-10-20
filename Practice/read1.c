#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

int main()
{
	char buffer[BUFSIZ];
	int fileDes;
	ssize_t nread;
	long total = 0;

	printf("BUFSIZE of this computer: %d\n", BUFSIZ);

	if ((fileDes = open("anotherfile", O_RDONLY)) == -1) {
		printf("error in opening anotherfile\n");
		exit(1);
	}

	while ((nread = read(fileDes, buffer, BUFSIZ)) > 0) {
		total += nread;
		printf("nread: %d\n", nread);
	}

	printf("total chars in anotherfile: %d\n", total);
	exit(0);

	return 0;
}

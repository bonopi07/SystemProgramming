#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

#define BUFSIZE 64
#define PERM 0644

int copyfile(const char* filename1, const char* filename2) {
	int infile, outfile;
	ssize_t nread;
	char buffer[BUFSIZE];

	if ((infile = open(filename1, O_RDONLY)) < 0) {
		return -1; // -1: flie open error
	}

	if ((outfile = open(filename2, O_WRONLY|O_CREAT|O_TRUNC, PERM)) < 0) {
		close(infile);
		return -2; // -2: cannot open filename2
	}

	while ((nread = read(infile, buffer, BUFSIZE)) > 0) {
		if (write(outfile, buffer, nread) < nread) {
			close(infile);
			close(outfile);
			return -3; // -3: cannot write filename2
		}
	}

	close(infile);
	close(outfile);

	if (nread < 0)
		return -4; // -4: occur error during final read
	else
		return 0; // 0: normal exit
}

int main() {
	printf("result: %d\n", copyfile("input.txt", "copyed.txt"));

	return 0;
}

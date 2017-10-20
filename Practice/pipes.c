#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>
#include "ourhdr.h"

int main(int argc, char **argv)
{
	int n, fin, fd[2];
	pid_t pid;
	char line[MAXLINE];

	if (pipe(fd) < 0)
		err_sys("pipe error");

	fin = open(argv[1], O_RDONLY);

	if ((pid = fork()) < 0)
		err_sys("fork error");
	else if (pid > 0) { // parent
		close(fd[0]);
		while ((n = read(fin, line, MAXLINE)))
			write(fd[1], line, n);
	}
	else {
		close(fd[1]);
		close(0);
		dup(fd[0]);
		execl("/bin/more", "more", (char*) 0);
	}

	exit(0);
}

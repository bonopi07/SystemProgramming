#include <sys/types.h>
#include <sys/wait.h>
#include "ourhdr.h"

int main()
{
	pid_t pid;

	if ((pid = fork()) < 0)
		err_sys("fork error");
	else if (pid == 0) { // first child
		if ((pid = fork()) < 0)
			err_sys("fork error");
		else if (pid > 0) // first child's parent
			exit(0);
		
		sleep(1);
		printf("second child, parent pid = %d\n", getppid());
		exit(0);
	}

	if (waitpid(pid, NULL, 0) != pid) // wait for first child
		err_sys("wait error");

	exit(0);
}

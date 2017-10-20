#include <sys/types.h>
#include <sys/wait.h>
#include "ourhdr.h"
#include "prexit.c"

int main()
{
	int status;
	pid_t pid;

	if ((pid = fork()) < 0)
		err_sys("fork error");
	else if (pid == 0) // child
		exit(7);
	if (wait(&status) != pid) // wait for child
		err_sys("wait error");
	pr_exit(status);

	if ((pid = fork()) < 0)
		err_sys("fork error");
	else if (pid == 0) // child
		abort();
	if (wait(&status) != pid) // wait for child
		err_sys("wait error");
	pr_exit(status);

	if ((pid = fork()) < 0)
		err_sys("fork error");
	else if (pid == 0) // child
		status /= 0;
	if (wait(&status) != pid) // wait for child
		err_sys("wait error");
	pr_exit(status);

	exit(0);
}

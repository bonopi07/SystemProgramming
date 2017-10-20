#include <sys/types.h>
#include "ourhdr.h"

int glob = 6;

int main()
{
	int var;
	pid_t pid;
	var = 88;

	printf("before fork\n");

	if ((pid = vfork()) < 0)
		err_sys("vfork error");
	else if (pid == 0) { // child
		glob++;
		var++;
		_exit(0);
	}

	// parent
	printf("pid = %d, glob = %d, var = %d\n", getpid(), glob, var);
	exit(0);
}

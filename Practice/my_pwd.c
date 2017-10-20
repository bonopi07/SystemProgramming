#include <stdio.h>
#include <unistd.h>

#define VERYBIG 200

void my_pwd(void)
{
	char dirname[VERYBIG];

	if (getcwd(dirname, VERYBIG) == NULL)
		printf("getcwd error");
	else
		printf("%s\n", dirname);
}

int main()
{
	my_pwd();

	return 0;
}

#include <dirent.h>
#include <stdio.h>

int my_double_ls(const char* name)
{
	struct dirent *d;
	DIR *dp;

	if ((dp = opendir(name)) == NULL)
		return -1;

	while (d = readdir(dp)) {
		if (d->d_ino != 0) {
			printf("%s\n", d->d_name);
		}
	}

	rewinddir(dp);

	closedir(dp);
	return 0;
}

int main(int argc, char *argv[])
{
	printf("\nfunction return value: %d\n", my_double_ls(argv[1]));

	return 0;
}

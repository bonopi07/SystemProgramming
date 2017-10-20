

int pclose(FILE *fp)
{
	int fd, stat;
	pid_t pid;

	if (childpid == NULL)
		return -1;

	fd = fileno(fp);

	if ((pid = childpid[fd]) < 0)
		return -1;

	childpid[fd] = 0;
	
	if (fclose(fp) == EOF)
		return -1;

	while (waitpid(pid, &stat, 0) < 0)
		if (errno != EINTR)
			return -1;
	return stat;
}

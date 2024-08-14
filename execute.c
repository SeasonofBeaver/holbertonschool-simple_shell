#include "shell.h"
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>

int _exec(char **args, char *command)
{
	pid_t pid;
	int status;

	pid = fork();
	if (pid == -1)
	{
		perror("fork");
		return 1;
	}
	if (pid == 0)
	{
		if (execve(args[0], args, environ) == -1)
		{
			perro(comman);
			exit(1);
		}
	}
	else
	{
		wait(&status);
		if (WIFEXITED(status))
		{
			return WEXITSTATUS(status);
		}
	}
	return 0;
}

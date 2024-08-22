#include "shell.h"

/**
 * _exec - executes the commandline
 *
 * @args: array of arguments of the commandline
 *
 * @command: the user input commandline
 *
 * Return: 0 if correct and non 0 if failed
 */


int _exec(char **args, char *command)
{
	pid_t pid;
	int status;

	pid = fork();
	if (pid == -1)
	{
		perror("fork");
		return (0);
	}
	if (pid == 0)
	{
		if (execve(args[0], args, environ) == -1)
		{
			perror(command);
			exit(127);
		}
	}
	else
	{
		wait(&status);
		if (WIFEXITED(status))
		{
			return (WEXITSTATUS(status));
		}
	}
	return (0);
}

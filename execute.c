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
	pid_t pid = 0;
	int status = 0, value = 0;

	pid = fork();
	if (pid == 0)
	{
		value = execve(args[0], args, environ);
		if (value == -1)
		{
			fprintf(stderr, "./hsh:  %s: not found\n", strtok(command, " "));
			exit(127);
		}
		exit(EXIT_SUCCESS);
	}
	else if (pid > 0)
	{
		wait(&status);
		if (WIFEXITED(status))
		{
			status = WEXITSTATUS(status);
		}
	}
	else
	{
		perror("fork process failed.");
		return (status);
	}

	return (status);
}

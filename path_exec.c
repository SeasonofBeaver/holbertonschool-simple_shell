#include "shell.h"
#include <sys/stat.h>

/**
 * find_path -find the full of a command if it exists in the PATH.
 * @comman: the command to find.
 *
 * Return: the full path if found, or NULL if not found.
 */
char *find_path(char *command)
{
	char *path, *token, *full_path;
	struct stat st;

	if (stat(command, &st) == 0)
	{
		return strdup(command);
	}
	path = getenv("PATH");
	if(path == NULL)
	{
		return (NULL);
	}

	path = strdup(path);
	if (path == NULL)
	{
		perror("strdup");
		return (NULL);
	}

	token = strtok(path, ":");
	while (token != NULL)
	{
		full_path = malloc(strlen(token) + strlen(command) + 2);
		if (full_path == NULL)
		{
			perror("malloc");
			free(path);
			return (NULL);
		}
		
		sprintf(full_path, "%s/%s", token, command);
		if (stat(full_path, &st) == 0)
		{
			free(path);
			return full_path;
		}
		free(full_path);
		token = strtok(NULL, ":");
	}

	free(path);
	return (NULL);
}

/**
 * _exec - executes a command bysearching for it in PATH.
 * @args: the command and its arguments.
 *
 * Return: 1 on success, -1 on failure.
 */
int _exec(char **args, char *command)
{
	char *path;

	path = find_path(command);
	if (path == NULL)
	{
		fprintf(stderr, "%s: comman notfound\n", command);
		return (-1);
	}
	args[0] = path;
	execve(args[0], args, environ);

	perror("execve");
	free(path);
	return (-1);
}

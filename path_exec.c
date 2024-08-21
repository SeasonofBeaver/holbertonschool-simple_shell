#include "shell.h"
#include <sys/stat.h>

/**
 * find_path - find the full of a command if it exists in the PATH.
 *
 * @command: the command to find.
 *
 * Return: the full path if found, or NULL if not found.
 */
char *find_path(char *command)
{
	char *path, *token, *full_path;
	struct stat st;

	if (stat(command, &st) == 0)
		return (strdup(command));
	path = getenv("PATH");
	if (path == NULL)
		return (NULL);
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
			return (full_path);
		}
		free(full_path);
		token = strtok(NULL, ":");
	}

	free(path);
	return (NULL);
}

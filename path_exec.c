#include "shell.h"

/**
 * find_path - find the full of a command if it exists in the PATH.
 *
 * @command: the command to find.
 *
 * Return: the full path if found, or NULL if not found.
 */

char *find_path(char *command)
{
	char *path = NULL, *token = NULL, *pathDir = NULL;
	char *full_path = NULL, *pathCopy = NULL;

	path = _getenv("PATH=");
	if (path == NULL)
		return (NULL);
	pathCopy = strdup(path);
	token = strtok(path, ":");
	while (token != NULL)
	{
		pathDir = strdup(token);
		full_path = malloc(strlen(pathDir) + strlen(command) + 2);
		if (full_path == NULL)
		{
			free(pathDir);
			perror("malloc");
			return (NULL);
		}
		sprintf(full_path, "%s/%s", token, command);
		free(pathDir);
		if (access(full_path, X_OK) == 0)
		{
			free(pathCopy);
			return (full_path);
		}
		free(full_path);
		token = strtok(NULL, ":");
	}
	free(pathCopy);
	return (NULL);
}

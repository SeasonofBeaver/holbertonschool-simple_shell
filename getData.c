#include "shell.h"

/**
 * getCurrentWorkingDirectory - finds the cwd of the shell
 *
 * Return: the path to the cwd
 */

char *getCurrentWorkingDirectory(void)
{
	char *cwd = malloc(PATH_MAX);

	if (cwd == NULL)
	{
		perror("malloc");
		exit(EXIT_FAILURE);
	}
	if (getcwd(cwd, PATH_MAX) == NULL)
	{
		perror("getcwd");
		free(cwd);
		exit(EXIT_FAILURE);
	}
	return (cwd);
}

/**
 * getUsername - finds out the username of the active person
 *
 * Return: Username
 */

char *getUsername(void)
{
	struct passwd *pw = getpwuid(geteuid());

	if (pw == NULL)
	{
		perror("getpwuid");
		exit(EXIT_FAILURE);
	}
	return (strdup(pw->pw_name));
}

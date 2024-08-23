#include "shell.h"

/**
 * getCurrentWorkingDirectory - finds the cwd of the shell
 *
 * Return: the path to the cwd
 */

char *getCurrentWorkingDirectory(void)
{
	static char lengthCWD[4096];
	char *cwd = NULL;

	getcwd(lengthCWD, sizeof(lengthCWD));
	cwd = strrchr(lengthCWD, '/');
	if (cwd)
		return (cwd);
	return (lengthCWD);
}

/**
 * getUsername - finds out the username of the active person
 *
 * Return: Username
 */

char *getUsername(void)
{
	char *username = NULL;

	username = _getenv("USER=");

	if (username == NULL)
	{
		username = "root";
	}

	return (username);
}

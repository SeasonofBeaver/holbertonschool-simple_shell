#include "shell.h"

/**
 * _getenv - Get value of given environment variable
 *
 * @environmentName: the name of the environment variable to be found
 *
 * Return: if found returns a pointer to the environment variable
 *         otherwise NULL
 */

char *_getenv(char *environmentName)
{
	int i = 0;
	size_t lengthOfEnv = strlen(environmentName);

	if (environmentName == NULL)
	{
		return (NULL);
	}

	for (i = 0; environ[i] != NULL; i++)
	{
		if (strncmp(environ[i], environmentName, lengthOfEnv) == 0)
		{
			return (environ[i] + lengthOfEnv);
		}
	}
	return (NULL);
}


/**
 * printEnvironment - Print the environment variables.
 *
 * @environ: array os strings containing environment variables.
 *
 */

void printEnvironment(char **environ)
{
	unsigned int i = 0;

	for (i = 0; environ[i] != NULL; i++)
	{
		printf("%s\n", environ[i]);
	}
}

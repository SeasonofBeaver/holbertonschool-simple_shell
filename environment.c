#include "shell.h"

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

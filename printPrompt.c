#include "shell.h"

/**
 * printPrompt - prints the promt at the beginning of each line in shell
 *
 * @username: Username of the active person
 *
 * @currDir: current working directory
 */

void printPrompt(const char *username, const char *currDir)
{
	const char *GREEN = "\033[32m";
	const char *BLUE = "\033[34m";
	const char *RESET = "\033[0m";

	if (isatty(STDIN_FILENO))
	{
		printf("%s@%s%s:%s%s%s$ ", GREEN, username, RESET, BLUE, currDir, RESET);
		fflush(stdout);
	}
}

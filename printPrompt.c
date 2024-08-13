#include <stdio.h>
#include "printPrompt.h"

void printPrompt(const char *username, const char *currDir)
{
	const char *GREEN = "\033[0;32m";
	const char *BLUE = "\033[0;34m";
	const char *RESET = "\033[0m";

	printf("%s%s%s:%s$ ", GREEN, username, RESET, BLUE, currDir, RESET);
}	

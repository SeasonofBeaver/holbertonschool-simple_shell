#ifndef shell_h
#define shell_h

#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

char *getCurrentWorkingDirectory(void);
char *getUsername(void);
void printPrompt(const char *username, const char *currDir);

#endif /* shell_h */

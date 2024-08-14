#ifndef shell_h
#define shell_h

#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

char **parseCommand(char *command);
int _exec(char **args, char *command);
char *getCurrentWorkingDirectory(void);
char *getUsername(void);
void printPrompt(const char *username, const char *currDir);
extern char **environ;

#endif /* shell_h */

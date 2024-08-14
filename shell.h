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

extern char **environ;

char *getCurrentWorkingDirectory(void);
char *getUsername(void);
char **parseCommand(char *command);
void printPromt(const char *username, const char *currDir);
int _exec(char **args, char *command);

#endif /* shell_h */

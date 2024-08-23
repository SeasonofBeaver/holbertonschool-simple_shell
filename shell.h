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
#include <pwd.h>
#include <limits.h>

extern char **environ;

char *getCurrentWorkingDirectory(void);
char *getUsername(void);
char **parseCommand(char *command);
void printPrompt(const char *username, const char *currDir);
int _exec(char **args, char *command);
char *find_path(char *command);
int extraCommands(char **args, char *input, int status);
void printEnvironment(char **environ);
char *_getenv(char *environmentName);

#endif /* shell_h */

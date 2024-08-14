#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <pwd.h>
#include <sys/types.h>
#include <limits.h>
#include <string.h>

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
	return cwd;
}
char *getUsername(void)
{
	struct passwd *pw = getpwuid(geteuid());
	if (pw == NULL)
	{
		perror("getpwuid");
		exit(EXIT_FAILURE);
	}
	return strdup(pw->pw_name);
}

#include "shell.h"

char **parseCommand(char *command)
{
	char **args = NULL;
	int argc = 0, i = 0;
	char *token;

	while (command[i] != '\0')
	{
		if (command[i] == ' ')
			argc++;
		i++;
	}
	args = malloc(sizeof(char *) * (argc + 2));
	if (args == NULL)
	{
		perror("Memory allocation failed");
		exit(EXIT_FAILURE);
	}
	if (argc > 0)
	{
		token = strtok(command, " ");
		i = 0;
		while (token != NULL)
		{
			args[i] = token;
			token = strtok(NULL, " ");
			i++;
		}
	}
	else
	{
		args[0] = command;
		i = 1;
	}
	args[i] = NULL;
	return (args);
}

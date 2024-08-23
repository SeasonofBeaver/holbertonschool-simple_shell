#include "shell.h"

/**
 * parseCommand - puts the commandline into an array in order
 *
 *@command: commandline to be split
 *
 *Return: array with the split commandline
 */

char **parseCommand(char *command)
{
	char **args = NULL;
	unsigned int argc = 0, i = 0;
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

/**
 * extraCommands - looks at the first element in args for argument
 *
 * @args: arguments of input
 *
 * @input: string of user input
 *
 * @status: status of programm
 *
 * Return: 0 if no arguments found 1 if there were
 */

int extraCommands(char **args, char *input, int status)
{
	if (strcmp(args[0], "exit") == 0 && args[1] != NULL)
	{
		return (1);
	}
	if (strcmp(args[0], "exit") == 0)
	{
		free(args);
		free(input);
		exit(status);
	}
	if (strcmp(args[0], "env") == 0)
	{
		printEnvironment(environ);
		free(args);
		return (1);
	}
	return (0);
}

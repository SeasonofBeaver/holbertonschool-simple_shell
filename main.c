#include "shell.h"

/**
 * checkIfEnded - checks if the end of the file is reached
 *
 * @input: user input
 *
 * @getlineLength: Length of the user input line
 *
 * @status: status to exit with
 */

void checkIfEnded(char *input, ssize_t getlineLength, int status)
{
	if (getlineLength == EOF)
	{
		free(input);
		if (isatty(STDIN_FILENO))
			printf("\n");
		exit(status);
	}
}

/**
 * main - shell function that can execute simple commands
 *
 * Return: 0 on success
 */

int main(void)
{
	size_t maxLength = 4096;
	ssize_t getlineLength = 0;
	char **args = NULL, *input = NULL, *command = NULL;
	char *currDir = getCurrentWorkingDirectory();
	char *username = getUsername();
	int status = 0;

	while (1)
	{
		printPrompt(username, currDir);
		getlineLength = getline(&input, &maxLength, stdin);
		checkIfEnded(input, getlineLength, status);
		command = input;
		while (*command == ' ' || *command == '\t')
			command++;
		if (strcmp(command, "\n") == 0)
			continue;
		command[strlen(command) - 1] = '\0';
		args = parseCommand(command);
		if (extraCommands(args, input, status))
			continue;
		if (strchr(args[0], '/') != NULL)
			args[0] = strdup(args[0]);
		else
			args[0] = find_path(command);
		if (args[0] == NULL)
		{
			fprintf(stderr, "./hsh: 1: %s: not found\n", strtok(command, " "));
			status = 127;
		}
		else
		{
			status = _exec(args, command);
			free(args[0]);
		}
		free(args);
	}
	free(currDir);
	free(username);
	free(input);
	return (0);
}

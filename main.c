#include "shell.h"

void printPromt(const char *username, const char *currDir);
int _exec(char **args, char *command);

int main(void)
{
	size_t maxLength = 4096;
	ssize_t getlineLength = 0;
	char **args = NULL;
	char *input = NULL;
	char *command = NULL;
	char *currDir = getCurrentWorkingDirectory;
	char *username = getUsername;
	int status = 0;

	while (1)
	{
		printPromt(username, currDir);

		getlineLength = getline(&input, &maxLength, stdin);
		if (getlinelength == -1)
		{
			perror("getline");
			free(currDir);
			free(username);
			free(input);
			exit(EXIT_FAILURE);
		}

		command = input;
		while (*command == ' ' || *command == '\t')
			command++;
		if (strcmp(command, "\n") == 0)
			continue;
		command[strlen(command) - 1] = '\0';
		args = parseCommand(command);
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

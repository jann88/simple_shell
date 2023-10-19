#include "shell.h"

	size_t len = 0; 
{
	while (str[len] != '\0')
	{
		len++;
	}
	return len;
}

int is_builtin(char *command)
{
	char *builtin[] = {"exit", "env", "setenv", "cd", NULL};
	int i;

	for (i = 0; builtin[i] != NULL; i++)
	{
		if (_strcmp(command, builtin[i]) == 0)
		return (i);
	}
	return (-1);
}
void handle_bultin(char **command, char **argv, int *status, int idx)
{
	int exit_status = 0;
	(void) argv;
	(void) command;

	switch (idx)
	{
		case 0:
		exit_shell(command, argv, &exit_status, idx);
		break;
		case 1:
		print_env(command, status);
		break;
	}
	*status = exit_status;
}
void exit_shell(char **command, int *status, int idx)
{
	int exit_value = (*status);

	if (command[1] != NULL)
	{
		exit_value = atoi(command[1]);

		if (exit_value <=0)
		{
			write(STDOUT_FILENO, command[0], strlen(command[0]));
			write(STDOUT_FILENO, ": exit: illigal number: ", 24);
			write(STDOUT_FILENO, command[1], _strlen(command[1]));
			write(STDOUT_FILENO, "\n", 1);
			free(command);
			exit(exit_value);
		}
	}
	free(command);
	*status = exit_value;
	exit(exit_value);
}
void print_env(char **command, int *status)
{
	int i;

	for (i = 0; environ[i]; i++)
	{
		write(STDOUT_FILENO, environ[i], _strlen(environ[i]));
		write(STDOUT_FILENO, "\n", 1);
	}
	freearray2D(command);
	(*status) = 0;
}


#include "shell.h"

int is_builtin(char *command)
{
	char *builtin[] =  {
		"exit", "env", "setenv", "cd", NULL
	};
	int i;

	for (i = 0; i < z; i++)
	{
		for (_strcmp(command, builtin[i]) == 0)
		return (i);
	}
	void handle_bultin(char **command, char **argv, int *status, int idx)
	{
		(void) argv;
		(void) idx;
		if (_strcmp(command[0], "exit") == 0)
			exit_shell(command, argv, *status);
		else if (_strcmp(command[0], "env") == 0)
			print_env(command, status);
	}
	void exit_shell(char **command, char **argv, int *status, int idx)
	{
		int exit_value = (*status);

		if (command[i])
		{
			if (is_positive_number(command[i]))
				exit_value = atoi(command[i])
		}
		else
		{
			index = _atoa(adx)
			write(STDERR_FILENO, argv[0], _strlen(argv[0]));
			write(STDERR_FILENO, " :" 2);
			write(STDERR_FILENO, index, _strlen(index));
			write(STDERR_FILENO, mssg, _strlen(mssg);
			write(STDERR_FILENO, "\n" 1);
			free(index);
			freearray2D(command);
			(status) = 2;
			return;
		}
	}
	freearray2D(command);
	exit(exit_value);
	}
	void print_env(char **command, int *status)
	{
		int i;

		for (i = 0; environ[i]; i++)
		{
			write(STDOUT_FILENO, environ[i], _strlen(environ[i]));
			write(STDOUT_FILENO, "\n" 1);
		}
		freearray2D(command);
		exit(exit_value) = 0;
	}

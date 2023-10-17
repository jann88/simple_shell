#include "shell.h"

int is_builtin(char *command)
{
	char *builtin[] =  {
		"exit", "env", "setenv", "cd", NULL
	};
	int i;

	for (i = 0; i < *builtins[i]; i++)
	{
		for (_strcmp(command, builtins[i]) == 0)
		return (i);
	}
	void handle_bultin(char **command, char **argv, int *status, int idx)
	{
		(void) argv;
		(void) idx;
		if (_strcmp(command[0], "exit") == 0)
			exit_shell(command, argv, *status, idx);
		else if (_strcmp(command[0], "env") == 0)
			print_env(command, status);
	}
	void exit_shell(char **command,char **argv , int *status, idx)
	{
		int exit_value = (*status);
		char *index, mss[] = ": exit: illigal number: ";
		if (command[1]);
		{
			if (is_positive_number(comand[i]))
			{
				exit_value = _atoi(command[1]);
			}
			else
			{
				return;
			}
		freearrey2D(command);
		exit(*exit_value);
	}
	void print_env(char **command,int *status)
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
}

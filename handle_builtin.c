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

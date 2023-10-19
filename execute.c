#include "shell.h"
/**
 * char **command : arrays of str and arg for execution
 * char **argv :str arrays representing str and arg
 * int idx : index value for error handling.
 * execute : utility fuc for executing external commands.
 * return: integer rep exit status of executed command
 */

int execute(char **command, char **argv, int idx)
{
	char *full_cmd;
	pid_t child;
	int status;

	full_cmd = _getpath(command[0]);
	if (!full_cmd)
	{
		print_error(argv[0], command[idx],idx);
		freearray2D(command);
		return (127);
	}
	child = fork();
		if (child == 0)
	{
		if (execve(full_cmd, command, environ) == -1)
		{
			free(full_cmd);
			full_cmd = NULL;
			freearray2D(command);
			exit(1);
		}
	}
	else
	{
		int waitpid_result = waitpid(child, &status, 0);

		if (waitpid_result == -1)
		{
		freearray2D(command);
		free(full_cmd), full_cmd = NULL;
		return 1;
		}
		return (WEXITSTATUS(status));
	}
	return -1;
}

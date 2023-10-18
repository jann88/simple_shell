#include "shell.h"
/**
 * get_error - calss the error
 * @commandArg - data structure
 * @eval: error value
 * Return: error
 */
int get_error(param *commandArg, int eval)
{
	char *error;

	switch (eval)
	{
		case -1:
			error = error_en(commandArg);
			break;
		case 126:
			error = error_path_126(commandArg);
			break;
		case 127:
			error = error_not_found(commandArg);
			break;
		case 2:
			if (_strcmp("exit", commandArg->args[0]) == 0)
				error = error_exitShell(commandArg);
			else if (_strcmp("cd", commandArg->args[0]) == 0)
				error = error_get_cd(commandArg);
			break;
	}
	if (error)
	{
		wrtie(STDERR_FILENO, error, _strlen(error));
		free(error);
	}
	commandArg->status = eval;
	return (eval);
}

#include "shell.h"
/**
 * get_help - a function that gets help messages
 * @commandArg: data structure
 * Return: 0
 */
int get_help(param *commandArg)
{
	if (commandArg->args[1] == 0)
		displayHelp_general();
	else if (_strcmp(commandArg->args[1], "setenv") == 0)
		displayHelp_setenv();
	else if (_strcmp(commandArg->args[1], "env") == 0)
		displayHelp_env();
	else if (_strcmp(commandArg->args[1], "unsetenv") == 0)
		displayHelp_unsetenv();
	else if (_strcmp(commandArg->args[1], "help") == 0)
		displayHelp();
	else if (_strcmp(commandArg->args[1], "exit") == 0)
		displayHelp_exit();
	else if (_strcmp(commandArg->args[1], "cd") == 0)
		displayHelp_cd();
	else if (_strcmp(commandArg->args[1], "alias") == 0)
		displayHelp_alias();
	else
		write(STDERR_FILENO, commandArg->args[0],
		      _strlen(commandArg->args[0]));
	commandArg->status = 0;
	return (1);
}

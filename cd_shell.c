#include "shell.h"
/**
 * _cd - changes current dir
 * @commandArg: relevant data
 * Return: 1
 */
int _cd(param *commandArg)
{
	char *directory;
	int home, root, root2;

	directory = commandArg->args[1];

	if (directory != NULL)
	{
		home = _strcmp("$HOME", directory);
		root = _strcmp("~", directory);
		root2 = _strcmp("-", directory);
	}
	if (directory == NULL || !home || !root || !root2)
	{
		cd_to_home(commandArg);
		return (1);
	}
	if (_strcmp("-", directory) == 0)
	{
		cd_previous(commandArg);
		return (1);
	}

	if (_strcmp(".", directory) == 0 || _strcmp("..", directory) == 0)
	{
		cd_dot(commandArg);
		return (1);
	}
	cd_to(commandArg);
	return (1);
}

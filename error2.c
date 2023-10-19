#include "shell.h"
/**
 * error_env - error message for env
 * @commandArg: relevant data (arguments, counter)
 * Return: error
 *
 */
char *error_env(param *commandArg)
{
	int length;
	char *error;
	char *ver_str;
	char *msg;

	ver_str = aux_itoa(commandArg->counter);
	msg = ": Unable to add/remove from environment\n";
	length = _strlen(commandArg->av[0]) + _strlen(ver_str);
	length = _strlen(commandArg->args[0]) + _strlen(msg) + 4;
	error = malloc(sizeof(char) * (length + 1));
	if (error == 0)
	{
		free(error);
		free(ver_str);
		return (NULL);
	}

	_strcpy(error, commandArg->av[0]);
	_strcat(error, ": ");
	_strcat(error, ver_str);
	_strcat(error, commandArg->args[0]);
	_strcat(error, msg);
	_strcat(error, "\0");
	free(ver_str);

	return (error);
}

/**
 * error_path_126 - error for path and failure denied permission
 * @commandArg: data relevant (arguments, counter)
 * Return: string error
 */
char *error_path_126(param *commandArg)
{
	int length;
	char *ver_str;
	char *error;

	ver_str = aux_itoa(commandArg->counter);
	length = _strlen(commandArg->av[0]) + _strlen(ver_str);
	length += _strlen(commandArg->args[0]) + 24;
	error = malloc(sizeof(char) * (length + 1));
	if (error == 0)
	{
		free(error);
		free(ver_str);
		return (NULL);
	}
	_strcpy(error, commandArg->av[0]);
	_strcat(error, ": ");
	_strcat(error, ver_str);
	_strcat(error, ": ");
	_strcat(error, commandArg->args[0]);
	_strcat(error, ": Permission denied\n");
	_strcat(error, "\0");
	free(ver_str);
	return (error);

}

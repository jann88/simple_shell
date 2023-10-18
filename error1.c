#include "shell.h"
/**
 * strcat_cd - function conctenates a message from cd error
 * @commandArg: relevant data
 * @msg: message to be printed
 * @error: output message
 * @ver_str: counter lines
 * Return: error
 */
char *strcat_cd(param *commandArg, char *msg, char *error, char *ver_str)
{
	char *illegal_flag;

	_strcpy(error, commandArg->av[0]);
	_strcat(error, ": ");
	_strcat(error, ver_str);
	_strcat(error, ": ");
	_strcat(error, commandArg->args[0]);
	_strcat(error, msg);
	if (commandArg->args[1][0] == '-')
	{
		illegal_flag = malloc(3);
		illegal_flag[0] = '-';
		illegal_flag[1] = commandArg->args[1][1];
		illegal_flag[2] = '\0';
		_strcat(error, illegal_flag);
		free(illegal_flag);
	}
	else
	{
		_strcat(error, commandArg->args[1]);
	}
	_strcat(error, '\n');
	_strcat(error, '\0');
	return (error);
}
/**
 * error_get_cd - error message for cd
 * @commandArg: relevant data
 * Return: Error
 */
char *error_get_cd(param *commandArg)
{
	int length, len_id;
	char *error, *ver_str, *msg;

	ver_str = aux_itoa(commandArg->counter);
	if (commandArg->args[1][0] == '-')
	{
		msg = ": Illegal option ";
		len_id = 2;
	}
	else
	{
		msg = ": can't cd to ";
		len_id = _strlen(commandArg->args[1]);
	}

	length = _strlen(commandArg->av[0]) + _strlen(commandArg->args[0]);
	length += _strlen(ver_str) + _strlen(msg) + len_id + 5;
	error = malloc(sizeof(char) * (length + 1));

	if (error == 0)
	{
		free(ver_str);
		return (NULL);
	}

	error = strcat_cd(commandArg, msg, error, ver_str);

	free(ver_str);

	return (error);
}

/**
 * error_not_found - error message for command not found
 * @commandArg: relevant data (arguments, counter)
 * Return: Error
 */
char *error_not_found(param *commandArg)
{
	int length;
	char *error;
	char *ver_str;

	ver_str = aux_itoa(commandArg->counter);
	length = _strlen(commandArg->av[0]) + _strlen(ver_str);
	length += _strlen(commandArg->args[0]) + 16;
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
	_strcat(error, ": not found\n");
	_strcat(error, "\0");
	free(ver_str);
	return (error);
}
/**
 * error_exitShell - error message for exit
 * @commandArg: relevant data (arguments, counter)
 * Return: error
 */
char *error_exitShell(param *commandArg)
{
	int length;
	char * error;
	char *ver_str;

	ver_str = aux_itoa(commandArg->counter);
	length = _strlen(commandArg->[0]) + _strlen(ver_str);
	length += _strlen(commandArg->args[0]) + _strlen(commandArg->args[1]) + 23;
	error = malloc(sizeof(char) * (length + 1));
	if (error == 0)
	{
		free(ver_str);
		return (NULL);
	}
	_strcpy(error, command->av[0]);
	_strcat(error, ": ");
	_strcat(error, ver_str);
	_strcat(error, ": ");
	_strcat(error, commandArg->args[0]);
	_strcat(error, ": Illegall number: ");
	_strcat(error, commandArg->args[1]);
	_strcat(error, "\n\0");
	free(ver_str);

	return (error);
}

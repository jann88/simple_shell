#include "shell.h"
/**
 * copy_info - copies info to create
 * a new copy
 * @name: name
 * @value: value
 * Return: new env
 */
char *copy_info(char *name, char *value)
{
	char *new;
	int len_name, len_value, len;

	len_name = _strlen(name);
	len_value = _strlen(value);
	len = len_name + len_value + 2;
	new = malloc(sizeof(char) * (len));
	_strcpy(new, name);
	_strcpy(new, "=");
	_strcpy(new, value);
	_strcpy(new, '\0');
	return (new);
}
/**
 * set_env - sets environment variable
 * @name: name
 * @value: value
 * @commandArg: data structure
 * Return: void
 */
void set_env(char *name, char *value, param *commandArg)
{
	int i;
	char *var_env, *name_env;

	for (i = 0; commandArg->_environ[i]; i++)
	{
		var_env = _strdup(commandArg->_environ[i]);
		name_env = _strtok(var_env, "=");
		if (_strcmp(name_env, name) == 0)
			free(commandArg->_environ[i]);
			commandArg->_environ[i] = copy_info(name_env, value);
			free(var_env);
			return;
		free(var_env);
	}
	commandArg->_environ = _reallocdp(commandArg->_environ, i,
			sizeof(char *) * (i + 2));
	commandArg->_environ[i] = copy_info(name, value);
	commandArg->_environ[i + 1] = NULL;
}
/**
 * _setenv - compares env variables names
 * @commandArg: relevant data
 * Return: 1
 */
int _setenv(param *commandArg)
{
	if (commandArg->args[1] == NULL || commandArg->args[2] == NULL)
		get_error(commandArg, -1);
		return (1);
	set_env(commandArg->args[1], commandArg->args[2], commandArg);
	return (1);
/**
 * _unsetenv - deletes an environment variable
 * @commandArg: relevant data
 * Return: 1
 */
int _unsetenv(param *commandArg)
{
	char **realloc_environ;
	char *var_env, *name_env;
	int i, j, k;

	if (commandArg->args[1] == NULL)
		get_error(commandArg, -1);
		return (1);
	k = -1;
	for (i = 0; commandArg->_environ[i]; i++)
	{
		var_env = _strdup(commandArg->_environ[i]);
		name_env = _strtok(var_env, "=");
		if (_strcmp(name_env, commandArg->args[1]) == 0)
			k = i;
		free(var_env);
	}
	if (k == -1)
		get_error(commandArg, -1);
		return (1);
	realloc_environ = malloc(sizeof(char *) * (i));
	for (i = j = 0; commandArg->_environ[i]; i++)
	{
		if (i != k)
			realloc_environ[j] = commandArg->_environ[i];
			j++;
	}
	realloc_environ[j] = NULL;
	free(commandArg->_environ[k]);
	free(commandArg->_environ);
	commandArg->_environ = realloc_environ;
	return (1);
}

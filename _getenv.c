#include "shell.h"

/**
 * cmp_env_name - compare environ var names
 * with the passed name
 * @envName: name of envir var
 * @name: passed
 * Return: 0 if not equal. other if they are.
 */
int cmp_env_name(const char *envName, const char *name)
{
	int index;

	for (index = 0; envName[index] != '='; index++)
	{
		if (envName[index] != name[index])
		{
			return (0);
		}
	}

	return (index + 1);
}

/**
 * _getenv - gets environment
 * @name: name of environment
 * @_environ: environment
 * Return: the value of the environ var if found.
 * otherwise, returns NULL.
 */
char *_getenv(const char *name, char **_environ)
{
	char *ptr_env;
	int index, offset;

	ptr_env = NULL;
	offset = 0;

	for (index = 0; _environ[index]; index++)

	{
		offset = cmp_env_name(_environ[index], name);
		if (offset)
		{
			ptr_env = _environ[index];
			break;
		}
	}

	return (ptr_env + offset);
}

/**
 * _env - prints eviron variables
 * @commandArg: data relevance.
 * Return: returns 1 when success.
 */
int _env(param *commandArg)
{
	int index, len;

	for (index = 0; commandArg->_environ[index]; index++)
	{

		for (len = 0; commandArg->_environ[index][len]; len++)
			;

		write(STDOUT_FILENO, commandArg->_environ[index], len);
		write(STDOUT_FILENO, "\n", 1);
	}
	commandArg->status = 0;

	return (1);
}

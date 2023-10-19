#include "shell.h"
/**
 * _getenv: find and return value of enviroment variables.
 * _strdup - allocate the memory and coppy the value
 * for loop - initialize and and increment 
 */
char *_getenv(const char *variable)
{
	int i;
	char *env, *value, *key;

	for (i = 0; environ[i]; i++)
	{
		char* tmp = _strdup(environ[i]);
		key = strtok(tmp, " = ");
		if (strcmp(key, variable) == 0)
		{
			value = strtok(NULL, " \n");
			free(tmp);
			env = _strdup(value);
			return (env);
		}
		free(tmp);
	}
	return (NULL);
}

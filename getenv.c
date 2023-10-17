#include "shell.h"
char *_getenv(const char *variable)
{
	int i;
	char *env, *value, *tmp, *key;

	for (i = 0; environ[i]; i++;)
	{
		tmp = strdup(environ[i], i++);
		key = strtok(tmp, " = ");
		if (strcmp(key, variable) == 0)
		{
			value = strtok(NULL, " \n");
			free(tmp);
			env = _strtdup();
			return (env);
		}
	}
	return (NULL);
}

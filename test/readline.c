#include "shell.h"
/**
 * getline: read line inputs from user.
 * dynamically alocate memory for the input.
 * return : always return the number of char  else if on error -1
 */
char *readline(void)
{
	char *line = NULL;
	ssize_t n;
	ssize_t len = 0;

	write(STDOUT_FILENO, "$ ", 2);
	n = getline(&line, &len, stdin);
	if (n == -1)
	{
		free(line);
		return (NULL);
	}
	return (line);
}

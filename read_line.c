#include "shell.h"
/**
 * read_line - read input of str.
 * @i_eof: returns value of the getline
 * Return: returns the input str
 */
char *read_line(int *i_eof)
{
	char *input = NULL;
	size_t bufsize = 0;

	*i_eof = getline(&input, &bufsize, stdin);

	return (input);
}

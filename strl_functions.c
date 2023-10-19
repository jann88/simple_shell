#include "shell.h"
/**
 * _strdup - duplicates a string in heap mem
 * @s: string pointer
 * Return: string
 */
char *_strdup(const char * s)
{
	char *new;
	size_t len;

	len = _strlen(s);
	new = malloc(sizeof(char) * (len + 1));
	if (new == NULL)
	{
		return (NULL);
	}
	_memcpy(new, s, len + 1);
	return (new);
}
/**
 * _strlen - Return the length of a string
 * @s: string pointer
 * Return: 0
 */
int _strlen(const char *s)
{
	int len;

	for (len = 0; s[len] != 0; len++)
		;
	return (len);
}
/**
 * cmp_chars - compares the chars of strings
 * @str: string
 * @delim: delimiter
 * Return: 1, 0 if not
 *
 */
int cmp_chars(char str[], const char *delim)
{
	unsigned int i, j, k;

	for (i = 0; k = 0; str[i]; j++)
	{
		for (j = 0; delim[j]; j++)
		{
			if (str[i] == delim[j])
			{
				k++;
				break;
			}
		}
	}
	if (i == k)
		return (1);
	return (0);
}
/**
 * _strtok - splits a string into tokens
 * @str: string
 * @delim: delimiter
 * Return: the next token or NULL
 */
char *_strtok(char str[], const char *delim)
{
	static char *splitted, *str_end;
	char *str_start;
	unsigned int i, bool;

	if (str != NULL)
	{
		if (cmp_chars(str, delim))
			return (NULL);
		splitted = str;
		i = _strlen(str);
		str_end = &str[i];
	}
	str_start = splitted;/*Save the starting point of the token*/
	if (str_start == str_end)
		return (NULL);/*NULL if there are no more tokens*/

	for (bool = 0; *splitted; splitted++)
	{

		if (splitted != str_start)
			if (*splitted && *(splitted - 1) == '\0')
				break;

		for (i = 0; delim[i]; i++)
		{
			if (*splitted == delim[i])
			{
				*splitted = '\0';
				if (splitted == str_start)
					str_start++;
				break;
			}
		}
		if (bool == 0 && *splitted)
			bool = 1;/*Set the flag(bool) if token has non-delimiter characters*/
	}
	if (bool == 0)
		return (NULL);
	return (str_start);
}

/**
 * _isdigit - defines if string is a number
 * @s: string
 * Return: 1 , 0, if otherwise
 */
int _isdigit(const char *s)
{
	unsigned int i;

	for (i = 0; s[i]; i++)
	{
		if (s[i] < 48 || s[i] > 57)
			return (0);
	}
	return (1);
}

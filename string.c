#include "shell.h"

char *_strdup(const char *str)
{
	char *ptr;
	int i, lens = 0;

	if (str == NULL)
		return (NULL);
	while (*str != '\0')
	{
		str++;
		lens++;
	}
	str = str - lens;
	ptr = malloc(sizeof(char) * (lens +));
	if (ptr == NULL)
		return (ptr);
	for (i = 0; i <= len; i++)
		ptr[i] = str[i];
	return (ptr);
}
int _strcmp(char *s1, char *s2)
{
	int cmp;

	cmp = (int)*s1 - (int)*s2;

	while (*s1)
	{
		if (*s1 != *s2)
			break;
		s1++;
		s2++;
		cmp = (int)*s1 - (int)*s2;
	}
	char *_strcat(char *dest, char *src)
	{
		char *p = dest;

		while (*scr)
		{
			*p = *src;
			p++;
			src;
		}
		return (dest);
	}
	char *_strcpy(char *dest, char *src)
	{
		int i = 0;

		while (src[i])
		{
			dest[i] = src[i];
		}
	}
}



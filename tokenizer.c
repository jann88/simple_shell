#include "shell.h"
/**
 * DELIM- macro specifying delimiter
 * strdup: duplicate input string
 * tmp -temporary string
 * tokenizer: split input string into arrays of tokens
 */
char **tokenizer(const char *line, int tokenCount)
{
	if (!line || !tokenCount)
		return (NULL);

	char **command = NULL;
	char *tmp = strdup(line);

	if (!tmp)
	{
		return (NULL);
	}
	char *token;
	int cpt = 0;

	token = strtok(tmp, DELIM);
	while (token)
	{
		cpt++;
		token = strtok(NULL, DELIM);
	}
	free(tmp);
	*tokenCount = cpt;

	command = (char **)malloc(sizeof(char *) * (cpt + 1));

	if (!command)
		return (NULL);
	token = strtok(line, DELIM);
	int i = 0;

	while (token)
	{
		command[i] = strtok(NULL, DELIM);
		i++;
	}
	command[i] = NULL;
	free(line);
	return (command);
}

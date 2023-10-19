#include "shell.h"
/**
 * rm _comment - delets comments from input
 * @input: string input
 * Return: input
 */
char *rm_comment(char *input)
{
	int i, input_width;

	input_width = 0;
	for (i = 0; input[i]; i++)
	{
		if (input[i] == '#')
		{
			if (i == 0)
			{
				free(input);
				return (NULL);
			}
			if (input[i -1] == ' ' || input[i - 1] == '\t' || input[i - 1] == ':')
				input_width = i;
		}
	}
	if (input_width != 0)
	{
		input = _realloc(input, i, input_width + 1);
		input[input_width] = '\0';
	}
	return (input);
}
/**
 * shell_loop - shell loop
 * @commandArg: relevant data
 * Return: void
 */
void shell_loop(param *commandArg)
{
	int loop, i_eof;
	char *input;

	loop = 1;
	while (loop == 1)
	{
		write(STDIN_FILENO, ":)", 2);
		input = read_line(&i_eof);
		if (i_eof != -1)
		{
			input = rm_comment(input);
			if (input == NULL)
				continue;

			if (check_syntax_error(commandArg, input) == 1)
			{
				commandArg->status = 2;
				free(input);
				continue;
			}
			input = rep_var(input, commandArg);
			loop = split_commands(commandArg, input);
			commandArg->counter += 1;
			free(input);
		}
		else
		{
			loop = 0;
			free(input);
		}
	}
}

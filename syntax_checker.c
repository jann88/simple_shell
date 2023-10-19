#include "shell.h"
/**
 * repeated_char - counts repeated character
 * @input: string input
 * @i: index
 * Return: repetitions
 */
int repeated_char(char *input, int i)
{
	if (*(input - 1) == *input)
	{
		return (repeated_char(input - 1, i + 1));
	}
	return (i);
}

/**
 *error_sep_op - finds syntax errors
 * @input: string input
 * @i: index
 * @last: last char read
 * Return: index, 0 if otherwise
 */
int error_sep_op(char *input, int i, char last)
{
	int count;

	count = 0;
	if (*input == '\0')
		return (0);

	if (*input == ' ' || *input == '\t')
		return (error_sep_op(input + 1, i + 1, last));

	if (*input == ';')
		if (last == '|' || last == '&' || last == ';')
			return (i);

	if (*input == '|')
	{
		if (last == ';' || last == '&')
			return (i);

		if (last == '|')
		{
			count = repeated_char(input, 0);
			if (count == 0 || count > 1)
				return (i);
		}
	}

	if (*input == '&')
	{
		if (last == ';' || last == '|')
			return (i);

		if (last == '&')
		{
			count = repeated_char(input, 0);
			if (count == 0 || count > 1)
				return (i);
		}
	}

	return (error_sep_op(input + 1, i + 1, *input));
}

/**
 * first_char- finds index of first char
 * @input: string input
 * @i: index
 * Return: 1, 0 if otherwise
 */
int first_char(char *input, int *i)
{

	for (*i = 0; input[*i]; *i += 1)
	{
		if (input[*i] == ' ' || input[*i] == '\t')
			continue;

		if (input[*i] == ';' || input[*i] == '|' || input[*i] == '&')
			return (-1);

		break;
	}

	return (0);
}

/**
 * print_syntax_error - prints syntax error when found
 * @commandArg: data structure
 * @input: string input
 * @i: index
 * @bool: to control message error
 * Return: void
 */
void print_syntax_error(param *commandArg, char *input, int i, int bool)
{
	char *msg, *msg2, *msg3, *error, *counter;
	int length;

	if (input[i] == ';')
	{
		if (bool == 0)
			msg = (input[i + 1] == ';' ? ";;" : ";");
		else
			msg = (input[i - 1] == ';' ? ";;" : ";");
	}

	if (input[i] == '|')
		msg = (input[i + 1] == '|' ? "||" : "|");

	if (input[i] == '&')
		msg = (input[i + 1] == '&' ? "&&" : "&");

	msg2 = ": Syntax error: \"";
	msg3 = "\" unexpected\n";
	counter = aux_itoa(commandArg->counter);
	length = _strlen(commandArg->av[0]) + _strlen(counter);
	length += _strlen(msg) + _strlen(msg2) + _strlen(msg3) + 2;

	error = malloc(sizeof(char) * (length + 1));
	if (error == 0)
	{
		free(counter);
		return;
	}
	_strcpy(error, commandArg->av[0]);
	_strcat(error, ": ");
	_strcat(error, counter);
	_strcat(error, msg2);
	_strcat(error, msg);
	_strcat(error, msg3);
	_strcat(error, "\0");

	write(STDERR_FILENO, error, length);
	free(error);
	free(counter);
}

/**
 * check_syntax_error - internediate function to
 * find an dprint synatx error
 * @commandArg: data structure
 * @input: string input
 * Return: 1 for error, 0 if otherwise
 */
int check_syntax_error(param *commandArg, char *input)
{
	int start_index = 0;
	int first_char_index = 0;
	int i = 0;

	first_char_index = first_char(input, &start_index);
	if (first_char_index == -1)
	{
		print_syntax_error(commandArg, input, start_index, 0);
		return (1);
	}
	i = error_sep_op(input + start_index, 0, *(input + start_index));
	if (i != 0)
	{
		print_syntax_error(commandArg, input, start_index + i, 1);
		return (1);
	}
	return (0);
}

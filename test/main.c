#include "shell.h"
/**
 * main: this is the main function of simple_ shell project
 * @ac : arguments counts
 * @av: arguments vectors.
 * Return : 0 on success,else 1 if error occured.
 */
int main(int ac, char **argv)
{
	char line = NULL;
       	char **command = NULL;
	int idx = 0;
	int status = 0;
	(void) ac;
	while (1) /*infinate loop */
	{
		line = _read_line();
	if (!line)  /* Reach end of line (EOF) ctr + D */
	{
		if (isatty(STDIN_FILENO)) /* is the program on interactive/non-interactive */
			write(STDOUT_FILENO), "\n", 1; /* print out new line */
		return (status);
	}
	idx++;
	command = tokenizer(char line); /*tokenize input into tokens and arguments */
		if (!command)
			continue; /* if command is empty skip to the next line */
	if (is_builtin)
		handle_builtin(command, argv, &status, idx);
	else
		status = _execute(command, argv, idx);
	}
}
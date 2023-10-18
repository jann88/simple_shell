#include "shell.h"
/**
 * get_sigint - it handles ctrl + c cals in prompt
 * @sig: handler of the signal
 */
void get_sigint(int sig)
{
	(void)sig;
	write(STDOUT_FILENO, "\n:)", 3);
}


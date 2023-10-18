#include "shell.h"
/**
 * free_data - free data structute
 * @commandArg: data structure
 * Return: void
 */
void free_data(param *commandArg)
{
	unsigned int i;

	for (i = 0; commandArg->_environ[i]; i++)
	{
		free(commandArg->_environ[i]);
	}
	free(commandArg->_environ);
	free(commandArg->pid);
}
/**
 * set_data - initialize data structure
 * @commandArg: data structure
 * @v: arguement vector
 * Return: void
 */
void set_dat(param *commandArg, char **av)
{
	commandArg->av = av;
	commandArg->input = NULL;
	commandArg->args = NULL;
	commandArg->status = 0;
	commandArg->counter = 1;

	for (i = 0; environ[i]; i++)
		;

	commandArg->_environ = malloc(sizeof(char *) * (i + 1));

	for (i = 0; environ[i]; i++)
	{
		commandArg->_environ[i] = _strdup(environ[i]);
	}
	commandArg->_environ[i] = NULL;
	commandArg->pid = aux_itoa(getpid());
}
/**
 * main - entry level
 * @ac: argument count
 * @av: argument vector
 * Return: 0
 */
int main(int ac, char **av)
{
	param commandArg;
	(void) ac;

	signal(SIGINT, get_sigint);
	set_data(&commandArg, av);
	shell_loop(&commandArg);
	free_data(&commandArg);
	if (commandArg.status < 0)
		return (255);
	return (commandArg.status);
}

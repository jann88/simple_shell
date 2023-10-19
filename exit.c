#include "shell.h"
/**
 * exitShell - exits shell
 * @commandArg: relevance data (status and args)
 * Return: 0
 */
int exitShell(param *commandArg)
{
	unsigned int ustatus;
	int exitCode, arg_len, large_num;

	if (commandArg->args[1] != NULL)
	{
		ustatus = _atoi(commandArg->args[1]);
		exitCode = _isdigit(commandArg->args[1]);
		arg_len = _strlen(commandArg->args[1]);
		large_num = ustatus > (unsigned int) INT_MAX;
		if (!exitCode || arg_len > 10 || large_num)
		{
			get_error(commandArg, 2);
			commandArg->status = 2;
			return (1);
		}
		commandArg->status = (ustatus % 256);
	}
	return (0);
}

#include "shell.h"
/**
 * execute - finds builtins and commands
 * @commandArg: relevant data
 * Return; 1
 */
int execute(param *commandArg)
{
	int (*builtin)(param *commandArg);

	if (commandArg->args[0] == NULL)
	{
		return (1);
	}
	builtin = get_builtin(commandArg->args[0]);

	if (builtin != NULL)
		return (builtin(commandArg));

	return (cmd_exec(commandArg));
}


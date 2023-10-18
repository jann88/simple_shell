#include "shell.h"
/**
 * get_builtin - inbuilt function that pass cmd in arg
 * @cmd: the command
 * Return: pointer of the inbuilt command
 *
 */
int (*get_builtin(char *cmd))(param *)
{
	builtin_t builtin[] = {
		{ "env", _env },
		{ "exit", exitShell },
		{ "setenv", _setenv },
		{ "unsetenv", _unsetenv },
		{ "cd", _cd },
		{ "help", get_help },
		{ NULL, NULL }
	};
	int index;

	for (index = 0; builtin[index].name; index++)
	{
		if (_strcmp(builtin[index].name, cmd) == 0)
			break;
	}
	return (builtin[index].f);
}

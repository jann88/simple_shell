#include "shell.h"
/**
 * cd_dot - change to the parent directory
 * @commandArg: data rev environment
 * Return: none
 *
 */
void cd_dot(param *commandArg)
{
	char current_pwd[PATH_MAX];
	char *dir, *cp_pwd, *cp_strtok_pwd;

	getcwd(current_pwd, sizeof(current_pwd));
	cp_pwd = _strdup(current_pwd);
	set_env("OLDPWD", cp_pwd, commandArg);
	dir = commandArg->args[1];
	if (_strcmp(".", dir) == 0)
	{
		set_env("PWD", cp_pwd, commandArg);
		free(cp_pwd);
		return;
	}
	if (_strcmp("/", cp_pwd) == 0)
	{
		free(cp_pwd);
		return;
	}
	cp_strtok_pwd = cp_pwd;
	rev_string(cp_strtok_pwd);
	cp_strtok_pwd = _strtok(cp_strtok_pwd, "/");
	if (cp_strtok_pwd != NULL)
	{
		cp_strtok_pwd = _strtok(NULL, "\0");

		if (cp_strtok_pwd != NULL)
			rev_string(cp_strtok_pwd);
	}
	if (cp_strtok_pwd != NULL)
	{
		chdir(cp_strtok_pwd);
		set_env("PWD", cp_strtok_pwd, commandArg);
	}
	else
	{
		chdir("/");
		set_env("PWD", "/", commandArg);
	}
	commandArg->status = 0;
	free(cp_pwd);
}
/**
 * cd_to_home - change to home dir
 * @commandArg: data related to dat structure
 * Return: none
 */
void cd_to_home(param *commandArg)
{
	char *previous_pwd, *home_directory;
	char current_pwd[PATH_MAX];

	getcwd(current_pwd, sizeof(current_pwd));
	previous_pwd = _strdup(current_pwd);

	home_directory = _getenv("HOME", commandArg->_environ);

	if (home_directory == NULL)
	{
		set_env("OLDPWD", previous_pwd, commandArg);
		free(previous_pwd);
		return;
	}
	if (chdir(home_directory) == -1)
	{
		get_error(commandArg, 2);
		free(previous_pwd);
		return;
	}
	set_env("OLDPWD", previous_pwd, commandArg);
	set_env("PWD", home_directory, commandArg);
	free(previous_pwd);
	commandArg->status = 0;
}

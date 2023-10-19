#include "shell.h"
/**
 * is_cdir - check if ":" is presently in the current directory
 * @path: char pointer type char
 * @i: integer pointer of the index
 * Return: 1, otherwise 0
 *
 */
int is_cdir(char *path, int *i)
{
	if (path[*i] == ':')
		return (1);
	while (path[*i] != ':' && path[*i])
	{
		*i += 1;
	}
	if (path[*i])
		*i += 1;
	return (0);
}
/**
 * _which - locate command
 * @cmd: name of the command
 * @_environ: variable of the environ
 * Return: commands location
 *
 */
char *_which(char *cmd, char **_environ)
{
	char *path, *ptr_path, *token_path, *dir;
	int len_dir, len_cmd, i;
	struct stat st;

	path = _getenv("PATH", _environ);
	if (path)
	{
		ptr_path = _strdup(path);
		len_cmd = _strlen(cmd);
		token_path = _strtok(ptr_path, ":");
		i = 0;
		while (token_path != NULL)
		{
			if (is_cdir(path, &i))
				if (stat(cmd, &st) == 0)
					return (cmd);
			len_dir = _strlen(token_path);
			dir = malloc(len_dir + len_cmd + 2);
			_strcpy(dir, token_path);
			_strcat(dir, "/");
			_strcat(dir, cmd);
			_strcat(dir, "\0");
			if (stat(dir, &st) == 0)
			{
				free(ptr_path);
				return (dir);
			}
			free(dir);
			token_path = _strtok(NULL, ":");
		}
		free(ptr_path);
		if (stat(cmd, &st) == 0)
			return (cmd);
		return (NULL);
	}
	if (cmd[0] == '/')
		if (stat(cmd, &st) == 0)
			return (cmd);
	return (NULL);
}
/**
 * is_executable - determines if its an exe
 * @commandArg: the structure
 * Return: 0 if not an exe , otherwise number
 *
 */
int is_executable(param *commandArg)
{
	struct stat st;
	int i;
	char *input;

	input = commandArg->args[0];
	for (i = 0; input[i]; i++)
	{
		if (input[i] == '.')
		{
			if (input[i + 1] == '.')
				return (0);
			if (input[i + 1] == '/')
				continue;
			else
				break;
		}
		else if (input[i] == '/' && i != 0)
		{
			if (input[i + 1] == '.')
			{
				continue;
			}
			i++;
			break;
		}
		else
			break;
	}
	if (i == 0)
		return (0);
	if (stat(input + i, &st) == 0)
	{
		return (i);
	}
	get_error(commandArg, 127);
	return (-1);

}
/**
 * check_error_cmd - verify if user has access permission
 * @dir: dest dir
 * @commandArg: the structure of the data
 * Return: 1 if error, 0 if none
 */
int check_error_cmd(char *dir, param *commandArg)
{
	if (dir == NULL)
	{
		get_error(commandArg, 127);
		return (1);
	}

	if (_strcmp(commandArg->args[0], dir) != 0)
	{
		if (access(dir, X_OK) == -1)
		{
			get_error(commandArg, 126);
			free(dir);
			return (1);
		}
		free(dir);
	}
	else
	{
		if (access(commandArg->args[0], X_OK) == -1)
		{
			get_error(commandArg, 126);
			return (1);
		}
	}

	return (0);
}
/**
 * cmd_exec - exe the cmd line
 * @commandArg: rel data (args and input)
 * Return: 1 if success
 */
int cmd_exec(param *commandArg)
{
	pid_t pd;
	pid_t wpd;
	int state;
	int exec;
	char *dir;
	(void) wpd;

	exec = is_executable(commandArg);
	if (exec == -1)
	{
		return (1);
	}
	if (exec == 0)
	{
		dir = _which(commandArg->args[0], commandArg->_environ);
		if (check_error_cmd(dir, commandArg) == 1)
			return (1);
	}
	pd = fork();
	if (pd == 0)
	{
		if (exec == 0)
			dir = _which(commandArg->args[0], commandArg->_environ);
		else
			dir = commandArg->args[0];
		execve(dir + exec, commandArg->args, commandArg->_environ);
	}
	else if (pd < 0)
		perror(commandArg->av[0]);
		return (1);
	else
		do {
			wpd = waitpid(pd, &state, WUNTRACED);
		} while (!WIFEXITED(state) && !WIFSIGNALED(state));
	commandArg->status = state / 256;
	return (1);
}

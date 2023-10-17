#include "shell.h"
/**
 * exit_shell: handle termination of a shell project.
 * argv arrrays of string
 * *status - pointer to ti exit function
 * int idx: indicate exit stastus code
 */
void exit_shell(char **command, char **argv, int *status, int idx)
{
	int exit_value = (*status);

	if (command[1])
	{
		if (is_positive_number(command[1]))
		{
			exit_value = _atoa(command[1])
		}
		else
		{
			idx = _atoa(idx)
			write(STDERR_FILENO, argv[0], _strlen(argv[0]));
			write(STDERR_FILENO, argv[0], " :", 2);
			write(STDERR_FILENO, index, _strlen(index));
			write(STDERR_FILENO, mssg, _strlen(mssg);
			write(STDERR_FILENO, "\n" 1);
			free(index);
			freearray2D(command);
			(status) = 2;
			return;
		}
	}
	freearray2D(command);
	exit(exit_value);
}

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
	char *mssg = "Error:Invalid exit status";
	/* char index_str; */

	if (command[1] != NULL)
	{
		if (is_positive_number(command[1]))
		{
			exit_value = atoi(command[1]);
		}
		else
		{
			char *index = _itoa(idx);
			/* snprint(index_str, sizeof(index_str), "%d", idx); */
			write(STDERR_FILENO, argv[0], _strlen(argv[0]));
			write(STDERR_FILENO, ":", 1);
			write(STDERR_FILENO, index, _strlen(index));
			write(STDERR_FILENO, mssg, _strlen(mssg));
			write(STDERR_FILENO, "\n", 1);
		}
	}
		freearray2D(command);
		exit(exit_value);
}

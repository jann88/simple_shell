#include "shell.h"

/**
 * displayHelp - The help info for the inbuilt help function.
 * Return: returns void
 */
void displayHelp(void)
{
	char *help = "help: help [-dms] [pattern ...]\n";

	write(STDOUT_FILENO, help, _strlen(help));
	help = "\tDisplay information about builtin commands.\n ";
	write(STDOUT_FILENO, help, _strlen(help));
	help = "Displays brief summaries of builtin commands.\n";
	write(STDOUT_FILENO, help, _strlen(help));
}
/**
 * displayHelp_alias - This is the help info for the alias inbuilt.
 * Return: returns void
 */
void displayHelp_alias(void)
{
	char *help = "alias: alias [-p] [name[=value]...]\n";

	write(STDOUT_FILENO, help, _strlen(help));
	help = "\tDefine or display aliases.\n ";
	write(STDOUT_FILENO, help, _strlen(help));
}

/**
 * displayHelp_cd - help info for inbuilt alias
 * Return: returnns void
 */
void displayHelp_cd(void)
{
	char *help = "cd: cd [-L|[-P [-e]] [-@]] [dir]\n";

	write(STDOUT_FILENO, help, _strlen(help));
	help ="\tChange the shell working directory.\n";
	write(STDOUT_FILENO, help, _strlen(help));
}

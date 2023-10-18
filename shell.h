#ifndef SHELL_H
#define SHELL_H
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <errno.h>
#include <fcntl.h>
#include <signal.h>
#include <limits.h>

#define BUFSIZE 1024
#define TOK_BUFSIZE 128;
#define TOK_DELIM "\t\r\n\a"

/* points to an array of pointers to strings called environment*/
extern char **environ;

/**
 * struct parameters - struct that contains all parameters used at runtime
 * @av: arguemet vector
 * @input: command line written by user
 * @args: tokens of the command line
 * @status: last status of the shell
 * @counter: lines counter
 * @_environ: environment variable
 * @pid: process ID of the shell
*/
typedef struct parameters
{
    char **_environ;
    char **args;
    int status;
    int counter;
    char **av;
    char *pid;
    char *input;
} param;

/**
 * struct sep_list_s - single linked list
 * @separator: ; | &
 * @next: next node
 * Description: single linked list to store separators
 *
 */
typedef struct sep_list_s
{
	char separator;
	struct sep_list_s *next;
} sep_list;

#endif

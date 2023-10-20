#ifndef _SHELL_H
#define _SHELL_H


#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>
#include <fcntl.h>
#include <signal.h>
#include <sys/time.h>
#include <dirent.h>

#define DELIM "\t\n"
	



char *_getpath(char *command);
char **tokenizer(char *line);
char *_getenv(const char *variable);
char *_read_line(void);
int _execute(char **command, char *argv, int idx);

/* builtins.c */
int is_builtin(char *command);
void handle_builtin(char **command, char **argv, int *status, int idx);
void exit_shell(char **command, char **argv,  int *status, int idx);
void print_env(char **command, int *status);


int is_positive_number(char *str);




/* strings.c */
int _strcmp(char *s1, char *s2);
int _strlen(char *s);
char *_strdup(const char *str);
char *_strcat(char *dest, char *src);
char *_strcpy(char *dest, char *src);

/* tools.c */
void print_error(char *name, char *cmd, int idx);
void freearray2D(char **array);
void reverse_string(char *str, int len);
char *_itoa(int n);
/* char snprint(index_str, sizeof(index_str), "%d", idx); */


extern char **environ;

size_t _stlen(const char *str);

#endif

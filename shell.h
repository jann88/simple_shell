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
/**
 * struct line_list_s - single linked list
 * @line: command line
 * @next: next node
 * Description: single linked list to store command lines
 */
typedef struct line_list_s
{
	char *line;
	struct line_list_s *next;
} line_list;

/**
 * struct r_var_list - single linked list
 * @len_var: length of the variable
 * @val: value of the variable
 * @len_val: length of the value
 * @next: next node
 * Description: single linked list to store variables
 */
typedef struct r_var_list
{
	int len_val;
	char *val;
	int len_var;
	struct r_var_list *next;
} r_var;

/**
 * struct builtin_s - Builtin struct for command args.
 * @name: The name of the command builtin i.e cd, exit, env
 * @f: data type pointer function.
 */
typedef struct builtin
{
	char *name;
	int (*f)(param *commandArg);
} builtin_t;

/* lists.c */
sep_list *sepNode(sep_list **head, char sep);
void freeSeplist(sep_list **head);
line_list *lineNode(line_list **head, char *line);
void freeLinelist(line_list **head);

/* add_lists.c */
r_var *add_rvar_node(r_var **head, int lvar, char *var, int lval);
void free_rvar_list(r_var **head);

/* str_functions.c */
char *_strcat(char *dest, const char *src);
char *_strcpy(char *dest, char *src);
int _strcmp(char *s1, char *s2);
char *_strchr(char *s, char c);
int _strspn(char *s, char *accept);

/* mem._func.c */
void _memcpy(void *newptr, const void *ptr, unsigned int size);
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);
char **_reallocdp(char **ptr, unsigned int old_size, unsigned int new_size);

/* strl_functions.c */
char *_strdup(const char *s);
int _strlen(const char *s);
int cmp_chars(char str[], const char *delim);
char *_strtok(char str[], const char *delim);
int _isdigit(const char *s);

/* rev_string.c */
void rev_string(char *s);

/* syntax_checker.c */
int repeated_char(char *input, int i);
int error_sep_op(char *input, int i, char last);
int first_char(char *input, int *i);
void print_syntax_error(param *commandArg, char *input, int i, int bool);
int check_syntax_error(param *commandArg, char *input);

/* prompt.c */
char *rm_comment(char *input);
void shell_loop(param *commandArg);

/* read_line.c */
char *read_line(int *i_eof);

/* split.c */
char *swap_char(char *input, int bool);
void add_nodes(sep_list **head_s, line_list **head_l, char *input);
void go_next(sep_list **list_s, line_list **list_l, param *commandArg);
int split_commands(param *commandArg, char *input);
char **split_line(char *input);

/* rep_var.c */
void check_env(r_var **h, char *in, param *data);
int check_vars(r_var **h, char *in, char *st, param *data);
char *replaced_input(r_var **head, char *input, char *new_input, int nlen);
char *rep_var(char *input, param *commandArg);

/* get_line.c */
void assign_line(char **lineptr, size_t *n, char *buffer, size_t j);
ssize_t get_line(char **lineptr, size_t *n, FILE *stream);

/* execmd */
int execute(param *commandArg);

/* cmd_exec.c */
int is_cdir(char *path, int *i);
char *_which(char *cmd, char **_environ);
int is_executable(param *commandArg);
int check_error_cmd(char *dir, param *commandArg);
int cmd_exec(param *commandArg);

/* _getenv.c */
char *_getenv(const char *name, char **_environ);
int _env(param *commandArg);

/* setenv.c */
char *copy_info(char *name, char *value);
void set_env(char *name, char *value, param *commandArg);
int _setenv(param *commandArg);
int _unsetenv(param *commandArg);

/* cd.c */
void cd_dot(param *commandArg);
void cd_to(param *commandArg);
void cd_previous(param *commandArg);
void cd_to_home(param *commandArg);

/* cd_shell.c */
int _cd(param *commandArg);

/* get_builtin */
int (*get_builtin(char *cmd))(param *commandArg);

/* _exit.c */
int exitShell(param *commandArg);

/* aux_stdlib.c */
int get_len(int n);
char *aux_itoa(int n);
int _atoi(char *s);

/* get_sigint.c */
void get_sigint(int sig);

/* get_help.c */
int get_help(param *commandArg);

/* help.c */
void displayHelp_env(void);
void displayHelp_setenv(void);
void displayHelp_unsetenv(void);
void displayHelp_general(void);
void displayHelp_exit(void);

/* alias_help.c */
void displayHelp(void);
void displayHelp_alias(void);
void displayHelp_cd(void);

/* error1.c */
char *strcat_cd(param *, char *, char *, char *);
char *error_get_cd(param *commandArg);
char *error_not_found(param *commandArg);
char *error_exitShell(param *commandArg);

/* error2.c */
char *error_get_alias(char **args);
char *error_env(param *commandArg);
char *error_syntax(char **args);
char *error_permission(char **args);
char *error_path_126(param *commandArg);

/* get_error.c */
int get_error(param *commandArg, int eval);
#endif

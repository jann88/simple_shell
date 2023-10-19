#include "shell.h"
/**
 * check_env - checks the typed variable
 * @h: head of linked list
 * @in: string input
 * @data: data structure
 * Return: void
 *
 */
void check_env(r_var **h, char *in, param *data)
{
	int row, char_index, j, value_length;
	char **_envr;

	_envr = data->_environ;
	for (row = 0; _envr[row]; row++)
	{
		for (j = 1, char_index = 0; _envr[row][char_index]; char_index++)
		{
			if (_envr[row][char_index] == "=")
			{
				value_length = _strlen(_envr[row] + char_index + 1);
				add_rvar_node(h, j, _envr[row] + char_index + 1, value_length);
				return;
			}
			if (in[j] == _envr[row][char_index])
				j++;
			else
				break;
		}
	}
		for (j = 0; in[j]; j++)
		{
			if (in[j] == ' ' || in[j] == '\t' || in[j] == ';' || in[j] == '\n')
				break;
		}
		add_rvar_node(h, j, NULL, 0);
}
/**
 * check_vars - check if variable is $$ or $?
 * @h: head of linked list
 * @in: string input
 * @st: last status of the shell
 * @data: data structure
 * Return: void
 */
int check_vars(r_var **h, char *in, char *st, param *data)
{
	int i, lst, lpd;

	lpd = _strlen(st);
	lpd = _strlen(data->pid);

	for (i = 0; in[i]; i++)
	{
		if (in[i] == '$')
		{
			if (in[i +1] == '?')
				add_rvar_node(h, 2, st, lst), i++;
			else if (in[i + 1] == '$')
				add_rvar_node(h, 2, data->pid, lpd), i++;
			else if (in[i + 1] == '\n')
				add_rvar_node(h, 0, NULL, 0);
			else if (in[i + 1] == '\0')
				add_rvar_node(h, 0, NULL, 0);
			else if (in[i + 1] == ' ')
				add_rvar_node(h, 0, NULL, 0);
			else if (in[i + 1] == '\t')
				add_rvar_node(h, 0, NULL, 0);
			else if (in[i + 1] == ';')
				add_rvar_node(h, 0, NULL, 0);
			else
				check_env(h, in + i, data);
		}
	}
	return (i);
}
/**
 * replaced_input - replaces string
 * 2head: head of the linked list
 * @input: string input
 * @new_input: new input string
 * @nlen: new length
 * Return: string
 */
char *replaced_input(r_var **head, char *input, char *new_input, int nlen)
{
	r_var *current_variable;
	int a, b, c;

	current_variable = *head;
	for (b = a = 0; a< nlen; a++)
	{
		if (input[b] == '$')
		{
			if (!(current_variable->len_var) && !(current_variable->len_val))
			{
				new_input[a] = input[b];
				b++;
			}
			else if (current_variable->len_var && !(current_variable->len_val))
			{
				for ( c = 0; c < current_variable->len_var; c++)
					b++;
				a--;
			}
			else
			{
				for (c = 0; c < current_variable->len_val; c++)
				{
					new_input[a] = current_variable->val[c];
					a++;
				}
				b += (current_variable->len_var);
				a--;
			}
			current_variable = current_variable->next;
		}
		else
		{
			new_input[a] = input[b];
			b++;
		}
	}
	return (new_input);
}
/**
 * rep_var - replaces string into vars
 * @input: string input
 * @commandArg: data structure
 * Return: string
 */
char *rep_var(char *input, param *commandArg)
{
	r_var *head, *current_variable;
	char *status, *new_input;
	int olen, nlen;

	status = aux_itoa(commandArg->status);
	head = NULL;

	olen = check_vars(&head, input, status, commandArg);

	if (head == NULL)
	{
		free(status);
		return (input);
	}
	current_variable = head;
	nlen = 0;

	while (current_variable != NULL)
	{
		nlen += (current_variable->len_val - current_variable->len_var);
		current_variable = current_variable->next;
	}
	nlen += olen;

	new_input = malloc(sizeof(char) * (nlen + 1));
	new_input[nlen] = '\0';

	new_input = replaced_input(&head, input, new_input, nlen);

	free(input);
	free(status);
	free_rvar_list(&head);

	return (new_input);
}

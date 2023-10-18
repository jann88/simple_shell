#include "shell.h"
/**
 * add_rvar_node - adds a variable at the end
 * @head: head of the linked lists
 * @lvar: length
 * @val: value
 * @lval: length of value
 * Return: the address
 */
r_var *add_rvar_node(r_var **head, int lvar, char *val, int lval)
{
	r_var *new, *reset_node;

	new = malloc(sizeof(r_var));
	if (new == NULL)
		return (NULL);

	new->len_var = lvar;
	new->val = val;
	new->len_val = lval;

	new->next = NULL;
	reset_node = *head;

	if (reset_node == NULL)
	{
		*head = new;
	}
	else
	{
		while (reset_node->next != NULL)
			reset_node = reset_node->next;
		reset_node->next = new;
	}
	return (*head);
}
/**
 * free_rvar_list - free the r_var linked list
 * @head: head of the linked list
 * Return: void
 */
void free_rvar_list(r_var **head)
{
	r_var *reset_node;
	r_var *current_node;

	if (head != NULL)
	{
		current_node = *head;
		while ((reset_node = current_node) != NULL)
		{
			current_node = current_node->next;
			free(reset_node);
		}
		*head = NULL;
	}
}

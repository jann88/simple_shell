#include "shell.h"
/**
 * sepNode - adds a separator
 * @head: head of the linked list
 * @sep: separator
 * Return: the address
 */
sep_list *sepNode(sep_list **head, char sep)
{
	sep_list *new, *reset_node;

	new = malloc(sizeof(sep_list));
	if (new == NULL)
		return (NULL);

	new->separator = sep;
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
 * freeSeplist - frees a sep_list
 * @head: head of the linked list
 * Return: void
 */
void freeSeplist(sep_list **head)
{
	sep_list *reset_node;
	sep_list *current_node;

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
/**
 * lineNode - adds a command line at the end
 * of line_list
 * @head: head of the linked list.
 * @line: The command line.
 * Return: The address
 */
line_list *lineNode(line_list **head, char *line)
{
	line_list *new, *reset_node;

	new = malloc(sizeof(line_list));
	if (new == NULL)
		return (NULL);

	new->line = line;
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
 * freeLinelist - frees a line_list
 * @head: head of the linked list
 * Return: void
 *
 */
void freeLinelist(line_list **head)
{
	line_list *reset_node;
	line_list *current_node;

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

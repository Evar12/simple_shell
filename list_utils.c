#include "main.h"

/**
 * add_var_list_node - variable list node added
 *
 * @head: parameter name head passed
 * @var_len: len var
 * @val: value used
 * @val_len: vallen used
 *
 * Return: returned
 */
var_listt *add_var_list_node(var_listt **head,
		int var_len, char *val, int val_len)
{
	var_listt *new, *tmp;

	new = malloc(sizeof(var_listt));
	if (new == NULL)
		return (NULL);

	new->var_len = var_len;
	new->val = val;
	new->val_len = val_len;

	new->next = NULL;
	tmp = *head;

	if (tmp == NULL)
	{
		*head = new;
	}
	else
	{
		while (tmp->next != NULL)
			tmp = tmp->next;
		tmp->next = new;
	}

	return (*head);
}

/**
 * free_var_list - listed all variable
 * @head: head file
 */
void free_var_list(var_listt **head)
{
	var_listt *tmp, *cur;

	if (head != NULL)
	{
		cur = *head;
		while ((tmp = cur) != NULL)
		{
			cur = cur->next;
			free(tmp);
		}
		*head = NULL;
	}
}

/**
 * add_nodes - including nodes
 *
 * @sep_head: Sep heading
 * @line_head: cmd line header
 * @input: input value
 */
void add_nodes(sep_listt **sep_head, cline_listt **line_head, char *input)
{
	int a;
	char *line;

	input = swap_chars(input, 0);

	for (a = 0; input[a]; a++)
	{
		if (input[a] == ';')
			add_sep_node(sep_head, input[a]);

		if (input[a] == '|' || input[a] == '&')
		{
			add_sep_node(sep_head, input[a]);
			a++;
		}
	}

	line = _strtok(input, ";|&");
	do {
		line = swap_chars(line, 1);
		add_line_node(line_head, line);
		line = _strtok(NULL, ";|&");
	} while (line != NULL);
}

/**
 * add_sep_node - sep node addition
 * @head: header
 * @sep: sep file
 * Return: header returned
 */
sep_listt *add_sep_node(sep_listt **head, char sep)
{
	sep_listt *new, *temp;

	new = malloc(sizeof(sep_listt));
	if (new == NULL)
		return (NULL);

	new->sep = sep;
	new->next = NULL;
	temp = *head;

	if (temp == NULL)
	{
		*head = new;
	}
	else
	{
		while (temp->next != NULL)
			temp = temp->next;
		temp->next = new;
	}

	return (*head);
}

/**
 * add_line_node - cline to tail
 * @head: header
 * @line: cline fxn
 * Return: header return
 */
cline_listt *add_line_node(cline_listt **head, char *line)
{
	cline_listt *new, *temp;

	new = malloc(sizeof(cline_listt));
	if (new == NULL)
		return (NULL);

	new->line = line;
	new->next = NULL;
	temp = *head;

	if (temp == NULL)
	{
		*head = new;
	}
	else
	{
		while (temp->next != NULL)
			temp = temp->next;
		temp->next = new;
	}

	return (*head);
}

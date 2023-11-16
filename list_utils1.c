#include "main.h"

/**
 * free_line_list - listing free
 * @head: header file
 */
void free_line_list(cline_listt **head)
{
	cline_listt *temp;
	cline_listt *curr;

	if (*head != NULL)
	{
		curr = *head;

	while (curr != NULL)
	{
	temp = curr;
	curr = curr->next;
	free(temp);
	}

	*head = NULL;
	}
}
/*
 * void free_line_list(cline_listt *head)
	{
	cline_listt *temp;
	cline_listt *curr;

	if (head != NULL)
	{
		cline_listt *curr = *head;
		cline_listt *temp;

		do {
			temp = curr;
			]curr = curr->next;
			free(temp);
		} while (temp != NULL);
		*head = NULL;
	}
}
*/

/**
 * free_sep_list - sep
 * @head: header
 */
void free_sep_list(sep_listt **head)
{
	if (head != NULL)
	{
		sep_listt *curr = *head;
		sep_listt *temp;

		do {
			temp = curr;
			curr = curr->next;
			free(temp);
		} while (temp != NULL);
		*head = NULL;
	}
}

/**
 * next_node - nxt node
 *
 * @sep_l: fxn sep list
 * @line_l: file cline list
 * @data: fxn shell d
 */
void next_node(sep_listt **sep_l, cline_listt **line_l, shell_dt *data)
{
	int loop_sep;
	sep_listt *ls_s;
	cline_listt *ls_l;

	do {
		loop_sep = 1;
		ls_s = *sep_l;
		ls_l = *line_l;

	if (ls_s != NULL && loop_sep)
	{
	if (data->stat == 0)
	{
		if (ls_s->sep == '&' || ls_s->sep == ';')
			loop_sep = 0;
			if (ls_s->sep == '|')
			ls_l = ls_l->next, ls_s = ls_s->next;
	}
	else
	{
		if (ls_s->sep == '|' || ls_s->sep == ';')
		loop_sep = 0;
		if (ls_s->sep == '&')
		ls_l = ls_l->next, ls_s = ls_s->next;
	}
	}

	if (ls_s != NULL && !loop_sep)
	ls_s = ls_s->next;
} while (ls_s != NULL && loop_sep);

	*sep_l = ls_s;
	*line_l = ls_l;
}

#include "main.h"

/**
 * vars_sub - substitution of variable
 *
 * @input: file input
 * @data: data
 * Return: returned str
 */
char *vars_sub(char *input, shell_dt *data)
{
	var_listt *head, *temp;
	char *status, *new_input;
	int old_lenn, new_lenn;

	status = _itoa(data->stat);
	head = NULL;

	old_lenn = vars_check(&head, input, status, data);

	if (head == NULL)
	{
		free(status);
		return (input);
	}

	temp = head;
	new_lenn = 0;

	while (temp != NULL)
	{
		new_lenn += (temp->val_len - temp->var_len);
		temp = temp->next;
	}

	new_lenn += old_lenn;

	new_input = malloc(sizeof(char) * (new_lenn + 1));
	new_input[new_lenn] = '\0';

	new_input = var_val_sub(&head, input, new_input, new_lenn);

	free(input);
	free(status);
	free_var_list(&head);

	return (new_input);
}

/**
 * vars_check - fxn check vars
 *
 * @head: linked list
 * @input: file input
 * @status: status
 * @data: shll data
 *
 * Return: returned int
 */
int vars_check(var_listt **head, char *input, char *status, shell_dt *data)
{
	int a, stat_lenn, pid_lenn;

	stat_lenn = _strlen(status);
	pid_lenn = _strlen(data->pid);

	for (a = 0; input[a]; a++)
	{
		if (input[a] == '$')
		{
			if (input[a + 1] == '?')
				add_var_list_node(head, 2, status, stat_lenn), a++;
			else if (input[a + 1] == '$')
				add_var_list_node(head, 2, data->pid, pid_lenn), a++;
			else if (input[a + 1] == '\n')
				add_var_list_node(head, 0, NULL, 0);
			else if (input[a + 1] == '\0')
				add_var_list_node(head, 0, NULL, 0);
			else if (input[a + 1] == ' ')
				add_var_list_node(head, 0, NULL, 0);
			else if (input[a + 1] == '\t')
				add_var_list_node(head, 0, NULL, 0);
			else if (input[a + 1] == ';')
				add_var_list_node(head, 0, NULL, 0);
			else
				check_env(head, input + a, data);
		}
	}

	return (a);
}

/**
 * check_env - env variable
 *
 * @head: linked list
 * @input: fxn input
 * @data: data
 */
void check_env(var_listt **head, char *input, shell_dt *data)
{
	int r, c, j, val_lenn;
	char **_envar;

	_envar = data->_env;
	for (r = 0; _envar[r]; r++)
	{
		for (j = 1, c = 0; _envar[r][c]; c++)
		{
			if (_envar[r][c] == '=')
			{
				val_lenn = _strlen(_envar[r] + c + 1);
				add_var_list_node(head, j, _envar[r] + c + 1, val_lenn);
				return;
			}

			if (input[j] == _envar[r][c])
				j++;
			else
				break;
		}
	}

	for (j = 0; input[j]; j++)
	{
		if (input[j] == ' ' || input[j] == ';'
				|| input[j] == '\t' || input[j] == '\n')
			break;
	}

	add_var_list_node(head, j, NULL, 0);
}

/**
 * var_val_sub - val
 *
 * @head: header
 * @input: put
 * @replc_str: strng
 * @new_len: length
 * Return: strng
 */
char *var_val_sub(var_listt **head, char *input, char *replc_str, int new_len)
{
	var_listt *temp;
	int i, j, k;

	temp = *head;
	for (j = i = 0; i < new_len; i++)
	{
		if (input[j] == '$')
		{
			if (!(temp->var_len) && !(temp->val_len))
			{
				replc_str[i] = input[j];
				j++;
			}
			else if (temp->var_len && !(temp->val_len))
			{
				for (k = 0; k < temp->var_len; k++)
					j++;
				i--;
			}
			else
			{
				for (k = 0; k < temp->val_len; k++)
				{
					replc_str[i] = temp->val[k];
					i++;
				}
				j += (temp->var_len);
				i--;
			}
			temp = temp->next;
		}
		else
		{
			replc_str[i] = input[j];
			j++;
		}
	}

	return (replc_str);
}

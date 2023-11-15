#include "main.h"

/**
 * sheller - shell handles std
 * @data: fxn for shell data
 */
void sheller(shell_dt *data)
{
	int results, condition = 1;
	char *input = NULL;

	while (condition)
	{
		if (isatty(STDIN_FILENO))
			write(1, "$ ", 2);
		input = std_in(&results);
		if (results != -1)
		{
			if (is_empty(input))
			{
				write(1, "\n", 1);
				free(input);
				continue;
			}
			input = remove_comments(input);
			if (input == NULL)
				continue;

			if (check_syntax(data, input) == 1)
			{
				data->stat = 2;
				free(input);
				continue;
			}
			input = vars_sub(input, data);
			condition = run_cmds(data, input);
			data->count += 1;
			free(input);
		}
		else
		{
			condition = 0;
			free(input);
		}
	}
}

/**
 * std_in - std reads stdin
 *
 * @result: file result of getline
 * Return: returned input
 */
char *std_in(int *result)
{
	char *input = NULL;
	size_t size = 0;

	*result = getline(&input, &size, stdin);
	return (input);
}

/**
 * remove_comments - comments
 *
 * @input: fxn str
 * Return: returned str
 */
char *remove_comments(char *input)
{
	int a, count = 0;

	for (a = 0; input[a]; a++)
	{
		if (input[a] == '#')
		{
			if (a == 0)
			{
				free(input);
				return (NULL);
			}

			if (input[a - 1] == ' ' || input[a - 1] == ';' || input[a - 1] == '\t')
				count = a;
		}
	}

	if (count != 0)
	{
		input = _realloc(input, a, count + 1);
		input[count] = '\0';
	}

	return (input);
}
/**
 * is_empty - is it empyt?
 * @str: file string
 * Return: returned int
 */
int is_empty(char *str)
{
	while (*str != '\0')
	{
		if (*str != ' ')
			return (0);
		str++;
	}
	return (1);
}

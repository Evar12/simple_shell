#include "main.h"

/**
* tokenize - to tokenizes our string
*@buffer: buffer
*@separator: separators
*Return: returns the tokenized string
*/

char **tokenize(char *buffer, char *separator)
{
	char *token, *str, *str_d;
	char **tokens, *tmp;
	int count = 0, index = 0;

	token = NULL;
	tokens = NULL;
	if (buffer == NULL)
		return (NULL);
	str_d = strdup(buffer);
	count = count_token(str_d, separator);
	if (count == 0)
	{
		free(buffer);
		return (NULL);
	}
	tokens = malloc(sizeof(char *) * (count + 1));
	if (tokens == NULL)
	{
		free(buffer);
		return (NULL);
	}
	tmp = buffer;
	token = my_strtok(buffer, separator);
	while (token != NULL)
	{
		str = strdup(token);
		tokens[index++] = str;
		token = my_strtok(NULL, separator);
	}
	tokens[index] = NULL;
	free(tmp);
	return (tokens);
}
/**
*count_token - number of tokens
*@buffer: buffer
*@separator: separators
*Return: number o tokens
*/
int count_token(char *buffer, char *separator)
{
	char *token;
	int count = 0;
	char *tmp;

	tmp = buffer;
	if (buffer == NULL)
		return (0);
	token = my_strtok(buffer, separator);
	while (token)
	{
		count++;
		token = my_strtok(NULL, separator);
	}
	free(tmp);
	return (count);
}

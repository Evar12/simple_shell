#include "main.h"

/**
*free_mem - To free memory
*@tokens: tokens
*Return: 0
*/

void free_mem(char **tokens)
{
	char **tokens_c;

	if (tokens == NULL)
		return;
	tokens_c = tokens;
	while (*tokens_c)
	{
		free(*tokens_c);
		tokens_c++;
	}
	free(tokens);
}

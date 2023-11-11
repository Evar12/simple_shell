#include "main.h"

/**
* handle_sig - signal int
* @sig: file signal
*/
void handle_sig(int __attribute__((__unused__)) sig)
{
	write(1, "\n$ ", 3);
}

/**
 * _realloc - loc function
 * @ptr: file pointer
 * @old_size: size int
 * @new_size: size int
 *
 * Return: return pointer
 */
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	char *np;
	unsigned int a;

	if (new_size == old_size)
		return (ptr);
	if (ptr == NULL)
	{
		np = malloc(new_size);
		if (np == NULL)
		{
			free(np);
			return (NULL);
		}
		return (np);
	}
	if (new_size == 0 && ptr != NULL)
	{
		free(ptr);
		return (NULL);
	}

	np = malloc(new_size);
	if (np == NULL)
	{
		free(np);
		return (NULL);
	}

	for (a = 0; a < old_size; a++)
		np[a] = *((char *)ptr + a);

	free((void *) ptr);
	return (np);
}

/**
 * swap_chars - fxn swaps
 *
 * @input: file input
 * @type: file type
 * Return: return string
 */
char *swap_chars(char *input, int type)
{
	int a;

	if (type == 0)
	{
		for (a = 0; input[a]; a++)
		{
			if (input[a] == '|')
			{
				if (input[a + 1] != '|')
					input[a] = 16;
				else
					a++;
			}

			if (input[a] == '&')
			{
				if (input[a + 1] != '&')
					input[a] = 12;
				else
					a++;
			}
		}
	}
	else
	{
		for (a = 0; input[a]; a++)
		{
			input[a] = (input[a] == 16 ? '|' : input[a]);
			input[a] = (input[a] == 12 ? '&' : input[a]);
		}
	}
	return (input);
}

/**
 * _realloc2 - double p
 * @ptr: pointer
 * @old_size: file size
 * @new_size: size
 * Return: pointer
 */
char **_realloc2(char **ptr, unsigned int old_size, unsigned int new_size)
{
	char **newptr;
	unsigned int i;

	if (ptr == NULL)
		return (malloc(sizeof(char *) * new_size));

	if (new_size == old_size)
		return (ptr);

	newptr = malloc(sizeof(char *) * new_size);
	if (newptr == NULL)
		return (NULL);

	for (i = 0; i < old_size; i++)
		newptr[i] = ptr[i];

	free(ptr);

	return (newptr);
}

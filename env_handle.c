#include "main.h"
/**
  *handle_setenv - set enviroment function
  *@token: token to be passed
  *@file: file name
  *@env: environment variable
  *@n: status
  *Return: Returns status of the program
  */

int handle_setenv(char **token, char *file, char **env, int *n)
{
	(void)env;

	if (token[1] == NULL || (token[1] != NULL && token[2] == NULL))
	{
		env_err_handler(file, "Invalid argument");
		return (*n);
	}
	if (set_env(token[1], token[2], 1) == -1)
	{
		env_err_handler(file, "Invalid argument");
		*n = -1;
		return (*n);
	}
	*n = 0;
	return (*n);
}

/**
 * handle_unsetenv - environment variable
 * @token: the tokens
 * @file: the filename
 * @env: the environment
 * @n: the status code
 * Return: returns 0 - success
 */

int handle_unsetenv(char **token, char *file, char **env, int *n)
{
	(void)env;

	if (token[1] == NULL)
	{
		env_err_handler(file, "Invalid argument");
		return (*n);
	}
	if (my_unsetenv(token[1]) == -1)
	{
		error_handler(file, token[0], *n);
		*n = -1;
		return (*n);
	}
	*n = 0;
	return (*n);
}

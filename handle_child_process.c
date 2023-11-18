#include "main.h"

/**
  *handle_child - child process
  *@tokens: tokens passed into it
  *@file: file path
  *@env: environment variable
  *@ret_code: return code of the function
  */

void handle_child(char **tokens, char *file, char **env, int *ret_code)
{
	pid_t pid;
	int status;
	static int number = 1;

	pid = fork();
	if (pid < 0)
		*ret_code = -1;
	else if (pid == 0)
	{
		if (execve(tokens[0], tokens, env) == -1)
		{
			if (isatty(STDIN_FILENO))
				perror(file);
			else
				error_handler(file, tokens[0], number);
			free_mem(environ);
			free_mem(tokens);
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		wait(&status);
		if (!isatty(STDIN_FILENO))
			number++;
		if (status > 0)
			*ret_code = 2;
		else
			*ret_code = status;
	}
}

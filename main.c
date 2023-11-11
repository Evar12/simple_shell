#include "main.h"

/**
 * main - Main entry point
 *
 * @ac: numb of args
 * @av: args used
 *
 * Return: returned int
 */
int main(int __attribute__((__unused__)) ac, char **av)
{
	shell_dt data;

	signal(SIGINT, handle_sig);
	data_init(&data, av);
	sheller(&data);
	data_deinit(&data);

	if (data.stat < 0)
		return (255);
	return (data.stat);
}

/**
 * data_init - Shell data
 *
 * @data: shell
 * @av: arg
 */
void data_init(shell_dt *data, char **av)
{
	size_t a = 0;

	data->av = av;
	data->input = NULL;
	data->args = NULL;
	data->stat = 0;
	data->count = 1;

	while (environ[a])
		a++;

	data->_env = malloc(sizeof(char *) * (*a + 1));

	for (a = 0; environ[a]; a++)
	{
		data->_env[a] = _strdup(environ[a]);
	}

	data->_env[a] = NULL;
	data->pid = _itoa(getpid());
}

/**
 * data_deinit - init data
 *
 * @data: data
 */
void data_deinit(shell_dt *data)
{
	size_t a;

	for (a = 0; data->_env[a]; a++)
	{
		free(data->_env[a]);
	}

	free(data->_env);
	free(data->pid);
}

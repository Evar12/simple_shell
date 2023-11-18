#include "main.h"

/**
 * cd_previous - going into the desired directory
 * @dir_name: display the directory name
 * Return: Return 0 on success
 *-1 on failure returned
 *-2 on special case failure returned
 */

int cd_previous(char *dir_name)
{
	char pwd[300], oldpwd[300], *tmp1, *tmp2;

	(void)dir_name;
	tmp1 = my_getenv_val("PWD");
	tmp2 = my_getenv_val("OLDPWD");
	strcpy(pwd, tmp1);
	strcpy(oldpwd, tmp2);
	if (chdir(oldpwd) == -1)
	{
		return (-2);
	}
	if (set_env("PWD", oldpwd, 1) == -1)
		return (-1);
	if (set_env("OLDPWD", pwd, 1) == -1)
		return (-1);
	return (0);
}

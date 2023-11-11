#include "main.h"

/**
 * char_check - char
 * @str: file string
 * @delim: fxn delim
 *
 * Return: returned int
 */
int char_check(char str[], const char *delim)
{
	unsigned int xx, yy, zz;

	for (xx = 0, zz = 0; str[xx]; xx++)
	{
		for (yy = 0; delim[yy]; yy++)
		{
			if (str[xx] == delim[yy])
			{
				zz++;
				break;
			}
		}
	}
	if (xx == zz)
		return (1);
	return (0);
}

/**
 * _strtok - string
 * @str: file string
 * @delim: fxn delim
 *
 * Return: returned token
 */
char *_strtok(char str[], const char *delim)
{
	static char *str_cpy, *str_end;
	char *str_start;
	unsigned int i, found = 0;

	if (str != NULL)
	{
		if (char_check(str, delim))
			return (NULL);
		str_cpy = str;
		i = _strlen(str);
		str_end = &str[i];
	}
	str_start = str_cpy;
	if (str_start == str_end)
		return (NULL);

	for (; *str_cpy; str_cpy++)
	{
		if (str_cpy != str_start)
			if (*str_cpy && *(str_cpy - 1) == '\0')
				break;
		for (i = 0; delim[i]; i++)
		{
			if (*str_cpy == delim[i])
			{
				*str_cpy = '\0';
				if (str_cpy == str_start)
					str_start++;
				break;
			}
		}
		if (found == 0 && *str_cpy)
			found = 1;
	}
	if (found == 0)
		return (NULL);
	return (str_start);
}

/**
 * _strlen - str
 * @s: fxn pointer
 * Return: Rtn int
 */
int _strlen(const char *s)
{
	int counting = 0;

	while (s[counting])
		counting++;
	return (counting);
}

/**
* _strdup - a string
*
* @str: point str
* Return: rtn *char
*/
char *_strdup(char *str)
{
	char *p;
	unsigned int a;

	if (!str)
	{
		return (NULL);
	}

	for (a = 0; str[a] != '\0'; a++)
	{
	}
	p = (char *) malloc(a + 1);
	if (!p)
		return (NULL);
	for (a = 0; str[a] != '\0'; a++)
	{
		p[a] = str[a];
	}
	p[a] = '\0';
	return (p);

}

/**
* *_strcat - fxn stuff
*
* @src: file pointer
* @dest: file pointer
* Return: return char
*/
char *_strcat(char *dest, char *src)
{
	int a = 0, j = 0;

	while (dest[a] != '\0')
	{
		a++;
	}
	while (src[j] != '\0')
	{
		dest[a++] = src[j++];
	}
	dest[a] = '\0';
	return (dest);
}

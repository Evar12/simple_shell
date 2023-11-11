#include "main.h"

/**
* *_strcpy - fxn stuff
*
* @src: file pointer
* @dest: file pointer
* Return: return int
*/
char *_strcpy(char *dest, char *src)
{


	int count = 0, len = 0;

	while (src[len] != '\0')
	{
		len++;
	}

	while (count <= len)
	{
		dest[count] = src[count];
		count++;
	}
	return (dest);
}

/**
* *_strcmp - fxn stuff
*
* @s1: ex pointer
* @s2: ex pointer
* Return: return int
*/
int _strcmp(char *s1, char *s2)
{
	while (*s1 != '\0' && *s2 != '\0' && *s1 == *s2)
	{
		s1++;
		s2++;
	}

	return (*s1 - *s2);
}

/**
* rev_string - fxn stuff
*
* @s: ex pointer
* Return: return void
*/
void rev_string(char *s)
{
	int a;
	char temp;
	int lenn = _strlen(s);

	for (a = 0; a < lenn / 2; a++)
	{
		temp = s[a];
		s[a] = s[lenn - a - 1];
		s[lenn - a - 1] = temp;
	}


}

/**
 * _atoi - string to int
 *
 *
 * @s: fex string
 *
 * Return: return int
 */

int _atoi(char *s)
{
	int sign = 1, a = 0;
	unsigned int num = 0;

	while (!(s[a] <= '9' && s[a] >= '0') && s[a] != '\0')
	{
		if (s[a] == '-')
			sign *= -1;
		a++;
	}
	while (s[a] <= '9' && (s[a] >= '0' && s[a] != '\0'))
	{
		num = (num * 10) + (s[a] - '0');
		a++;
	}
	num *= sign;
	return (num);
}

/**
* _isint - if s is digit
*
* @s: check
*
* Return: true
*/
int _isint(const char *s)
{
	unsigned int a;

	for (a = 0; s[a]; a++)
	{
		if (s[a] < 48 || s[a] > 57)
			return (0);
	}
	return (1);
}

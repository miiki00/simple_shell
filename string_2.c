#include "main.h"

/**
 * _fputs - prints the string @str to the given fd(file descriptor).
 * @str: The string to be printed (should be null terminated)
 * @fd: The file descriptor.
 *
 * Return: The number of bytes written (success), -1 (error).
 */
ssize_t _fputs(char *str, int fd)
{
	return (write(fd, str, _strlen(str)));
}

/**
 * end_it - end a string with a null character if there is
 * any character similar with delimeters listed in @delim string.
 * @str: The string to be ended with a null value.
 * @delim: The delimetrs used to end the string.
 *
 * Return: The address of the null terminated string (success),
 * NULL (error).
 */
char *end_it(char *str, char *delim)
{
	ssize_t i, j;

	if (str == NULL || delim == NULL)
		return (NULL);
	for (i = 0; str[i] != '\0';  i++)
	{
		for (j = 0; j < _strlen(delim); j++)
		{
			if (str[i] == delim[j] && i != 0)
			{
				str[i] = '\0';
				break;
			}
		}
	}
	if (_strlen(str) == i)
		return (NULL);
	return (str);
}

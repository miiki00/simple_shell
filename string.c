#include "main.h"

/**
 * _strlen - countes the length of a string
 * @str: Pointer to the first value of the string.
 *
 * Return: Void.
 */
ssize_t _strlen(const char *str)
{
	ssize_t len = 0;

	if (str == NULL)
		return (0);
	while (*(str + len) != '\0')
		len++;
	return (len);
}
/**
 * concat_string - strings in the passed array.
 * @str: NULL terminated array of strings.
 *
 * Return: address of the concated string (success)
 * NULL (error)
 */
char *concat_string(char *str[])
{
	ssize_t i, m, j, len = 0;
	char *all;

	if (str == NULL)
		return (NULL);
	if (str[1] == NULL)
		return (str[0]);
	for (i = 0; str[i] != NULL; i++)
		len = len + _strlen(str[i]);
	all = malloc(sizeof(char) * (len + 1));
	if (all == NULL)
		return (NULL);
	for (i = 0, m = 0; str[i] != NULL; i++)
	{
		for (j = 0; j < _strlen(str[i]); j++, m++)
			all[m] = str[i][j];
	}
	all[len + 1] = '\0';
	return (all);
}
/**
 * _strcmp - compares string locatet @s1 and @s2.
 * @s1: The first string address.
 * @s2: The second string address.
 *
 * Return: 0 if they are same.
 * >0 if the first character's ascii value of @s1 if greater
 * than @s2. <0 if the ascii value of the first char of @s2 is
 * greater than @s2.
 */
int _strcmp(const char *s1, const char *s2)
{
	int ret;

	/* NULL case output should be checked */
	/* urgent */
	while (*s1 == *s2  && *s1 != '\0' && *s2 != '\0')
	{
		s1++;
		s2++;
	if (*(s1 + 1) == '\0' || *(s1 + 1) == '\0')
		ret = 0;
	}
	if (*s1 != '\0' && *s2 != '\0')
		ret = *s1 - *s2;
	return (ret);
}

/**
 * num_of_delim - calculates the no of existence of given delimeteres
 * in a given string.
 * @str: The string to search delimeters in.
 * @delim: The delimeteres to search on the string.
 *
 * Return: The number of delimeteres int the string (success)
 * -1 (error).
 */
int num_of_delim(char *str, char *delim)
{
	int i, j, num_delim = 0;

	if (str == NULL || delim == NULL)
		return (-1);
	for (i = 0; str[i] != '\0'; i++)
		for (j = 0; delim[j] != '\0'; j++)
			if (str[i] == delim[j])
				num_delim++;
	return (num_delim);
}

/**
 * _strdup - duplicates a string and stores it to a dynamicaly
 * allocated space and return address to it.
 * @str: The string to be duplicated.
 *
 * Return: address of the duplicate string (success), NULL (error)
 */
char *_strdup(const char *str)
{
	int len, i;
	char *dup = NULL;

	if (str == NULL)
		return (NULL);
	len = _strlen(str);
	if (len == 0)
		return (NULL);
	dup = malloc(sizeof(char) * (len + 1));
	if (dup == NULL)
		return (NULL);
	for (i = 0; i <= len; i++)
		dup[i] = str[i];
	return (dup);
}

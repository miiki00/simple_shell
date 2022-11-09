#include "main.h"

/**
 * free_darray - free all the address pointed by a pointer array.
 * @arr: The array of the pointer that points to the address to be freed.
 *
 * Return: Void.
 */
void free_darray(char **arr)
{
	int i;

	if (arr == NULL || *arr == NULL)
		return;
	for (i = 0; arr[i] != NULL; i++)
		free(arr[i]);
	free(arr);
}
/**
 * alloc_split - allocates memory for a string to be splited by @split_str.
 * @delim: The indexs of the delimeters in the string to be splited.
 *
 * Return: NULL terminated array of the allocated spaces (success) NULL (error)
 */
char **alloc_split(int *delim, int ndelim)
{
	int i, j, idx, tmp;
	char **split;
	
	
	if (delim == NULL || ndelim < 2)
		return (NULL);
	split = malloc(sizeof(char *) * ndelim + 1);
	if (split == NULL)
		return (NULL);
	for (j = 1, i = idx = 0; delim[j] != -1; j++, i++)
	{
		if (i == 0 && (tmp = delim[i] + 1) > 1)
		{
			split[idx++] = malloc(sizeof(int) * tmp);
			if (split[idx - 1] == NULL)
			{
				free_darray(split);
				return (NULL);
			}
		}
		else if ((tmp = delim[j] - delim[i]) > 1)
		{
			split[idx++] = malloc(sizeof(int) * tmp);
			if (split[idx - 1] == NULL)
			{
				free_darray(split);
				return (NULL);
			}
		}
	}
	split[idx] = NULL;
	return (split);
}

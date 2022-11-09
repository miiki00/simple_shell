#include "main.h"

/**
 * init_path - initialize a linked list of the path variables
 * of a the system.
 *
 * Return: The head of the list (success), NULL (error).
 */
path_l *init_path(void)
{
	char **paths = NULL;
	path_l *head = NULL, *tmp = NULL;
	int i;

	paths = split_path();
	if (paths == NULL)
	{
		printf("can't get path variables\n");
		return (NULL);
	}
	head = malloc(sizeof(path_l));
	if (head == NULL)
	{
		printf("not enough memory\n");
		return (NULL);
	}
	for (i = 1, tmp = head; ; i++, tmp = tmp->next)
	{
		tmp->path = paths[i];
		if (paths[i + 1] != NULL)
		{
			tmp->next = malloc(sizeof(path_t));
			if (tmp->next == NULL)
			{
				printf("not enough memory\n");
				return (NULL);
			}
		}
		else
		{
			tmp->next = NULL;
			break;
		}
	}

	free_darray(paths);
	return (head);
}

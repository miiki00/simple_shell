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

	if (arr == NULL)
		return;
	for (i = 0; arr[i] != NULL; i++)
		free(arr[i]);
	free(arr);
}

/**
 * free_path - free the linked list of the path variales.
 * @head: The head of the list.
 *
 * Retrun: Void.
 */
void free_path(path_l *head)
{
	path_l *tmp;

	if (head == NULL)
		return;
	tmp = head->next;
	while (head != NULL)
	{
		free(head);
		head = tmp;
		if (tmp != NULL)
			tmp = head->next;
	}
}


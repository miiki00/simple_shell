#include "main.h"

/**
 * free_darray - free all the address pointed by a pointer array.
 * @arr: The array of the pointer that points to the address to be freed.
 * @tog: to switch betweend 3 different modes
 * 0 - for freeing only the double pointer.
 * 1 - for freeing only the double pointer and the first address
 * that the double pointer pointes to.
 * 2 - (if the double pointer was array of pointers)for freeing
 * all the address that are pointed by the pointer in the array.
 *
 * Return: Void.
 */
void free_darray(char **arr, int tog)
{
	int i;

	if (arr == NULL || tog > 2 || tog < 0)
		return;
	if (tog == 2)
		for (i = 0; arr[i] != NULL; i++)
			free(arr[i]);
	if (tog == 1)
		free(*arr);
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
	free(head->path);
	tmp = head->next;
	while (head != NULL)
	{
		free(head);
		head = tmp;
		if (tmp != NULL)
			tmp = head->next;
	}
}


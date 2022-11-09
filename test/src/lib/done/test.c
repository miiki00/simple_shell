#include "main.h"

/**
 * main - test the code.
 * 
 * Return: Always 0.
 */
int main(void)
{
	static path_l *head;
	path_l *tmp;
	int i;

	head = init_path();
	if (head == NULL)
		return(1);
	for (tmp = head, i = 0; tmp != NULL; tmp = tmp->next)
		printf("list elt %d : %s\n", i++, tmp->path);
	free_path(head);
	return (0);
}

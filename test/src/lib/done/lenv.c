#include "main.h"

/**
 * _getenv - search for a given environtal variable environ
 * @name: The name of the variable.
 *
 * Return: The adress of the variable in the environ.
 * NULL (error).
 */
char *_getenv(const char *name)
{
	int i;

	if (name == NULL)
		return (NULL);
	for (i = 0; environ[i] != NULL; i++)
		if (_strcmp(name, environ[i]) == 0)
			return (environ[i]);
	return (NULL);
}

/**
 * split_path - split the enviromental vriable PATH of a process's in to dir
 *
 * Return: array of the directories (success), NULL (error).
 */
char **split_path(void)
{
	char *tmp = NULL, *dup = NULL, *delim = "=:", **paths = NULL;
	int i;

	tmp  = _getenv("PATH");
	if (tmp  == NULL)
		return (NULL);
	i = num_of_delim(tmp, delim);
	if (i == 0)
		return (NULL);
	dup = _strdup(tmp);
	if (dup == NULL)
		return (NULL);
	tmp = strtok(dup, &delim[0]);
	if (tmp == NULL)
	{
		free(dup);
		return (NULL);
	}
	paths = malloc(sizeof(char *) * (i + 4));
	if (paths == NULL)
	{
		free(dup);
		return (NULL);
	}
	i = 0;
	paths[i++] = tmp;
	paths[i++] = NULL;
	do {
		paths[i] = strtok(NULL, &delim[1]);
	} while (paths[i++] != NULL);
	return (paths);
}

/**
 * init_path - initialize a linked list of the path variables
 * of a the system.
 *
 * Return: The head of the list (success), NULL (error).
 */
path_l *init_path(void)
{
	char **paths = NULL;
	path_l *path_h = NULL, *tmp = NULL;
	int i;

	paths = split_path();
	if (paths == NULL)
		return (NULL);
	path_h = malloc(sizeof(path_l));
	if (path_h == NULL)
		return (NULL);
	for (i = 2, tmp = path_h; ; i++, tmp = tmp->next)
	{
		tmp->path = paths[i];
		if (paths[i + 1] != NULL)
		{
			tmp->next = malloc(sizeof(path_l));
			if (tmp->next == NULL)
				return (NULL);
		}
		else
		{
			tmp->next = NULL;
			break;
		}
	}
	free_darray(paths);
	return (path_h);
}

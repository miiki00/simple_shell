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
	int len;
	char **tmp;

	if (name == NULL)
		return (NULL);
	len = _strlen(name) + 1;
	for (tmp = environ; *tmp != NULL; tmp++)
		if (_strcmp(name, *tmp) == 0)
			return (*tmp + len);
	return (NULL);
}

/**
 * split_path - split the enviromental vriable PATH of a process's in to dir
 *
 * Return: array of the directories (success), NULL (error).
 */
char **split_path(void)
{
	char *tmp = NULL, *dup = NULL, delim = ':', **paths = NULL;
	int i;

	tmp  = _getenv("PATH");
	if (tmp  == NULL)
		return (NULL);
	i = num_of_delim(tmp, &delim);
	if (i == 0)
		return (NULL);
	dup = _strdup(tmp);
	if (dup == NULL)
		return (NULL);
	paths = malloc(sizeof(char *) * (i + 2));
	if (paths == NULL)
	{
		free(dup);
		return (NULL);
	}
	i = 0;
	paths[i++] = strtok(dup, &delim);
	do {
		paths[i] = strtok(NULL, &delim);
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
	for (i = 0, tmp = path_h; ; i++, tmp = tmp->next)
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
	free_darray(paths, 0);
	return (path_h);
}


/**
 * is_there - checks for the exixstenc of files in the
 * PATH variable list of directory
 * @file: The name of the file to look for.
 * @path_head: The head pointer of the list of PATH variables.
 * Description: you have to freee the address in the retuned pointer.
 *
 * Return: The full path of the file  (success), NULL (error)
 */
char *is_there(char *file, path_l *path_head)
{
	struct stat st;
	path_l *tmp;
	int ret;
	char *str = NULL, *path[] = {NULL, "/", NULL, NULL};

	if (file == NULL)
		return (NULL);
	for (tmp = path_head, path[2] = file; tmp != NULL; tmp = tmp->next)
	{
		path[0] = tmp->path;
		str = concat_string(path);
		if (str == NULL)
			return (NULL);
		ret = stat(str, &st);
		if (ret == 0)
			return (str);
		free(str);
	}
	return (NULL);
}

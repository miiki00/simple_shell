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
	char **paths = NULL;
	char *tmp = NULL, *path = NULL, *delim = "=:";
	int i;
	
	path = _getenv("PATH");
	if (path == NULL)
		return (NULL);
	i = num_of_delim(path, delim);
	if (i == 0)
		return (NULL);
	tmp = strtok(path, &delim[0]);
	if (tmp == NULL)
		return (NULL);
	paths = malloc(sizeof(char *) * i + 1);
	if (paths == NULL)
		return (NULL);
	for (i = 0; tmp != NULL; i++)
	{
		paths[i] = tmp;
		tmp = strtok(NULL, &delim[1]);
	}
	paths[i] = NULL;
	return (paths);
}
/**
 * main - test the code.
 * @ac: Number of arguments to main.
 * @av: The actual list argument.
 *
 * Return: 0 (success), 1 (error).
 */
int main(__attribute__((unused))int ac, __attribute__((unused))char **av)
{
        int i;
	char **paths;

	paths = split_path();
	if (paths == NULL)
	{
		printf("paths not splited");
		return (1);
	}
	for (i = 1; paths[i] != NULL; i++)
		printf("%s\n", paths[i]);
	paths[0] = NULL;
	free_darray(paths);
	return (0);
}

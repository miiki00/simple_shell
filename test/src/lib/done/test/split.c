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

/* test */

int main (void)
{
	char **split;
	int i;

	split = split_path();
	if (split == NULL)
		return (1);
	for (i = 2; split[i] != NULL; i++)
		printf("%s\n", split[i]);
	free_darray(split);
	return (0);
}

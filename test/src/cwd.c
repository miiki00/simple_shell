#include "main.h"

/**
 * main - prints current working directory.
 *
 * Return: 0 (success), 1 (error)
 */
int main(int ac, char *av[])
{
	struct stat st;
	int ret, i;
	char *cwd, *str;
	char *path[] = {NULL, "/", NULL};

	cwd = NULL;
	cwd = getcwd(cwd, 0);
	if (cwd == NULL)
	{
		perror("getcwd");
		return (1);
	}
	path[0] = cwd;
	for (i = 1; i < ac; i++)
	{
		path[2] = av[i];
		str = concat_string(path);
		if (str == NULL)
			return (1);
		ret = stat(str, &st);
		if (ret == 0)
			printf("%s : FOUND\n", str);
		else
			printf("%s : NOT FOUND\n", av[i]);
		free(str);
	}
	free(cwd);

	return (0);
}

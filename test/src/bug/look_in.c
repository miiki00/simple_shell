#include "main.h"

/**
 * main - checks for the exixstenc of files listd in
 * the array av in the current directory.
 * @av: Null terminated array containing list of file names.
 * descritption: arguments passed to the excutable program.
 * @ac: The number of arguments to passed to the program.
 *
 * Return: 0 (success), 1 (error)
 */
int main(int ac, char *av[])
{
	struct stat st;
	int ret, i;
	char *cwd = NULL, *str = NULL;
	char *path[] = {NULL, "/", NULL};

	if (ac == 1)
	{
		fprintf(stderr, "Usage: %s <files> ...\n", av[0]);
		return (1);
	}
	cwd = getcwd(cwd, 0);
	if (cwd == NULL)
	{
		perror("getcwd");
		return (1);
	}
	path[0] = cwd;
	for (i = 1; av[i] != NULL; i++)
	{
		path[2] = av[i];
		str = concat_string(path);
		if (str == NULL)
			return (1);
		ret = stat(str, &st);
		if (ret == 0)
			printf("%s : FOUND\n", av[i]);
		else
			printf("%s : NOT FOUND\n", av[i]);
		free(str);
	}
	free(cwd);

	return (0);
}

#include "main.h"

/**
 * _end_it - end a string with a null character if
 * there is any space new line or separator listed in the
 * below array.
 * @str: The string to be ended with a null value.
 *
 * Return: The address of the null terminated string (success),
 * NULL (error).
 */
char *_end_it(char *str)
{
	size_t i, j;
	char *arr = " ,;\t\n";
		
	if (str == NULL)
		return (NULL);
	for (i = 0; str[i] != '\0';  i++)
	{
		for (j = 0; j < 5; j++)
		{
			if (str[i] == arr[j] && i != 0)
			{
				str[i] = '\0';
				break;
			}
		}
	}
	if (strlen(str) == i)
		return (NULL);
	return (str);
}
/**
 * main - a simple command interpreter that interprets
 * commands with a full path given.
 *
 * Return: 0 (Success), 1 (Error).
 */
int main(void)
{
	ssize_t ret;
	size_t length;
	int status;
	char *command = NULL;
	char *argv[] = {NULL, NULL};
	pid_t executor;

	while (1)
	{
		printf("#cisfun$ ");
		ret = getline(&command, &length, stdin);
		if (ret == -1)
		{
			perror(NULL);
			return (1);
		}
		argv[0] = _end_it(command);
		executor = fork();
		if (executor == -1)
		{
			perror("Error: ");
			return (1);
		}
		if (executor == 0)
		{
			if (execve(command, argv, NULL) == -1)
			{
				free(command);
				perror("Error");
				return (1);
			}
			free(command);
			return (0);
		}
		else
		{
			ret = wait(&status);
			free(command);
			command = NULL;
			if (ret == -1)
				return (1);
		}
	}
	free(command);
	return (0);
}

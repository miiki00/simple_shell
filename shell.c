#include "main.h"

/**
 * _execute - excutes an excutable in @path wiht the arguments
 * in argv and in failuer to do so prints error message with
 * the name of the program at the front.
 * @path: The path to the executable.
 * @args: The argumets to the executable.
 * @prog: The name of the program.
 *
 * Return: 1 (success), -1 (error), -2 (invalid input).
 */
int _execute(char *path, char **args, char *prog)
{
	pid_t execute;
	int _stat;

	if (path == NULL || args == NULL || prog == NULL)
		return (-2);
	execute = fork();
	if (execute == -1)
		return (-1);
	if (execute == 0)
	{
		if (execve(path, args, environ) == -1)
		{
			perror(prog);
			exit(errno);
		}
	}
	else
	{
		wait(&_stat);
	}
	return (1);
}

/**
 * prompt - prompots with a message on the standard output and
 * takes input form the standard input
 * Description: Returns the input by terminating the last new line
 * charcter if there is.If msg is NULL it will continue with the
 * process with out prompting a message. if the program reaches EOF
 * in the statndard input the program will exit.
 * @msg: The message to prompte with.
 *
 * Return: The input strings address (success), NULL (error).
 */
char *prompt(char *msg)
{
	char *input = NULL;
	size_t len;
	ssize_t ret;

	_fputs(msg, STDOUT_FILENO);
	ret = getline(&input, &len, stdin);
	if (ret == -1)
		return (NULL);
	end_it(input, "\n");
	return (input);
}

/**
 * main - test the code.
 *
 * Return: Always 0.
 */
int main(__attribute__((unused))int argc, char *argv[])
{
	/* path_l *path_head; */
	char *input = NULL, *promp_msg = "#cisfun$ ";
	char *args[] = {NULL, NULL};


	while (1)
	{
		input = prompt(promp_msg);
		if (input == NULL)
		{
			_fputs("\n", STDOUT_FILENO);
			exit(errno);
		}
		args[1] = input;
		_execute(input, args, argv[0]);
		free(input);
	}
}

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
		_fputs("\n", STDOUT_FILENO);
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
	{
		free(input);
		return (NULL);
	}
	end_it(input, "\n");
	return (input);
}

/**
 * main - entry point of the shell programe.
 * @argc: The number of arguments passed to main.
 * @argv: The actual array of the arguments.
 *
 * Return: Always 0.
 */
int main(__attribute__((unused))int argc, char *argv[])
{
	path_l *path_head;
	char *input = NULL, *promp_msg = "#cisfun$ ";
	char *inp_path = NULL;
	char **args = NULL;

	path_head = init_path();
	while (1)
	{
		input = prompt(promp_msg);
		if (input == NULL)
			break;
		args = _split(input, " ");
		if (*input != '.' && *input != '/')
		{
			inp_path = is_there(args[0], path_head);
			if (inp_path == NULL)
			{
				_fputs(argv[0], STDERR_FILENO);
				_fputs(" : No such file or directory\n", STDERR_FILENO);
			}
		}
		if (*input == '.' || *input == '/')
			inp_path = _strdup(args[0]);
		if (inp_path != NULL)
			if (*inp_path == '.' || *inp_path == '/' || inp_path != NULL)
				_execute(inp_path, args, argv[0]);
		free(inp_path);
		free_darray(args, 1);
		free(input);
	}
	free_path(path_head);
	_fputs("\n", STDOUT_FILENO);
	exit(errno);
}

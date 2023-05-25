#include "shell.h"

/**
 * execute_command - executes a command with the given path
 * @path_cmd: path of the command
 * @argv: array of arguments
 * Return: void
 */
void execute_command(char *path_cmd, char *argv[])
{
	if (execve(path_cmd, argv, environ) == -1)
	{
		perror("Command not found");
		if (path_cmd)
			free(path_cmd);
		exit(EXIT_FAILURE);
	}
}

/**
 * _execute - executes the command
 * @argv: array of arguments
 * Return: void
 */
int _execute(char *argv[])
{
	char *path_cmd = NULL;
	pid_t born;
	int status;
	int built_in_flag = handl_built_fnc(argv[0], argv);

	if (_strcmp(argv[0], "cd") == 0)
	{
		if (_chdir(argv[1]) != 1)
			return (1);
		return (0);
	}
	path_cmd = get_path(argv[0]);

	if (path_cmd == NULL && !built_in_flag)
	{
		perror(argv[0]);
		return (100);
	}
	if (built_in_flag)
	{
		if (path_cmd)
			free(path_cmd);
		return (1);
	}
	born = fork();
	if (born == -1)
	{
		perror("Error (fork)");
		if (path_cmd)
			free(path_cmd);
		exit(EXIT_FAILURE);
	}
	else if (born == 0)
		execute_command(path_cmd, argv);
	wait(&status);
	/*printf("value of child %d\n", status);*/
	if (path_cmd)
		free(path_cmd);
	return (status);
}

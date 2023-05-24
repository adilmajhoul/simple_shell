#include "shell.h"

/**
 * _change_directory - helper function to change directory
 * @path: path to change to another one
 * Return: 1 on success, 0 on failure
 */
int _change_directory(char *path)
{
	char *home = NULL;

	if (path == NULL)
		path = "~";

	if (_strcmp(path, "cd") == 0)
		home = _getenv("HOME");
	else if (path[0] == '\0' || _strcmp(path, "~") == 0)
		home = _getenv("HOME");
	else
		home = path;

	if (home == NULL)
	{
		perror("error2");
		return (0);
	}

	if (chdir(home) != 0)
	{
		perror("error3");
		return (0);
	}

	return (1);
}

/**
 * _chdir - change directory
 * @path: path to change to another one
 * Return: 1 on success, 0 on failure
 */
int _chdir(char *path)
{
	char *argv;
	char cwd[1024];

	argv = _strdup(path);
	if (argv == NULL)
	{
		perror("error1");
		return (0);
	}

	if (!_change_directory(argv))
	{
		free(argv);
		return (0);
	}

	if (getcwd(cwd, sizeof(cwd)) == NULL)
	{
		perror("error7");
		free(argv);
		return (0);
	}

	free(argv);
	return (1);
}

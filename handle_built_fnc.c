#include "shell.h"

/**
 * handl_built_fnc - handles the built in functions
 * @cmd: command
 * @args: arguments
 * Return: 0 if not found, 1 if found
 */
int handl_built_fnc(char *cmd, char **args)
{
	if (_strcmp(cmd, "exit") == 0)
	{
		exit_fnc(args);
		return (1);
	}

	if (_strcmp(cmd, "env") == 0)
	{
		environment_fnc(args);
		return (1);
	}

	if (_strcmp(cmd, "setenv") == 0)
	{
		setenv_fnc(args);
		return (1);
	}

	if (_strcmp(cmd, "unsetenv") == 0)
	{
		_unsetenv(args[1]);
		return (1);
	}
	return (0);
}

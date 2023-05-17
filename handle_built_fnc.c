#include "shell.h"

/**
 * handl_built_fnc - handles the built in functions
 * @cmd: command
 * @args: arguments
 * @status: status
 * Return: 0 if not found, 1 if found
 */
void handl_built_fnc(char *cmd, char **args)
{
	if (_strcmp(cmd, "exit") == 0)
	{
		exit_fnc(args);
	}

	if (_strcmp(cmd, "env") == 0)
	{
		environment_fnc(args);
	}

	if (_strcmp(cmd, "setenv") == 0)
	{
		setenv_fnc(args);
	}
}

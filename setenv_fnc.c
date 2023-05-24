#include "shell.h"
/**
 * setenv_fnc - add new environment variable
 * @args: arguments
 * Return: void
 */
void setenv_fnc(char **args)
{
	int i = 0;

	for (i = 0; args[i] != NULL; i++)
		;

	if (i == 3)
	{
		_setenv(args[1], args[2], 1);
	}
	else
	{
		perror("setenv failed");
	}
}

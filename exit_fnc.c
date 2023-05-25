#include "shell.h"
/**
 * exit_fnc - exits the shell
 * @args: arguments
 * Return: void
 */
void exit_fnc(char **args)
{
	int i = 0;

	/* Count number of arguments */
	for (i = 0; args[i] != NULL; i++)
		;
	/* Check if there is only one argument */
	if (i == 1)
	{
		free(args);
		exit(0);
	}
	else if (i == 2)
	{
		int status = atoi(args[1]);

		free(args);
		exit(status);
	}
	else
	{
		perror("exit does not work");
		free(args);
		exit(2);
	}
}

#include "shell.h"
/**
 * shell_comments - replaces # with null character
 * @cmd: command line
 * Return: void
 */
void shell_comments(char *cmd)
{
	int i;

	/*
	if (strstr(cmd, "echo ") != NULL || strstr(cmd, "/bin/echo ") != NULL)
			return;
			*/

	for (i = 0; cmd[i] != '\0'; i++)
	{
		if (cmd[i] == '#')
		{
			cmd[i] = '\0'; /*replace # with null character*/
			break;		   /*stop counting the line after # cmnt is found*/
		}
	}
}

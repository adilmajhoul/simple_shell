#include "shell.h"
/**
 * shell_comments - replaces # with null character
 * @cmd: command line
 * Return: void
 */
void shell_comments(char *cmd)
{
	int i;
	int quotes = 0;

	for (i = 0; cmd[i] != '\0'; i++)
	{
		if ((cmd[i] == '\'' || cmd[i] == '\"') && !quotes)
			quotes = 1;
		else if ((cmd[i] == '\'' || cmd[i] == '\"') && quotes)
			quotes = 0;
		else if (!quotes && cmd[i] == '#')
		{
			if (i == 0 || cmd[i - 1] == ' ')
			{
				cmd[i] = '\0';
				break;
			}
		}
	}
}

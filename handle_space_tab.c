#include "shell.h"
/**
 * handle_space_tab - check if there is a space or tab in the command
 *@cmd: the command
 *Return: 1 if there is a space or tab, 0 otherwise
 */
int handle_space_tab(char *cmd)
{
	int i = 0;

	while (cmd[i])
	{
		if (cmd[i] == ' ' || cmd[i] == '\t')
			i++;
		else
			return (0);
	}

	return (1);
}

#include "shell.h"

/**
 * get_path - looks for command path
 * @command: commands
 * Return: path or null
 */
char *get_path(char *command)
{
	char *path, *hold_path_cpy, *file_path, *token;
	int cmd_len, dir_len;

	if (command[0] == '/' || command[0] == '.')
	{
		if (access(command, F_OK) == 0)
			return (_strdup(command));
		else
			return (NULL);
	}
	path = _getenv("PATH");
	if (path)
	{
		hold_path_cpy = _strdup(path);
		cmd_len = _strlen(command);
		token = _strtok(hold_path_cpy, ":");
		while (token)
		{
			dir_len = _strlen(token);
			file_path = malloc(sizeof(char) * (cmd_len + dir_len + 2));
			_strcpy(file_path, token);
			_strcat(file_path, "/");
			_strcat(file_path, command);
			_strcat(file_path, "\0");
			if (access(file_path, F_OK) == 0)
			{
				free(hold_path_cpy);
				return (file_path);
			}
			else
			{
				free(file_path);
				token = _strtok(NULL, ":");
			}
		}
		free(hold_path_cpy);
		return (NULL);
	}
	return (NULL);
}

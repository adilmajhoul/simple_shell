#include "shell.h"

/**
 * get_path - looks for command path
 * command: commands
 * Return: papth or null
 */
char *get_path(char *command)
{
	char *path, *hold_path_cpy, *file_path, *token;
	int cmd_len, dir_len;

	/* Check if command already includes an absolute or relative path */
	if (command[0] == '/' || command[0] == '.')
	{
		/* Check if file exists */
		if (access(command, F_OK) == 0)
			return _strdup(command);
		else
			return NULL;
	}

	/* Search through directories in PATH */
	path = _getenv("PATH");

	if (path)
	{
		/* Duplicate PATH */
		hold_path_cpy = _strdup(path);
		/* Get length of command */
		cmd_len = _strlen(command);
		/* Tokenize the PATH */
		token = _strtok(hold_path_cpy, ":");
		while (token)
		{
			/* Get length of directory */
			dir_len = _strlen(token);
			/* Allocate memory for command */
			file_path = malloc(sizeof(char) * (cmd_len + dir_len + 2)); /* +2 for '/' and '\0' */
			_strcpy(file_path, token);
			_strcat(file_path, "/");
			_strcat(file_path, command);
			_strcat(file_path, "\0");
			if (access(file_path, F_OK) == 0)
			{
				free(hold_path_cpy);
				return file_path;
			}
			else
			{
				free(file_path);
				token = _strtok(NULL, ":");
			}
		}
		/* Free memory if the path is not found */
		free(hold_path_cpy);
		return NULL;
	}
	return NULL;
}

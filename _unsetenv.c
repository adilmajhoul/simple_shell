#include "shell.h"

/**
 * _unsetenv - removes an environment variable
 * @name: the name of the environment variable to remove
 *
 * Return: 0 on success, -1 if the environment variable does not exist
 */
int _unsetenv(char *name)
{
	char **env = __environ;
	int i, j;
	int name_len = strlen(name);

	if (is_environment(name) == 0)
		return (-1);

	for (i = 0; env[i]; i++)
	{
		if (strncmp(name, env[i], name_len) == 0 && (env[i][name_len] == '='))
		{
			for (j = i; environ[j] != NULL; j++)
			{
				environ[j] = environ[j + 1];
			}
			environ[j] = NULL;

			return (0);
		}
	}
	return (-1);
}

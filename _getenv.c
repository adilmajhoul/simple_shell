#include "shell.h"
/**
 * _getenv - get environment variable
 * @PATH: environment variable
 *Return: value of environment variable
 */
char *_getenv(char *PATH)
{
	char **holder = __environ;
	char *value = NULL;
	int i = 0;
	size_t len = _strlen(PATH);

	for (; holder[i]; i++)
	{
		if (strncmp(PATH, holder[i], len) == 0 && (holder[i][len] == '='))
		{
			value = holder[i] + len + 1;
			break;
		}
	}
	return (value);
}

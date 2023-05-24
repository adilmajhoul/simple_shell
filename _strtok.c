#include "shell.h"
/*by me*/
/**
 * _strtok - tokenizes a string
 * @str: string to tokenize
 * @delimiter: base delimiter
 *
 * Return: token
 */

char *_strtok(char *str, const char *delimiter)
{
	char *tokenStart;
	static char *nextToken;

	if (str != NULL)
		nextToken = str;
	if (nextToken == NULL)
		return (NULL);
	while (*nextToken != '\0' && strchr(delimiter, *nextToken) != NULL)
		nextToken++;

	if (*nextToken == '\0')
		return (NULL);

	tokenStart = nextToken;
	while (*nextToken != '\0' && strchr(delimiter, *nextToken) == NULL)
		nextToken++;

	if (*nextToken != '\0')
	{
		*nextToken = '\0';
		nextToken++;
	}

	return (tokenStart);
}

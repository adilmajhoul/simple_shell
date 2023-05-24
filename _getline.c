#include "shell.h"
/**
 * _getline - get environment variable
 * @lineptr: environment variable
 * @n: ...
 * @stream:....
 *
 *Return: written bytes
 */

ssize_t _getline(char **lineptr, size_t *n, FILE *stream)
{
	char *buf = NULL;
	size_t buf_size = 0;
	ssize_t bytes_read;

	if (stream == NULL)
	{
		free(*lineptr);
		*lineptr = NULL;
		*n = 0;
		return (0);
	}

	bytes_read = getline(&buf, &buf_size, stream);

	if (bytes_read == -1)
	{
		free(buf);
		free(*lineptr);
		*lineptr = NULL;
		*n = 0;
	}
	else
	{
		free(*lineptr);
		*lineptr = buf;
		*n = buf_size;
	}

	return (bytes_read);
}

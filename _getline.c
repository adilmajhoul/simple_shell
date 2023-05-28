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
	char *buf;
	ssize_t i = 0, j;
	ssize_t bytes_read;

	if (!lineptr || !n || !stream)
		return (-1);
	if (*n == 0)
		*n = 100;
	buf = malloc(*n + 1);
	if (!buf)
		return (-1);
	bytes_read = read(fileno(stream), buf, *n);
	if (bytes_read < 0)
	{
		free(buf);
		return (-1);
	}
	while (buf[i] != '\n' && buf[i] != '\0')
		i++;

	buf[i] = '\0';
	if (*lineptr == NULL)
	{
		*lineptr = malloc(i + 1);
		if (!lineptr)
			return (-1);
	}
	for (j = 0; j <= i; j++)
	{
		(*lineptr)[j] = buf[j];
	}
	free(buf);
	return (i);
}

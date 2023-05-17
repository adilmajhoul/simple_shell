#include "shell.h"
/**
 * _getline - get environment variable
 * @lineptr: environment variable
 * @n: ...
 * @stream:....
 *
 *Return: written bytes
 */

ssize_t _getline(char **lineptr, __attribute__((unused))size_t *n, FILE *stream) 
{
    static char *buf = NULL;
    static size_t buf_size = 0;
    ssize_t bytes_read, i = 0;

    /* Allocate buffer if it is not already allocated */
    if (buf == NULL) {
        buf_size = 1024;  /* initial buffer size */
        buf = malloc(buf_size);
        if (buf == NULL) {
            *lineptr = NULL;
            return -1;
        }
    }

    /* Check for EOF */ 
    if ((bytes_read = read(fileno(stream), buf, buf_size)) < 0) {
        *lineptr = NULL;
        return -1;
    } else if (bytes_read == 0) { /* EOF */
        *lineptr = NULL;
        return -1;
    }

    /* Resize buffer if input exceeds size */
    while ((size_t)bytes_read >= buf_size) {
        buf_size *= 2;
        buf = realloc(buf, buf_size);
        if (buf == NULL) {
            *lineptr = NULL;
            return -1;
        }
    }

    /* Find EOL or EOF in input */
    while (i < bytes_read && buf[i] != '\n') {
        i++;
    }
    
    /* Null-terminate and set *lineptr */
    buf[i] = '\0';
    *lineptr = buf;

    return i; 
}
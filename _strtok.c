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

    static char *nextToken = NULL; /*stores the pointer to the next token*/
    if (str != NULL)
        nextToken = str;

    if (nextToken == NULL)
        return (NULL);

    /*Skip leading delimiters*/
    while (*nextToken != '\0' && strchr(delimiter, *nextToken) != NULL)
        nextToken++;

    if (*nextToken == '\0')
        return (NULL);

    /*Find the end of the token*/
    tokenStart = nextToken;
    while (*nextToken != '\0' && strchr(delimiter, *nextToken) == NULL)
        nextToken++;

    if (*nextToken != '\0')
    {
        *nextToken = '\0';
        nextToken++;
    } /*Null-terminate the token and move to the next character*/

    return (tokenStart);
}
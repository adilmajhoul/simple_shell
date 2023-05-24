#include "shell.h"
/**
 * _strcat - concatenates two strings
 * @dest: destination string
 * @src: source string
 * Return: pointer to resulting string
 */
char *_strcat(char *dest, char *src)
{
	int i = 0, j = 0;

	while (dest[i] != '\0')
		i++;
	while (src[j] != '\0')
	{
		dest[i] = src[j];
		i++;
		j++;
	}
	dest[i] = '\0';
	return (dest);
}
/**
 * _strcmp - compares two strings
 * @s1: first string
 * @s2: second string
 * Return: 0 if equal, less than 1 or greater than 1
 */
int _strcmp(char *s1, char *s2)
{
	int i = 0;

	for (; i < *s1 && i < *s2; i++)
	{
		if (*s1 != *s2)
			return (*s1 - *s2);
		s1++, s2++;
	}
	return (*s1 - *s2);
}
/**
 * _strdup - duplicates a string
 * @str: string to be duplicated
 * Return: pointer to the duplicated string
 */
char *_strdup(char *str)
{
	unsigned int i = 0;
	unsigned int len = 0;
	char *duplicater;

	if (str == NULL)
		return (NULL);

	for (; str[len] != '\0'; len++)
	{
	}
	duplicater = (char *)malloc((len + 1) * sizeof(char));

	if (duplicater == NULL)
		return (NULL);

	for (i = 0; i <= len; i++)
	{
		duplicater[i] = str[i];
	}
	return (duplicater);
}

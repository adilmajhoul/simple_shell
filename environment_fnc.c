#include "shell.h"

/**
 * environment_fnc - prints the environment
 * @args__attribute((unused)): unused arguments
 * Return: void
*/
void environment_fnc(char **args __attribute((unused)))
{
	int i = 0;

	for (; environ[i] != NULL; i++, _putchar('\n'))
		_puts(environ[i]);
}

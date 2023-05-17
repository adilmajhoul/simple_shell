#include "shell.h"
/**
 * setenv_fnc - add new environment variable
 * @args: arguments
 * Return: void
 */
void setenv_fnc(char **args)
{
    int i = 0;
    /* Count number of arguments */
    for (i = 0; args[i] != NULL; i++)
        ;
    /* Check if there are only two arguments */

    if (i == 3) // Change this condition to 3 because args[0] is probably the command itself
    {
        setenv(args[1], args[2], 1);

        // Don't free args here. It might be used later in the program.
    }
    else
    {
        perror("setenv failed");

        // Don't free args here. It might be used later in the program.
    }
}

#include "shell.h"
/**
 * execute - executes the command
 * @argv: array of arguments
 * Return: void
 */
int _execute(char *argv[])
{
    char *path_cmd = NULL;
    pid_t born;
    int status;

    /* Check if command is a built-in function */
    int built_in_flag = handl_built_fnc(argv[0], argv);
    /*change directories*/
    if (_strcmp(argv[0], "cd") == 0)
    {
        if (_chdir(argv[1]) != 1)
            return (1);
        return (0);
    }

    /* Get path for the command */
    path_cmd = get_path(argv[0]);

    /*if command doesn't exist don't fork*/
    if (path_cmd == NULL && !built_in_flag)
    {
        perror("walaaaa");
        return (100);
    }
    /*if built in function execute don't fork :( */
    if (built_in_flag)
    {
        if (path_cmd)
            free(path_cmd);
        return (1);
    }

    born = fork();
    if (born == -1)
    {
        perror("Error (fork)");
        if (path_cmd)
            free(path_cmd);
        exit(EXIT_FAILURE);
    }
    else if (born == 0)
    {
        /*execve the command along with path*/
        if (execve(path_cmd, argv, environ) == -1)
        {
            perror("Command not found");
            if (path_cmd)
                free(path_cmd);
            exit(EXIT_FAILURE);
        }
    }
    wait(&status);
    printf("value of child %d\n", status);

    if (path_cmd)
        free(path_cmd);

    return (status);
}

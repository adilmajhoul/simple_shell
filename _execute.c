#include "shell.h"
/**
 * execute - executes the command
 * @argv: array of arguments
 * Return: void
 */
int _execute(char *argv[])
{
    char *command = NULL, *path_cmd = NULL;
    pid_t born;
    int status;

    /* Check if command is a built-in function */
    handl_built_fnc(argv[0], argv);
    /*if command doesn't exist don't fork*/
    path_cmd = get_path(argv[0]);
    if (path_cmd == NULL)
    {
        perror("walaaaa");
        return (100);
    }
    born = fork();
    if (born == -1)
    {
        perror("Error (fork)");
        exit(EXIT_FAILURE);
    }
    else if (born == 0)
    {
        /*get cmd from user*/
        command = argv[0];
        /*get path_cmd before passing it to execve*/
        path_cmd = get_path(command);
        /*execve the command along with path*/
        if (execve(path_cmd, argv, environ) == -1)
        {
            perror("Command not found");
            exit(EXIT_FAILURE);
        }
    }
    wait(&status);
    printf("value of child %d\n", status);
    return (status);
}

#include "shell.h"
/**
 * _chdirection - change directory
 * @path: path to change to another one
 * Return: 1 on success, 0 on failure
 */
int _chdir(char *path)
{
    char *argv;
    char cwd[1024];

    if (path == NULL)
    {
        path = "~";
    }

    argv = _strdup(path);
    if (argv == NULL)
    {
        perror("error1");
        return 0;
    }

    if (_strcmp(argv, "cd") == 0)
    {
        char *home = _getenv("HOME");
        if (home == NULL)
        {
            perror("error2");
            free(argv);
            return 0;
        }
        if (chdir(home) != 0)
        {
            perror("error3");
            free(argv);
            return 0;
        }
    }
    else
    {
        if (argv[0] == '\0' || _strcmp(argv, "~") == 0)
        {
            char *home = _getenv("HOME");
            if (home == NULL)
            {
                perror("error4");
                free(argv);
                return 0;
            }
            if (chdir(home) != 0)
            {
                perror("error5");
                free(argv);
                return 0;
            }
        }
        else
        {
            if (chdir(argv) != 0)
            {
                perror("error6");
                free(argv);
                return 0;
            }
        }
    }

    if (getcwd(cwd, sizeof(cwd)) == NULL)
    {
        perror("error7");
        free(argv);
        return 0;
    }

    free(argv);
    return 1;
}

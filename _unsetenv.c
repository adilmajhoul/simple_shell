#include "shell.h"

extern char **__environ;

int _unsetenv(char *name)
{
    char **env = __environ;
    int i, j;
    int name_len = strlen(name);

    if (is_environment(name) == 0)
        return (-1);

    for (i = 0; env[i]; i++)
    {
        if (strncmp(name, env[i], name_len) == 0 && (env[i][name_len] == '='))
        {
            for (j = i; environ[j] != NULL; j++)
            {
                environ[j] = environ[j + 1];
            }
            environ[j] = NULL;
            return (0);
        }
    }
    return (-1);
}

/*

int main()
{
    // Print initial environment variables
    printf("Initial environment variables:\n");
    for (char **env = __environ; *env != NULL; env++)
    {
        printf("%s\n", *env);
    }
    printf("\n");

    // Unset environment variable
    if (_unsetenv("TERM") == 0)
    {
        printf("TERM successfully unset\n");
    }
    else
    {
        printf("TERM not found\n");
    }
    printf("\n");

    // Print updated environment variables
    printf("Updated environment variables:\n");
    for (char **env = __environ; *env != NULL; env++)
    {
        printf("%s\n", *env);
    }

    return 0;
}

*/
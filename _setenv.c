#include "shell.h"

extern char **__environ;

int is_environment(char *name)
{
    char **env = __environ;
    int i;
    int name_len = strlen(name);

    for (i = 0; env[i]; i++)
    {
        if (strncmp(name, env[i], name_len) == 0 && (env[i][name_len] == '='))
            return (1);
    }

    return (0);
}

/*----------------------------------------------------------*/
int concat_env(char *env_name, char *env_value)
{
    char *full_env;
    if (!env_name || !env_value)
        return 1;

    full_env = malloc(strlen(env_name) + strlen(env_value) + 2);
    strcpy(full_env, env_name);
    strcat(full_env, "=");
    strcat(full_env, env_value);

    if (putenv(full_env) != 0)
    {
        free(full_env);
        return 1;
    }

    return 0;
}
/*-------------------------------------------------------------*/
int _setenv(const char *name, const char *value, int overwrite)
{
    /*overwrite = 1*/
    if (overwrite)
    {
        if (concat_env((char *)name, (char *)value) == 0)
            return 0;
    }
    /*overwrite = 0*/
    else
    {
        if (is_environment((char *)name) != 1)
        {
            if (concat_env((char *)name, (char *)value) == 0)
                return 0;
        }
    }

    return 1;
}

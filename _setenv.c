#include "shell.h"

/**
 * is_environment - checks if a given name exists in the environment variables
 * @name: the name to search for
 * Return: 1 if the name exist, 0 otherwise
 */
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

/**
 * concat_env - concatenates an environment variable name and value
 * and adds it to the environment
 * @env_name: the name of the environment variable
 * @env_value: the value of the environment variable
 * Return: 0 on success, 1 on failure
 */
int concat_env(char *env_name, char *env_value)
{
	char *full_env;

	if (!env_name || !env_value)
		return (1);

	full_env = malloc(strlen(env_name) + strlen(env_value) + 2);
	strcpy(full_env, env_name);
	strcat(full_env, "=");
	strcat(full_env, env_value);

	if (putenv(full_env) != 0)
	{
		free(full_env);
		return (1);
	}

	return (0);
}
/**
 * print_env - prints the environment
 * Return: void
 */
void print_env(void)
{
	int i = 0;

	for (; environ[i] != NULL; i++, _putchar('\n'))
		_puts(environ[i]);
}
/**
 * _setenv - sets the value of an environment variable
 * @name: the name of the environment variable to set
 * @value: the value to assign to the environment variable
 * @overwrite: a flag indicating whether to overwrite an existing variable
 * with the same name (1) or not (0)
 * Return: 0 on success, 1 on failure
 */
int _setenv(const char *name, const char *value, int overwrite)
{
	/*overwrite */
	if (overwrite)
	{
		if (concat_env((char *)name, (char *)value) == 0)
		{
			print_env();
			return (0);
		}
	}
	/* dont overwrite */
	else
	{
		if (is_environment((char *)name) != 1)
		{
			if (concat_env((char *)name, (char *)value) == 0)
			{
				print_env();
				return (0);
			}
		}
	}

	return (1);
}

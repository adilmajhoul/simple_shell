#include "shell.h"
/**
 * free_tokens - helper function
 * @tokens: tokens to free
 * Return: nothing
 */
void free_tokens(char **tokens)
{
	int i = 0;

	while (tokens[i] != NULL)
	{
		free(tokens[i]);
		i++;
	}

	free(tokens);
}

/**
 * cleanup_and_exit - frees allocated memory and exits the program
 * @cmd: command string to free
 */
void cleanup_and_exit(char *cmd)
{
	/*_puts("Goodbye Lagend :)\n");*/
	_putchar('\n');
	free(cmd);
	exit(EXIT_SUCCESS);
}

/**
 * main - simple shell
 * @argc: number of arguments
 * @argv: arguments
 * @envp: environment
 * Return: 0 on success
 */
int main(__attribute__((unused)) int argc, char **argv __attribute__((unused)),
		 __attribute__((unused)) char **envp)
{
	char *cmd = NULL, *prompt = "$ ", *token_cmd;
	char **argu;
	ssize_t len = 0;
	size_t size = 0;
	bool flag = true;

	while (1 && flag)
	{
		if (isatty(STDIN_FILENO) == 0)
			flag = false;
		else
			_puts(prompt);
		if (getline(&cmd, &size, stdin) == -1)
			cleanup_and_exit(cmd);
		len = strlen(cmd);
		if (len > 0 && cmd[len - 1] == '\n')
			cmd[len - 1] = '\0';
		if (len == 1 || cmd[0] == '\n' || handle_space_tab(cmd) == 1)
			continue;
		shell_comments(cmd);
		if (cmd[0] == '\0')
			continue;
		token_cmd = strtok(cmd, ";\n");
		while (token_cmd)
		{
			argu = _allocate_strtoke(token_cmd);
			if (argu[0] == NULL || argu[0][0] == '\0')
			{
				token_cmd = strtok(NULL, ";\n");
				continue;
			}
			_execute(argu);
			free_tokens(argu);
			token_cmd = strtok(NULL, ";\n");
		}
	}
	free(cmd);
	return (0);
}

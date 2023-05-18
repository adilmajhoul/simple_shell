#include "shell.h"
/*by me*/
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
		/**
		 * check if input that is used with echo is no
		 * longer readable from a terminal
		 */
		if (isatty(STDIN_FILENO) == 0)
			flag = false;
		else
			_puts(prompt); /*write the prompt*/
		/*get input from user*/
		len = _getline(&cmd, &size, stdin);
		/*if getline fails free allocated memory*/
		if (len == EOF)
		{
			_puts("Goodbye Lagend :)\n");
			free(cmd);
			exit(EXIT_FAILURE);
		}
		/*replace newline with null character*/
		if (cmd[len - 1] == '\n')
			cmd[len - 1] = '\0';
		/*prinnt new line without error*/
		if (len == 1 || cmd[0] == '\n' || handle_space_tab(cmd) == 1)
			continue;

		token_cmd = strtok(cmd, ";"); /*Tokenize the command using ";"*/
		while (token_cmd)
		{
			/* split command into command name and arguments */
			argu = _allocate_strtoke(token_cmd);
			/* child born and execute command */
			_execute(argu);
			free(argu);					   /* free allocated memory of argu */
			token_cmd = strtok(NULL, ";"); /*Update token_cmd with next token*/
		}
	}
	free(cmd);
	return (0);
}

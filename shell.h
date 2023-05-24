#ifndef SHELL_H
#define SHELL_H
/*colors*/
#define BLOD "\x1b[1m"
#define RED "\x1b[31m"
#define GREEN "\x1b[32m"
#define YELLOW "\x1b[33m"
#define RESET "\x1b[0m"
/*macros*/
#define PATH_MAX 4096
#define input stdin
extern char **environ;
/*headers*/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <limits.h>
#include <fcntl.h>
#include <errno.h>
#include <stdbool.h>
#include <sys/stat.h>
#include <string.h>
#include <ctype.h>
#include <stddef.h>
#include <stdlib.h>
/*functions_helper*/
int _putchar(char c);
int _strlen(char *s);
char _puts(char *str);
char *_strcpy(char *dest, char *src);
char *_strcat(char *dest, char *src);
int _strcmp(char *s1, char *s2);
char *_strdup(char *str);
/*prototypes*/
char *_getenv(char *PATH);
int _execute(char *argv[]);
char **_allocate_strtoke(char *value);
int handl_built_fnc(char *cmd, char **args);
void environment_fnc(char **args __attribute((unused)));
void exit_fnc(char **args);
char *get_path(char *command);
int handle_space_tab(char *cmd);

ssize_t _getline(char **lineptr, size_t *n, FILE *stream);
char *_strtok(char *str, const char *delimiter);

/* setenv */
int _setenv(const char *name, const char *value, int overwrite);
int is_environment(char *name);
int concat_env(char *env_name, char *env_value);
void setenv_fnc(char **args);
extern char **__environ;
void print_env(void);
/* unsetenv */
int _unsetenv(char *name);
extern char **__environ;
void print_env(void);
/* cd */
int _chdir(char *path);
/*comment*/
void shell_comments(char *cmd);

#endif

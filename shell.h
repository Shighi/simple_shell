#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <dirent.h>
#include <signal.h>

/* Global environment variable */
extern char **environ;

/**
 * struct alias_s - Structure for alias
 * @name: Name of the alias
 * @value: Value of the alias
 */
typedef struct alias_s
{
	char *name;
	char *value;
} alias_t;

/* Function prototypes */
char *read_input(void);
char **parse_input(char *input);
int execute_command(char **args);
char *_getenv(const char *name);
int _setenv(const char *name, const char *value, int overwrite);
int _unsetenv(const char *name);
int _cd(char **args);
int process_file(char *filename);
void _puts(char *str);
int _putchar(char c);
char *_strdup(const char *str);
int _strcmp(char *s1, char *s2);
char *_strchr(char *s, char c);
unsigned int _strspn(char *s, char *accept);

/* Built-in commands */
int shell_exit(char **args);
int shell_env(char **args);
int shell_setenv(char **args);
int shell_unsetenv(char **args);
int shell_cd(char **args);
int shell_alias(char **args);

/* Helper functions */
char *find_command(char *command);
int is_builtin(char *command);
int execute_builtin(char **args);
int handle_logical_operators(char *input);
void replace_variables(char **args);
void handle_comments(char *input);
void print_alias(char *name, char *value);
void add_alias(char *name, char *value, alias_t *aliases, int *alias_count);
char *get_alias(char *name, alias_t *aliases, int alias_count);

#define BUFFER_SIZE 1024
#define MAX_ALIASES 100

#endif /* SHELL_H */

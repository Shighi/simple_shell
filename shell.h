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

extern char **environ;
extern int status;

#define BUFFER_SIZE 1024
#define MAX_ALIASES 100

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

/* Input and parsing functions */
char *read_input(void);
char **parse_input(char *input);
ssize_t _getline(char **lineptr, size_t *n, FILE *stream);

/* Command execution functions */
int execute_command(char **args);
int execute_command_list(char **commands, int num_commands);
int handle_logical_operators(char *input);

/* Environment functions */
char *_getenv(const char *name);
int _setenv(const char *name, const char *value, int overwrite);
int _unsetenv(const char *name);

/* File processing function */
int process_file(char *filename);

/* Helper functions */
void _puts(char *str);
int _putchar(char c);
char *_strdup(const char *str);
int _strcmp(char *s1, char *s2);
char *_strchr(char *s, char c);
unsigned int _strspn(char *s, char *accept);
char *pid_to_str(pid_t pid);
char *int_to_str(int num);

/* Built-in commands */
int shell_exit(char **args);
int shell_env(char **args);
int shell_setenv(char **args);
int shell_unsetenv(char **args);
int shell_cd(char **args);
int shell_alias(char **args);

/* Other function prototypes */
char *find_command(char *command);
int is_builtin(char *command);
int execute_builtin(char **args);
void replace_variables(char **args);
void handle_comments(char *input);

/* Alias functions */
void print_alias(char *name, char *value);
void add_alias(char *name, char *value, alias_t *aliases, int *alias_count);
char *get_alias(char *name, alias_t *aliases, int alias_count);

#endif /* SHELL_H */

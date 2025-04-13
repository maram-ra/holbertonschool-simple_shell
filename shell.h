#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <errno.h>

/* Access to the environment */
extern char **environ;

/* Prompt */
void shell_prompt(void);

/* Parsing */
char **tokenize_input(char *line);

/* Execution */
int execute_command(char **args, char *program_name);

/* PATH */
char *resolve_path(char *cmd);

/* Built-ins */
void print_env(void);

/* Helpers */
void free_array(char **arr);

#endif

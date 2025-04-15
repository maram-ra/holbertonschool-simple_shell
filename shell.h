#ifndef SHELL_H
#define SHELL_H

/* ==== STANDARD LIBRARIES ==== */
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>

/* ==== MACROS ==== */
#define MAX_ARGS 64
#define _GNU_SOURCE

/* ==== GLOBAL VARIABLES ==== */
extern char **environ;

/* ==== FUNCTION PROTOTYPES ==== */
int main(void);
int only_spaces(char *s);
char *read_line(void);
int only_spaces(char *s);
void parse_arguments(char *line, char **args);
char *find_command_path(char *command);
void execute_command(char *command_path, char **args);


#endif /* SHELL_H */

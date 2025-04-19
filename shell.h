#ifndef SHELL_H
#define SHELL_H

/**
 * shell.h - Header file for a simple UNIX-like shell.
 *
 * Description: Contains function prototypes, macros, and
 * global variables used throughout the shell.
 * Author: Hessah & Maram
 */

/* ================= STANDARD LIBRARY HEADERS ================ */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>

/* =========================== MACROS ======================== */

#define MAX_ARGS 64 /* Maximum number of arguments supported */
#define _GNU_SOURCE /* Enable GNU extensions (e.g., getline) */

/* ===================== GLOBAL VARIABLES ==================== */

extern char **environ;
extern int last_status;
extern char *line;

/* ================== FUNCTION PROTOTYPES ==================== */

/* input_utils.c */
int only_spaces(char *s);
char *read_line(void);
void parse_arguments(char *line, char **args);

/* tokenizer.c */
char *tokenize_input(char *line);

/* string_utils.c */
int _strlen(const char *s);
int _strncmp(const char *s1, const char *s2, size_t n);
char *_strdup(const char *str);

/* command execution */
char *find_command_path(char *command);
void execute_command(char *command_path, char **args);
void handle_command(char **args);

/* builtins */
int check_builtin(char **args);
void print_env(void);
void free_args_and_exit(void);

#endif /* SHELL_H */

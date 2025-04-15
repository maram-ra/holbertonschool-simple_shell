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

/* ==== GLOBAL VARIABLES ==== */
extern char **environ;

/* ==== FUNCTION PROTOTYPES ==== */

/* main.c */
int only_spaces(char *s);

/* path.c */
char *find_command(char *cmd);

#endif /* SHELL_H */

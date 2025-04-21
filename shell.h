#ifndef SIMPLE_SHELL_H
#define SIMPLE_SHELL_H

/* ========== AUTHORS ========== */
/* Maram Alsofyani & Hessah */

/* ========== Standard Libraries ========== */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/wait.h>

/* ========== External Variables ========== */
extern char **env;
extern char *command;
extern char **environ;

/* ========== Function Prototypes ========== */
int execute(char *const command[], char **envp);
int print_env(void);
char *_getenv(const char *name, char **envp);
void parse(char command[], char **envp);
void input(char **command, size_t *size);
char *pathfinder(char *cmd, char **envp);
void printerror(char *const command[]);

#endif /* SIMPLE_SHELL_H */

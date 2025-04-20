#include "shell.h"
#include <ctype.h>

char **env;
char *command;

/**
 * print_env - prints environment variables
 * Return: 0 on success
 */
int print_env(void)
{
	int i = 0;

	while (env[i])
	{
		printf("%s\n", env[i]);
		i++;
	}
	return (0);
}

/**
 * parse - tokenizes and executes command
 * @command: user input
 * @envp: environment
 */
void parse(char command[], char **envp)
{
	char *args[11];
	char *token;
	int i = 0;


	while (isspace(*command))
		command++;

	token = strtok(command, " ");
	while (token && i < 10)
	{
		args[i++] = token;
		token = strtok(NULL, " ");
	}
	args[i] = NULL;

	if (i > 0)
		execute(args, envp);
}


/**
 * input - handles user input
 * @command: pointer to input buffer
 * @size: size of buffer
 */
void input(char **command, size_t *size)
{
	ssize_t nread = getline(command, size, stdin);

	if (nread == -1)
	{
		if (isatty(STDIN_FILENO))
			write(STDOUT_FILENO, "\n", 1);
		free(*command);
		exit(EXIT_SUCCESS);
	}
	if ((*command)[nread - 1] == '\n')
		(*command)[nread - 1] = '\0';
}

/**
 * main - shell loop
 * @argc: argument count
 * @argv: argument vector
 * @envp: environment
 * Return: 0
 */
int main(int argc, char *argv[], char **envp)
{
	size_t size;

	(void)argv;
	env = envp;

	if (argc > 1)
	{
		fprintf(stderr, "./hsh: Too many arguments\n");
		exit(EXIT_FAILURE);
	}

	while (1)
	{
		command = NULL;
		size = 0;

		if (isatty(STDIN_FILENO))
			printf("($) ");
		input(&command, &size);

		if (strcmp(command, "exit") == 0)
		{
			free(command);
			exit(EXIT_SUCCESS);
		}
		else if (strcmp(command, "env") == 0)
		{
			print_env();
		}
		else
		{
			parse(command, envp);
		}
		free(command);
	}
	return (0);
}

#include "shell.h"

char **env;
char *command;

/**
 * print_env - prints the environment
 * Return: 0 on success, -1 on error
 */
int print_env(void)
{
	int i = 0;

	if (env == NULL)
		return (-1);
	while (env[i])
	{
		printf("%s\n", env[i++]);
	}
	return (0);
}

/**
 * parse - tokenizes the command
 * @command: command from user
 * @envp: environment variables
 */
void parse(char command[], char **envp)
{
	char *arguments[11];
	char *token = strtok(command, " ");
	int arg_count = 0;

	while (token != NULL && arg_count < 10)
	{
		arguments[arg_count++] = token;
		token = strtok(NULL, " ");
	}
	if (arg_count > 10)
	{
		perror("Error: Too many arguments");
		return;
	}
	arguments[arg_count] = NULL;
	if (arg_count > 0)
	{
		if (envp != NULL)
			execute(arguments, envp);
		else
		{
			fprintf(stderr, "./hsh: 1: %s: not found\n", arguments[0]);
			exit(127);
		}
	}
}

/**
 * input - prompts user for input
 * @command: pointer to input buffer
 * @size: pointer to buffer size
 */
void input(char **command, size_t *size)
{
	ssize_t read_bytes;

	read_bytes = getline(command, size, stdin);
	if (read_bytes == EOF)
	{
		if (isatty(STDIN_FILENO))
			printf("\n");
		if (*command != NULL)
			free(*command);
		exit(EXIT_SUCCESS);
	}
	if ((*command)[read_bytes - 1] == '\n')
		(*command)[read_bytes - 1] = '\0';
}

/**
 * main - entry point for the shell
 * @argc: argument count
 * @argv: argument vector
 * @envp: environment variables
 * Return: 0 on success
 */
int main(int argc, char *argv[], char **envp)
{
	size_t size;

	env = envp;
	command = NULL;
	(void)argv;

	if (argc > 1)
	{
		printf("./shell: command does not exist\n");
		exit(EXIT_FAILURE);
	}

	while (1)
	{
		size = 0;
		if (isatty(STDIN_FILENO))
			printf("($) ");
		input(&command, &size);

		if (strcmp(command, "exit") == 0)
		{
			free(command);
			exit(EXIT_SUCCESS);
		}
		if (strcmp(command, "env") == 0)
		{
			print_env();
			free(command);
			exit(EXIT_SUCCESS);
		}
		if (_getenv("PATH", envp) == NULL)
		{
			if (command[0] != '/')
			{
				fprintf(stderr, "./hsh: 1: %s: not found\n", command);
				free(command);
				exit(127);
			}
		}
		parse(command, envp);
		free(command);
	}
	return (0);
}

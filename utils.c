#include "shell.h"

/* Input Utilities */
int only_spaces(char *s)
{
    while (*s) {
        if (*s != ' ' && *s != '\t' && *s != '\n')
            return (0);
        s++;
    }
    return (1);
}

char *read_line(void)
{
    char *line = NULL;
    size_t len = 0;
    ssize_t read;

    read = getline(&line, &len, stdin);
    if (read == -1) {
        free(line);
        return (NULL);
    }

    if (line[read - 1] == '\n')
        line[read - 1] = '\0';

    return (line);
}

/* Tokenization */
char *tokenize_input(char *line)
{
    static char *current;
    char *start;

    if (line)
        current = line;

    while (*current == ' ' || *current == '\t')
        current++;

    if (*current == '\0')
        return (NULL);

    start = current;

    while (*current && *current != ' ' && *current != '\t')
        current++;

    if (*current) {
        *current = '\0';
        current++;
    }

    return (start);
}

void parse_arguments(char *line, char **args)
{
    int i = 0;
    char *token;

    while (*line == ' ' || *line == '\t')
        line++;

    token = tokenize_input(line);
    while (token && i < MAX_ARGS - 1) {
        args[i++] = token;
        token = tokenize_input(NULL);
    }
    args[i] = NULL;
}

/* String Utilities */
int _strlen(const char *s)
{
    int len = 0;

    while (s[len])
        len++;

    return (len);
}

int _strncmp(const char *s1, const char *s2, size_t n)
{
    size_t i;

    for (i = 0; i < n && s1[i] && s2[i]; i++)
        if (s1[i] != s2[i])
            return (s1[i] - s2[i]);

    if (i < n)
        return (s1[i] - s2[i]);

    return (0);
}

char *_strdup(const char *str)
{
    char *dup;
    int len, i;

    if (!str)
        return (NULL);

    len = _strlen(str);
    dup = malloc(len + 1);
    if (!dup)
        return (NULL);

    for (i = 0; i <= len; i++)
        dup[i] = str[i];

    return (dup);
}

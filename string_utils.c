#include "shell.h"

/**
 * _strlen - Calculates the length of a string (like strlen)
 * @s: The input string
 *
 * Return: Length of the string
 */
int _strlen(const char *s)
{
	int len = 0;

	while (s[len])
		len++;

	return (len);
}

/**
 * _strncmp - Compares two strings up to n bytes (like strncmp)
 * @s1: First string
 * @s2: Second string
 * @n: Number of characters to compare
 *
 * Return: 0 if strings are equal up to n, otherwise difference
 */
int _strncmp(const char *s1, const char *s2, size_t n)
{
	size_t i;

	for (i = 0; i < n && s1[i] && s2[i]; i++)
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
	}

	if (i < n)
		return (s1[i] - s2[i]);

	return (0);
}

/**
 * _strdup - Duplicates a string (like the standard strdup)
 * @str: The input string to duplicate
 *
 * Return: A pointer to the newly allocated copy of the string,
 *         or NULL if memory allocation fails
 */
char *_strdup(const char *str)
{
	char *dup;
	int len = _strlen(str);
	int i;

	dup = malloc(sizeof(char) * (len + 1));
	if (!dup)
		return (NULL);

	for (i = 0; i < len; i++)
		dup[i] = str[i];

	dup[i] = '\0'; /* Null-terminate the new string */
	return (dup);
}

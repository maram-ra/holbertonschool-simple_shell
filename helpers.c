#include "shell.h"

/**
 * free_array - Frees an array of strings
 * @arr: The array to free
 */
void free_array(char **arr)
{
	int i = 0;

	if (!arr)
		return;

	while (arr[i])
		free(arr[i++]);

	free(arr);
}

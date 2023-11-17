#include "shell.h"

/**
 * bfree - frees a pointer and sets it to NULL
 * @frpt: pointer to free
 * Return: 1 if freed, else 0.
 */
int bfree(void **frpt)
{
	if (frpt && *frpt)
	{
		free(*frpt);
		*frpt = NULL;
		return (1);
	}
	return (0);
}

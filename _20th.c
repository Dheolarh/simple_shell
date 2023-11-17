#include "shell.h"

/**
 * **strtow - splits a string into words
 * @is: input string
 * @ds: delimeter string
 * Return: a pointer to an array of strings, or NULL on failure
 */

char **strtow(char *is, char *ds)
{
	int u, x, y, z, numwords = 0;
	char **s;

	if (is == NULL || is[0] == 0)
		return (NULL);
	if (!ds)
		ds = " ";
	for (u = 0; is[u] != '\0'; u++)
		if (!is_delim(is[u], ds) && (is_delim(is[u + 1], ds) || !is[u + 1]))
			numwords++;

	if (numwords == 0)
		return (NULL);
	s = malloc((1 + numwords) * sizeof(char *));
	if (!s)
		return (NULL);
	for (u = 0, x = 0; x < numwords; x++)
	{
		while (is_delim(is[u], ds))
			u++;
		y = 0;
		while (!is_delim(is[u + y], ds) && is[u + y])
			y++;
		s[x] = malloc((y + 1) * sizeof(char));
		if (!s[x])
		{
			for (y = 0; y < x; y++)
				free(s[y]);
			free(s);
			return (NULL);
		}
		for (z = 0; z < y; z++)
			s[x][z] = is[u++];
		s[x][z] = 0;
	}
	s[x] = NULL;
	return (s);
}

/**
 * **strtow2 - splits a string into words
 * @is: input string
 * @ds: delimeter string
 * Return: a pointer to an array of strings, or NULL on failure
 */
char **strtow2(char *is, char ds)
{
	int u, x, y, z, numwords = 0;
	char **s;

	if (is == NULL || is[0] == 0)
		return (NULL);
	for (u = 0; is[u] != '\0'; u++)
		if ((is[u] != ds && is[u + 1] == ds) ||
				    (is[u] != ds && !is[u + 1]) || is[u + 1] == ds)
			numwords++;
	if (numwords == 0)
		return (NULL);
	s = malloc((1 + numwords) * sizeof(char *));
	if (!s)
		return (NULL);
	for (u = 0, x = 0; x < numwords; x++)
	{
		while (is[u] == ds && is[u] != ds)
			u++;
		y = 0;
		while (is[u + y] != ds && is[u + y] && is[u + y] != ds)
			y++;
		s[x] = malloc((y + 1) * sizeof(char));
		if (!s[x])
		{
			for (y = 0; y < x; y++)
				free(s[y]);
			free(s);
			return (NULL);
		}
		for (z = 0; z < y; z++)
			s[x][z] = is[u++];
		s[x][z] = 0;
	}
	s[x] = NULL;
	return (s);
}


#include "shell.h"

/**
 * _strncpy - this function copies a string from source to destination.
 * @ds: The destination string to be copied to.
 * @ss: The source string.
 * @n: The amount of characters to be copied.
 * Return: The concatenated string.
 */
char *_strncpy(char *ds, char *ss, int n)
{
	int i, j;
	char *t = ds;

	i = 0;
	while (ss[i] != '\0' && i < n - 1)
	{
		ds[i] = ss[i];
		i++;
	}
	if (i < n)
	{
		j = i;
		while (j < n)
		{
			ds[j] = '\0';
			j++;
		}
	}
	return (t);
}

/**
 * _strncat - appends the src string to the dest string.
 * @os: The first string to be appended to.
 * @ts: The second string to be appended to the first one.
 * @n: The amount of bytes to be maximally appended to dest.
 * Return: The concatenated string.
 */
char *_strncat(char *os, char *ts, int n)
{
	int i, j;
	char *t = os;

	i = 0;
	j = 0;
	while (os[i] != '\0')
		i++;
	while (ts[j] != '\0' && j < n)
	{
		ds[i] = ts[j];
		i++;
		j++;
	}
	if (j < n)
		ds[i] = '\0';
	return (t);
}

/**
 * _strchr - checks for a character in a string
 * @t: The string to be parsed.
 * @c: The character to look for.
 * Return: A pointer to the memory area t.
 */
char *_strchr(char *t, char c)
{
	do {
		if (*t == c)
			return (t);
	} while (*t++ != '\0');

	return (NULL);
}

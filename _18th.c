#include "shell.h"

/**
 * _strlen - shows the length of a string
 * @cs: string to check length of
 * Return: integer length of string
 */
int _strlen(char *cs)
{
	int i = 0;

	if (!cs)
		return (0);

	while (*cs++)
		i++;
	return (i);
}

/**
 * _strcmp - compares two strings
 * @os: first strang
 * @ts: second strang
 * Return: negative if os < ts, positive if os > ts, zero if os == ts
 */
int _strcmp(char *os, char *ts)
{
	while (*os && *ts)
	{
		if (*os != *ts)
			return (*os - *ts);
		os++;
		ts++;
	}
	if (*os == *ts)
		return (0);
	else
		return (*os < *ts ? -1 : 1);
}

/**
 * starts_with - checks if a string starts with a given substring
 * @haystack: string query
 * @needle: substring query
 * Return: address of next char of haystack or 0 (NULL)
 */
char *starts_with(const char *haystack, const char *needle)
{
	while (*needle)
		if (*needle++ != *haystack++)
			return (NULL);
	return ((char *)haystack);
}

/**
 * _strcat - concatenates two strings
 * @dest: destination buffer
 * @src: source buffer
 * Return: pointer to destination buffer
 */
char *_strcat(char *dest, char *src)
{
	char *ret = dest;

	while (*dest)
		dest++;
	while (*src)
		*dest++ = *src++;
	*dest = *src;
	return (ret);
}


#include "shell.h"

/**
 * _strcpy - copies a string
 * @dest: destination of the copied string
 * @src: the source of the copied string
 *
 * Return: pointer to destination
 */
char *_strcpy(char *dest, char *src)
{
	int i = 0;

	if (dest == src || src == 0)
		return (dest);
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = 0;
	return (dest);
}

/**
 * _strdup - multiply same string
 * @stp: the string to multiply
 * Return: pointer to the multiplied string
 */
char *_strdup(const char *stp)
{
	int length = 0;
	char *ret;

	if (stp == NULL)
		return (NULL);
	while (*stp++)
		length++;
	ret = malloc(sizeof(char) * (length + 1));
	if (!ret)
		return (NULL);
	for (length++; length--;)
		ret[length] = *--stp;
	return (ret);
}

/**
 * _puts - prints a string
 * @stp: the string to be printed
 * Return: Nothing
 */
void _puts(char *stp)
{
	int i = 0;

	if (!stp)
		return;
	while (stp[i] != '\0')
	{
		_putchar(stp[i]);
		i++;
	}
}

/**
 * _putchar - writes the character c to stdout
 * @c: The character to print
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _putchar(char c)
{
	static int i;
	static char buf[WRITE_BUF_SIZE];

	if (c == BUF_FLUSH || i >= WRITE_BUF_SIZE)
	{
		write(1, buf, i);
		i = 0;
	}
	if (c != BUF_FLUSH)
		buf[i++] = c;
	return (1);
}


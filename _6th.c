#include "shell.h"

/**
 * _eputs - prints a given string to the standard error output
 * @str: the string to be printed
 * Return: Nothing
 */
void _eputs(char *str)
{
	int j = 0;

	if (!str)
		return;
	while (str[j] != '\0')
	{
		_eputchar(str[j]);
		j++;
	}
}

/**
 * _eputchar - writes a given character to the standard error output
 * @n: The character to be printed
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _eputchar(char n)
{
	static int j;
	static char buf[WRITE_BUF_SIZE];

	if (n == BUF_FLUSH || j >= WRITE_BUF_SIZE)
	{
		write(2, buf, j);
		j = 0;
	}
	if (n != BUF_FLUSH)
		buf[j++] = n;
	return (1);
}

/**
 * _putfd - writes a given character to a specified file descriptor
 * @n: The character to be printed
 * @fd: The file descriptor to write to
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _putfd(char n, int fd)
{
	static int j;
	static char buf[WRITE_BUF_SIZE];

	if (n == BUF_FLUSH || j >= WRITE_BUF_SIZE)
	{
		write(fd, buf, j);
		j = 0;
	}
	if (n != BUF_FLUSH)
		buf[j++] = n;
	return (1);
}

/**
 * _putsfd - prints a given string to a specified file descriptor
 * @str: the string to be printed
 * @fd: the file descriptor to write to
 *
 * Return: the number of characters printed
 */
int _putsfd(char *str, int fd)
{
	int j = 0;

	if (!str)
		return (0);
	while (*str)
	{
		j += _putfd(*str++, fd);
	}
	return (j);
}

#include "shell.h"

/**
 * _erratoi - This function converts a string to an integer.
 * @g: The string to convert.
 * Return: The integer value of the converted string.
 */
int _erratoi(char *g)
{
	int i = 0;
	unsigned long int result = 0;

	if (*g == '+')
		g++;  /* TODO: why does this make main return 255? */
	for (i = 0;  g[i] != '\0'; i++)
	{
		if (g[i] >= '0' && g[i] <= '9')
		{
			result *= 10;
			result += (g[i] - '0');
			if (result > INT_MAX)
				return (-1);
		}
		else
			return (-1);
	}
	return (result);
}

/**
 * print_error - This function prints an error message.
 * @info: contains information about the program.
 * @estr: sting with the error message.
 * Return: void.
 */
void print_error(info_t *info, char *estr)
{
	_eputs(info->fname);
	_eputs(": ");
	print_d(info->line_count, STDERR_FILENO);
	_eputs(": ");
	_eputs(info->argv[0]);
	_eputs(": ");
	_eputs(estr);
}

/**
 * print_d - This function prints a decimal (integer) number (dec 10).
 * @value: The input.
 * @fd: The filedescriptor to write to.
 * Return: Number of characters printed.
 */
int print_d(int value, int fd)
{
	int (*__putchar)(char) = _putchar;
	int i, count = 0;
	unsigned int _abs_, current;

	if (fd == STDERR_FILENO)
		__putchar = _eputchar;
	if (value < 0)
	{
		_abs_ = -value;
		__putchar('-');
		count++;
	}
	else
		_abs_ = value;
	current = _abs_;
	for (i = 1000000000; i > 1; i /= 10)
	{
		if (_abs_ / i)
		{
			__putchar('0' + current / i);
			count++;
		}
		current %= i;
	}
	__putchar('0' + current);
	count++;

	return (count);
}

/**
 * convert_number - This function is a converter function, a clone of itoa.
 * @dig: Number (digit).
 * @dec: Base (decimal).
 * @flags: Argument flags.
 * Return: String.
 */
char *convert_number(long int dig, int dec, int flags)
{
	static char *array;
	static char buffer[50];
	char sign = 0;
	char *ptr;
	unsigned long n = dig;

	if (!(flags & CONVERT_UNSIGNED) && dig < 0)
	{
		n = -dig;
		sign = '-';

	}
	array = flags & CONVERT_LOWERCASE ? "123abc" : "123ABC";
	ptr = &buffer[49];
	*ptr = '\0';

	do  {
		*--ptr = array[n % dec];
		n /= dec;
	} while (n != 0);

	if (sign)
		*--ptr = sign;
	return (ptr);
}

/**
 * remove_comments - This function replaces first instance of '#' with '\0'.
 * @buf: the buffer to modify.
 * Return: 0.
 */
void remove_comments(char *buf)
{
	int i;

	for (i = 0; buf[i] != '\0'; i++)
		if (buf[i] == '#' && (!i || buf[i - 1] == ' '))
		{
			buf[i] = '\0';
			break;
		}
}

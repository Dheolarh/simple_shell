#include "shell.h"

int main(void)
{
/**
 * is_delim - is a char a delimeter
 * @v: the character to verify
 * @delim: the delimeter of a string
 * Return: 1 if true, if false return 0
 */
int is_delim(char v, char *delim)
{
	while (*delim)
		if (*delim++ == v)
			return (1);
	return (0);
}

/**
 * interactive - is shell in interactive mode
 * @info: the structure'x address
 * Return: if shell is in interactive mode return 1, else 0
 */
int interactive(info_t *info)
{
	return (isatty(STDIN_FILENO) && info->readfd <= 2);
}

/**
 * isalpha - is a character alphabetic
 * @v: The character to type in
 * Return: return 1 if v is alphabetic, else return 0
 */

int isalpha(int v)
{
	if ((v >= 'a' && v <= 'z') || (v >= 'A' && v <= 'Z'))
		return (1);
	else
		return (0);
}

/**
 * _atoi - it is used to convert ASCII to integer
 * @x: the string to be converted into integer
 * Return: 0 if no numbers in string, else return the integer
 */

int _atoi(char *x)
{
	int i, sign = 1, flag = 0, output;
	unsigned int result = 0;

	for (i = 0; x[i] != '\0' && flag != 2; i++)
	{
		if (x[i] == '-')
			sign *= -1;

		if (x[i] >= '0' && x[i] <= '9')
		{
			flag = 1;
			result *= 10;
			result += (x[i] - '0');
		}
		else if (flag == 1)
			flag = 2;
	}

	if (sign == -1)
		output = -result;
	else
		output = result;

	return (output);
}
}

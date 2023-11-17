#include "shell.h"

/**
 * is_chain - Checks if the current char in the buffer is a chain delimiter.
 * @info: contains the parameter struct
 * @buf: the char buffer
 * @x: address of the current position in buf
 * 
 * Returns: 1 if the character is a chain delimiter, 0 otherwise.
 */
int is_chain(info_t *info, char *buf, size_t *x)
{
	size_t j = *x;

	if (buf[j] == '|' && buf[j + 1] == '|')
	{
		buf[j] = 0;
		j++;
		info->cmd_buf_type = CMD_OR;
	}
	else if (buf[j] == '&' && buf[j + 1] == '&')
	{
		buf[j] = 0;
		j++;
		info->cmd_buf_type = CMD_AND;
	}
	else if (buf[j] == ';') /* found end of this command */
	{
		buf[j] = 0; /* replace semicolon with null */
		info->cmd_buf_type = CMD_CHAIN;
	}
	else
		return (0);
	*x = j;
	return (1);
}

/**
 * check_chain - Checks if we should continue chaining based on last status.
 * @info: contains the parameter struct
 * @buf: char buffer
 * @xp: address of the current position in buf
 * @i: starting position in buf
 * @len: length of buffer
 * 
 * Returns: void.
 */
void check_chain(info_t *info, char *buf, size_t *xp, size_t i, size_t len)
{
	size_t j = *xp;

	if (info->cmd_buf_type == CMD_AND)
	{
		if (info->status)
		{
			buf[i] = 0;
			j = len;
		}
	}
	if (info->cmd_buf_type == CMD_OR)
	{
		if (!info->status)
		{
			buf[i] = 0;
			j = len;
		}
	}

	*xp = j;
}

/**
 * replace_alias - Replaces an alias in the tokenized string.
 * @info: contains the parameter struct
 * 
 * Returns: 1 if the alias is replaced, else 0.
 */
int replace_alias(info_t *info)
{
	int i;
	list_t *node;
	char *x;

	for (i = 0; i < 10; i++)
	{
		node = node_starts_with(info->alias, info->argv[0], '=');
		if (!node)
			return (0);
		free(info->argv[0]);
		x = _strchr(node->str, '=');
		if (!x)
			return (0);
		x = _strdup(x + 1);
		if (!x)
			return (0);
		info->argv[0] = x;
	}
	return (1);
}

/**
 * replace_vars - Replaces variables in the tokenized string.
 * @info: contains the parameter struct
 * 
 * Returns: 1 if the variables are replaced, 0 otherwise.
 */
int replace_vars(info_t *info)
{
	int i = 0;
	list_t *node;

	for (i = 0; info->argv[i]; i++)
	{
		if (info->argv[i][0] != '$' || !info->argv[i][1])
			continue;

		if (!_strcmp(info->argv[i], "$?"))
		{
			replace_string(&(info->argv[i]),
					_strdup(convert_number(info->status, 10, 0)));
			continue;
		}
		if (!_strcmp(info->argv[i], "$$"))
		{
			replace_string(&(info->argv[i]),
					_strdup(convert_number(getpid(), 10, 0)));
			continue;
		}
		node = node_starts_with(info->env, &info->argv[i][1], '=');
		if (node)
		{
			replace_string(&(info->argv[i]),
					_strdup(_strchr(node->str, '=') + 1));
			continue;
		}
		replace_string(&info->argv[i], _strdup(""));

	}
	return (0);
}

/**
 * replace_string - replaces a string.
 * @os: address of the old string
 * @ns: new string
 * 
 * Returns: 1 if the string is replaced, 0 otherwise.
 */
int replace_string(char **os, char *ns)
{
	free(*os);
	*os = ns;
	return (1);
}


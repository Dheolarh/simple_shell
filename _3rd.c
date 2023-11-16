#include "shell.h"

/**
 * _myhistory - shows the history of commands
 * @info: contains the arguments given by user
 *  Return: 0
 */
int _myhistory(info_t *info)
{
	print_list(info->history);
	return (0);
}

/**
 * unset_alias - clears an alias string
 * @info: contains the arguments given by user
 * @str: string to clear
 * Return: 0 on success, 1 on error
 */
int unset_alias(info_t *info, char *str)
{
	char *t, k;
	int ret;

	t = _strchr(str, '=');
	if (!t)
		return (1);
	k = *t;
	*t = 0;
	ret = delete_node_at_index(&(info->alias),
		get_node_index(info->alias, node_starts_with(info->alias, str, -1)));
	*t = k;
	return (ret);
}

/**
 * set_alias - creates an alias string
 * @info: contains the arguments given by user (unused)
 * @str: the string alias to set
 * Return: 0 on success, 1 on error
 */
int set_alias(info_t *info, char *str)
{
	char *t;

	t = _strchr(str, '=');
	if (!t)
		return (1);
	if (!*++t)
		return (unset_alias(info, str));

	unset_alias(info, str);
	return (add_node_end(&(info->alias), str, 0) == NULL);
}

/**
 * print_alias - creates an alias string
 * @node: the node to print
 * Return: 0 on success, 1 on error
 */
int print_alias(list_t *node)
{
	char *t = NULL, *a = NULL;

	if (node)
	{
		t = _strchr(node->str, '=');
		for (a = node->str; a <= t; a++)
		_putchar(*a);
		_putchar('\'');
		_puts(t + 1);
		_puts("'\n");
		return (0);
	}
	return (1);
}

/**
 * _myalias - mimics the alias command
 * @info: contains the arguments given by user
 *  Return: 0
 */
int _myalias(info_t *info)
{
	int i = 0;
	char *t = NULL;
	list_t *node = NULL;

	if (info->argc == 1)
	{
		node = info->alias;
		while (node)
		{
			print_alias(node);
			node = node->next;
		}
		return (0);
	}
	for (i = 1; info->argv[i]; i++)
	{
		t = _strchr(info->argv[i], '=');
		if (t)
			set_alias(info, info->argv[i]);
		else
			print_alias(node_starts_with(info->alias, info->argv[i], '='));
	}

	return (0);
}

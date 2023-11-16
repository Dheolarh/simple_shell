#include "shell.h"

/**
 * _myhistory - shows the history list
 * @info: contains potential arguments. Used to maintain constant function
 *  Return: Always 0
 */
int _myhistory(info_t *info)
{
	print_list(info->history);
	return (0);
}

/**
 * unset_alias - sets alias to string
 * @info: contains potential arguments. Used to maintain constant function
 * @str: string alias
 *
 * Return: return 0 on success, 1 on error
 */
int unset_alias(info_t *info, char *str)
{
	char *v, n;
	int ret;

	v = _strchr(str, '=');
	if (!v)
		return (1);
	n = *v;
	*v = 0;
	ret = delete_node_at_index(&(info->alias),
		get_node_index(info->alias, node_starts_with(info->alias, str, -1)));
	*v = n;
	return (ret);
}

/**
 * set_alias - sets alias to string
 * @info:  contains potential arguments. Used to maintain constant function
 * @str: string alias
 *
 * Return: Always 0 on success, 1 on error
 */
int set_alias(info_t *info, char *str)
{
	char *v;

	v = _strchr(str, '=');
	if (!v)
		return (1);
	if (!*++v)
		return (unset_alias(info, str));

	unset_alias(info, str);
	return (add_node_end(&(info->alias), str, 0) == NULL);
}

/**
 * print_alias - prints alias
 * @node: alias node
 * Return: 0 on success, 1 on error
 */
int print_alias(list_t *node)
{
	char *v = NULL, *a = NULL;

	if (node)
	{
		v = _strchr(node->str, '=');
		for (a = node->str; a <= v; a++)
		_putchar(*a);
		_putchar('\'');
		_puts(v + 1);
		_puts("'\n");
		return (0);
	}
	return (1);
}

/**
 * _myalias - copies the string pointed to by src, including the terminating
 * @info: contains potential arguments. Used to maintain constant function
 *  Return: 0
 */
int _myalias(info_t *info)
{
	int i = 0;
	char *v = NULL;
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
		v = _strchr(info->argv[i], '=');
		if (v)
			set_alias(info, info->argv[i]);
		else
			print_alias(node_starts_with(info->alias, info->argv[i], '='));
	}

	return (0);
}

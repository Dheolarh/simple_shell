#include "shell.h"

/**
 * add_node - adds a new node to the start of the linked list
 * @hp: address of pointer to head node
 * @strt: string field of the new node
 * @num: node index used by history
 *
 * Return: size of the linked list
 */
list_t *add_node(list_t **hp, const char *strt, int num)
{
	list_t *new_head;

	if (!hp)
		return (NULL);
	new_head = malloc(sizeof(list_t));
	if (!new_head)
		return (NULL);
	_memset((void *)new_head, 0, sizeof(list_t));
	new_head->num = num;
	if (strt)
	{
		new_head->strt = _strdup(strt);
		if (!new_head->strt)
		{
			free(new_head);
			return (NULL);
		}
	}
	new_head->next = *hp;
	*hp = new_head;
	return (new_head);
}

/**
 * add_node_end - adds a new node to the end of the linked list
 * @hp: address of pointer to hp node
 * @strt: string field of the new node
 * @num: node index used by history
 *
 * Return: size of the linked list
 */
list_t *add_node_end(list_t **hp, const char *strt, int num)
{
	list_t *new_node, *node;

	if (!hp)
		return (NULL);

	node = *hp;
	new_node = malloc(sizeof(list_t));
	if (!new_node)
		return (NULL);
	_memset((void *)new_node, 0, sizeof(list_t));
	new_node->num = num;
	if (strt)
	{
		new_node->strt = _strdup(strt);
		if (!new_node->strt)
		{
			free(new_node);
			return (NULL);
		}
	}
	if (node)
	{
		while (node->next)
			node = node->next;
		node->next = new_node;
	}
	else
		*hp = new_node;
	return (new_node);
}

/**
 * print_list_str - prints only the string field of a linked list
 * @h: pointer to first node
 *
 * Return: size of the linked list
 */
size_t print_list_str(const list_t *h)
{
	size_t i = 0;

	while (h)
	{
		_puts(h->strt ? h->strt : "(nil)");
		_puts("\n");
		h = h->next;
		i++;
	}
	return (i);
}

/**
 * delete_node_at_index - deletes a node at a given index
 * @hp: address of pointer to first node
 * @index: index of node to delete
 *
 * Return: 1 on success, 0 on failure
 */
int delete_node_at_index(list_t **hp, unsigned int index)
{
	list_t *node, *prev_node;
	unsigned int i = 0;

	if (!hp || !*hp)
		return (0);

	if (!index)
	{
		node = *hp;
		*hp = (*hp)->next;
		free(node->strt);
		free(node);
		return (1);
	}
	node = *hp;
	while (node)
	{
		if (i == index)
		{
			prev_node->next = node->next;
			free(node->strt);
			free(node);
			return (1);
		}
		i++;
		prev_node = node;
		node = node->next;
	}
	return (0);
}

/**
 * free_list - frees all nodes of a linked list
 * @head_ptr: address of pointer to hp node
 *
 * Return: void
 */
void free_list(list_t **head_ptr)
{
	list_t *node, *next_node, *hp;

	if (!head_ptr || !*head_ptr)
		return;
	hp = *head_ptr;
	node = hp;
	while (node)
	{
		next_node = node->next;
		free(node->strt);
		free(node);
		node = next_node;
	}
	*head_ptr = NULL;
}

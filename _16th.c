#include "shell.h"

/**
 * is_cmd - checks if a file is executable or not
 * @info: contains the info struct with PATH
 * @path: the path to the file
 * Return: 1 if true, else 0
 */
int is_cmd(info_t *info, char *path)
{
	struct stat st;

	(void)info;
	if (!path || stat(path, &st))
		return (0);

	if (st.st_mode & S_IFREG)
	{
		return (1);
	}
	return (0);
}

/**
 * dup_chars - creates multiple same characters
 * @ptst: the PATH string
 * @begin: the start index
 * @end: the stop index
 * Return: the pointer to new buffer
 */
char *dup_chars(char *ptst, int begin, int end)
{
	static char buf[1024];
	int i = 0, v = 0;

	for (v = 0, i = begin; i < end; i++)
		if (ptst[i] != ':')
			buf[v++] = ptst[i];
	buf[v] = 0;
	return (buf);
}

/**
 * find_path - finds the full path of a command
 * @info: contains the info struct with PATH
 * @ptst: the PATH string
 * @cmd: the cmd to search for
 * Return: full path of cmd if found else 0
 */
char *find_path(info_t *info, char *ptst, char *cmd)
{
	int i = 0, curr_pos = 0;
	char *path;

	if (!ptst)
		return (NULL);
	if ((_strlen(cmd) > 2) && starts_with(cmd, "./"))
	{
		if (is_cmd(info, cmd))
			return (cmd);
	}
	while (1)
	{
		if (!ptst[i] || ptst[i] == ':')
		{
			path = dup_chars(ptst, curr_pos, i);
			if (!*path)
				_strcat(path, cmd);
			else
			{
				_strcat(path, "/");
				_strcat(path, cmd);
			}
			if (is_cmd(info, path))
				return (path);
			if (!ptst[i])
				break;
			curr_pos = i;
		}
		i++;
	}
	return (NULL);
}

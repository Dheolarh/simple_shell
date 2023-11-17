#include "shell.h"

/**
 * _memset - occupies a memory area with a constant byte
 * @pm: pointer to the memory area
 * @byte: byte to fill *pm with
 * @mt: amount of bytes to be filled
 * Return: (pm) a pointer to the memory area pm
 */
char *_memset(char *pm, char byte, unsigned int mt)
{
	unsigned int i;

	for (i = 0; i < mt; i++)
		pm[i] = byte;
	return (pm);
}

/**
 * ffree - releases a string of strings
 * @sos: string of strings
 */
void ffree(char **sos)
{
	char **d = sos;

	if (!sos)
		return;
	while (*sos)
		free(*sos++);
	free(d);
}

/**
 * _realloc - changes the size of a memory block
 * @ppmb: pointer to previous malloc'ated block
 * @os: byte size of previous block
 * @ns: byte size of new block
 * Return: pointer to da ol'block nameen.
 */
void *_realloc(void *ppmb, unsigned int os, unsigned int ns)
{
	char *p;

	if (!ppmb)
		return (malloc(ns));
	if (!ns)
		return (free(ppmb), NULL);
	if (ns == os)
		return (ppmb);

	p = malloc(ns);
	if (!p)
		return (NULL);

	os = os < ns ? os : ns;
	while (os--)
		p[os] = ((char *)ppmb)[os];
	free(ppmb);
	return (p);
}


#include "shell.h"
/**
 * contar_separador - Function that search for separators and counts.
 * @lectura:          A string.
 * @sep:              A separator.
 * Return:            Number of separators.
 */

int contar_separador(char *lectura, char sep)
{
	int n = 0, i = 0;

	while (lectura[i])
	{
		if (lectura[i] == sep)
			n++;
		i++;
	}
	n++;

	return (n);
}

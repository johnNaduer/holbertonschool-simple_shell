#include "shell.h"

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

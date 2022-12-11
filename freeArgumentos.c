#include "shell.h"
/**
 * free_argumentos - Function that frees entry arguments.
 * @argumentos:     Arguments passed to the function.
 */

void free_argumentos(char **argumentos)
{
	size_t i = 0;

	if (argumentos == NULL)
	{
		return;
	}

	while (argumentos[i])
	{
		free(argumentos[i]);
		i++;
	}

	if (argumentos[i] == NULL)
	{
		free(argumentos[i]);
	}

	free(argumentos);
}

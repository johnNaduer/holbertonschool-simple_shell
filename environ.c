#include "shell.h"
/**
 * imprimir_env - Functions that prints the environmental variables.
 */

void imprimir_env(void)
{
	int i;

	for (i = 0; environ[i] != NULL; i++)
	{
		printf("%s\n", environ[i]);
	}
}

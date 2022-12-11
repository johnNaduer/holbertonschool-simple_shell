#include "shell.h"
/**
 * localizar_path - Function that localizes the path.
 * Return:          A path.
 */

char *localizar_path()
{
	char *buscar_path = NULL, path_0[4];
	size_t i = 0;

	for (i = 0; environ[i] != NULL; i++)
	{
		strncpy(path_0, environ[i], 4);
		if (strcmp(path_0, "PATH") == 0)
		{
			free(buscar_path);
			buscar_path = strdup(environ[i]);
			break;
		}

	}
	return (buscar_path);
}

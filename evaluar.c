#include "shell.h"
/**
 * evaluar - Function that evalues the first argument.
 * @primer_argumento: Pointer to a string.
 * Return:            The first argument in to an allocated memory space.
 */

char *evaluar(char *primer_argumento)
{
	char *path_1 = NULL;
	char separador_1[] = ":";
	char *construir_path = NULL;
	char **listas_de_path = NULL;
	size_t i = 0, len_line = 0;

	/* declare a variable to store information about a file */
	struct stat st;

	/* get the value of the PATH environment variable */
	path_1 = localizar_path();

	/* tokenize the PATH variable */
	listas_de_path = toukenizar_lectura(path_1, separador_1);

	/* free the memory used to store the PATH variable */
	free(path_1);

	while (listas_de_path[i])
	{
		len_line = (strlen(primer_argumento));
		construir_path = malloc((strlen(listas_de_path[i]) + len_line +
					 2) * sizeof(char));
		/* copy the current directory from the PATH variable to construir_path */
		strcpy(construir_path, listas_de_path[i]);
		strcat(construir_path, "/");
		strcat(construir_path, primer_argumento);

		/* check if the file exists */
		if (stat(construir_path, &st) == 0)
		{
			/* if the file exists, break out of the loop */
			break;
		}
		free(construir_path);
		construir_path = strdup(primer_argumento);
		i++;
	}
	return (construir_path);

}

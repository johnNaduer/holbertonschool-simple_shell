#include "shell.h"
/**
 * toukenizar_lectura - Function that tokenizes a string.
 * @lectura:            A string.
 * @separador:          An array containing chars.
 * Return:              Returns a string but tokenized.
 */
char **toukenizar_lectura(char *lectura, char *separador)
{
	int i = 0, n = 0;
	/* declare a variable to store the tokenized input */
	char **argumentos_1 = NULL;
	char *token = NULL;
	/* count the number of tokens in the input */
	n = contar_separador(lectura, ' ');
	/* allocate memory to store the tokens */
	argumentos_1 = malloc((n + 1) * sizeof(char *));

	/*if (argumentos_1 == NULL) return (NULL); */
	/* get the first token from the input string */
	token = strtok(lectura, separador);

	for (i = 0; token != NULL; i++)
	{
		/* store the current token in the argumentos_1 array */
		argumentos_1[i] = strdup(token);
		/* if (argumentos_1[i] == NULL) return (NULL);*/
		/* get the next token */
		token = strtok(NULL, separador);

	}
	argumentos_1[i] = NULL;
	/* return the tokenized input */
	return (argumentos_1);
}

#include "shell.h"

/**
 * main - Main function that calls functions in order to run a simple shell.
 * Return: 0 if success.
 * @ac: attribute not used
 * @av: input first argument
 */

int main(int ac __attribute__((unused)), char **av)
{
	/*declare a variable to store user input */
	char *lectura = NULL;
	/* define a string of delimiters to use for tokenizing user input */
	char *separador = {" \t\n"};
	/* declare a variable to store the evaluated argument */
	char *evaluar_argumento = NULL;
	/* declare a variable to store the tokenized input */
	char **argumentos = NULL;
	/* set up a signal handler for when the user presses Ctrl+C */
	signal(SIGINT, sig_handler);

	while (1)
	{
		lectura = cargar_texto();

		if (strcmp(lectura, "env\n") == 0)
		{
			/*print the environment variables */
			imprimir_env();
			free(lectura);
			continue;
		}

		/* tokenize the user input */
		argumentos = toukenizar_lectura(lectura, separador);

		/* evaluate the first argument (i.e. the command) */
		evaluar_argumento = evaluar(argumentos[0]);
		argumentos[0] = NULL;
		argumentos[0] = evaluar_argumento;
		evaluar_argumento = NULL;

		/* create a child process and execute the command */
		proceso_hijo(lectura, argumentos, av);
	}

	return (0);
}

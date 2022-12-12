#include "shell.h"
/**
 * proceso_hijo - Function that duplicates a process.
 * @argumentos: Pointer to a pointer to a char.
 * @lectura: input char
 * @av: input char
 * Return:                    Void.
 */
int proceso_hijo(char *lectura, char **argumentos, char **av)
{
	/* declare a variable to store the child process ID */
	pid_t p_pid;
	/* declare a variable to store the status of the child process */
	int status;
	/* create a child process */
	p_pid = fork();

	if (p_pid == 0)
	{
		/* try to execute the command */
		if (execve(argumentos[0], argumentos, NULL) == -1)
		{
			/* if the command is not found, print an error message */
			printf("bash: %s: command not found\n", av[0]);

			 /* exit the child process */
			exit(EXIT_FAILURE);
		}
	}
	/* if fork() failed */
	if (p_pid < 0)
	{
		perror("process error");
		free(argumentos);
		free(lectura);
	}

	wait(&status);

	free_argumentos(argumentos);
	free(lectura);
	return (0);

}

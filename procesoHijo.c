#include "shell.h"
/**
 * proceso_hijo - Function that duplicates a process.
 * @argumentos: Pointer to a pointer to a char.
 * @lectura: input char
 * @av: input char
 * Return:                    Void.
 */
void proceso_hijo(char *lectura, char **argumentos, char **av)
{
	/* declare a variable to store the child process ID */
	pid_t p_pid;
	/* declare a variable to store the status of the child process */
	int status = 0;
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
	else if (p_pid < 0)
	{
		perror("process error");
		free(argumentos);
		free(lectura);
	}
	else
	{
		/* wait for the child process to finish */
		waitpid(-1, &status, 0);
		/* if the child process exited normally */
		if (WIFEXITED(status))
			/* get the exit status of the child process */
			WEXITSTATUS(status);
	}
	free_argumentos(argumentos);
	free(lectura);
}

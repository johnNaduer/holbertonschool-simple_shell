#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/**
 *main-prototype
 *Return: 0
 */
int main(void)
{
	char *buffer = malloc(1024);
	char *token;
	size_t len = 1024;
	size_t lee;
	char separador[]=" ,\t\n";
	while (1)
	{
		printf("$ ");
		lee = getline(&buffer, &len, stdin);
		printf("%s",buffer);
		if (lee == EOF)
		{
			free(buffer);
			exit(EXIT_SUCCESS);
		}

		token = strtok(buffer,separador);
		while(token!=NULL)
		{
		printf("%s\n",token);
		token = strtok(NULL,separador);
		}

	}
	return (0);
}

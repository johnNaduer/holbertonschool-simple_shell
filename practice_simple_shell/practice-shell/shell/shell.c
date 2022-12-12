#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include <sys/types.h>
/**
 *main-prototype
 *Return: 0
 */
int main(void)
{
        pid_t child_pid;
	char *buffer = malloc(1024);
        char *token;
        size_t len = 1024;
        size_t lee;
        char separador[]=" ,\t\n";
        char **palabra;
	char *tem;
	int i=0;
	int status;
	

	while (1)
        {
	
		palabra = calloc(10, sizeof(char *));
		
		child_pid = fork();
		if (child_pid == -1)
    		{
        	perror("Error:");
        	return (1);
    		}

		if (child_pid == 0)
		{

		printf("$ ");
               	lee = getline(&buffer, &len, stdin);
                printf("%s",buffer);
                if (lee == EOF)
                {
                        free(buffer);
                        exit(EXIT_FAILURE);
                }

                token = strtok(buffer,separador);
                
		while(token!=NULL)
                {
                
		printf("%s\n",token);
                tem=strdup(token);
		palabra[i]=tem;
		token = strtok(NULL,separador);
                i++;
		}
			
		if (execve(palabra[0],palabra,NULL) == -1)
		{
			free(palabra);
			exit(EXIT_FAILURE);
			//perror("Error:");
		}
		}

		else
		{
			wait(NULL);
		}
		free(palabra);	
        }
        return (0);
}

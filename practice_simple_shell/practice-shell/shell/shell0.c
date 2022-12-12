#include <unistd.h>
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
char **palabra;
char *tem;
int i=0;
int estatus;
while (1)
{
	    palabra = calloc(10, sizeof(char *));
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

            printf("%s\\n",token);
            tem=strdup(token);
            palabra[i]=tem;
            token = strtok(NULL,separador);
            i++;
            }

            if (execve(palabra[0],palabra,NULL) == -1)
            {
                    perror("Error:");
            }

    }
    return (0);
}

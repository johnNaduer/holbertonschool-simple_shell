#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <unistd.h>

char *cargar_texto(char *buf,size_t len);
char **toukenizar_lectura(char *lectura, char separador[]);
char **evaluar(char **primer_argumento);
void proceso_hijo(char **evaluar_primer_argumento);

typedef struct dato
{
char *comandos;
} dato1;

char *cargar_texto(char *buf,size_t len)
{
	int len_letra;
        getline(&buf,&len,stdin);
	len_letra=strlen(buf);
	buf[len_letra-1]='\0';
	
	return (buf);
	free(buf);

}

char **toukenizar_lectura(char *lectura, char separador[])
{

	
	char **guardar_argumentos;
	char *tem;
	char *token;
	int i=0;
	guardar_argumentos = calloc(10,sizeof(char *));
	token = strtok(lectura,separador);
	
	while(token!=NULL)
	{
	tem=strdup(token);
	guardar_argumentos[i]=tem;
	token = strtok(NULL,separador);
	i++;
	}
	
	return (guardar_argumentos);
}

void proceso_hijo(char **evaluar_primer_argumento)
{
	pid_t child_pid;
	
	child_pid = fork();

	if (child_pid == -1)
        {
                perror("Error:");
                //return (1);
        }

	if (child_pid == 0)
	{

	if (execve(evaluar_primer_argumento[0],evaluar_primer_argumento,NULL) == -1)
	{
	free(evaluar_primer_argumento);
	exit(EXIT_FAILURE);
                        //perror("Error:");
	}	
	}

	else
	{
		wait(NULL);
                
	}
}

char **evaluar(char **primer_argumento)
{
	dato1 command[]={"ls","cp","mv","cd","ps","rm","ip","id",NULL};
	char path[8]="/bin/";
	int i;
	for(i=0;command[i].comandos!=NULL;i++)
	{
	if(!strcmp(primer_argumento[0],command[i].comandos))
	{
    	strcat(path,command[i].comandos);
   	}
	}	
	strcpy(primer_argumento[0],path);
	
	return (primer_argumento);
	
}

int main(void)
{
        char *lectura;
        char *buffer = NULL;
        size_t len = 0;
	char **toukenizado;
	char separador[]=" ,\t\n";
	//
	char **evaluar_primer_argumento;
	//
while (1)
{

        printf("$ ");

        lectura = cargar_texto(buffer,len);
		
	toukenizado = toukenizar_lectura(lectura,separador);

	evaluar_primer_argumento = evaluar(toukenizado);

	proceso_hijo(evaluar_primer_argumento);		
	
}

free(lectura);

return (0);
}

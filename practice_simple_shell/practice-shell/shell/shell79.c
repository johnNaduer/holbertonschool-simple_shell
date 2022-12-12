#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/stat.h>

char *cargar_texto(char *buf,size_t len);
char **toukenizar_lectura(char *lectura, char separador[]);
char *evaluar(char *primer_argumento);
void proceso_hijo(char **evaluar_primer_argumento);
char *localizar_path();

extern char **environ;

char *localizar_path();

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

char *evaluar(char *primer_argumento)
{
	struct stat st;
	
	char **listas_de_path = NULL;
	char *path_1=NULL;
	char separador_1[] = ":";
	char *construir_path = NULL;
	int len_primer_argumento;
	path_1 = localizar_path();
	listas_de_path = toukenizar_lectura(path_1,separador_1);
	
	int i=0;
	
	for(i=0;listas_de_path[i]!=NULL;i++)
	{
	len_primer_argumento = strlen(primer_argumento);
	construir_path = malloc((strlen(listas_de_path[i]) + len_primer_argumento + 2)*sizeof(char));
	strcpy(construir_path, listas_de_path[i]);
	strcat(construir_path,"/");
	strcat(construir_path, primer_argumento);
	if(stat(construir_path, &st) == 0)
	{
		break;
	}
	construir_path = strdup(primer_argumento);
	}
	return (construir_path);	

}

char *localizar_path()
{
	char *buscar_path;
	char path_0[4];
	int i =0;
	for (i=0;environ[i]!=NULL;i++)
	{
	strncpy(path_0,environ[i],4);
	if(!strcmp(path_0,"PATH"))
	{
	buscar_path = strdup(environ[i]);
	break;
	}
	}
	return (buscar_path);
}


int main(void)
{
        char *lectura;
        char *buffer = NULL;
        size_t len = 0;
	char **toukenizado;
	char separador[]=" ,\t\n";
	//
	char *evaluar_primer_argumento;
	//
while (1)
{

        printf("$ ");

        lectura = cargar_texto(buffer,len);
		
	toukenizado = toukenizar_lectura(lectura,separador);	

	if(lectura[0]!='/')
	{
	evaluar_primer_argumento = evaluar(toukenizado[0]);
	free(toukenizado[0]);
	toukenizado[0] = NULL;
	toukenizado[0] = evaluar_primer_argumento;
	evaluar_primer_argumento = NULL;
	}
	proceso_hijo(toukenizado);		
	
}

free(lectura);

return (0);
}

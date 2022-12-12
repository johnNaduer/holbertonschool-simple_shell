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
void proceso_hijo(char **evaluar_primer_argumento,char **av);
char *localizar_path();
extern char **environ;
char *localizar_path();
int contar_separador(char *lectura, char sep);
void free_argumentos(char **argu);
char *cargar_texto(char *buf,size_t len)
{
	int len_letra;
        size_t get_line, r_isatty = 0;
	
	r_isatty = isatty(STDIN_FILENO);
	if (r_isatty == 1)
		write(1, "#cisfun$ ", 9);
	
	get_line = getline(&buf,&len,stdin);

	if(get_line == EOF)
	{
	free(buf);
	exit(EXIT_FAILURE);
	}
	
	len_letra=strlen(buf);
	buf[len_letra-1]='\0';


	if(!strcmp(buf,"exit"))
	{
	
		free(buf);
		exit(EXIT_FAILURE);

	}
	return (buf);
	free(buf);

}

char **toukenizar_lectura(char *lectura, char separador[])
{	
	char **guardar_argumentos;
	char *tem;
	char *token;
	int i=0;
	int n;
	n = contar_separador(lectura,' ');
	guardar_argumentos = malloc((n+1)*sizeof(char *));
	token = strtok(lectura,separador);
	
	while(token!=NULL)
	{
	tem=strdup(token);
	guardar_argumentos[i]=tem;
	token = strtok(NULL,separador);
	i++;
	}
	guardar_argumentos[i] = NULL;
	return (guardar_argumentos);
}

int contar_separador(char *lectura, char sep)
{

int n=0, i=0;
while(lectura[i])
{
	if(lectura[i] == sep)
	n++;
i++;
}
n++;
return (n);
}


void proceso_hijo(char **evaluar_primer_argumento,char **av)
{
	pid_t child_pid;
	int status;
	child_pid = fork();


	if (child_pid == 0)
	{

	if (execve(evaluar_primer_argumento[0],evaluar_primer_argumento,NULL) == -1)
	{
	printf("bash: %s: command not found\n",evaluar_primer_argumento[0]);
	free(evaluar_primer_argumento);
	exit(EXIT_FAILURE);
                        //perror("Error:");
	}	
	}
	
	else if (child_pid == -1)
        {
                
		free_argumentos(evaluar_primer_argumento);
		perror("Error:");
                //return (1);
        }

	else
	{
		waitpid(-1, &status, 0);
    		if (WIFEXITED(status))
		WEXITSTATUS(status);
		free_argumentos(evaluar_primer_argumento);
	}


}

void free_argumentos(char **argu)
{
	int i;
	for(i=0;argu[i]!=NULL;i++)
	{
		free(argu[i]);
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
	int i;
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


void imprimir_env(void)
{
	int i;
	
	for (i = 0; environ[i] != NULL; i++)
	{
	printf("%s\n", environ[i]);
    	}
}


void sig_handler(int signum)
{

	if(signum == SIGINT)
	{
		write(1, "\n#cisfun$ ",10);
	}
}


int main(int ac __attribute__((unused)), char **av)
{
        char *lectura;
        char *buffer = NULL;
        size_t len = 0;
	char **toukenizado;
	char separador[]=" \t\n";
	//
	char *evaluar_primer_argumento;
	//
while (1)
{
	
	signal(SIGINT, sig_handler);
        lectura = cargar_texto(buffer,len);	
	if (!strcmp(lectura,"env"))
	{
		imprimir_env();
		free(lectura);
		continue;
	}
	toukenizado = toukenizar_lectura(lectura,separador);
	evaluar_primer_argumento = evaluar(toukenizado[0]);
	toukenizado[0] = evaluar_primer_argumento;
	evaluar_primer_argumento = NULL;
	proceso_hijo(toukenizado,av);
	
}

free(lectura);

return (0);

}

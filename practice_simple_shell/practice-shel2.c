#include <stdio.h>
#include <stdlib.h>
#include <string.h>
extern char **environ;

int main()
{
    	char *path=NULL;
	char *token;
	char separador[]=":";
	path = getenv("PATH");
	token = strtok(path,separador);
	printf("%s\n",token);
	
    return 0;
}

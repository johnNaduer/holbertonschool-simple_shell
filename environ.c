#include "shell.h"



void imprimir_env(void)
{
	int i;

	for (i=0; environ[i]!=NULL; i++)
	{
		printf("%s\n", environ[i]);
	}
}

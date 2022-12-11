#include "shell.h"
/**
 * 
*/

char *cargar_texto (void)
{
	char *lectura_0 = NULL;
	size_t len = 0, r_isatty = 0;
	ssize_t get_line = 0;
	/* call isatty() to check if standard input is a terminal */
	 r_isatty = isatty(STDIN_FILENO);
	 /* if standard input is a terminal */
	if (r_isatty == 1)
	{
		 write(1, "#cisfun$ ", 9);
	}
	/* read a line of input from the user */
	get_line = getline(&lectura_0, &len, stdin);
	
	/* check if the user entered the "exit" command */
	if (strcmp(lectura_0, "exit\n") == 0)
	{
		free(lectura_0);
		exit(0);			
	}
	
	/* check if getline() returned EOF */
	if (get_line == EOF)
	{
		free(lectura_0);
		exit(0);
	}
	/* return the user input*/
	return (lectura_0);
}

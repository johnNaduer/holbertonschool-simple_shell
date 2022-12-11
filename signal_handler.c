#include "shell.h"



void sig_handler(int s_num)
{
	if ( s_num == SIGINT)
	{
		write(1, "\n#cisfun$ ", 10);
	}
}

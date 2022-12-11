#include "shell.h"
/**
* sig_handler - function is a signal handler
* @s_num: input int s_num
*/
void sig_handler(int s_num)
{
	if (s_num == SIGINT)
	{
		write(1, "\n#cisfun$ ", 10);
	}
}

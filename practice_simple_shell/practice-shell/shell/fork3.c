#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
int main(void)
{

        pid_t pid;

	printf("after fork i became one %d \n",getpid());
        pid = fork();
        if(pid == -1)
        {
        perror("unuseful\n");
        return (1);
        }
        if(pid == 0)
	{
	printf("after fork i became two %d \n",getpid());
	}
	else
	{
	wait(&estatus);
	}
        return (0);
}

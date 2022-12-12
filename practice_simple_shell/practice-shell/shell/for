#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
int main(void)
{

	pid_t pid;
	fork();
	printf("before fork i was one %d \n",getpid());
	if(pid == -1)
	{
	perror("unuseful\n");
	return (1);
	}
	printf("after fork i became two %d \n",getpid());

	return (0);
}

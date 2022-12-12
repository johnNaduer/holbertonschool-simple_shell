#include <signal.h>
#include <unistd.h>
#include <stdio.h>

void MySignalhandler(int sig)
{
	printf("Signal number is %d \n", sig);
}

int main(void)
{
	signal(SIGIO, &MySignalhandler);
	while(1)
	{
	printf("zzzZZZzzz \n");
	sleep(2);
	
	}


return (0);

}

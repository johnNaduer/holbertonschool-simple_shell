#include <unistd.h>
#include <stdio.h>

int var = 22;

int main(void)
{
pid_t pidc;
printf("**proc. PID = %d comienza ** \n", getpid());
pidc = fork();
pidc = fork();
printf("proc. PID = %d , pidc = %d ejecutandose \n",getpid(),pidc);
if(pidc > 0)
{
var=44;
}
else if(pidc ==0)
{
var = 33;
}
else
{
}

printf("proc. PID = %d , var =%d ejecutandose \n",getpid(),var);
return (0);
}

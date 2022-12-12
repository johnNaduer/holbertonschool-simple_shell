#include <stdio.h>
#include <sys/types.h>

int main(void)
{
	pid_t var;

	var = -200;

	printf("size of int: %ld\n",sizeof(int));
	printf("size if pid_t: %ld\n",sizeof(pid_t));
	printf("value of var: %d\n",var);

	return 0;
}

#include <unistd.h>
#include <stdio.h>

int main(int argc, char* argv[])
{
	
	char *const argv2[]={"prog2","abcdef","ghij",NULL};

	printf("%s : %i \n", argv[0], getpid());
	execv("./prog2", argv2);

	printf("Error \n");

	return (-1);
}

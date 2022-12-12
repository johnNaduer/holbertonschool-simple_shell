#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
int main()
{
	char *args[]={"./EXEC",NULL};
	execve(args[0],args);
	printf("Ending ------------");
	return (0);
}


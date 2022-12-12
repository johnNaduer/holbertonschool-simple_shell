#include <stdio.h>
#include <string.h>
int main()
{


char path[8]="/bin/";
char *comando="ls";

strcat(path,comando);
printf("%s\n",path);

return (0);

}

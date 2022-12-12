#include <stdio.h>
#include <string.h>
int main()
{

char *path="/bin/";
char *comando="ls";
char *fusion;
fusion=strcat(path,comando);
printf("%s\n",fusion);

return (0);

}

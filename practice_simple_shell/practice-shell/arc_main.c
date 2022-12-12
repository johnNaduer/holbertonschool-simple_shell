#include <stdio.h>

int main(int ac, char **av)
{
int i=1;
printf("%c ",'$');
while(i < ac)
{
printf("%s ",av[i]);
i++;
}
printf("\n");
return (0);
}

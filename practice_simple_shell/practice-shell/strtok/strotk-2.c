#include <string.h>
#include <stdio.h>
#include <stdlib.h>
int main( void )
{
   
	char *buffer;
	char *token;
	char seps[] = " ,\t\n";
	buffer = malloc(sizeof(1024));
	size_t len = 1024;
	size_t string;
if (buffer == NULL)
{
	printf("no hay reserva de memoria\n");
	exit(1);
}
	getline(&buffer,&len,stdin);
	printf( "Tokens:\n" );

   	// Establish string and get the first token:
   	token = strtok( buffer, seps ); // C4996
   	// Note: strtok is deprecated; consider using strtok_s instead
   	while( token != NULL )
   	{
      // While there are tokens in "string"
      	printf( "%s\n", token );

      // Get next token:
      	token = strtok( NULL, seps ); // C4996
   	}
}

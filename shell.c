/***
 * shell.c implementation for shell application functions
 * Created By : Amr Elzawawy
 * Created On : 10-10-18
 ***/
#include <stdio.h>
#include "shell.h"
#include "parser.h"
void executeCommand(char ** args)
{
    
}
void openShellSession(void) 
{
    char *args[MAX_TOKEN_LENGTH];
    printf(">>");
    char * command = (char *) malloc(MAX_COMMAND_LENGTH*sizeof(char));
    fgets(command,MAX_COMMAND_LENGTH,stdin); 
    if(command == NULL )
        openShellSession();
    else
        parseLine(command,args);
    



}
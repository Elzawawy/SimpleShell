/***
 * Shell Module
 * shell.c implementation for shell application functions
 * Created By : Amr Elzawawy
 * Created On : 10-10-18
 ***/
#include <stdio.h>
#include <stdlib.h>
#include "shell.h"
#include "parser.h"
#include "process.h"
void executeCommand(char ** args)
{
    int Local_backgroundProcessFlag = 0;
    while( *args != '\0')
        if(*args == '&')
            Local_backgroundProcessFlag=1;
    if(Local_backgroundProcessFlag)
        newBackgroundProcess(args);
    else 
        newForegroundProcess(args);
        
}
void openShellSession(void) 
{
    char *args[MAX_TOKENS_NUM];
    printf(">>");
    char * command = (char *) malloc(MAX_COMMAND_LENGTH*sizeof(char));
    fgets(command,MAX_COMMAND_LENGTH,stdin); 
    if(command == NULL )
        openShellSession();
    else if(command == "exit")
        exit(0);
    else
        parseLine(command,args);
    //Execute the command according to the last argument specified ( Background Or Foreground ).
    executeCommand(args);
}
/***
 * main.c main application file
 * Created By : Amr Elzawawy
 * Created On : 10-10-18
 ***/


#include "shell.h"
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include "parser.h"
void main(void)
{
    char *args[64];
    char * command = (char *) malloc(50*sizeof(char));
    command = "ls -l";
    //printf("%d",1);
    //parseCommand(command,args);
    parseLine(command, args);
   int res = execvp(*args, args);
   printf("%d",res);
    

}

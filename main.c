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
    char *args[20];
    printf(">>");
    char * command = (char *) malloc(50*sizeof(char));
    fgets(command,50,stdin);     
    parseLine(command, args);
   int res = execvp(*args, args);
    

}

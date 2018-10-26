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
#include "string.h"
#include "process.h"
//MACRO like-function to read the input from user.
#define readInput()     printf(">>");\
                        fgets(command, MAX_COMMAND_LENGTH, stdin);\
                        removeLastChar(command)
//MACRO like-function to check type of child to be created and set flag accordingly.
#define checkChildType()    do {\
                            if(stringCompare(args[getSArrayLength(args)-1],"&") == 0)\
                            {\
                            args[getSArrayLength(args)-1] = '\0';\
                            Local_backgroundProcessFlag =1; \
                            }\
                            }while(0)
//MACRO like-function to free up allocated memory.
#define freeMemory()    while(*args != 0){\
                        free(*args);\
                        args++;\
                        }\
                        free(command)

void openShellSession(void)
{
    //Flag to indicate type of process to be executed.
    int Local_backgroundProcessFlag = 0;
    //Allocate Memory for the Shell process.
    char **args = (char **)malloc(MAX_ARGUMENTS_NUM * sizeof(char *));
    char *command = (char *)malloc(MAX_COMMAND_LENGTH * sizeof(char));
    //Read Input from user.
    readInput();
    //Decision Construct based on the Command value read.
    //Case 1 : Re-open session if "NULL".
    if (stringCompare(command, "\0") == 0)
        return ;
    //Case 2 : Exit if command "exit" read.
    else if (stringCompare(command, "exit") == 0)
        exit(0);
    //Case 3 : Parse Command to execute.
    else 
        parseLine(command, args);
    //Check Child type and control background flag accordingly.
    checkChildType();
    //Create a new child process with the arguments and type sent as parameters.
    newChildProcess(args,Local_backgroundProcessFlag);
    //Free up the memory created by the Shell.
    freeMemory();
}
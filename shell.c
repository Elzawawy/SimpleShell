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
#include "string.h"

void executeCommand(char **args)
{
    //Temproray running pointer
    char **temp_args = args;
    //Flag to indicate type of process to be executed.
    int Local_backgroundProcessFlag = 0;
    while (*temp_args != '\0')
    {
        if (stringCompare(*temp_args, "&") == 0)
        {
            Local_backgroundProcessFlag = 1;
            *temp_args = '\0';
        }

        temp_args++;
    }
    //Free-up temproary pointer allocated.
    free(temp_args);
    //Decision Construct to execute the process according to type.
    if (Local_backgroundProcessFlag)
        newBackgroundProcess(args);
    else
        newForegroundProcess(args);
}
void openShellSession(void)
{
    //Allocate Memory for the Shell process.
    char **args = (char **)malloc(MAX_ARGUMENTS_NUM * sizeof(char *));
    char *command = (char *)malloc(MAX_COMMAND_LENGTH * sizeof(char));
    //Read Input and remove new-line break character at the end.
    printf(">>");
    fgets(command, MAX_COMMAND_LENGTH, stdin);
    removeLastChar(command);
    //Decision Construct based on the Command value read.
    //Re-open session if NULL
    if (command == NULL)
        openShellSession();
    //Exit
    else if (stringCompare(command, "exit") == 0)
        exit(0);
    //Parse Command to execute.
    else
        parseLine(command, args);
    //Execute the command according to the last argument specified ( Background Or Foreground ).
    executeCommand(args);
    //Free up the memory created by the Shell.
    free(args);
    free(command);
}
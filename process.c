/***
 * Process Module
 * process.c implementation of process.h library functions.
 * Created By : Amr Elzawawy
 * Created On : 11-10-18
 ***/

#include <unistd.h>
#include <sys/wait.h>
#include <signal.h>
#include <stdio.h>
#include <time.h>
#include "string.h"
/* SIGCHILD signal handler */
void SIGCHILD_Handler(int signum)
{
    //Open File For Logging.
    FILE * file = fopen("SHELL_LOG.txt","a");
    //Get current timestamp from the system.
    time_t rawtime;
    struct tm * timeinfo;
    time (&rawtime);
    timeinfo = localtime (&rawtime);
    //Append Message to the file followed with the current timestamp.
    fputs("\nA Child was dead at ",file);
    fputs(asctime(timeinfo),file);
    //Close the File resource.
    fclose(file);
}

void newChildProcess(char** args, int Copy_BackgroundFlag)
{
    //Create a new child with process ID = pid.
    int pid = fork();
    int status;
    //pid is a -ve number, Error State
    if( pid < 0 )
    {
        printf("An Error has occured ! Try again later.\n");
    }
    //pid is zero, Child State
    else if( pid == 0 ) 
    {
        if(Copy_BackgroundFlag)
            setpgid(0,0);
        if(execvp(*args , args) == -1)
           printf("An Error has occured ! Try again later.\n");
    }
    //pid is +ve number, Parent State
    else 
    {
        //Assign SIGCHILD signal handler to the parent.
        signal(SIGCHLD,SIGCHILD_Handler);
        if(Copy_BackgroundFlag)
            tcsetpgrp(0,getpgrp());
        else 
            wait(&status);
    }
}
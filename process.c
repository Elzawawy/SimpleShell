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
#include <string.h>
void SIGCHILD_Handler(int signum)
{
    FILE * file = fopen("SHELL_LOG.txt","a");
    time_t rawtime;
    struct tm * timeinfo;
    time (&rawtime);
    timeinfo = localtime (&rawtime);
    char * logMessage = "\nA Child was dead at ";
    fputs(logMessage,file);
    fputs(asctime(timeinfo),file);
    fclose(file);
}
void newBackgroundProcess(char ** args)
{
    int pid = fork();
    if( pid < 0 )
        printf("An Error has occured ! Try again later.\n");
    else if( pid == 0 )
        execvp(*args , args);
    else 
        signal(SIGCHLD,SIGCHILD_Handler);
}

void newForegroundProcess(char ** args)
{
    int status;
    int pid = fork();
    if( pid < 0 )
        printf("An Error has occured ! Try again later.\n");
    else if( pid == 0 ){
        int res = execvp(*args , args);
    }
    else {
        wait(&status);
    }

    
}
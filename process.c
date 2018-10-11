/***
 * Process Module
 * process.c implementation of process.h library functions.
 * Created By : Amr Elzawawy
 * Created On : 11-10-18
 ***/

#include <unistd.h>
#include <sys/wait.h>
void newBackgroundProcess(char ** args)
{
    int pid = fork();
    

}

void newForegroundProcess(char ** args)
{
    int status;
    int pid = fork();
    if( pid < 0 )
        printf("An Error has occured ! Try again later.\n");
    else if( pid = 0 )
        execvp(*args , args);
    else 
        wait(&status);

    
}
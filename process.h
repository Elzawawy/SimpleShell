/***
 * Process Module
 * process.h Process different usage library for creating and using processes.
 * Created By : Amr Elzawawy
 * Created On : 11-10-18
 ***/

#ifndef POCESS_H_
#define POCESS_H_

/* Input : Arguments of the command, Type of the Child process to create.
            (Foreground --> 0 , Background ---> 1)
   Output : N/A
   Function : creates a new child process based on inputs. */
void newChildProcess(char** args, int Copy_BackgroundFlag);

#endif
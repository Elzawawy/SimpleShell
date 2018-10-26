/***
 * Shell Module
 * shell.h declration for shell application functions
 * Created By : Amr Elzawawy
 * Created On : 10-10-18
 ***/

#ifndef SHELL_H_
#define SHELL_H_
/* Configurable command length and argumnets number */
#define MAX_COMMAND_LENGTH 100
#define MAX_ARGUMENTS_NUM 64
//Opens a shell terminal.
void openShellSession(void);

#endif
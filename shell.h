/***
 * shell.h declration for shell application functions
 * Created By : Amr Elzawawy
 * Created On : 10-10-18
 ***/

/* Command Text Processing API --->  convert them into C strings */
void parseCommand(char * command, char ** args);
/* Command Execution API ---> execute the command and handling both foreground and background cases */
void executeCommand();

/***
 * parser.h library for parsing any string into tokens according to a token splitter.
 * Created By : Amr Elzawawy
 * Created On : 10-10-18
 ***/

#define MAX_TOKEN_LENGTH 20
#define TOKEN_SEPARATOR ' '

int parseLine(char * Line,char ** Tokens);

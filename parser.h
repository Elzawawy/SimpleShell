/***
 * Parser  Module 
 * parser.h library for parsing any string into tokens.
 * Created By : Amr Elzawawy
 * Created On : 10-10-18
 ***/

#define MAX_TOKEN_LENGTH 20
#define MAX_TOKENS_NUM 64
#define TOKEN_SEPARATOR ' '

int parseLine(char * Line,char ** Tokens);

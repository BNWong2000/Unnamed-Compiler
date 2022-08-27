#include "parser.h"


void parse(FileStream *scanner, int printAST){
    char curr = readChar(scanner);
    while(curr != EOF){
        printf("%c --- Character\n", curr);
        curr = readChar(scanner);
    }
    

    
}




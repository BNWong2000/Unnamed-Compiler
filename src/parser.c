#include "parser.h"

void parse( Parser *parser , int printAST){
    Token *currToken = lex(parser->scanner);
    while(currToken->theType != T_EOF){
        currToken = lex(parser->scanner);
    }
}


Parser *initParser(FileStream *stream){
    Parser *parser = (Parser *)malloc (sizeof(Parser));
    if(parser == NULL) {
        fprintf(stderr, "ERROR: Unable to allocate memory for parser\n");
        return NULL;
    }
    Scanner *scanner = (Scanner *) malloc (sizeof(Scanner));
    
    if(scanner == NULL) {
        fprintf(stderr, "ERROR: Unable to allocate memory for parser\n");
        free(parser);
        return NULL;
    }

    scanner->stream = stream;
    return parser;
}



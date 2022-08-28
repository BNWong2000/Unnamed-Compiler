#include "parser.h"

void parse( Parser *parser, int printAST){
    if(parser->scanner == NULL)     printf("scanner issue\n");

    Token *currToken = lex(parser->scanner);
    while(currToken->theType != T_EOF){

        currToken = lex(parser->scanner);
        printToken(currToken);
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
    // Inits currChars to be whitespace so the lex can work properly. 
    scanner->currChar = ' ';
    scanner->currLine = 0;
    scanner->currCol = 0;

    parser->scanner = scanner;
    return parser;
}



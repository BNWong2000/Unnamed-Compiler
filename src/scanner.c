#include "scanner.h"

/**
 * checks if character is a number
 */ 
static int isNum(char c){
    if (c >= '0' && c <= '9' ){
        return 1;
    }
    return 0;
}

/**
 * checks if character is a letter
 */ 
static int isAlpha(char c){
    if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') ){
        return 1;
    } 
    return 0;
}

/**
 * checks if character is a letter or number
 */ 
static int isAlphaNum(char c){
    if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c == '_') || (c >= '0' && c <= '9')){
        return 1;
    }
    return 0;
}


Token *lex(Scanner *scanner){
    while(isspace(scanner->currChar)){
        if(scanner->currChar == '\n') {
            scanner->currLine++;
            scanner->currCol = 0;
        }
        nextChar(scanner);
    }
    switch (scanner->currChar){
        case EOF:
            return makeToken(T_EOF, scanner->currLine, scanner->currCol, "");
        default:
            nextChar(scanner);
            return makeToken(T_BIT_AND, scanner->currLine, scanner->currCol, "");
    }
}

Token *makeToken( TokenType theType, int line, int col, char *lexeme){
    Token *result = (Token *) malloc(sizeof(Token));
    if ( result == NULL ){
        fprintf(stderr,"ERROR: out of memory\n");
        return NULL;
    }
    result->theType = theType;
    result->lineNum = line;
    result->colNum = col;
    return result;
}

void nextChar(Scanner *scanner){
    scanner->currChar = readChar(scanner->stream);
}
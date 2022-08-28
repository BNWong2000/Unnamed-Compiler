#ifndef SCANNER_H
#define SCANNER_H

#include "token.h"
#include "util/fileIO.h"

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>


struct Scanner {
    int currLine;
    int currCol;
    FileStream *stream; 

    // Stores the current Char (1 character lookahead.)
    int currChar;
};

typedef struct Scanner Scanner;

/**
 * A function to scan the next char in the scanner. 
 */ 
void nextChar(Scanner *scanner);

/**
 * A function to lex the file for tokens. 
 */ 
Token *lex( Scanner *scanner );

/**
 * A helper function to create a token. 
 */ 
Token *makeToken( TokenType theType, int line, int col, char *lexeme);

#endif

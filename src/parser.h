#ifndef PARSER_H
#define PARSER_H

#include <stdio.h>
#include <stdlib.h>

#include "scanner.h"
#include "token.h"
#include "util/fileIO.h"


struct Parser {
    // Scanner
    Scanner *scanner;
    
    // TODO: Add an AST here.
};

typedef struct Parser Parser;

/**
 * A function to construct a parser struct
 *
 */
Parser *initParser(FileStream *stream);

/**
 * A function to start parsing.
 */
void parse(Parser *parser, int printAST);


#endif

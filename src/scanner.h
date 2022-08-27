#ifndef SCANNER_H
#define SCANNER_H

#include "token.h"
#include <stdio.h>

Token lex(FILE *inputFile);

struct Scanner {
    int currLine;
    int currCol;
    
};

typedef struct Scanner Scanner;


#endif

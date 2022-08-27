#ifndef SCANNER_H
#define SCANNER_H

#include "token.h"
#include "util/fileIO.h"
#include <stdio.h>


struct Scanner {
    int currLine;
    int currCol;
    FileStream *stream; 
};

typedef struct Scanner Scanner;

Token *lex( Scanner *scanner );

#endif

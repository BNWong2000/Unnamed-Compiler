#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <string.h>
#include "util/fileIO.h"
#include "parser.h"

#include "dataStructures/hashTable.h"

int run(const char *fileName, int noOp, int showAst);

#endif

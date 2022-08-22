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


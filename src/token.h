#ifndef TOKEN_H
#define TOKEN_H


enum TokenType{
    T_LBRACK,
    T_RBRACK
};


typedef enum TokenType TokenType;

struct Token{
    TokenType theType;
};

typedef struct Token Token;


#endif

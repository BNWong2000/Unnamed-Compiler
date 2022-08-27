#ifndef TOKEN_H
#define TOKEN_H

#include <stdio.h>


enum TokenType{
    // brace = {}, paren = (), bracket = []
    T_LEFT_BRACE,
    T_RIGHT_BRACE,
    T_LEFT_PAREN,
    T_RIGHT_PAREN,
    T_LEFT_BRACKET,
    T_RIGHT_BRACKET,

    // Arithmetic Operators
    T_PLUS,
    T_MINUS,
    T_STAR,
    T_SLASH,
    T_MOD,
    T_BIT_OR,
    T_BIT_AND,
    T_BIT_XOR,
    T_BIT_NOT,
    T_LEFT_SHIFT,
    T_RIGHT_SHIFT,

    // Logical Operators
    T_LOGIC_NOT,
    T_LOGIC_AND,
    T_LOGIC_OR,
    T_LOGIC_EQUAL,
    T_LOGIC_NEQUAL,
    T_LESS,
    T_GREATER,
    T_LESS_EQUAL,
    T_GREATER_EQUAL,

    // Assignment Operators
    T_ASSIGN,
    T_PLUS_EQUAL,
    T_MINUS_EQUAL,
    T_STAR_EQUAL,
    T_SLASH_EQUAL,
    T_MOD_EQUAL,
    T_AND_EQUAL,
    T_OR_EQUAL,
    T_XOR_EQUAL,
    T_LSHIFT_EQUAL,
    T_RSHIFT_EQUAL,

    // Misc
    T_COMMA,
    T_DOT,
    T_COLON,
    T_SEMICOLON,
    T_ARROW,

    // Types:
    T_INT_TYPE,
    T_CHAR_TYPE,
    T_FLOAT_TYPE,
    T_DOUBLE_TYPE,
    T_VOID_TYPE,
    T_STRUCT_TYPE,

    // Switch Case:
    T_SWITCH_KEYWORD,
    T_CASE_KEYWORD,
    T_DEFAULT_KEYWORD,
    T_BREAK_KEYWORD,

    // If-Else
    T_IF_KEYWORD,
    T_ELSE_KEYWORD,

    // Loops
    T_DO_KEYWORD,
    T_WHILE_KEYWORD,
    T_FOR_KEYWORD,
    T_CONTINUE_KEYWORD,

    // Return
    T_RETURN_KEYWORD,

    // Literals
    T_INTEGER_LIT,
    T_FLOAT_LIT,
    T_CHAR_LIT,
    T_STRING_LIT,

    T_IDENTIFIER,
    T_EOF
};


typedef enum TokenType TokenType;

/** 
 * Structure for storing token information. 
 * 
 * Lexeme might be changed to a void *
 */
struct Token{
    TokenType theType;
    int lineNum;
    int colNum;
    char *lexeme;
};

typedef struct Token Token;

/**
 * A function to print a token for debugging and testing.
 *
 */
void printToken(Token *token);


#endif

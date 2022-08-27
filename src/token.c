#include "token.h"

// TODO: Print lexemes. 
void printToken(Token *token){
    switch (token->theType) {
        case T_LEFT_BRACE:
            printf("TOKEN: \"{\" \n");
            return;
        case T_RIGHT_BRACE:
            printf("TOKEN: \"}\" \n");
            return;
        case T_LEFT_PAREN:
            printf("TOKEN: \"(\" \n");
            return;
        case T_RIGHT_PAREN:
            printf("TOKEN: \")\" \n");
            return;
        case T_LEFT_BRACKET:
            printf("TOKEN: \"[\" \n");
            return;
        case T_RIGHT_BRACKET:
            printf("TOKEN: \"]\" \n");
            return;
        case T_PLUS:
            printf("TOKEN: \"+\" \n");
            return;
        case T_MINUS:
            printf("TOKEN: \"-\" \n");
            return;
        case T_STAR:
            printf("TOKEN: \"*\" \n");
            return;
        case T_SLASH:
            printf("TOKEN: \"/\" \n");
            return;
        case T_MOD:
            printf("TOKEN: \"%%\" \n");
            return;
        case T_BIT_OR:
            printf("TOKEN: \"|\" \n");
            return;
        case T_BIT_AND:
            printf("TOKEN: \"&\" \n");
            return;
        case T_BIT_XOR:
            printf("TOKEN: \"^\" \n");
            return;
        case T_BIT_NOT:
            printf("TOKEN: \"~\" \n");
            return;
        case T_LEFT_SHIFT:
            printf("TOKEN: \"<<\" \n");
            return;
        case T_RIGHT_SHIFT:
            printf("TOKEN: \">>\" \n");
            return;
        case T_LOGIC_NOT:
            printf("TOKEN: \"!\" \n");
            return;
        case T_LOGIC_AND:
            printf("TOKEN: \"&&\" \n");
            return;
        case T_LOGIC_OR:
            printf("TOKEN: \"||\" \n");
            return;
        case T_LOGIC_EQUAL:
            printf("TOKEN: \"==\" \n");
            return;
        case T_LOGIC_NEQUAL:
            printf("TOKEN: \"!=\" \n");
            return;
        case T_LESS:
            printf("TOKEN: \"<\" \n");
            return;
        case T_GREATER:
            printf("TOKEN: \">\" \n");
            return;
        case T_LESS_EQUAL:
            printf("TOKEN: \"<=\" \n");
            return;
        case T_GREATER_EQUAL:
            printf("TOKEN: \">=\" \n");
            return;
        case T_ASSIGN:
            printf("TOKEN: \"=\" \n");
            return;
        case T_PLUS_EQUAL:
            printf("TOKEN: \"+=\" \n");
            return;
        case T_MINUS_EQUAL:
            printf("TOKEN: \"-=\" \n");
            return;
        case T_STAR_EQUAL:
            printf("TOKEN: \"*=\" \n");
            return;
        case T_SLASH_EQUAL:
            printf("TOKEN: \"/=\" \n");
            return;
        case T_MOD_EQUAL:
            printf("TOKEN: \"%%=\" \n");
            return;
        case T_AND_EQUAL:
            printf("TOKEN: \"&=\" \n");
            return;
        case T_OR_EQUAL:
            printf("TOKEN: \"|=\" \n");
            return;
        case T_XOR_EQUAL:
            printf("TOKEN: \"^=\" \n");
            return;
        case T_LSHIFT_EQUAL:
            printf("TOKEN: \"<<=\" \n");
            return;
        case T_RSHIFT_EQUAL:
            printf("TOKEN: \">>=\" \n");
            return;
        case T_COMMA:
            printf("TOKEN: \",\" \n");
            return;
        case T_DOT:
            printf("TOKEN: \".\" \n");
            return;
        case T_COLON:
            printf("TOKEN: \":\" \n");
            return;
        case T_SEMICOLON:
            printf("TOKEN: \";\" \n");
            return;
        case T_ARROW:
            printf("TOKEN: \"->\" \n");
            return;
        case T_INT_TYPE:
            printf("TOKEN: \"int\" \n");
            return;
        case T_CHAR_TYPE:
            printf("TOKEN: \"char\" \n");
            return;
        case T_FLOAT_TYPE:
            printf("TOKEN: \"float\" \n");
            return;
        case T_DOUBLE_TYPE:
            printf("TOKEN: \"double\" \n");
            return;
        case T_VOID_TYPE:
            printf("TOKEN: \"void\" \n");
            return;
        case T_STRUCT_TYPE:
            printf("TOKEN: \"struct\" \n");
            return;
        case T_SWITCH_KEYWORD:
            printf("TOKEN: \"switch\" \n");
            return;
        case T_CASE_KEYWORD:
            printf("TOKEN: \"case\" \n");
            return;
        case T_DEFAULT_KEYWORD:
            printf("TOKEN: \"default\" \n");
            return;
        case T_BREAK_KEYWORD:
            printf("TOKEN: \"break\" \n");
            return;
        case T_IF_KEYWORD:
            printf("TOKEN: \"if\" \n");
            return;
        case T_ELSE_KEYWORD:
            printf("TOKEN: \"else\" \n");
            return;
        case T_DO_KEYWORD:
            printf("TOKEN: \"do\" \n");
            return;
        case T_WHILE_KEYWORD:
            printf("TOKEN: \"while\" \n");
            return;
        case T_FOR_KEYWORD:
            printf("TOKEN: \"for\" \n");
            return;
        case T_CONTINUE_KEYWORD:
            printf("TOKEN: \"continue\" \n");
            return;
        case T_RETURN_KEYWORD:
            printf("TOKEN: \"return\" \n");
            return;
        case T_INTEGER_LIT:
            printf("TOKEN: \"Integer Literal\" \n");
            return;
        case T_FLOAT_LIT:
            printf("TOKEN: \"Float Literal\" \n");
            return;
        case T_CHAR_LIT:
            printf("TOKEN: \"Char Literal\" \n");
            return;
        case T_STRING_LIT:
            printf("TOKEN: \"String Literal\" \n");
            return;
        case T_IDENTIFIER:
            printf("TOKEN: \"Identifier\" \n");
            return;
        case T_EOF:
            printf("TOKEN: \"EOF\" \n");
            return;
    }
}






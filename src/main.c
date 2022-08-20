#include "main.h"

void printHelp(){
    printf("Usage: ./main <File> -Options\n\n"
         "Options can include:\n\t-help\t"
         " Shows all instructions\n\t-o0\t"
         " Compile without any optimizations\n\t-ast\t"
         " Show the AST\n");
}

int main(int argc, char *argv[]){
    if( argc < 2 ) {
        fprintf(stderr, "No input file specified. Usage: ./main <File> -Options.\n\t for more options, try ./main -help");
    } else if (argc == 2) {
        if(strcmp("-help", argv[1]) == 0){
            printHelp();
        } else {
            // Single file. Attempt to open. 
        }
    } else { 
        int noOptimization = 0;
        int showAst = 0;
        int flag = 1;
        for (int i = 2; i < argc; i++) {
            if(strcmp("-o0", argv[i]) == 0){
                noOptimization = 1;
            } else if(strcmp("-ast", argv[i]) == 0) {
                showAst = 1;
            } else if(strcmp("-help", argv[i]) == 0) {
                printHelp();
            } else {
                fprintf(stderr, "ERROR: unkown command. exiting.\n");
                flag = 0;
                break;
            }
        }
        
        if(flag){
            // 
        }
    }
    return 0;
}

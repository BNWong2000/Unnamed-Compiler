#include "main.h"

void printHelp(){
    printf("Usage: ./main <File> -Options\n\n"
         "Options can include:\n\t-help\t"
         " Shows all instructions\n\t-o0\t"
         " Compile without any optimizations\n\t-ast\t"
         " Show the AST\n");
}

/**
 * Starts the compilation process with the selected flags. 
 * fileName     The name of the input source file. 
 * noOp         Flag for whether or not to optimize.
 * showAst      Flag for whether or not to print the AST.
 * 
 * Returns the return code (0 for success)
 */
int run(char *fileName, int noOp, int showAst){
    // Open file and check if valid.
    FILE *inputFile = fopen(fileName, "r");
    if (inputFile == NULL) {
        fprintf(stderr, "ERROR: Unable to open file. \n");    
        return 1;
    }

    // Check Grammar. Use showAst here. 
    

    // Check Semantics. 

    if( !noOp ) {
        // Optimize the code.
    }

    // Output the file. 
    return 0;
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
            return run(argv[1], noOptimization, showAst); 
        }
    }
    return 0;
}

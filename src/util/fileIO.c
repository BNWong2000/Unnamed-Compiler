#include "fileIO.h"





int initReadOnlyFileStream(FileStream *stream, const char *fileName){
    FILE *input = fopen(fileName, "r");

    if ( input == NULL ){
        fprintf(stderr, "ERROR: Unable to open file. \n");
        return 1;
    }
    stream->inputFile = input;
    stream->currIndex = 0;

    // Fill the buffer. 
    int buffSize = (int) fread(stream->readBuffer, 1, READ_BUFFER_SIZE, input);
    
    // If we've read less than our buffer, then we've read the whole file.
    if(buffSize < READ_BUFFER_SIZE) {
        fclose(stream->inputFile);
        stream->fileFinishedReading = 1;
    }


    stream->currBuffSize = buffSize; 
    return 0;
}

char readChar(FileStream *stream){
    return '$';
}



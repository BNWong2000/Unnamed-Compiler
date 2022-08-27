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

int readChar(FileStream *stream){
    if(stream->currIndex >= stream->currBuffSize ){ 
        // buffer has already been exhausted.
        if( stream->fileFinishedReading ){
            // reached EOF
            return EOF;
        }
        
        // Otherwise re-fill the buffer.
        stream->currIndex = 0;
        int buffSize = (int) fread(stream->readBuffer, 1, READ_BUFFER_SIZE, stream->inputFile);

        if(stream->currBuffSize < READ_BUFFER_SIZE) {
            fclose(stream->inputFile);
            stream->fileFinishedReading = 1;
        }

        // Edge case - Previous buffer read filled the buffer
        // and also reached EOF. 
        if(stream->currBuffSize <= 0) {
            return EOF;
        }

        stream->currBuffSize = buffSize;
    }

    // At this point, we know the buffer has something in it. 
    int result = stream->readBuffer[stream->currIndex];
    stream->currIndex++;
    // could also just return stream->charBuffer[stream->currIndex++] but I hate that syntax tbh. 
    return result;
}



#ifndef FILEIO_H
#define FILEIO_H

#include <stdio.h>

#define READ_BUFFER_SIZE 1024

struct FileStream {
    // Input file.
    FILE *inputFile;

    // Buffered read input
    char readBuffer[READ_BUFFER_SIZE];
    
    // Current index to read from. 
    int currIndex;

    // The current size of the buffer
    // (important for if the buffer isn't filled fully by the file)
    int currBuffSize;

    // Flag for if we've already hit EOF.
    int fileFinishedReading;
};

typedef struct FileStream FileStream;


/**
 * A function to initialize the fileStream Object
 * Opens the file.
 * Fills the Buffer. 
 */
int initReadOnlyFileStream(FileStream *stream, const char *fileName);

/**
 * A function for buffered reading of a char from the input stream. 
 */
char readChar (FileStream *stream); 

#endif

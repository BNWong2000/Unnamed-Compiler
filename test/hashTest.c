#include "../src/dataStructures/hashTable.h"

typedef struct HashTable HashTable;


// Very Basic test for hash tables.
int main (int argc, char *argv[]) {
    HashTable *testTable;
    testTable = constructTable();

    int info = 1;
    hashTableSet(testTable, "BOB", (void *) &info);
    hashTableSet(testTable, "JOE", (void *) &info);
    hashTableSet(testTable, "SAM", (void *) &info);
    hashTableSet(testTable, "SARAH", (void *) &info);
    hashTableSet(testTable, "GREG", (void *) &info);
    hashTableSet(testTable, "ALEX", (void *) &info);
    hashTableSet(testTable, "KATE", (void *) &info);
    printf("printing the table...\n");
    printHashTable(testTable);


    printf("BOB is %d\n", *(int *)(hashTableGet(testTable, "BOB")));


}
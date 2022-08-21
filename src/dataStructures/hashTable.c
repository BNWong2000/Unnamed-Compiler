#include "hashTable.h"

/**
 * Collision prevention
 * 
 */ 
struct HashTableEntry {
    const char *key;
    void *value;
    HashTableEntry *next;
};

HashTableEntry *createTableEntry(const char *key, void *value) {
    HashTableEntry *newEntry = (HashTableEntry *) malloc( sizeof(HashTableEntry) );
    if ( newEntry == NULL ) {
        fprintf(stderr, "ERROR: Out of memory. \n");
        return NULL;
    }

    char *keyVal = (char *) malloc( sizeof(key) );
    if ( keyVal == NULL ) {
        free(newEntry);
        fprintf(stderr, "ERROR: Out of memory. \n");
        return NULL;
    }

    strcpy(keyVal, key);
    newEntry->key = keyVal;
    newEntry->value = value;
    newEntry->next = NULL;

    return newEntry;
}

void destroyTableEntry(HashTableEntry *entry){
    if( entry == NULL ) return;

    HashTableEntry *currEntry = entry;
    HashTableEntry *nextEntry = entry->next;
    while(nextEntry != NULL){
        free(currEntry->key);
        free(currEntry);
        currEntry = nextEntry;
        nextEntry = currEntry->next;
    } 

    free(currEntry);
}

HashTable *constructTable(){
    HashTable *table = (HashTable *) malloc( sizeof(HashTable) );

    if ( table == NULL ) {
        fprintf(stderr, "ERROR: Out of memory. \n");
        return NULL;
    }
    
    // calloc chosen over malloc so we init values to null. 
    table->tableEntries = (HashTableEntry *) calloc ( (size_t) INITIAL_CAPACITY, sizeof(HashTableEntry *));
    table->arrayLen = INITIAL_CAPACITY;
    table->numEntries = 0;

    if( table->tableEntries == NULL ){
        free( table );
        fprintf(stderr, "ERROR: Out of memory. \n");
        return NULL;
    }

    return table;
}

void destroyTable(HashTable *table){
    for (int i = 0; i < table->arrayLen; i++) {
        destroyTableEntry(table->tableEntries[i]);
    }
    free(table);
}

void *hashTableGet(HashTable *table, const char *key){
    if (table == NULL) {
        return NULL;
    }

    if (key == NULL) {
        return NULL;
    }

    uint32_t index;
}

const char *hashTableSet(HashTable *table, const char *key, void *value){
    
}

/** 
 * Based on the algorithm defined here:
 * https://en.wikipedia.org/wiki/MurmurHash
 */
uint32_t hash (const char *strEntry, size_t len) {
    uint32_t seed = HASH_SEED;
    uint32_t c1 = 0xcc9e2d51;
    uint32_t c2 = 0x1b873593;
    uint32_t r1 = 15;
    uint32_t r2 = 13;
    uint32_t m = 5;
    uint32_t n = 0xe6546b64;
    


}

